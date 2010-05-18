/* recognize tokens for s-expressions */
%option noyywrap nodefault yylineno
%{
#include "spl.h"
#include "spl.tab.hpp"

#define YY_DECL int yylex(yy::spl_parser::semantic_type *yylval, yy::spl_parser::location_type *yylloc)
// make location include the current token
#define YY_USER_ACTION yylloc->columns(yyleng);

typedef yy::spl_parser::token token;
%}

/* float exponent */
EXP		([Ee][-+][0-9]+)

%%
 // rules for C++ compatible scanner
%{
	// start where previous token ended
	yylloc->step();
%}

 /* single character operators */
":" |
"#" |
"," |
"=" |
"+" |
"*" |
"-" |
"/" |
"^" |
"." |
"[" |
"]" |
"(" |
")" { /*printf("%c\n", yytext[0]);*/ return yytext[0]; }

"&&" { return token::ANDAND; }
"||" { return token::OROR; }

 /* i-code comparison operators */
"==" { yylval->cmp = EQUAL_EQUAL; return token::CMP; }
"!=" { yylval->cmp = NOT_EQUAL; return token::CMP; }
">=" { yylval->cmp = GREATER_THAN_EQUAL; return token::CMP; }
"<=" { yylval->cmp = LESS_THAN_EQUAL; return token::CMP; }
">"  { yylval->cmp = GREATER_THAN;  return token::CMP; }
"<"  { yylval->cmp = LESS_THAN; return token::CMP; }

 /* i-code do / end */
do { return token::DO; }
end { return token::END; }

 /* i-code intrinsic function */
W { yylval->c = "W"; return token::W; }

 /* i-code directive keywords */
subname { return token::SUBNAME; }
shape { return token::SHAPE; }

\(template { return token::TEMPLATE; }

\(define { return token::DEFINE; }

 /* identifiers */
[A-Za-z]{1}[A-Za-z0-9\_]*[A-Za-z0-9]+|[A-Za-z]{1}[A-Za-z0-9]* { /*printf("IDENT: %s\n", yytext);*/ yylval->i = strdup(yytext); return token::IDENT; }

 /* i-code identifiers */
\$in { yylval->ici = strdup(yytext); return token::IN_IDENT; }
\$out { yylval->ici = strdup(yytext); return token::OUT_IDENT; }
\$i[0-9]+ { yylval->ici = strdup(yytext); return token::INDEX_IDENT; }
\$f[0-9]+ { yylval->ici = strdup(yytext); return token::FLOAT_IDENT; }
\$t[0-9]+ { yylval->ici = strdup(yytext); return token::TMP_VEC_IDENT; }
\$r[0-9]+ { yylval->ici = strdup(yytext); return token::INT_IDENT; }

 /* i-code Matrix pattern */
[A-Z]\_ { /*printf("ICODE_PATTERN (matrix): %s\n", yytext);*/ yylval->p = strdup(yytext); return token::ICODE_MATRIX_PAT;}

 /* i-code Scalar pattern */
[a-z]\_ { /*printf("ICODE_PATTERN (scalar): %s\n", yytext);*/ yylval->p = strdup(yytext); return token::ICODE_SCALAR_PAT;}

 /* Integers */
[0-9]+{EXP}? { /*printf("NUM: %f\n", atof(yytext));*/ yylval->n = atoi(yytext); return token::INTEGER; }

 /* Doubles */
[0-9]+"."[0-9]+{EXP}? { /*printf("NUM: %f\n", atof(yytext));*/ yylval->d = atof(yytext); return token::DOUBLE; }

 /* Complex: 1.1i2.2 */
[0-9]+"."[0-9]+"i"[0-9]+"."[0-9]+ { yylval->x = strdup(yytext); return token::COMPLEX; }

^;;.* { /* SPL comments to ignore */ yylloc->step(); }

^;.* { yylval->c = strdup(yytext); return token::COMMENT; }

[ \t] { /* ignore whitespace */ yylloc->step(); }

\n { yylloc->lines(1); yylloc->step(); /*return token::TERM;*/ }

. { fprintf(stderr, "Mystery character %c\n", yytext[0]); }
%%

/*
int main(int argc, char *argv[])
{
	printf("parser\n");

	int tok;
	while(tok = yylex())
	{
	}
}
*/


