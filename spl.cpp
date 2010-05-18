#include "spl.h"
#include "spl.tab.hpp"

#include "symboltable.h"

int in_vector_size = -1;

// Storage
list<Template*> templates;
list<List*> lists;
list<ICode*> *new_icode;

// Last loop var for computing vector offsets
vector<ICodeIdent*> loop_stack;

void yyerror(char *s, ...)
{
	va_list ap;
	va_start(ap, s);

	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
	va_end(ap);
}

void indent(int lvl)
{
	for(int i = 0; i < lvl; i++)
	{
		cout << " ";
	}
}

void eval(StmtList *sl)
{
	cerr << "Eval Started..." << endl;

	cerr << "Checking Started..." << endl;
	sl->check();
	cerr << "Done Checking." << endl;

	sl->eval();

	cerr << "Done Eval." << endl;

	//sl->print(0);
}

Template *Template::find(string ident, int opts)
{
	for(list<Template*>::iterator iter = templates.begin(); iter != templates.end(); iter++)
	{
		Template *t = *iter;
		if(t->ident == ident && t->pattern->s.size() == opts)
		{
			return t;
		}
	}

	return NULL;
}

Template *match_template(string ident, Seq *l)
{
	for(list<Template*>::iterator iter = templates.begin(); iter != templates.end(); iter++)
	{
		Template *t = *iter;

		if(t->ident == ident)
		{
			//cout << "template found." << endl;
			// identifiers match - no check if the pattern matches
			if(match_pattern(t->pattern, l) == true)
			{
				//TODO: match condition
				return t;
			}
		}
	}

	return NULL;
}

bool match_pattern(Seq *p, Seq *l)
{
	/*expr_list sp = p->s;
	expr_list lp = l->s;
	
	expr_iter piter = sp.begin();
	expr_iter liter = lp.begin();

	for(piter = sp.begin(), liter = lp.begin(); piter != sp.end(), liter != lp.end(); piter++, liter++)
	{
		Node *e1 = *piter;
		Node *e2 = *liter;


	}*/

	return true;
}

bool match_condition()
{
	return true;
}

