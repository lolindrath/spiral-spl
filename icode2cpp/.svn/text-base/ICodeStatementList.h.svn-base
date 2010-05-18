#ifndef ICODE_STATEMENT_LIST_H_
#define ICODE_STATEMENT_LIST_H_

#include <vector>
#include <string>
#include <ICodeStatement.h>

class ICodeStatementList: public std::vector<ICodeStatement*>
{
  
  
  public:
  
  /**
   *default constructor
   */
    ICodeStatementList(): std::vector<ICodeStatement*>()
    {
    }
 
  /**
   *copy constructor
   *@param list the statement list to be copied
   */
    ICodeStatementList(const ICodeStatementList& list)
    : std::vector<ICodeStatement*>()
    {
      for(size_t i =0; i < list.size(); i++)
      {
	push_back(static_cast<ICodeStatement*>(list[i]->clone()));
      }
    }
    
   /**
   *assignment operator
   *@param list the statement list to be copied
   *@return a reference to this
   */
   const ICodeStatementList& operator = (const ICodeStatementList& list)
   {
      clear();
      for(size_t i =0; i < list.size(); i++)
      {
	push_back(static_cast<ICodeStatement*>(list[i]->clone()));
      }
      return *this;
   }
   
   /**
    *virtual destructor deletes ICodeStatements
    */
   virtual ~ICodeStatementList()
   {
     clear();
   }
   
   /**
    *clear overload deletes ICodeStatements
    */
   void clear()
   {
     for(size_t i = 0; i < size(); i++)
     {
       delete at(i);
     }
   }
};
#endif