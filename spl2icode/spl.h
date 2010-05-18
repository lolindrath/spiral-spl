#ifndef __SPL__H__
#define __SPL__H__

#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <cmath>
#include <cassert>

#include <string>
#include <list>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
using namespace std;

//#include "icode.h"

class Integer;
class Double;
class Complex;
class Ident;
class List;
class Seq;
class ListElement;
class Comment;
class Directive;
class StmtList;
class Node;
class NodeList;
class ICodeStmtList;
class ICodeStmt;
class Template;
class Value;
class ICode;
class Vector;

extern int yylineno; /* from flex */
void yyerror(char *s, ...);

void indent(int lvl);
void eval(StmtList *sl);
Template *match_template(string ident, List *l);
bool match_pattern(Seq *p, Seq *l);
Node *match_param(Node *n, Seq *p, Seq *opts);
void expand_seq(Seq *s, Vector *in, Vector *out);

typedef list<Node*> expr_list;
typedef vector<Node*>::iterator expr_iter;
typedef list<ICode*> icode_list;
typedef list<ICode*>::iterator icode_iter;

enum DirectiveType
{
	DIR_SUBNAME = 0,
	DIR_SHAPE
};

enum CmpType
{
	EQUAL_EQUAL = 0,
	GREATER_THAN,
	GREATER_THAN_EQUAL,
	LESS_THAN,
	LESS_THAN_EQUAL,
	NOT_EQUAL,
};

enum NodeType
{
	NODE_NONE = 0,
	NODE_LIST,
	NODE_INTEGER,
	NODE_DOUBLE,
	NODE_COMPLEX,
	NODE_IDENT,
	NODE_ICODE_IDENT,
	NODE_ICODE_PATTERN,
	NODE_COMMENT,
	NODE_DIRECTIVE,
	NODE_PLUS, /* 10 */
	NODE_MINUS,
	NODE_MULTIPLY,
	NODE_DIVIDE,
	NODE_COMPARISON,
	NODE_DEFINE,
	NODE_CALL,
	NODE_ICODE,
	NODE_ICODE_VEC_IND,
	NODE_SEQ,
	NODE_ICODE_DOT, /* 20 */
	NODE_TEMPLATE,
	NODE_ICODE_FUNC
};

enum ICodeIdentType
{
	IDENT_SCALAR = 0,
	IDENT_INDEX,
	IDENT_IN,
	IDENT_OUT,
	IDENT_VEC,
	IDENT_COMPLEX /* 5 */
};

class Node
{
public:
	NodeType type;

	virtual void check() = 0;
	virtual void eval() = 0;
	virtual void print(int) = 0;
};

class Stmt
{
public:
	virtual void check() = 0; 
	virtual void print(int) = 0;
	virtual void eval() = 0;
};

class StmtList
{
public:
	list<Node *> sl;

	StmtList(Node *stmt)
	{
		sl.push_front(stmt);
	}

	void check();
	void insert(Node *stmt);
	void print(int);
	void eval();
};

class List: public Node
{
public:
	Comment *c;
	Directive *d;
	Seq *s;

	List()
	{
		type = NODE_LIST;
		c = NULL;
		d = NULL;
		s = NULL;
	}

	List(Seq *seq);
	List(Comment *cmt, List *l);
	List(Directive *dir, List *l);

	void check();
	void print(int);
	void eval() {};
};

class Integer: public Node
{
public:
	int n;

	Integer(int i)
	{
		type = NODE_INTEGER;
		n = i;
	}

	void check() {};
	void print(int);
	void eval() {};
};

class Double: public Node
{
public:
	double d;

	Double(double i)
	{
		type = NODE_DOUBLE;
		d = i;
	}

	void check() {};
	void print(int);
	void eval() {};
};

class Complex: public Node
{
public:
	double re;
	double im;

	Complex(double r, double i)
	{
		type = NODE_COMPLEX;
		re = r;
		im = i;
	}

