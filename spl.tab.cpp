
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 9 "spl.ypp"

#include "spl.h"
#include "symbol.h"
#include "symboltable.h"
#include <iostream>

extern list<Template*> templates;
extern list<List*> lists;


/* Line 311 of lalr1.cc  */
#line 52 "spl.tab.cpp"


#include "spl.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 80 "spl.ypp"

extern int yylex(yy::spl_parser::semantic_type *yylval, yy::spl_parser::location_type *yylloc);


/* Line 317 of lalr1.cc  */
#line 66 "spl.tab.cpp"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace yy {

/* Line 380 of lalr1.cc  */
#line 135 "spl.tab.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  spl_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  spl_parser::spl_parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {
  }

  spl_parser::~spl_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  spl_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  spl_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  spl_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  spl_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  spl_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  spl_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  spl_parser::debug_level_type
  spl_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  spl_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  spl_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 86 "spl.ypp"
    { eval((yysemantic_stack_[(1) - (1)].sl)); }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 89 "spl.ypp"
    { (yysemantic_stack_[(2) - (2)].sl)->insert((yysemantic_stack_[(2) - (1)].node)); (yyval.sl) = (yysemantic_stack_[(2) - (2)].sl); }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 90 "spl.ypp"
    { (yyval.sl) = new StmtList((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 93 "spl.ypp"
    { (yyval.node) = new Comment(string((yysemantic_stack_[(1) - (1)].c))); }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 94 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(2) - (2)].node); templates.push_front((Template*) (yysemantic_stack_[(2) - (2)].node)); }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 95 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); templates.push_front((Template*) (yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 96 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 97 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(2) - (2)].node); }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 98 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 99 "spl.ypp"
    { 
	
		SymbolTable *t = SymbolTable::instance();
		Symbol *s = t->find(string((yysemantic_stack_[(1) - (1)].i)));

		if(s == NULL)
		{
			cerr << "Error: symbol undefined: " << (yysemantic_stack_[(1) - (1)].i) << endl;
			exit(1);
		}
		else
		{
			cerr << "replacing symbol: " << (yysemantic_stack_[(1) - (1)].i) << endl;
			Seq *seq = ((Define*)s->node)->seq;
			(yyval.node) = *seq->s.begin();
			/*ICodeIdent *i = (ICodeIdent*)*seq->s.begin();
			vector<Node*> v(seq->s.begin()+1,seq->s.end());
			Seq *new_seq = new Seq();
			new_seq->s = v;
			$$ = new Call(i->ident, new_seq);*///((Define*)s->node)->seq);
			//$$ = ((Define*)s->node)->seq;
		}
	}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 124 "spl.ypp"
    { (yyval.dir) = new Directive(DIR_SUBNAME, string((yysemantic_stack_[(3) - (3)].i))); }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 125 "spl.ypp"
    { (yyval.dir) = new Directive(DIR_SHAPE, string((yysemantic_stack_[(4) - (3)].i)), string((yysemantic_stack_[(4) - (4)].i))); }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 128 "spl.ypp"
    { (yyval.node) = new Template(string((yysemantic_stack_[(10) - (3)].i)), (yysemantic_stack_[(10) - (4)].s), (yysemantic_stack_[(10) - (6)].node), (yysemantic_stack_[(10) - (8)].icode_stmtlist)); }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 131 "spl.ypp"
    { (yysemantic_stack_[(2) - (2)].s)->insert((yysemantic_stack_[(2) - (1)].node)); (yyval.s) = (yysemantic_stack_[(2) - (2)].s); }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 132 "spl.ypp"
    { (yyval.s) = new Seq((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 135 "spl.ypp"
    { (yyval.node) = new ICodePattern(string((yysemantic_stack_[(1) - (1)].p))); }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 136 "spl.ypp"
    { (yyval.node) = new ICodePattern(string((yysemantic_stack_[(1) - (1)].p))); }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 137 "spl.ypp"
    { (yyval.node) = new Integer((yysemantic_stack_[(1) - (1)].n)); }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 141 "spl.ypp"
    { 
		(yyval.node) = new Define((yysemantic_stack_[(4) - (2)].i), (yysemantic_stack_[(4) - (3)].s)); 
		SymbolTable *t = SymbolTable::instance();
		Symbol *s = new Symbol((yysemantic_stack_[(4) - (2)].i), (yyval.node));
		t->insert(s);
	}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 149 "spl.ypp"
    { (yyval.node) = new Call((yysemantic_stack_[(4) - (2)].i), (yysemantic_stack_[(4) - (3)].s)); }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 152 "spl.ypp"
    {(yysemantic_stack_[(2) - (2)].icode_stmtlist)->insert((yysemantic_stack_[(2) - (1)].icode)); (yyval.icode_stmtlist) = (yysemantic_stack_[(2) - (2)].icode_stmtlist); }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 153 "spl.ypp"
    { (yyval.icode_stmtlist) = new ICodeStmtList((yysemantic_stack_[(1) - (1)].icode)); }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 156 "spl.ypp"
    { (yyval.icode) = (yysemantic_stack_[(1) - (1)].icode); }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 157 "spl.ypp"
    { (yyval.icode) = (yysemantic_stack_[(1) - (1)].icode); }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 158 "spl.ypp"
    { (yyval.icode) = (yysemantic_stack_[(1) - (1)].icode); }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 159 "spl.ypp"
    {(yyval.icode) = (yysemantic_stack_[(1) - (1)].icode); }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 162 "spl.ypp"
    { (yyval.icode) = new ICode(ICODE_OP_DO, new ICodeIdent(IDENT_INDEX, (yysemantic_stack_[(6) - (2)].ici)), (yysemantic_stack_[(6) - (4)].node), (yysemantic_stack_[(6) - (6)].node)); }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 165 "spl.ypp"
    { (yyval.icode) = new ICode(ICODE_OP_END); }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 168 "spl.ypp"
    { (yyval.icode) = new ICode(ICODE_OP_ASSIGN, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 169 "spl.ypp"
    { (yyval.icode) = new ICode(ICODE_OP_ADD, (yysemantic_stack_[(5) - (1)].node), (yysemantic_stack_[(5) - (3)].node), (yysemantic_stack_[(5) - (5)].node)); }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 170 "spl.ypp"
    { (yyval.icode) = new ICode(ICODE_OP_SUB, (yysemantic_stack_[(5) - (1)].node), (yysemantic_stack_[(5) - (3)].node), (yysemantic_stack_[(5) - (5)].node)); }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 171 "spl.ypp"
    { (yyval.icode) = new ICode(ICODE_OP_MUL, (yysemantic_stack_[(5) - (1)].node), (yysemantic_stack_[(5) - (3)].node), (yysemantic_stack_[(5) - (5)].node)); }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 172 "spl.ypp"
    { (yyval.icode) = new ICode(ICODE_OP_DIV, (yysemantic_stack_[(5) - (1)].node), (yysemantic_stack_[(5) - (3)].node), (yysemantic_stack_[(5) - (5)].node)); }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 175 "spl.ypp"
    { (yyval.node) = new ICode(ICODE_OP_ADD, NULL, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 176 "spl.ypp"
    { (yyval.node) = new ICode(ICODE_OP_SUB, NULL, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 177 "spl.ypp"
    { (yyval.node) = new ICode(ICODE_OP_MUL, NULL, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 178 "spl.ypp"
    { (yyval.node) = new ICode(ICODE_OP_DIV, NULL, (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 179 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 182 "spl.ypp"
    { (yyval.icode) = new ICode(ICODE_OP_CALL, new ICodePattern(string((yysemantic_stack_[(14) - (1)].p))), (yysemantic_stack_[(14) - (3)].node), (yysemantic_stack_[(14) - (5)].node), (yysemantic_stack_[(14) - (7)].node), (yysemantic_stack_[(14) - (9)].node), (yysemantic_stack_[(14) - (11)].node), (yysemantic_stack_[(14) - (13)].node)); }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 185 "spl.ypp"
    { (yysemantic_stack_[(2) - (2)].s)->insert((yysemantic_stack_[(2) - (1)].node)); (yyval.s) = (yysemantic_stack_[(2) - (2)].s); }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 186 "spl.ypp"
    { (yyval.s) = new Seq((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 189 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 190 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 192 "spl.ypp"
    { 
		SymbolTable *t = SymbolTable::instance();
		Symbol *s = t->find(string((yysemantic_stack_[(1) - (1)].i)));

		if(s == NULL)
		{
			cerr << "Error: symbol undefined: " << (yysemantic_stack_[(1) - (1)].i) << endl;
			exit(1);
		}
		else
		{
			cerr << "replacing symbol: " << (yysemantic_stack_[(1) - (1)].i) << endl;
			Seq *seq = ((Define*)s->node)->seq;
			(yyval.node) = *seq->s.begin();
			/*ICodeIdent *i = (ICodeIdent*)*seq->s.begin();

			cout << "type: " << i->type << "--"<<endl;
			i->print(0);
			cout << "--"<<endl;

			seq->print(0);
			cout << "--"<<endl;
			exit(1);
			vector<Node*> v(seq->s.begin()+1,seq->s.end());
			Seq *new_seq = new Seq();
			new_seq->s = v;
			$$ = new Call(i->ident, new_seq);//((Define*)s->node)->seq);*/
			//$$ = ((Define*)s->node)->seq;
		}
	}
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 224 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(3) - (2)].node); }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 227 "spl.ypp"
    { (yyval.node) = new List(); }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 228 "spl.ypp"
    { (yyval.node) = new List(); }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 229 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 232 "spl.ypp"
    { (yyval.node) = new Comparison((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (2)].cmp), (yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 235 "spl.ypp"
    {(yyval.node) = new Plus((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 236 "spl.ypp"
    {(yyval.node) = new Minus((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 237 "spl.ypp"
    {(yyval.node) = new Multiply((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 238 "spl.ypp"
    {(yyval.node) = new Divide((yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node)); }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 240 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(3) - (2)].node); }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 241 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 247 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].icode_vec_ind); }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 248 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 250 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 253 "spl.ypp"
    { (yyval.icode_vec_ind) = new ICodeVecIndex(new ICodeIdent(IDENT_VEC, string((yysemantic_stack_[(4) - (1)].ici))), (yysemantic_stack_[(4) - (3)].ind_list)); }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 254 "spl.ypp"
    { (yyval.icode_vec_ind) = new ICodeVecIndex(new ICodeIdent(IDENT_IN, string((yysemantic_stack_[(4) - (1)].ici))), (yysemantic_stack_[(4) - (3)].ind_list)); }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 255 "spl.ypp"
    { (yyval.icode_vec_ind) = new ICodeVecIndex(new ICodeIdent(IDENT_OUT, string((yysemantic_stack_[(4) - (1)].ici))), (yysemantic_stack_[(4) - (3)].ind_list)); }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 258 "spl.ypp"
    { (yysemantic_stack_[(2) - (2)].ind_list)->insert((yysemantic_stack_[(2) - (1)].node)); (yyval.ind_list) = (yysemantic_stack_[(2) - (2)].ind_list); }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 259 "spl.ypp"
    { (yyval.ind_list) = new Seq((yysemantic_stack_[(1) - (1)].node)); }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 269 "spl.ypp"
    { (yyval.node) = new Integer((yysemantic_stack_[(1) - (1)].n)); }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 270 "spl.ypp"
    { (yyval.node) = new ICodeIdent(IDENT_COMPLEX, string((yysemantic_stack_[(1) - (1)].ici))); }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 271 "spl.ypp"
    { (yyval.node) = new ICodeIdent(IDENT_INDEX, string((yysemantic_stack_[(1) - (1)].ici))); }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 272 "spl.ypp"
    { (yyval.node) = new ICodeIdent(IDENT_SCALAR, string((yysemantic_stack_[(1) - (1)].ici))); }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 273 "spl.ypp"
    { (yyval.node) = new ICodeIdent(IDENT_IN, string((yysemantic_stack_[(1) - (1)].ici))); }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 274 "spl.ypp"
    { (yyval.node) = new ICodeIdent(IDENT_OUT, string((yysemantic_stack_[(1) - (1)].ici))); }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 275 "spl.ypp"
    { (yyval.node) = new ICodeIdent(IDENT_VEC, string((yysemantic_stack_[(1) - (1)].ici))); }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 276 "spl.ypp"
    { (yyval.node) = new ICodePattern(string((yysemantic_stack_[(1) - (1)].p))); }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 277 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node); }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 280 "spl.ypp"
    { (yyval.node) = new ICodeDot(new ICodePattern(string((yysemantic_stack_[(3) - (1)].p))), new Ident(string((yysemantic_stack_[(3) - (3)].i)))); }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 281 "spl.ypp"
    { (yyval.node) = new ICodeDot(new ICodeIdent(IDENT_IN, string((yysemantic_stack_[(3) - (1)].ici))), new Ident(string((yysemantic_stack_[(3) - (3)].i)))); }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 282 "spl.ypp"
    { (yyval.node) = new ICodeDot(new ICodeIdent(IDENT_OUT, string((yysemantic_stack_[(3) - (1)].ici))), new Ident(string((yysemantic_stack_[(3) - (3)].i)))); }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 283 "spl.ypp"
    { (yyval.node) = new ICodeDot(new ICodeIdent(IDENT_VEC, string((yysemantic_stack_[(3) - (1)].ici))), new Ident(string((yysemantic_stack_[(3) - (3)].i)))); }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 286 "spl.ypp"
    { (yyval.node) = new ICodeFunc(string((yysemantic_stack_[(8) - (1)].c)), (yysemantic_stack_[(8) - (3)].node), (yysemantic_stack_[(8) - (5)].node), (yysemantic_stack_[(8) - (7)].node)); }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 287 "spl.ypp"
    { (yyval.node) = new ICodeFunc(string((yysemantic_stack_[(6) - (1)].c)), (yysemantic_stack_[(6) - (3)].node), (yysemantic_stack_[(6) - (5)].node)); }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 290 "spl.ypp"
    { (yyval.node) = new Integer((yysemantic_stack_[(1) - (1)].n)); }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 291 "spl.ypp"
    { (yyval.node) = new Double((yysemantic_stack_[(1) - (1)].d)); }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 292 "spl.ypp"
    { (yyval.node) = new Complex(string((yysemantic_stack_[(1) - (1)].x))); }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 295 "spl.ypp"
    { (yyval.node) = new ICodeIdent(IDENT_INDEX, string((yysemantic_stack_[(1) - (1)].ici))); }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 296 "spl.ypp"
    { (yyval.node) = new ICodeIdent(IDENT_COMPLEX, string((yysemantic_stack_[(1) - (1)].ici))); }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 297 "spl.ypp"
    { (yyval.node) = new ICodeIdent(IDENT_SCALAR, string((yysemantic_stack_[(1) - (1)].ici))); }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 298 "spl.ypp"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].icode_vec_ind); }
    break;



/* Line 678 of lalr1.cc  */
#line 1075 "spl.tab.cpp"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  spl_parser::yysyntax_error_ (int yystate)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char spl_parser::yypact_ninf_ = -100;
  const short int
  spl_parser::yypact_[] =
  {
         0,  -100,  -100,     1,    -2,    29,   -12,    37,  -100,     0,
     -10,  -100,  -100,  -100,    54,    12,    12,    70,    91,  -100,
    -100,  -100,  -100,    64,  -100,  -100,  -100,  -100,  -100,    38,
      12,  -100,    76,  -100,   102,  -100,  -100,  -100,    94,    64,
    -100,  -100,  -100,  -100,    96,  -100,    75,   120,  -100,   106,
    -100,   112,   114,  -100,  -100,   121,  -100,    75,   -20,  -100,
      84,  -100,  -100,   117,   151,   152,   153,   154,   109,    75,
      75,  -100,    75,    75,    75,    75,    75,   129,   130,   131,
    -100,  -100,   132,  -100,   155,  -100,   133,   117,  -100,  -100,
    -100,  -100,  -100,   138,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,    51,    28,    28,  -100,  -100,   108,    89,    89,    89,
     140,   136,  -100,   108,    40,   116,   118,   139,   135,  -100,
    -100,  -100,   137,    89,   141,   142,   108,  -100,    65,    89,
     108,  -100,  -100,  -100,  -100,   143,   115,   108,   108,   108,
     108,   144,   145,   108,   108,   108,   108,   108,  -100,  -100,
    -100,  -100,    89,   108,  -100,  -100,  -100,  -100,  -100,   -28,
     146,  -100,    89,   108,   156,   147,  -100,   108,   148,   108,
     157,  -100
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  spl_parser::yydefact_[] =
  {
         0,    11,     5,     0,     0,     0,     0,     0,     2,     4,
       0,     7,     8,    10,     0,     0,     0,     0,     0,     1,
       3,     6,     9,     0,    80,    81,    82,    45,    44,     0,
      42,    43,     0,    12,     0,    19,    17,    18,     0,    16,
      20,    41,    21,    13,     0,    15,     0,     0,    65,     0,
      72,    69,    70,    67,    66,    71,    68,     0,     0,    49,
       0,    56,    73,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,     0,    85,     0,    29,     0,    23,    24,    25,
      26,    27,    86,     0,    74,    75,    76,    77,    55,    47,
      48,    50,    51,    52,    53,    54,     0,     0,     0,     0,
       0,     0,    22,     0,    69,    70,    71,     0,     0,    57,
      59,    58,     0,    64,     0,     0,     0,    14,    30,     0,
       0,    61,    63,    62,    60,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,     0,     0,    28,    35,    36,    37,    38,     0,
       0,    79,     0,     0,     0,     0,    78,     0,     0,     0,
       0,    40
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  spl_parser::yypgoto_[] =
  {
      -100,  -100,   164,  -100,  -100,   166,   149,  -100,  -100,    56,
      90,  -100,  -100,  -100,  -100,    35,  -100,    39,  -100,  -100,
    -100,    85,   -23,   -99,   -62,   -66,   -46,  -100,  -100,  -100,
    -100
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  spl_parser::yydefgoto_[] =
  {
        -1,     7,     8,     9,    10,    11,    38,    39,    12,    28,
      86,    87,    88,    89,    90,   135,    91,    29,    30,    47,
      58,    59,    60,   136,   119,   122,   120,    62,   121,    31,
      93
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char spl_parser::yytable_ninf_ = -1;
  const unsigned char
  spl_parser::yytable_[] =
  {
        61,    92,    69,    70,    15,   161,     1,   118,     2,   162,
       3,    61,    17,    18,   128,    24,    25,    26,    27,    71,
       3,     4,     5,    61,    61,    92,    61,    61,    61,    61,
      61,   142,     5,    14,    68,    16,     6,    19,   148,   149,
     150,   151,   124,   125,     5,   155,   156,   157,   158,   101,
     102,   103,   104,   105,   160,    32,    13,   132,    75,    76,
      23,   123,   123,   123,   165,    13,    22,    35,   168,    41,
     170,    40,   107,    36,    37,    65,    33,   123,    48,    73,
      74,    75,    76,   141,    49,    50,    51,    52,    53,    54,
      55,    56,    48,   137,   138,   139,   140,    34,    49,    50,
      51,    52,    53,    54,    55,    56,   159,    57,    43,    42,
      72,    48,    73,    74,    75,    76,   164,    49,    50,   114,
     115,    53,    54,   116,    56,   117,    77,    44,    78,    79,
      80,    81,    82,    83,    46,    84,    85,    73,    74,    75,
      76,    64,    98,   144,   145,   146,   147,    65,   108,    66,
     109,    66,    63,    67,    99,   100,    67,    94,    95,    96,
      97,   106,   107,   108,   109,   113,   111,   126,   110,   127,
     131,   129,   130,    20,   133,   134,    21,   112,   154,     0,
     143,   152,   153,   163,   167,   169,     0,     0,    45,   166,
     171
  };

  /* YYCHECK.  */
  const short int
  spl_parser::yycheck_[] =
  {
        46,    63,    22,    23,     6,    33,     6,   106,     8,    37,
      20,    57,    24,    25,   113,     3,     4,     5,     6,    39,
      20,    21,    32,    69,    70,    87,    72,    73,    74,    75,
      76,   130,    32,    32,    57,     6,    36,     0,   137,   138,
     139,   140,   108,   109,    32,   144,   145,   146,   147,    72,
      73,    74,    75,    76,   153,    16,     0,   123,    30,    31,
       6,   107,   108,   109,   163,     9,    10,     3,   167,    30,
     169,    33,    32,     9,    10,    35,     6,   123,     3,    28,
      29,    30,    31,   129,     9,    10,    11,    12,    13,    14,
      15,    16,     3,    28,    29,    30,    31,     6,     9,    10,
      11,    12,    13,    14,    15,    16,   152,    32,     6,    33,
      26,     3,    28,    29,    30,    31,   162,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     9,    33,    11,    12,
      13,    14,    15,    16,    38,    18,    19,    28,    29,    30,
      31,    35,    33,    28,    29,    30,    31,    35,    32,    35,
      32,    35,    32,    35,    69,    70,    35,     6,     6,     6,
       6,    32,    32,    32,    32,    27,    33,    27,    13,    33,
      33,    32,    37,     9,    33,    33,    10,    87,   143,    -1,
      37,    37,    37,    37,    37,    37,    -1,    -1,    39,    33,
      33
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  spl_parser::yystos_[] =
  {
         0,     6,     8,    20,    21,    32,    36,    41,    42,    43,
      44,    45,    48,    49,    32,     6,     6,    24,    25,     0,
      42,    45,    49,     6,     3,     4,     5,     6,    49,    57,
      58,    69,    57,     6,     6,     3,     9,    10,    46,    47,
      33,    57,    33,     6,    33,    46,    38,    59,     3,     9,
      10,    11,    12,    13,    14,    15,    16,    32,    60,    61,
      62,    66,    67,    32,    35,    35,    35,    35,    62,    22,
      23,    39,    26,    28,    29,    30,    31,     9,    11,    12,
      13,    14,    15,    16,    18,    19,    50,    51,    52,    53,
      54,    56,    64,    70,     6,     6,     6,     6,    33,    61,
      61,    62,    62,    62,    62,    62,    32,    32,    32,    32,
      13,    33,    50,    27,    11,    12,    15,    17,    63,    64,
      66,    68,    65,    66,    65,    65,    27,    33,    63,    32,
      37,    33,    65,    33,    33,    55,    63,    28,    29,    30,
      31,    66,    63,    37,    28,    29,    30,    31,    63,    63,
      63,    63,    37,    37,    55,    63,    63,    63,    63,    66,
      63,    33,    37,    37,    66,    63,    33,    37,    63,    37,
      63,    33
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  spl_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,    43,    45,
      42,    47,    40,    41,   282,    46,    35,    44,    91,    93
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  spl_parser::yyr1_[] =
  {
         0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    44,    44,    45,    46,    46,    47,    47,    47,
      48,    49,    50,    50,    51,    51,    51,    51,    52,    53,
      54,    54,    54,    54,    54,    55,    55,    55,    55,    55,
      56,    57,    57,    58,    58,    58,    59,    60,    60,    60,
      61,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    67,    68,    68,
      69,    69,    69,    70,    70,    70,    70
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  spl_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     1,     2,     1,     1,     2,
       1,     1,     3,     4,    10,     2,     1,     1,     1,     1,
       4,     4,     2,     1,     1,     1,     1,     1,     6,     1,
       3,     5,     5,     5,     5,     3,     3,     3,     3,     1,
      14,     2,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       4,     4,     4,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     8,     6,
       1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const spl_parser::yytname_[] =
  {
    "$end", "error", "$undefined", "INTEGER", "DOUBLE", "COMPLEX", "IDENT",
  "LIST", "COMMENT", "ICODE_MATRIX_PAT", "ICODE_SCALAR_PAT", "IN_IDENT",
  "OUT_IDENT", "INDEX_IDENT", "FLOAT_IDENT", "TMP_VEC_IDENT", "INT_IDENT",
  "W", "DO", "END", "TEMPLATE", "DEFINE", "ANDAND", "OROR", "SUBNAME",
  "SHAPE", "CMP", "'='", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "UMINUS", "'.'", "'#'", "','", "'['", "']'", "$accept", "start",
  "stmt_list", "stmt", "directive", "template", "pattern_list", "pattern",
  "define", "call", "icode_stmt_list", "icode_stmt", "icode_do_stmt",
  "icode_end_stmt", "icode_assign_stmt", "icode_expr", "icode_matrix_call",
  "listsequence", "listelement", "cond", "condition", "compare", "expr",
  "opt", "icode_vec_index", "index_list", "int_opt", "icode_dot",
  "icode_func", "value", "icode_ident", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const spl_parser::rhs_number_type
  spl_parser::yyrhs_[] =
  {
        41,     0,    -1,    42,    -1,    43,    42,    -1,    43,    -1,
       8,    -1,    44,    45,    -1,    45,    -1,    48,    -1,    44,
      49,    -1,    49,    -1,     6,    -1,    36,    24,     6,    -1,
      36,    25,     6,     6,    -1,    20,    32,     6,    46,    33,
      59,    32,    50,    33,    33,    -1,    47,    46,    -1,    47,
      -1,     9,    -1,    10,    -1,     3,    -1,    21,     6,    57,
      33,    -1,    32,     6,    57,    33,    -1,    51,    50,    -1,
      51,    -1,    52,    -1,    53,    -1,    54,    -1,    56,    -1,
      18,    13,    27,    55,    37,    55,    -1,    19,    -1,    70,
      27,    63,    -1,    70,    27,    63,    28,    63,    -1,    70,
      27,    63,    29,    63,    -1,    70,    27,    63,    30,    63,
      -1,    70,    27,    63,    31,    63,    -1,    63,    28,    63,
      -1,    63,    29,    63,    -1,    63,    30,    63,    -1,    63,
      31,    63,    -1,    63,    -1,     9,    32,    63,    37,    63,
      37,    63,    37,    63,    37,    63,    37,    63,    33,    -1,
      58,    57,    -1,    58,    -1,    69,    -1,    49,    -1,     6,
      -1,    38,    60,    39,    -1,    60,    22,    61,    -1,    60,
      23,    61,    -1,    61,    -1,    62,    26,    62,    -1,    62,
      28,    62,    -1,    62,    29,    62,    -1,    62,    30,    62,
      -1,    62,    31,    62,    -1,    32,    62,    33,    -1,    66,
      -1,    64,    -1,    68,    -1,    66,    -1,    15,    32,    65,
      33,    -1,    11,    32,    65,    33,    -1,    12,    32,    65,
      33,    -1,    66,    65,    -1,    66,    -1,     3,    -1,    14,
      -1,    13,    -1,    16,    -1,    11,    -1,    12,    -1,    15,
      -1,    10,    -1,    67,    -1,     9,    35,     6,    -1,    11,
      35,     6,    -1,    12,    35,     6,    -1,    15,    35,     6,
      -1,    17,    32,    66,    37,    66,    37,    66,    33,    -1,
      17,    32,    66,    37,    66,    33,    -1,     3,    -1,     4,
      -1,     5,    -1,    13,    -1,    14,    -1,    16,    -1,    64,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  spl_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    12,    15,    17,    19,
      22,    24,    26,    30,    35,    46,    49,    51,    53,    55,
      57,    62,    67,    70,    72,    74,    76,    78,    80,    87,
      89,    93,    99,   105,   111,   117,   121,   125,   129,   133,
     135,   150,   153,   155,   157,   159,   161,   165,   169,   173,
     175,   179,   183,   187,   191,   195,   199,   201,   203,   205,
     207,   212,   217,   222,   225,   227,   229,   231,   233,   235,
     237,   239,   241,   243,   245,   249,   253,   257,   261,   270,
     277,   279,   281,   283,   285,   287,   289
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  spl_parser::yyrline_[] =
  {
         0,    86,    86,    89,    90,    93,    94,    95,    96,    97,
      98,    99,   124,   125,   128,   131,   132,   135,   136,   137,
     140,   149,   152,   153,   156,   157,   158,   159,   162,   165,
     168,   169,   170,   171,   172,   175,   176,   177,   178,   179,
     182,   185,   186,   189,   190,   191,   224,   227,   228,   229,
     232,   235,   236,   237,   238,   240,   241,   247,   248,   250,
     253,   254,   255,   258,   259,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   280,   281,   282,   283,   286,   287,
     290,   291,   292,   295,   296,   297,   298
  };

  // Print the state stack on the debug stream.
  void
  spl_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  spl_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  spl_parser::token_number_type
  spl_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    36,     2,     2,     2,     2,
      32,    33,    30,    28,    37,    29,    35,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    34
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int spl_parser::yyeof_ = 0;
  const int spl_parser::yylast_ = 190;
  const int spl_parser::yynnts_ = 31;
  const int spl_parser::yyempty_ = -2;
  const int spl_parser::yyfinal_ = 19;
  const int spl_parser::yyterror_ = 1;
  const int spl_parser::yyerrcode_ = 256;
  const int spl_parser::yyntokens_ = 40;

  const unsigned int spl_parser::yyuser_token_number_max_ = 282;
  const spl_parser::token_number_type spl_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yy

/* Line 1054 of lalr1.cc  */
#line 1654 "spl.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 301 "spl.ypp"


namespace yy {
	void spl_parser::error(location const&loc, const std::string& s)
	{
		std::cerr << "error at " << loc << ": " << s << std::endl;
	}
}



