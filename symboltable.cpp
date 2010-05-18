#include "symboltable.h"

SymbolTable *SymbolTable::inst = NULL;

SymbolTable *SymbolTable::instance()
{
	if(inst == NULL)
	{
		inst = new SymbolTable();
	}

	return inst;
}

Symbol *SymbolTable::find(string i)
{
	map<string,Symbol*>::iterator iter;

	iter = table.find(i);

	if(iter != table.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}

SymbolTable::SymbolTable()
{
		
}

void SymbolTable::insert(Symbol *s)
{
	table[s->name] = s;
}


