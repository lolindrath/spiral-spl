#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_
#include <string>
#include <map>
#include <ICodeSymbol.h>

class SymbolTable: public std::map<std::string, ICodeSymbol*>
{
  public:
    
    SymbolTable(): std::map<std::string, ICodeSymbol*>()
    {
    }
    
    SymbolTable(const SymbolTable& symbolTable): std::map<std::string, ICodeSymbol*>(symbolTable)
    {
      
    }
    
    const SymbolTable& operator = (const SymbolTable& symbolTable)
    {
      std::map<std::string, ICodeSymbol*>::operator = (symbolTable);
    }
    
    virtual ~SymbolTable()
    {
    }
    
    inline bool addSymbol(ICodeSymbol* symbol)
    {
      if(containsSymbol(symbol))
	return false;
      
     (*this)[symbol->getKey()] = symbol;
      return true;
    }
    
    
    
    inline bool containsSymbol(ICodeSymbol* symbol)
    {
      return symbol != NULL && find(symbol->getKey()) != end();
    }
    
    inline bool containsKey(const std::string& key)
    {
      return find(key) != end();
    }
 
};
#endif