Node *match_param(Node *n, Seq *pat, Seq *opts, Node *in, Node *in_offset, Node *in_stride, Node *out, Node *out_offset, Node *out_stride)
{

	if(n->type == NODE_ICODE_PATTERN)
	{
		ICodePattern *p = (ICodePattern*)n;
		string ident = p->i;
		expr_iter pi = pat->s.begin();
		expr_iter oi = opts->s.begin();

		for(; pi != pat->s.end() && oi != opts->s.end(); pi++, oi++)
		{
			ICodePattern *tp = (ICodePattern*)*pi;

			if(ident == tp->i)
			{
				return *oi;
			}
		}

		cerr << "match_param: unmatched template parameter!" << endl;
	}
	else if(n->type == NODE_ICODE_FUNC)
	{
		ICodeFunc *f = (ICodeFunc*)n;

		f->param1 = match_param(f->param1, pat, opts, in, in_offset, in_stride, out, out_offset, out_stride);
		f->param2 = match_param(f->param2, pat, opts, in, in_offset, in_stride, out, out_offset, out_stride);

		if(f->param3 != NULL)
			f->param3 = match_param(f->param3, pat, opts, in, in_offset, in_stride, out, out_offset, out_stride);

		return n;
	}
	else if(n->type == NODE_ICODE_IDENT)
	{
		ICodeIdent *i = (ICodeIdent*)n;

		if(i->ident_type == IDENT_IN)
		{
			//if(i->ident == "$in")
			//{
				return in;
			//}
		}
		else if(i->ident_type == IDENT_OUT)
		{
			//if(i->ident == "$out")
			//{
				return out;
			//}
		}
		/*else if(i->ident_type == IDENT_VEC && i != in && i != out)
		{
			cerr << "HERE" << endl;
			int hacky_offset = 100;
			char buf[200];
			sprintf(buf, "$t%d", i->num+hacky_offset);
			i->ident = string(buf);

			return n;
		}*/

		return n;
	}
	else if(n->type == NODE_ICODE_DOT)
	{

		// identifier should be a matrix pattern variable
		ICodeDot *d = (ICodeDot*)n;
		string ident;

		Node *left = match_param(d->expr1, pat, opts, in, in_offset, in_stride, out, out_offset, out_stride);
		assert(left);

		if(left->type == NODE_CALL)
		{
			Call *c = (Call*)left;
			Node *n = *(c->seq->s.begin());
			//cout << "DOT->CALL(" << c->ident << "): " << n->type << endl;

			if(n->type == NODE_CALL)
			{
				//another call level deep
				c = (Call*)n;
				n = *(c->seq->s.begin());

				if(n->type == NODE_CALL)
				{
					c = (Call*)n;
					n = *(c->seq->s.begin());
					//FIXME: I should be recursive!!
				if(n->type == NODE_CALL)
				{
					c = (Call*)n;
					n = *(c->seq->s.begin());
					//FIXME: I should be recursive!!
				if(n->type == NODE_CALL)
				{
					c = (Call*)n;
					n = *(c->seq->s.begin());
					//FIXME: I should be recursive!!
				if(n->type == NODE_CALL)
				{
					c = (Call*)n;
					n = *(c->seq->s.begin());
					//FIXME: I should be recursive!!
				if(n->type == NODE_CALL)
				{
					c = (Call*)n;
					n = *(c->seq->s.begin());
					//FIXME: I should be recursive!!
				if(n->type == NODE_CALL)
				{
					c = (Call*)n;
					n = *(c->seq->s.begin());
					//FIXME: I should be recursive!!
				if(n->type == NODE_CALL)
				{
					c = (Call*)n;
					n = *(c->seq->s.begin());
					//FIXME: I should be recursive!!
				if(n->type == NODE_CALL)
				{
					c = (Call*)n;
					n = *(c->seq->s.begin());
					//FIXME: I should be recursive!!
				if(n->type == NODE_CALL)
				{
					c = (Call*)n;
					n = *(c->seq->s.begin());
					//FIXME: I should be recursive!!
				}
				}
				}
				}
				}
				}
				}
				}
				}
			}

			return n;
		}
		else if(left->type == NODE_ICODE_IDENT)
		{
			ICodeIdent *i = (ICodeIdent*)d->expr1;


			switch(i->ident_type)
			{
				case IDENT_IN:
					return new Integer(in_vector_size);
					break;
				default:
					cerr << "match_param: ident type not supported! " << i->ident_type << " ident: " << i->ident << endl;
					exit(1);
					break;
			};
		}

		cerr << "match_param: unmatched template parameter! " << ident << " type: " << d->expr1->type << endl;
		exit(1);
	}
	else if(n->type == NODE_ICODE_VEC_IND)
	{
		ICodeVecIndex *v = (ICodeVecIndex*) n;

		char buf[200];
		string loop_math = "";
		int count = 1;
		int last = v->index->s.size()-1;
		int ex_offset = ((Integer*)v->index->s[0])->n;

		sprintf(buf,"");

		if(v->index->s.size() == 1)
		{
			Node *n = *v->index->s.begin();

			if(n->type == NODE_INTEGER)
			{
				//int val_num = ((Integer*)n)->n;
				sprintf(buf, "$i%d", last);
				loop_math += buf;
			}
			else
			{
				cerr << "crap!" << endl;
				exit(1);
			}
		}
		else if(v->index->s.size() > 1)
		{
			Node *n = *v->index->s.begin();

			if(n->type == NODE_ICODE_IDENT)
			{
				sprintf(buf, "%s*$i%d+",((ICodeIdent*)n)->ident.c_str(), (int)(loop_stack.size()-v->index->s.size()));
			}
			else if(n->type == NODE_INTEGER)
			{
				sprintf(buf, "%d*$i%d+",((Integer*)n)->n, (int)(loop_stack.size()-v->index->s.size()));
			}
			loop_math += buf;

		// start the s[1] because the first slot is an offset
		for(vector<Node*>::iterator it = v->index->s.begin()+1; it != v->index->s.end(); it++, count++)
		{
			Node *n = *it;
			int val_num = 0;
			string val_str = "";

			//the loop index to use at this depth
			int loop_num = loop_stack.size()-v->index->s.size()+count;

			if(n->type == NODE_INTEGER)
			{
				val_num = ((Integer*)n)->n;
			}
			else if(n->type == NODE_ICODE_IDENT)
			{
				val_str = ((ICodeIdent*)n)->ident;
				cerr << "OMG! IDENT!" << endl;
			}
			else if(n->type == NODE_ICODE_PATTERN)
			{
				Node *np = match_param(n, pat, opts, in, in_offset, in_stride, out, out_offset, out_stride);

				if(np->type == NODE_INTEGER)
				{
					val_num = ((Integer*)np)->n;
				}
				else
				{
					cerr << "icode_vec_ind: icode_pattern variable didn't resolve to an integer!" << endl;
					exit(1);
				}
			}
			else
			{
				cerr << "icode_vec_ind: bad value! " << v->index->type << endl;
				exit(1);
			}

				if(count != last)
				{
					if(val_str == "" && val_num > 0)
					{
						if(val_num == 1)
						{
							sprintf(buf, "$i%d+", loop_num);
						}
						else
						{
							sprintf(buf, "%d*$i%d+", val_num, loop_num);
						}
					}
					else if(val_num == 0 && val_str != "")
					{
						sprintf(buf, "%s*$i%d+", val_str.c_str(), loop_num);
					}
					loop_math += buf;
				}
				else
				{
					if(val_str == "")
					{
						if(val_num == 1)
						{
							sprintf(buf, "$i%d", loop_num);
						}
						else
						{
							sprintf(buf, "%d*$i%d", val_num, loop_num);
						}
					}
					else if(val_num == 0 && val_str != "")
					{
						sprintf(buf, "%s*$i%d", val_str.c_str(), loop_num);
					}
					loop_math += buf;
				}
		}
		}

		sprintf(buf, "");

		int temp = 0;
		if(v->ident->ident == "$in")
		{
				//if(ex_offset == 0)
				//{
					//temp = ((Integer*)in_stride)->n; // + ((Integer*)in_offset)->n;
					temp = 0;
				//}
				//else
				//{
					temp = ex_offset * ((Integer*)in_offset)->n;
				//}
				if(temp == 0)
					sprintf(buf, "%d*%s", ((Integer*)in_stride)->n, loop_math.c_str());
				else
					sprintf(buf, "%d*%s+%d", ((Integer*)in_stride)->n, loop_math.c_str(), temp);

				cerr << "in(" << v->ident->ident << ") " << ((Integer*)in_stride)->n << " lm: " << loop_math << " tmp: " << temp << endl;
				// when returning replace with the input symbol
				return new ICodeVecIndex((ICodeIdent*)in, v->index, string(buf));
		}
		else if(v->ident->ident == "$out")
		{
				//if(((Integer*)v->index->s[0])->n == 0)
				if(ex_offset == 0)
				{
					//temp = ((Integer*)out_stride)->n; // + ((Integer*)in_offset)->n;
					temp = 0;
				}
				else
				{
					//temp = ((Integer*)out_stride)->n + ((Integer*)out_offset)->n;
					temp = ex_offset * ((Integer*)out_offset)->n;
				}
				if(temp == 0)
					sprintf(buf, "%d*%s", ((Integer*)out_stride)->n, loop_math.c_str());
				else
					sprintf(buf, "%d*%s+%d", ((Integer*)out_stride)->n, loop_math.c_str(), temp);
				cerr << "out(" << v->ident->ident << ") " << ((Integer*)out_stride)->n << " lm: " << loop_math << " tmp: " << temp << endl;
				// when returning replace with the output symbol
				return new ICodeVecIndex((ICodeIdent*)out, v->index, string(buf));
				
		}
		else
		{
			cerr << "problem! " << v->ident->ident << endl;
			exit(1);
		}
		
		return NULL;
	}
	else
	{
		return n;
	}
}