	Complex(string c)
	{
		type = NODE_COMPLEX;
		size_t pos = c.find("i");
		
		if(pos == string::npos)
		{
			cerr << "Error parsing complex number!" << endl;
			exit(1);
		}

		re = atof(c.substr(0, pos).c_str());
		im = atof(c.substr(pos+1, c.size()-1).c_str());
	}

	void check() {};
	void print(int);
	void eval() {};
};

class Ident: public Node
{
public:
	string i;

	Ident(string ident)
	{
		type = NODE_IDENT;
		i = ident;
	}

	void check() {};
	void print(int);
	void eval() {};
};

class ICodeIdent: public Node
{
public:
	ICodeIdentType ident_type;
	string ident;
	int num;

	ICodeIdent(ICodeIdentType t, string i)
	{
		ident_type = t;
		type = NODE_ICODE_IDENT;
		ident = i;
		num = atoi(ident.c_str()+2);
	}

	void check() {}
	void print(int);
	void eval() {}
};

class ICodePattern: public Node
{
public:
	string i;

	ICodePattern(string ident)
	{
		type = NODE_ICODE_PATTERN;
		i = ident;
	}

	bool isMatrix()
	{
		return isupper(i[0]);
	}

	bool isVector()
	{
		return islower(i[0]);
	}

	void check() {}
	void print(int);
	void eval() {}
};

class Seq : public Node
{
public:
	vector<Node *> s;

	Seq(Node *e)
	{
		type = NODE_SEQ;
		s.push_back(e);
	}

	Seq()
	{
		type = NODE_SEQ;
	}

	void check();
	void insert(Node *v);
	void print(int);
	void eval();
};

class Comment: public Node
{
public:
	string c;

	Comment(string cmt)
	{
		type = NODE_COMMENT;
		c = cmt.substr(1, cmt.size()-1);
	}

	void check() {};
	void print(int);
	void eval() {};
};


extern const char *directives[];

class Directive: public Node
{
public:
	DirectiveType dir_type;
	string opt1;
	string opt2;

	Directive(DirectiveType d, string o1, string o2 = "")
	{
		type = NODE_DIRECTIVE;
		dir_type = d;
		opt1 = o1;
		opt2 = o2;
	}

	void check() {};
	void print(int);
	void eval() {};
};


class Plus : public Node
{
public:
	Node *e1;
	Node *e2;

	Plus(Node *expr1, Node *expr2)
	{
		type = NODE_PLUS;
		e1 = expr1;
		e2 = expr2;
	}

	void check() {}
	void print(int);
	void eval() {}
};

class Minus : public Node
{
public:
	Node *e1;
	Node *e2;

	Minus(Node *expr1, Node *expr2)
	{
		type = NODE_MINUS;
		e1 = expr1;
		e2 = expr2;
	}

	void check() {}
	void print(int);
	void eval() {}
};

class Multiply : public Node
{
public:
	Node *e1;
	Node *e2;

	Multiply(Node *expr1, Node *expr2)
	{
		type = NODE_MULTIPLY;
		e1 = expr1;
		e2 = expr2;
	}

	void check() {}
	void print(int);
	void eval() {}
};

class Divide : public Node
{
public:
	Node *e1;
	Node *e2;

	Divide(Node *expr1, Node *expr2)
	{
		type = NODE_DIVIDE;
		e1 = expr1;
		e2 = expr2;
	}

	void check() {}
	void print(int);
	void eval() {}
};

class UnaryMinus : public Node
{
public:
	UnaryMinus(Node *v1)
	{
		cerr << "NOT IN USE" << endl;
		exit(1);
		
	}
};

class Comparison : public Node
{
public:
	Node *expr1;
	CmpType ctype;
	Node *expr2;

	Comparison(Node *e1, enum CmpType t, Node *e2)
	{
		type = NODE_COMPARISON;
		expr1 = e1;
		ctype = t;
		expr2 = e2;
	}

	void check() {}
	void print(int);
	void eval() {}
};

class ICodeStmtList
{
public:
	list<ICode *> sl;

	ICodeStmtList(ICode *stmt)
	{
		sl.push_front(stmt);
	}

