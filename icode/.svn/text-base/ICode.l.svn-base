/* recognize tokens for s-expressions */
%option noyywrap nodefault yylineno
%{
#include <ICodeStatementList.h>
#include <ICode.tab.hpp>



#define YY_DECL int yylex(yy::icode_parser::semantic_type *yylval, yy::icode_parser::location_type *yylloc)
// make location include the current token
#define YY_USER_ACTION yylloc->columns(yyleng);

typedef yy::icode_parser::token token;
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

 /*"&&" { return token::ANDAND; }*/
 /*"||" { return token::OROR; }*/

 /* i-code comparison operators */
 /*
"==" { yylval->cmp = EQUAL_EQUAL; return token::CMP; }
"!=" { yylval->cmp = NOT_EQUAL; return token::CMP; }
">=" { yylval->cmp = GREATER_THAN_EQUAL; return token::CMP; }
"<=" { yylval->cmp = LESS_THAN_EQUAL; return token::CMP; }
">"  { yylval->cmp = GREATER_THAN;  return token::CMP; }
"<"  { yylval->cmp = LESS_THAN; return token::CMP; }*/

 /* i-code do / end */
do { return token::DO; }
end { return token::END; }
 /*
\(template { return token::TEMPLATE; }

\(define { return token::DEFINE; }*/

 /* i-code intrinsic function */
W { yylval->name = "W"; return token::W; }

 /* identifiers */
[A-Za-z]{1}[A-Za-z0-9\_]*[A-Za-z0-9]+|[A-Za-z]{1}[A-Za-z0-9]* { /*printf("IDENT: %s\n", yytext);*/ yylval->name = strdup(yytext); return token::IDENT; }

 /* i-code identifiers */
\$in { yylval->name = strdup(yytext); return token::IN_IDENT; }
\$out { yylval->name = strdup(yytext); return token::OUT_IDENT; }
\$i[0-9]+ { yylval->name = strdup(yytext); return token::INDEX_IDENT; }
\$f[0-9]+ { yylval->name = strdup(yytext); return token::FLOAT_IDENT; }
\$t[0-9]+ { yylval->name = strdup(yytext); return token::TMP_VEC_IDENT; }
\$r[0-9]+ { yylval->name = strdup(yytext); return token::INT_IDENT; }

 /* i-code Matrix pattern */
 /*[A-Z]\_ {yylval->p = strdup(yytext); return token::ICODE_MATRIX_PAT;} */


 /* i-code Scalar pattern */
 /*[a-z]\_ { yylval->p = strdup(yytext); return token::ICODE_SCALAR_PAT;} */

 /* Integers */
[0-9]+{EXP}? { /*printf("NUM: %f\n", atof(yytext));*/ yylval->integer = atoi(yytext); return token::INTEGER_VALUE; }

 /* Doubles */
[0-9]+"."[0-9]+{EXP}? { /*printf("NUM: %f\n", atof(yytext));*/ yylval->real = atof(yytext); return token::REAL_VALUE; }

 /* Complex: 1.1i2.2 */
\([0-9]+"."[0-9]+","[0-9]+"."[0-9]+")" { yylval->complex = strdup(yytext); return token::COMPLEX_VALUE; }

 /* Compiler directives */
 /* ^\#[A-Za-z0-9 ]+ {yylval->dir = strdup(yytext); return token::DIRECTIVE; } */

^;;.* { /* SPL comments to ignore */ yylloc->step(); }

 /*^;.* { yylval->c = strdup(yytext); return token::COMMENT; }*/

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


