#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H_

#include <map>
#include <string>
#include "spl.h"
#include "symbol.h"

using namespace std;

class SymbolTable
{
public:
	static SymbolTable *instance();
	void insert(Symbol *s);
	Symbol *find(string i);

protected:
	SymbolTable();

private:
	static SymbolTable *inst;
	map<string, Symbol*> table;
};

#endif