ICode *expand_icode_math(ICode *icode, Seq *pattern, Seq *opts, Node *in, Node *in_offset, Node *in_stride, Node *out, Node *out_offset, Node *out_stride)
{
	Node *p1 = NULL;
	Node *p2 = NULL;
	Node *p3 = NULL;

	if(icode->param1 != NULL)
		p1 = match_param(icode->param1, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride);

	p2 = match_param(icode->param2, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride);
	p3 = match_param(icode->param3, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride);
	return new ICode(icode->op, p1, p2, p3);
}

void Template::expand(Seq *opts, Node *in, Node *in_offset, Node *in_stride, Node *out, Node *out_offset, Node *out_stride)
{
	ICodeIdent *e_in = (ICodeIdent*)in;
	ICodeIdent *e_out = (ICodeIdent*)out;
	cerr << "Template::expand(" << ident << ") (" << e_in->ident << ", " << e_out->ident << " )" << endl;

	for(icode_iter iter = icode->sl.begin(); iter != icode->sl.end(); iter++)
	{
		ICode *icode = *iter;

		Node *e = NULL;
		Template *temp;
		ICodePattern *i_pattern;
		string tmp_str;

		ICode *i1 = NULL;
		ICode *i2 = NULL;
		Node *p1 = NULL;
		Node *p2 = NULL;
		Node *p3 = NULL;

		switch(icode->op)
		{
			case ICODE_OP_DO:

				char buf[200];
				sprintf(buf, "$i%d", (int)loop_stack.size());

				if(icode->param3->type == NODE_ICODE)
				{
					new_icode->push_back(new ICode(ICODE_OP_DO, new ICodeIdent(IDENT_INDEX, string(buf))/*icode->param1*/, icode->param2, expand_icode_math((ICode *)icode->param3, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride)));
				}
				else if(icode->param3->type == NODE_ICODE_DOT)
				{
					//cout << "ICODE_DOT(" << ident << ")" << endl;
					new_icode->push_back(new ICode(ICODE_OP_DO, new ICodeIdent(IDENT_INDEX, string(buf))/*icode->param1*/, icode->param2, match_param(icode->param3, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride)));
				}
				else
				{
					cerr << "UNHANDLED EXPANSION" << endl;
					exit(1);
				}

				loop_stack.push_back((ICodeIdent*)icode->param1);
				break;
			case ICODE_OP_END:
				loop_stack.pop_back();
				new_icode->push_back(new ICode(*icode));
				break;
			case ICODE_OP_ADD:
			case ICODE_OP_SUB:
			case ICODE_OP_MUL:
			case ICODE_OP_DIV:
				new_icode->push_back(expand_icode_math(icode, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride));
				break;
			case ICODE_OP_CALL:
				i_pattern = (ICodePattern*)icode->param1;
				e = match_param(i_pattern, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride);

				if(e == NULL)
				{
					cerr << "(" << ident << ") template parameters don't match input!" << endl;
					exit(1);
				}
				else
				{
					Call *c = (Call*)e;
					ICodeIdent *call_in = (ICodeIdent*)match_param(icode->param2, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride);
					ICodeIdent *call_out = (ICodeIdent*)match_param(icode->param5, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride);
					Node *io = match_param(icode->param3, pattern, opts, icode->param2, icode->param3, icode->param4, icode->param5, icode->param6, icode->param7);
					Node *is = match_param(icode->param4, pattern, opts, icode->param2, icode->param3, icode->param4, icode->param5, icode->param6, icode->param7);

					Node *oo = match_param(icode->param6, pattern, opts, icode->param2, icode->param3, icode->param4, icode->param5, icode->param6, icode->param7);
					Node *os = match_param(icode->param7, pattern, opts, icode->param2, icode->param3, icode->param4, icode->param5, icode->param6, icode->param7);

					cerr << "Call(" << i_pattern->i << ", " << call_in->ident << ", in_offset: " << ((Integer*)io)->n << " in_stride: " << ((Integer*)is)->n << ", " << call_out->ident << " out_offset: " << ((Integer*)oo)->n << " out_stride: " << ((Integer*)os)->n << endl;
					c->eval(call_in, io, is, call_out, oo, os);
				}
				break;
			case ICODE_OP_ASSIGN:
				p1 = match_param(icode->param1, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride);
				p2 = match_param(icode->param2, pattern, opts, in, in_offset, in_stride, out, out_offset, out_stride);
				new_icode->push_back(new ICode(ICODE_OP_ASSIGN, p1, p2));
				break;
		};
	}
}

