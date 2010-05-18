#ifndef __SYMBOL_H__
#define __SYMBOL_H__

enum SymbolType
{
	CONSTANT,
	GLOBAL
};

class Symbol
{
public:
	string name;
	Node *node;

	Symbol(string n, Node *n2)
	{
		name = n;
		node = n2;
	}
};


#endif