	void check();
	void insert(ICode *stmt);
	void print(int);
	void eval();
};

class ICodeDot : public Node
{
public:
	Node *expr1;
	Node *expr2;

	ICodeDot(Node *e1, Node *e2)
	{
		type = NODE_ICODE_DOT;
		expr1 = e1;
		expr2 = e2;
	}

	void check() {}
	void print(int);
	void eval() {}
};

class Template : public Node
{
public:
	string ident;
	Seq *pattern;
	Node *cond;
	ICodeStmtList *icode;
	
	Template(string i, Seq *p, Node *c, ICodeStmtList *sl)
	{
		type = NODE_TEMPLATE;
		ident = i;
		pattern = p;
		cond = c;
		icode = sl;
	}

	void check() {};
	void print(int);
	void eval() {};

	
	void expand(Seq *opts, Node *in, Node *in_offset, Node *in_stride, Node *out, Node *out_offset, Node *out_stride);
	static Template *find(string ident, int opts);
};

class ICodeVecIndex : public Node
{
public:
	ICodeIdent *ident;
	Seq *index;
	string str_index;

	ICodeVecIndex(ICodeIdent *e1, Seq *e2)
	{
		type = NODE_ICODE_VEC_IND;
		ident = e1;
		index = e2;
	}
	ICodeVecIndex(ICodeIdent *e1, Seq *e2, string s)
	{
		type = NODE_ICODE_VEC_IND;
		ident = e1;
		index = e2;
		str_index = s;
	}

	void check() {};
	void print(int);
	void eval() {};
};

class Define : public Node
{
public:
	string ident;
	Seq *seq;

	Define(string i, Seq *s)
	{
		type = NODE_DEFINE;
		ident = i;
		seq = s;
	}
	void check() {};
	void print(int lvl) {};
	void eval();
};

class Call : public Node
{
public:
	string ident;
	Seq *seq;

	Call(string i, Seq *s)
	{
		type = NODE_CALL;
		ident = i;
		seq = s;
	}

	void check();
	void print(int);
	void eval();
	void eval(Node *v_in, Node *in_offset, Node *in_stride, Node *v_out, Node *out_offset, Node *out_stride);
};

enum ICODE_OP
{
	ICODE_OP_DO = 0,
	ICODE_OP_END,
	ICODE_OP_ADD,
	ICODE_OP_SUB,
	ICODE_OP_MUL,
	ICODE_OP_DIV,
	ICODE_OP_CALL,
	ICODE_OP_ASSIGN
};

class ICode : public Node
{
public:
	ICODE_OP op;
	Node *param1;
	Node *param2;
	Node *param3;
	Node *param4;
	Node *param5;
	Node *param6;
	Node *param7;

	ICode(ICODE_OP o, Node *p1 = NULL, Node *p2 = NULL, Node *p3 = NULL, Node *p4 = NULL, Node *p5 = NULL, Node *p6 = NULL, Node *p7 = NULL)
	{
		type = NODE_ICODE;
		op = o;
		param1 = p1;
		param2 = p2;
		param3 = p3;
		param4 = p4;
		param5 = p5;
		param6 = p6;
		param7 = p7;
	}

	ICode(const ICode& copy)
	{
		type = NODE_ICODE;
		op = copy.op;
		param1 = copy.param1;
		param2 = copy.param2;
		param3 = copy.param3;
		param4 = copy.param4;
		param5 = copy.param5;
		param6 = copy.param6;
		param7 = copy.param7;
	}

	void check() {};
	void print(int lvl);
	void print(int lvl, bool);

	void eval() {};
};

class Vector
{
};

class ICodeFunc : public Node
{
public:
	string func;
	Node *param1;
	Node *param2;
	Node *param3;

	ICodeFunc(string f, Node *p1, Node *p2, Node *p3 = NULL)
	{
		type = NODE_ICODE_FUNC;
		func = f;
		param1 = p1;
		param2 = p2;
		param3 = p3;
	}

	void check() {};
	void print(int);
	void eval() {};
};

#endif