void expand_seq(Seq *s, Vector *in, Vector *out)
{
	
}

void init_table()
{
	SymbolTable *t = SymbolTable::instance();

	//TODO: insert intrinsics here
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cerr << "Usage: ./spl <vector_size>" << endl;
		exit(1);
	}

	in_vector_size = atoi(argv[1]);

	new_icode = new list<ICode*>();
	yy::spl_parser p;

	int v = p.parse();

	cerr << "Generated " << new_icode->size() << " i-code statments." << endl;
	for(icode_iter iter = new_icode->begin(); iter != new_icode->end(); iter++)
	{
		(*iter)->print(0);
	}

	return v;
}

void StmtList::check()
{
	for(list<Node*>::iterator iter = sl.begin(); iter != sl.end(); iter++)
	{
		(*iter)->check();
	}
}

void StmtList::insert(Node *stmt)
{
	sl.push_front(stmt);
}

void StmtList::eval()
{
	ICodeIdent *in = new ICodeIdent(IDENT_IN, "$in");
	ICodeIdent *out = new ICodeIdent(IDENT_OUT, "$out");

	for(list<Node*>::iterator iter = sl.begin(); iter != sl.end(); iter++)
	{
		if((*iter)->type == NODE_CALL)
		{
			((Call*)(*iter))->eval(in, new Integer(0), new Integer(1), out, new Integer(0), new Integer(1));
		}
		else
		{
			(*iter)->eval();
		}
	}
}

