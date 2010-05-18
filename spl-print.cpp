#include "spl.h"

// All debug printing logic extracted to here

void StmtList::print(int lvl)
{
	indent(lvl);
	printf("StmtList:\n");

	for(list<Node*>::iterator iter = sl.begin(); iter != sl.end(); iter++)
	{
		(*iter)->print(lvl+1);
	}
}

void List::print(int lvl)
{
	if(c != NULL)
	{
		c->print(lvl);
	}

	if(d != NULL)
	{
		d->print(lvl);
	}

	indent(lvl);
	cout << "(";
	s->print(lvl+1);
	indent(lvl);
	cout << ")" << endl;
}

void Integer::print(int lvl)
{
	//indent(lvl);
	cout << n;
}

void Double::print(int lvl)
{
	//indent(lvl);
	cout << d;
}

void Complex::print(int lvl)
{
	//indent(lvl);
	cout << re << "+" << im << "i";
}

void Ident::print(int lvl)
{
	//indent(lvl);
	cout << i;
}

void Seq::print(int lvl)
{
	for(vector<Node*>::iterator iter = s.begin(); iter != s.end(); iter++)
	{
		if(iter == s.begin())
		{
			cout << " ";
			(*iter)->print(0);
		}
		else
		{
			(*iter)->print(lvl+1);
		}
	}
}

void Comment::print(int lvl)
{
	indent(lvl);
	cout << "Comment: " << c << endl;
}

void Directive::print(int lvl)
{
	indent(lvl);
	cout << dir_type << " " << opt1 << " " << opt2 << endl;
}

void ICodeIdent::print(int lvl)
{
	//indent(lvl);
	cout << ident;
}

void Template::print(int lvl)
{
	indent(lvl);
	cout << "Template: " << ident << endl;
	pattern->print(lvl+1);
	indent(lvl); cout << "[" << endl;
	cond->print(lvl+1);
	indent(lvl); cout << "]" << endl;
	icode->print(lvl+1);
}

void ICodeStmtList::print(int lvl)
{
	//indent(lvl);
	//cout << "ICodeStmtList" << endl;

	for(list<ICode*>::iterator iter = sl.begin(); iter != sl.end(); iter++)
	{
		(*iter)->print(lvl+1);
	}
}

void Comparison::print(int lvl)
{
	indent(lvl);
	cout << "Comparison" << endl;
	expr1->print(lvl+1);

	indent(lvl);
	switch(type)
	{
		case EQUAL_EQUAL:
			cout << "==" << endl;
			break;
		case GREATER_THAN:
			cout << ">" << endl;
			break;
		case GREATER_THAN_EQUAL:
			cout << ">=" << endl;
			break;
		case LESS_THAN:
			cout << "<" << endl;
			break;
		case LESS_THAN_EQUAL:
			cout << "<=" << endl;
			break;
		case NOT_EQUAL:
			cout << "!=" << endl;
			break;
	}

	expr2->print(lvl+1);
}

void ICodeDot::print(int lvl) 
{ 
	//indent(lvl); 
	//cout << "ICodeDot" << endl;
	expr1->print(lvl+1);
	cout << ".";
	expr2->print(lvl+1);
}

void Plus::print(int lvl) 
{ 
	//indent(lvl); 
	e1->print(lvl+1);
	//indent(lvl); 
	cout << "+";
	e2->print(lvl+1);
}

void Minus::print(int lvl) 
{ 
	//indent(lvl); 
	//cout << "Minus" << endl;
	e1->print(lvl+1);
	//indent(lvl); 
	cout << "-";
	e2->print(lvl+1);
}

void Divide::print(int lvl) 
{ 
	indent(lvl); 
	//cout << "Divide" << endl;
	e1->print(lvl+1);
	//indent(lvl); 
	cout << "/";
	e2->print(lvl+1);
}

void Multiply::print(int lvl) 
{ 
	//cout << "!" << e1->type << "!" << endl;
	e1->print(lvl+1);
	cout << "*";
	e2->print(lvl+1);
}

void ICodeVecIndex::print(int lvl)
{
	//indent(lvl);
	//cout << "ICodeVecIndex" << endl;
	ident->print(lvl+1);
	cout << "(";
	//index->print(lvl+1);
	cout << str_index;
	cout << ")";
}

void Call::print(int lvl)
{
	indent(lvl);
	cout << "Call: " << ident << endl;
	indent(lvl); cout << "(" << endl;

	seq->print(lvl+1);

	indent(lvl); cout << ")" << endl;
}

void ICode::print(int lvl)
{
	print(lvl, true);
}

void ICode::print(int lvl, bool newline)
{ 
	switch(op)
	{
		case ICODE_OP_DO:
			cout << "do ";
			param1->print(lvl+1);
			cout << " = ";
			param2->print(lvl+1);
			cout << ", ";
			if(param3->type == NODE_ICODE)
				((ICode*)param3)->print(lvl+1, false);
			else
				param3->print(lvl+1);
			break;
		case ICODE_OP_END:
			cout << "end";
			break;
		case ICODE_OP_ADD:
			if(param1 != NULL)
			{
				param1->print(lvl+1);
				cout << " = ";
			}
			param2->print(lvl+1);
			cout << " + ";
			param3->print(lvl+1);
			break;
		case ICODE_OP_SUB:
			if(param1 != NULL)
			{
				param1->print(lvl+1);
				cout << " = ";
			}
			param2->print(lvl+1);
			cout << " - ";
			param3->print(lvl+1);
			break;
		case ICODE_OP_MUL:
			if(param1 != NULL)
			{
				param1->print(lvl+1);
				cout << " = ";
			}
			param2->print(lvl+1);
			cout << " * ";
			param3->print(lvl+1);
			break;
		case ICODE_OP_DIV:
			if(param1 != NULL)
			{
				param1->print(lvl+1);
				cout << " = ";
			}
			param2->print(lvl+1);
			cout << " / ";
			param3->print(lvl+1);
			break;
		case ICODE_OP_CALL:
			if(param1 != NULL) param1->print(lvl+1);
			cout << "(";
			if(param2 != NULL) param2->print(lvl+1);
			cout << ",";
			if(param3 != NULL) param3->print(lvl+1);
			cout << ",";
			if(param4 != NULL) param4->print(lvl+1);
			cout << ",";
			if(param5 != NULL) param5->print(lvl+1);
			cout << ",";
			if(param6 != NULL) param6->print(lvl+1);
			//cout << ",";
			//if(param7 != NULL) param7->print(lvl+1);
			cout << ")";
			break;
		case ICODE_OP_ASSIGN:
			param1->print(lvl+1);
			cout << " = ";
			param2->print(lvl+1);
			break;

		default:
			cerr << "Unknown OP code!" << endl;
			break;
	};

	if(newline) cout << endl;
}

void ICodePattern::print(int lvl) 
{ 
	//indent(lvl); 
	cout << i;
}

void ICodeFunc::print(int lvl)
{
	cout << func << "(";
	param1->print(lvl+1);
	cout << ",";
	param2->print(lvl+1);
	if(param3 != NULL)
	{
		cout << ",";
		param3->print(lvl+1);
	}
	cout << ")";
}