List::List(Seq *seq)
{
	type = NODE_LIST;
	c = NULL;
	d = NULL;
	s = seq;
}

List::List(Comment *cmt, List *l)
{
	type = NODE_LIST;
	c = cmt;
	d = NULL;
	s = l->s;
}

List::List(Directive *dir, List *l)
{
	type = NODE_LIST;
	c = NULL;
	d = dir;
	s = l->s;
}

void List::check()
{
	if(c != NULL)
		c->check();

	if(d != NULL)
		d->check();

	s->check();
}

void Seq::check()
{
	for(vector<Node*>::iterator iter = s.begin(); iter != s.end(); iter++)
	{
		(*iter)->check();
	}
}

void Seq::insert(Node *v)
{
	s.insert(s.begin(), v);
}


void Seq::eval()
{
	for(vector<Node*>::iterator iter = s.begin(); iter != s.end(); iter++)
	{
		(*iter)->eval();
	}
}

void ICodeStmtList::insert(ICode *stmt)
{
	sl.push_front(stmt);	
}

void Call::check()
{
}

void Call::eval(){cerr << "don't call me" << endl; exit(1);}
void Call::eval(Node *in, Node *in_offset, Node *in_stride, Node *out, Node *out_offset, Node *out_stride)
{
	// Find a matching template to use
	// TODO: use match_template()
	Template *t = Template::find(ident, seq->s.size());

	if(t == NULL)
	{
		cerr << "No matching template!: " << ident << " of size: " << seq->s.size() << endl;
		exit(1);
	}
	else
	{
		t->expand(seq, in, in_offset, in_stride, out, out_offset, out_stride);
	}
}

void Define::eval()
{
}




