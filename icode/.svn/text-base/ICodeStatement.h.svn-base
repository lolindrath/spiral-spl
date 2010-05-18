#ifndef ICODE_STATEMENT_H_
#define ICODE_STATEMENT_H_
#include <iostream>
#include <ICodeElement.h>
#include <ICodeValue.h>
#include <ICodeSymbol.h>
#include <SymbolTable.h>

/**
* @class ICodeStatement is a statement in icode
*/
class ICodeStatement: public ICodeElement
{
  public:
    
    ///enumeration of icode statements
    typedef enum ICODE_STATEMENT_TYPE
    {
      NO_STATEMENT, ///no statement
      ICODE_DECLARATION,  ///declaration
      ICODE_IDENTITY,
      ICODE_UNARY_EXPRESSION,
      ICODE_BINARY_EXPRESSION,
      ICODE_ADDITION,
      ICODE_SUBTRACTION,
      ICODE_MULTIPLICATION,
      ICODE_DIVISION,
      ICODE_DECREMENT,
      ICODE_INCREMENT,
      ICODE_DO,
      ICODE_END_DO,
      ICODE_SIZE,
      ICODE_ASSIGNMENT,
      ICODE_EVALUATE,
      ICODE_TW
      
    } STATEMENT_TYPE;
    
    /**
    * default constructor
    *@param statementType the type of the statement
    */
    ICodeStatement(const STATEMENT_TYPE& statementType):
    ICodeElement(ICODE_STATEMENT),mStatementType(statementType)
    {
    }
    
    /**
    * copy constructor
    * @param statement the statement that will have its type copied to this statement
    */
    ICodeStatement(const ICodeStatement& statement):
    ICodeElement(statement), mStatementType(statement.mStatementType)
    {
    }
    
    /**
    * assignment operator
    * @param statement the statement that will have its type copied to this statement
    * @return a reference to this statement
    */
    const ICodeStatement& operator = (const ICodeStatement& statement)
    {
      ICodeElement::operator = (statement);
      mStatementType = statement.mStatementType;
      return *this;
    }
    
    /**
    * virtual destructor does nothing
    */
    virtual ~ICodeStatement()
    {
    }
    
    /**
    *StatementType getter
    *@return the type of the ICodeStatemnt
    */
    inline STATEMENT_TYPE getStatementType() const
    {
      return mStatementType;
    }
    
    /**
    *StatementType setter
    *@param statementType the type of the ICodeStatement
    */
    inline void setStatementType(const STATEMENT_TYPE& statementType)
    {
      mStatementType = statementType;
    }
    
    /**
     * populate the symbol table
     *@param symbols the symbol table to populate
     */
    virtual void populateSymbols(SymbolTable& symbols) const = 0;
    
    /**
     * test for symbol definition
     * @param symbol the symbol to test for
     * @return true if the statement defines the arguement
     */
    virtual bool definesSymbol(const ICodeSymbol& symbol) const = 0;
    
    /**
     * test for symbol use
     * @param symbol the symbol to test for
     * @return true if the statement uses the arguement
     */
    virtual bool usesSymbol(const ICodeSymbol& symbol) const = 0;
    
    /**
     * replace a symbol
     * @param target the symbol to replace
     * @param symbol the symbol to replace target with
     */
    virtual void replaceSymbol(const ICodeSymbol& target, ICodeSymbol* symbol) = 0;
    
   /**
     * replace a symbol with a constant
     * @param target the symbol to replace
     * @param value the value to replace the symbol with
     */
    virtual void evaluateSymbol(const ICodeSymbol& target, ICodeValue* value) = 0;
    
  private:
    STATEMENT_TYPE mStatementType;
};

/**
*@class Declaration is the declaration of an ICodeSymbol
*/
class Declaration : public ICodeStatement
{
  public:
    /**
    *default constructor
    *@param symbol the symbol that is declared
    */
    Declaration(ICodeSymbol* symbol = NULL):ICodeStatement(ICODE_DECLARATION),mSymbol(symbol)
    {
      
    }
    
    /**
    *copy constructor
    *@param declaration the statement that will have its symbol cloned to this declaration
    */
    Declaration(const Declaration& declaration):ICodeStatement(declaration)
    {
      if(declaration.mSymbol != NULL)
	mSymbol = static_cast<ICodeSymbol*>(declaration.mSymbol->clone());
      else
	mSymbol = NULL;
    }
    
    /**
    *assignment operator 
    *@param declaration the statement that will have its symbol cloned to this declaration
    *@note deletes current symbol
    */
    const Declaration& operator = (const Declaration& declaration)
    {
      ICodeStatement::operator =(declaration);
      
      if(mSymbol != NULL)
	delete mSymbol;
      
      if(declaration.mSymbol != NULL)
	mSymbol =  static_cast<ICodeSymbol*>(declaration.mSymbol->clone());
      else
	mSymbol = NULL;
      
      return *this;
    }
    
    /**
    *virtual destructor deletes the Symobl
    */
    virtual ~Declaration()
    {
      if(mSymbol != NULL)
	delete mSymbol;
    }
    
    /**
    * Symbol getter
    *@return the symbol begin declared
    */
    inline ICodeSymbol* getSymbol()
    {
      return mSymbol;
    }
    
    /**
    * Symbol getter
    *@return the symbol begin declared
    */
    inline const ICodeSymbol* getSymbol() const
    {
      return mSymbol;
    }
    
    /**
    * Symbol setter
    *@param symbol the symbol begin declared
    */
    inline void setSymbol(ICodeSymbol* symbol)
    {
      if(mSymbol != NULL)
	delete mSymbol;
      
      mSymbol = symbol;
    }
    
    /**
    * icode string conversion
    * @return a string containing an icode representation of this element
    */
    inline virtual std::string toICode() const
    {
      std::stringstream buffer;
      buffer << "decl ";
      
      if(mSymbol != NULL)
	buffer << mSymbol->toICode();
      else
	buffer << "NULL symbol";
      
      return buffer.str();
    }
    
    /**
    * C code string conversion
    * @return a string containing a C code representation of this element
    */
    inline virtual std::string toCCode() const
    {
      if(mSymbol != NULL)
	return mSymbol->getCCodeDecl();
      else
	return "NULL symbol decl";
    }
    
    /**
    * cloning function
    * @return a clone of this element
    */
    inline virtual ICodeElement* clone() const
    {
      return new Declaration(*this);
    }
    
    /**
     * populate the symbol table
     *@param symbols the symbol table to populate
     */
    virtual void populateSymbols(SymbolTable& symbols) const
    {
      if(mSymbol != NULL)
	symbols.addSymbol(mSymbol);
    }
    
    /**
     * test for symbol definition
     * @param symbol the symbol to test for
     * @return true if the statement defines the arguement
     */
    virtual bool definesSymbol(const ICodeSymbol& symbol) const
    {
      return mSymbol != NULL && mSymbol->getKey() == symbol.getKey();
    }
    
    /**
     * test for symbol use
     * @param symbol the symbol to test for
     * @return true if the statement uses the arguement
     */
    virtual bool usesSymbol(const ICodeSymbol& symbol) const
    {
      return false;
    }
    
    /**
     * replace a symbol
     * @param target the symbol to replace
     * @param symbol the symbol to replace target with
     */
    virtual void replaceSymbol(const ICodeSymbol& target, ICodeSymbol* symbol)
    {
      if(definesSymbol(target))
	mSymbol = static_cast<ICodeSymbol*>(symbol->clone());
    }
    
    /**
     * replace a symbol with a constant
     * @param target the symbol to replace
     * @param value the value to replace the symbol with
     */
    virtual void evaluateSymbol(const ICodeSymbol& target, ICodeValue* value)
    {
      return;
    }
    
  private:
    ICodeSymbol* mSymbol;
};

/**
* @class Expression is an icode expresssion
*/
class Expression: public ICodeStatement
{
  public:
    /**
    * default constructor
    * @param statementType the type of the expression
    */
    Expression(const STATEMENT_TYPE& statementType):ICodeStatement(statementType)
    {
      
    }
    
    /**
    *copy constructor
    *@param expression the expression that will be copied
    */
    Expression(const Expression& expression):ICodeStatement(expression)
    {
      
    }
    
    /**
    * assignement operator
    *@param expression the expression that will be copied
    */
    inline const Expression& operator = (const Expression& expression)
    {
      ICodeStatement::operator =(expression);
      return *this;
    }
    
    /**
    * virtual destructor does nothing
    */
    virtual ~Expression()
    {
      
    }
    
    /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const = 0;
};


/**
 *@class VectorRef is a reference to a vector element
 */
class VectorRef : public ICodeSymbol
{
  
  public:
    
    /**
     *default constructor
     *@param name the name of the vector
     *@param index the index being referenced
     *@param valueType the value type of the vector being referenced
     */
    VectorRef(const std::string& name = "vector ref", Expression* index = NULL, const VALUE_TYPE& valueType = NULL_VALUE_TYPE):
    ICodeSymbol(name,ICODE_VECTOR_REF,valueType), mIndex(index)
    {
      
    }
    
    /**
     *copy constructor
     *@param ref the reference to be copied
     */
    VectorRef(const VectorRef& ref):ICodeSymbol(ref)
    {
      
      if(ref.mIndex != NULL)
	this->mIndex = static_cast<Expression*>(ref.mIndex->clone());
      else
	mIndex = NULL;
    }
    
    /**
     *assignment operator
     *@param ref the reference to be copied
     *@return a reference to this
     */
    const VectorRef& operator = (const VectorRef& ref)
    {
      if(mIndex != NULL)
	delete mIndex;
      ICodeSymbol::operator =(ref);
      
      if(ref.mIndex != NULL)
	this->mIndex = static_cast<Expression*>(ref.mIndex->clone());
      else
	mIndex = NULL;
      
      return *this;
    }
    
    /**
     *virtual destructor deletes Index
     */
    virtual ~VectorRef()
    {
      if(mIndex != NULL)
	delete mIndex;
    }
    
    /**
     *Index getter
     *@return the Index
     */
    inline const Expression* getIndex() const
    {
      return this->mIndex;
    }
    
     /**
     *Index getter
     *@return the Index
     */
    inline Expression* getIndex()
    {
      return this->mIndex;
    }
    
     /**
     *Index getter
     *@return the Index
     */
    inline void setIndex(Expression* index)
    {
      //if(mIndex != NULL)
	//delete mIndex;
      
      this->mIndex = index;
    }
    
    virtual std::string toICode() const
    {
      std::stringstream buffer;
      buffer << this->getName() <<"(" << this->mIndex->toICode() << ")";
      return buffer.str();
    }
    
    virtual std::string toCCode() const
    {
      std::stringstream buffer;
      buffer << this->getName() <<"[" << this->mIndex->toCCode() << "]";
      return buffer.str();
    }
    
    virtual ICodeSymbol* clone() const
    {
      return new VectorRef(*this);
    }
    
    virtual std::string getCCodeDecl() const
    {
      return "vector ref decl";
    }
    
     /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const
    {
      std::stringstream buffer;
      buffer << getName() << "[" << mIndex->getKey() << "]";
      
      return buffer.str();
    }
    
  private:
    Expression* mIndex;
};

/**
 *class evaluation is a value as an expression
 */
class Evaluation: public Expression
{
  public:
    /**
     *default constructor
     *@param value the value to be evaluated
     */
    Evaluation(ICodeValue* value):
    Expression(ICODE_EVALUATE), mValue(value)
    {
    }
    
    /**
     *copy constructor
     *@param id the identity to be copied
     */
    Evaluation(const Evaluation& eval)
    :Expression(eval)
    {
      if(eval.mValue != NULL)
	mValue = static_cast<ICodeValue*>(eval.mValue->clone());
      else
	mValue = NULL;
    }
    
    /**
     *assignment operator
     *@param id the identity to be copied
     *@return a reference to this
     */
    const Evaluation& operator = (const Evaluation& eval)
   
    {
      if(mValue != NULL)
	delete mValue;
      
      Expression::operator = (eval);
      if(eval.mValue != NULL)
	mValue = static_cast<ICodeValue*>(eval.mValue->clone());
      else
	mValue = NULL;
      
      return *this;
    }
    
    /**
     *virtual destructor deletes value
     */
    virtual ~Evaluation()
    {
      if(mValue != NULL)
	delete mValue;
    }
    
    /**
     *Symobl getter
     *@return the Value to be evaluated
     */
    inline ICodeValue* getValue()
    {
      return mValue;
    }
    
     /**
     *Symobl getter
     *@return the Value to be evaluated
     */
    inline const ICodeValue* getValue() const
    {
      return mValue;
    }
    
     /**
     *Symobl setter
     *@param value the Value to be evaluated
     */
    inline void setValue(ICodeValue* value)
    {
      if(mValue != NULL)
	delete mValue;
      
      mValue = value;
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    inline virtual std::string toICode() const
    {
      if(mValue != NULL)
	return mValue->toICode();
      else
	return "Null evaluation";
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    inline virtual std::string toCCode() const
    {
      if(mValue != NULL)
	return mValue->toCCode();
      else
	return "Null evaluation";
    }
    
    /**
     * cloning function
     * @return a clone of this element
     */
    inline virtual ICodeElement* clone() const
    {
      return new Evaluation(*this);
    }
    
    /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const
    {
      if(mValue != NULL)
	switch(mValue->getValueType())
	{
	  case ICodeValue::ICODE_INTEGER: return static_cast<const Integer*>(mValue)->toString();
	  case ICodeValue::ICODE_REAL: return static_cast<const Real*>(mValue)->toString();
	  case ICodeValue::ICODE_COMPLEX: return static_cast<const Complex*>(mValue)->toString();
	  default: return "null key";
	}
     
    }
    
    /**
     * populate the symbol table
     *@param symbols the symbol table to populate
     */
    virtual void populateSymbols(SymbolTable& symbols) const
    {
      return;
    }
    
    /**
     * test for symbol definition
     * @param symbol the symbol to test for
     * @return true if the statement defines the arguement
     */
    virtual bool definesSymbol(const ICodeSymbol& symbol) const
    {
      return false;
    }
    
    /**
     * test for symbol use
     * @param symbol the symbol to test for
     * @return true if the statement uses the arguement
     */
    virtual bool usesSymbol(const ICodeSymbol& symbol) const
    {
      return false;
    }
    
    /**
     * replace a symbol
     * @param target the symbol to replace
     * @param symbol the symbol to replace target with
     */
    virtual void replaceSymbol(const ICodeSymbol& target, ICodeSymbol* symbol)
    {
      return;
    }
    
    /**
     * replace a symbol with a constant
     * @param target the symbol to replace
     * @param value the value to replace the symbol with
     */
    virtual void evaluateSymbol(const ICodeSymbol& target, ICodeValue* value)
    {
      return;
    }
    
  private:
    ICodeValue* mValue;
};

/**
 *class identity is a symbol as an expression
 */
class Identity: public Expression
{
  public:
    /**
     *default constructor
     *@param symbol the symbol to be evaluated
     */
    Identity(ICodeSymbol* symbol):
    Expression(ICODE_IDENTITY), mSymbol(symbol)
    {
    }
    
    /**
     *copy constructor
     *@param id the identity to be copied
     */
    Identity(const Identity& id)
    :Expression(id)
    {
      if(id.mSymbol != NULL)
	mSymbol = static_cast<ICodeSymbol*>(id.mSymbol->clone());
      else
	mSymbol = NULL;
    }
    
    /**
     *assignment operator
     *@param id the identity to be copied
     *@return a reference to this
     */
    const Identity& operator = (const Identity& id)
    {
      if(mSymbol != NULL)
	delete mSymbol;
      
      Expression::operator=(id);
      if(id.mSymbol != NULL)
	mSymbol = static_cast<ICodeSymbol*>(id.mSymbol->clone());
      else
	mSymbol = NULL;
      
      return *this;
    }
    
    /**
     *virtual destructor deletes symbol
     */
    virtual ~Identity()
    {
      if(mSymbol != NULL)
	delete mSymbol;
    }
    
    /**
     *Symobl getter
     *@return the Symbol to be evaluated
     */
    inline ICodeSymbol* getSymbol()
    {
      return mSymbol;
    }
    
     /**
     *Symobl getter
     *@return the Symbol to be evaluated
     */
    inline const ICodeSymbol* getSymbol() const
    {
      return mSymbol;
    }
    
     /**
     *Symobl setter
     *@param symbol the Symbol to be evaluated
     */
    inline void setSymbol(ICodeSymbol* symbol)
    {
      if(mSymbol != NULL)
	delete mSymbol;
      
      mSymbol = symbol;
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    inline virtual std::string toICode() const
    {
      if(mSymbol != NULL)
	return mSymbol->toICode();
      else
	return "Null identity";
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    inline virtual std::string toCCode() const
    {
      if(mSymbol != NULL)
	return mSymbol->toCCode();
      else
	return "Null identity";
    }
    
    /**
     * cloning function
     * @return a clone of this element
     */
    inline virtual ICodeElement* clone() const
    {
      return new Identity(*this);
    }
    
    /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const
    {
      if(mSymbol != NULL)
	return mSymbol->getKey();
      else
	return "null key";
    }
    
    /**
     * populate the symbol table
     *@param symbols the symbol table to populate
     */
    virtual void populateSymbols(SymbolTable& symbols) const
    {
      if(mSymbol != NULL)
      {
	if(mSymbol->getSymbolType() == ICodeSymbol::ICODE_VECTOR_REF &&
	  !symbols.containsKey(mSymbol->getName()))
	{
      
	  Vector* vector = new Vector(mSymbol->getName(), 0, mSymbol->getValueType());
	  symbols.addSymbol(vector);
	}
	
	symbols.addSymbol(mSymbol);
      }
    }
    
    /**
     * test for symbol definition
     * @param symbol the symbol to test for
     * @return true if the statement defines the arguement
     */
    virtual bool definesSymbol(const ICodeSymbol& symbol) const
    {
      return false;
    }
    
    /**
     * test for symbol use
     * @param symbol the symbol to test for
     * @return true if the statement uses the arguement
     */
    virtual bool usesSymbol(const ICodeSymbol& symbol) const
    {
      if(mSymbol != NULL && mSymbol->getKey() == symbol.getKey())
	return true;
      else if(mSymbol != NULL && symbol.getSymbolType() == ICodeSymbol::ICODE_VECTOR && mSymbol->getName() == symbol.getName())
	return true;
      else if(mSymbol != NULL && mSymbol->getSymbolType() == ICodeSymbol::ICODE_VECTOR_REF)
      {
	VectorRef* ref = static_cast<VectorRef*>(mSymbol);
	return ref->getIndex() != NULL && ref->getIndex()->usesSymbol(symbol);
      }
      else
	return false;
    }
    
    /**
     * replace a symbol
     * @param target the symbol to replace
     * @param symbol the symbol to replace target with
     */
    virtual void replaceSymbol(const ICodeSymbol& target, ICodeSymbol* symbol)
    {
      if(mSymbol != NULL && mSymbol->getKey() == target.getKey())
	mSymbol = static_cast<ICodeSymbol*>(symbol->clone());
      else if(mSymbol != NULL && mSymbol->getSymbolType() == ICodeSymbol::ICODE_VECTOR_REF)
      {
	
	VectorRef* ref = static_cast<VectorRef*>(mSymbol);
	if(ref->getIndex() != NULL)
	{
	  //std::cout << "calling replace on " << ref->getIndex()->toCCode() << " with " << symbol->toCCode() << std::endl;
	  ref->getIndex()->replaceSymbol(target,symbol);
	}
      }
    }
    
    /**
     * replace a symbol with a constant
     * @param target the symbol to replace
     * @param value the value to replace the symbol with
     */
    virtual void evaluateSymbol(const ICodeSymbol& target, ICodeValue* value)
    {
      
      if(mSymbol != NULL && mSymbol->getSymbolType() == ICodeSymbol::ICODE_VECTOR_REF)
      {
	
	VectorRef* ref = static_cast<VectorRef*>(mSymbol);
	if(ref->getIndex() != NULL && ref->getIndex()->getStatementType() == ICodeStatement::ICODE_IDENTITY)
	{
	  //std::cout << "found ident vector ref" << std::endl;
	  Identity* ident = static_cast<Identity*>(ref->getIndex());
	  if(ident->getSymbol()->getKey() == target.getKey())
	  {
	   // std::cout << "found vector ref replace" << std::endl;
	    ref->setIndex(new Evaluation(static_cast<ICodeValue*>(value->clone())));
	  }
	}
	else if(ref->getIndex() != NULL)
	{
	  ref->getIndex()->evaluateSymbol(target,value);
	}
      }
    }
  private:
    ICodeSymbol* mSymbol;
};


/**
* class UnaryOperation is an icode operation of one value
*/
class UnaryOperation: public Expression
{
  public:
    
    /**
    *default constructor
    *@param operand the operand of the expression
    *@param statementType the type of the expression
    */
    UnaryOperation(Expression* operand, const STATEMENT_TYPE& statementType):
    Expression(statementType), mOperand(operand)
    {
      
    }
    
    /**
    * copy constructor
    * @param expression the expression that will be copied
    */
    UnaryOperation(const UnaryOperation& expression):
    Expression(expression)
    {
      if(expression.mOperand != NULL)
	mOperand = static_cast<Expression*>(expression.mOperand->clone());
      else
	mOperand = NULL;
    }
    
    /**
    *assignment operator
    *@param expression the expression that will be copied
    *@return a reference to this 
    */
    inline const UnaryOperation& operator = (const UnaryOperation& expression)
    {
      if(mOperand != NULL)
	delete mOperand;
      Expression::operator =(expression);
      
      if(expression.mOperand != NULL)
	mOperand = static_cast<Expression*>(expression.mOperand->clone());
      else
	mOperand = NULL;
      
      return *this;
    }
    
    /**
    * virtual destructor delete the Operand
    */
    virtual ~UnaryOperation()
    {
      if(mOperand != NULL)
	delete mOperand;
    }
    
    /**
    *Operand getter
    *@return the operand to this expression
    */
    inline Expression* getOperand()
    {
      return this->mOperand;
    }
    
    /**
    *Operand getter
    *@return the operand to this expression
    */
    inline const Expression* getOperand() const
    {
      return this->mOperand;
    }
    
    /**
    *Operand setter
    *@param operand the operand to this expression
    */
    inline void setOperand(Expression* operand)
    {
     // if(this->mOperand != NULL)
	//delete this->mOperand;
      
      this->mOperand = operand;
    }
    
    /**
     * populate the symbol table
     *@param symbols the symbol table to populate
     */
    virtual void populateSymbols(SymbolTable& symbols) const
    {
      if(mOperand != NULL)
	mOperand->populateSymbols(symbols);
    }
    
    /**
     * test for symbol definition
     * @param symbol the symbol to test for
     * @return true if the statement defines the arguement
     */
    virtual bool definesSymbol(const ICodeSymbol& symbol) const
    {
      return mOperand != NULL && mOperand->definesSymbol(symbol);
    }
    
    /**
     * test for symbol use
     * @param symbol the symbol to test for
     * @return true if the statement uses the arguement
     */
    virtual bool usesSymbol(const ICodeSymbol& symbol) const
    {
      return mOperand != NULL && mOperand->usesSymbol(symbol);
    }
    
    /**
     * replace a symbol
     * @param target the symbol to replace
     * @param symbol the symbol to replace target with
     */
    virtual void replaceSymbol(const ICodeSymbol& target, ICodeSymbol* symbol)
    {
      if(mOperand != NULL)
	mOperand->replaceSymbol(target,symbol);
    }
    
    /**
     * replace a symbol with a constant
     * @param target the symbol to replace
     * @param value the value to replace the symbol with
     */
    virtual void evaluateSymbol(const ICodeSymbol& target, ICodeValue* value)
    {
      if(mOperand != NULL && mOperand->getStatementType() == ICodeStatement::ICODE_IDENTITY)
      {
	Identity* ident = static_cast<Identity*>(mOperand);
	if(ident->getSymbol() != NULL)
	  if(ident->getSymbol()->getKey() == target.getKey())
	    mOperand = new Evaluation(static_cast<ICodeValue*>(value->clone()));
	  else
	    ident->evaluateSymbol(target,value);
      }
      else if(mOperand != NULL)
      {
	mOperand->evaluateSymbol(target,value);
      }
    }
  private:
    Expression* mOperand;
    
};

/**
*@class BinrayOperation is an operation on two exprssions
*/
class BinaryOperation: public Expression
{
  public:
    /**
    *default constructor
    *@param operand1 the first operand
    *@param operand2 the second operand
    *@param statementType the type of the operation
    */
    BinaryOperation(Expression* operand1, Expression* operand2, const STATEMENT_TYPE& statementType):
    Expression(statementType), mOperand1(operand1), mOperand2(operand2)
    {
      
    }
    
    /**
    * copy constructor
    * @param expression the expression that will be copied
    */
    BinaryOperation(const BinaryOperation& expression):
    Expression(expression)
    {
      if(expression.mOperand1 != NULL)
	mOperand1 = static_cast<Expression*>(expression.mOperand1->clone());
      else
	mOperand1 = NULL;
      
      if(expression.mOperand2 != NULL)
	mOperand2 = static_cast<Expression*>(expression.mOperand2->clone());
      else
	mOperand2 = NULL;
    }
    
    /**assignment operator
    * @param expression the expression that will be copied
    * @return a reference to this
    */
    const BinaryOperation& operator = (const BinaryOperation& expression)
    {
      if(mOperand1 != NULL)
	delete mOperand1;
      if(mOperand2 != NULL)
	delete mOperand2;
      
     if(expression.mOperand1 != NULL)
	mOperand1 = static_cast<Expression*>(expression.mOperand1->clone());
      else
	mOperand1 = NULL;
      
      if(expression.mOperand2 != NULL)
	mOperand2 = static_cast<Expression*>(expression.mOperand2->clone());
      else
	mOperand2 = NULL;
      
      return *this;
    }
    
    /**
    * virtual destructor deletes operands
    */
    virtual ~BinaryOperation()
    {
      if(mOperand1 != NULL)
	delete mOperand1;
      if(mOperand2 != NULL)
	delete mOperand2;
    }
    
    /**
    *Operand1 getter
    *@return the first operand of this expression
    */
    inline Expression* getOperand1()
    {
      return this->mOperand1;
    }
    
    /**
    *Operand1 getter
    *@return the first operand of this expression
    */
    inline const Expression* getOperand1() const
    {
      return this->mOperand1;
    }
    
    /**
    *Operand1 setter
    *@param operand1 the first operand of this expression
    */
    inline void setOperand1(Expression* operand1)
    {
     // if(this->mOperand1 != NULL)
	//delete mOperand1;
      this->mOperand1 = operand1;
    }
    
    /**
    *Operand2 getter
    *@return the first operand of this expression
    */
    inline Expression* getOperand2()
    {
      return this->mOperand2;
    }
    
    /**
    *Operand2 getter
    *@return the first operand of this expression
    */
    inline Expression* getOperand2() const
    {
      return this->mOperand2;
    }
    
    /**
    *Operand2 setter
    *@return the first operand of this expression
    */
    void setOperand2(Expression* operand)
    {
    // if(this->mOperand2 != NULL)
	//delete mOperand2;
      this->mOperand2 = operand;
    }
    
    /**
     * populate the symbol table
     *@param symbols the symbol table to populate
     */
    virtual void populateSymbols(SymbolTable& symbols) const
    {
      if(mOperand1 != NULL)
	mOperand1->populateSymbols(symbols);
      
      if(mOperand2 != NULL)
	mOperand2->populateSymbols(symbols);
    }
    
    /**
     * test for symbol definition
     * @param symbol the symbol to test for
     * @return true if the statement defines the arguement
     */
    virtual bool definesSymbol(const ICodeSymbol& symbol) const
    {
      return (mOperand1 != NULL && mOperand1->definesSymbol(symbol)) ||
      (mOperand2 != NULL && mOperand2->definesSymbol(symbol));
    }
    
    /**
     * test for symbol use
     * @param symbol the symbol to test for
     * @return true if the statement uses the arguement
     */
    virtual bool usesSymbol(const ICodeSymbol& symbol) const
    {
      return (mOperand1 != NULL && mOperand1->usesSymbol(symbol)) ||
      (mOperand2 != NULL && mOperand2->usesSymbol(symbol));
    }
    
    /**
     * replace a symbol
     * @param target the symbol to replace
     * @param symbol the symbol to replace target with
     */
    virtual void replaceSymbol(const ICodeSymbol& target, ICodeSymbol* symbol)
    {
      if(mOperand1 != NULL)
	mOperand1->replaceSymbol(target,symbol);
      if(mOperand2 != NULL)
	mOperand2->replaceSymbol(target,symbol);
    }
    
     /**
     * replace a symbol with a constant
     * @param target the symbol to replace
     * @param value the value to replace the symbol with
     */
    virtual void evaluateSymbol(const ICodeSymbol& target, ICodeValue* value)
    {
      if(mOperand1 != NULL && mOperand1->getStatementType() == ICodeStatement::ICODE_IDENTITY)
      {
	Identity* ident = static_cast<Identity*>(mOperand1);
	if(ident->getSymbol() != NULL)
	  if(ident->getSymbol()->getKey() == target.getKey())
	    mOperand1 = new Evaluation(static_cast<ICodeValue*>(value->clone()));
	  else
	    ident->evaluateSymbol(target,value);
      }
      else if(mOperand1 != NULL)
      {
	mOperand1->evaluateSymbol(target,value);
      }

      if(mOperand2 != NULL && mOperand2->getStatementType() == ICodeStatement::ICODE_IDENTITY)
      {
	Identity* ident = static_cast<Identity*>(mOperand2);
	if(ident->getSymbol() != NULL)
	  if(ident->getSymbol()->getKey() == target.getKey())
	    mOperand2 = new Evaluation(static_cast<ICodeValue*>(value->clone()));
	  else
	    ident->evaluateSymbol(target,value);
      }
      
      else if(mOperand2 != NULL)
      {
	mOperand2->evaluateSymbol(target,value);
      }
    }
  private:
    Expression* mOperand1;
    Expression* mOperand2;
};

/**
* @class Decrement is the decrement operation
*/
class Decrement: public UnaryOperation
{
  public:
    /**
    *default constructor
    *@param operand the element to be decremented
    */
    Decrement(Expression* operand):UnaryOperation(operand,ICODE_DECREMENT)
    {
      
    }
    
    /**
    *copy constructor
    *@param decrement the decrement to be copied
    */
    Decrement(const Decrement& decrement):UnaryOperation(decrement)
    {
      
    }
    /**
    *assignment operator
    *@param decrement the decrement to be copied
    *@return a reference to this
    */
    const Decrement& operator = (const Decrement& decrement)
    {
      UnaryOperation::operator =(decrement);
      return *this;
    }
    
    /**
    *virtual destructor does nothing
    */
    virtual ~Decrement()
    {
      
    }
    
    /**
    * icode string conversion
    * @return a string containing an icode representation of this element
    */
    inline virtual std::string toICode() const
    {
      std::stringstream buffer;
      buffer << "-- ";
      
      if(getOperand() != NULL)
	buffer << getOperand()->toICode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * C code string conversion
    * @return a string containing a C code representation of this element
    */
    inline virtual std::string toCCode() const
    {
      std::stringstream buffer;
      buffer << "-- ";
      
      if(getOperand() != NULL)
	buffer << getOperand()->toCCode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * cloning function
    * @return a clone of this element
    */
    inline virtual ICodeElement* clone() const
    {
      return new Decrement(*this);
    }
    
    /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const
    {
      if(getOperand() != NULL)
      {
	std::stringstream buffer;
	buffer << "--" << getOperand()->getKey();
	return buffer.str();
      }
      else
	return "null key";
    }
};


/**
* @class Increment is the increment operation
*/
class Increment: public UnaryOperation
{
  public:
    /**
    *default constructor
    *@param operand the element to be decremented
    */
    Increment(Expression* operand):UnaryOperation(operand,ICODE_INCREMENT)
    {
      
    }
    
    /**
    *copy constructor
    *@param increment the increment to be copied
    */
    Increment(const Increment& increment):UnaryOperation(increment)
    {
      
    }
    /**
    *assignment operator
    *@param increment the increment to be copied
    *@return a reference to this
    */
    const Increment& operator = (const Increment& increment)
    {
      UnaryOperation::operator =(increment);
      return *this;
    }
    
    /**
    *virtual destructor does nothing
    */
    virtual ~Increment()
    {
      
    }
    
    /**
    * icode string conversion
    * @return a string containing an icode representation of this element
    */
    inline virtual std::string toICode() const
    {
      std::stringstream buffer;
      buffer << "++ ";
      
      if(getOperand() != NULL)
	buffer << getOperand()->toICode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * C code string conversion
    * @return a string containing a C code representation of this element
    */
    inline virtual std::string toCCode() const
    {
      std::stringstream buffer;
      buffer << "++ ";
      
      if(getOperand() != NULL)
	buffer << getOperand()->toCCode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * cloning function
    * @return a clone of this element
    */
    inline virtual Expression* clone() const
    {
      return new Increment(*this);
    }
    
    /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const
    {
      if(getOperand() != NULL)
      {
	std::stringstream buffer;
	buffer << "++" << getOperand()->getKey();
	return buffer.str();
      }
      else
	return "null key";
    }
};

/**
*@class Addition is icode addition
*/
class Addition: public BinaryOperation
{
  public:
    
    /**
    *default constructor
    *@param operand1 the first operand
    *@param operand2 the second operand
    */
    Addition(Expression* operand1, Expression* operand2):
    BinaryOperation(operand1,operand2,ICODE_ADDITION)
    {
      
    }
    
    /**
    *copy constructor
    *@param operantion the operation to copy
    */
    Addition(const Addition& operation):
    BinaryOperation(operation)
    {
      
    }
    
    /**
    *assignment operator
    *@param operantion the operation to copy
    *@return a reference to this
    */
    const Addition& operator = (const Addition& operation)
    {
      BinaryOperation::operator =(operation);
      return *this;
    }
    
    /**
    *virtual destructor does nothing
    */
    virtual ~Addition()
    {
      
    }
    
    /**
    * icode string conversion
    * @return a string containing an icode representation of this element
    */
    inline virtual std::string toICode() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->toICode();
      else
	buffer << "NULL element";
      
      buffer << " + ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->toICode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * C code string conversion
    * @return a string containing a C code representation of this element
    */
    inline virtual std::string toCCode() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->toCCode();
      else
	buffer << "NULL element";
      
      buffer << " + ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->toCCode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * cloning function
    * @return a clone of this element
    */
    inline virtual ICodeElement* clone() const
    {
      return new Addition(*this);
    }
    
    /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->getKey();
      else
	buffer << "null key";
      
      buffer << " + ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->getKey();
      else
	buffer << "null key";
      
      return buffer.str();
    }
};

/**
*@class Subtraction is icode subtraction
*/
class Subtraction: public BinaryOperation
{
  public:
    
    /**
    *default constructor
    *@param operand1 the first operand
    *@param operand2 the second operand
    */
    Subtraction(Expression* operand1, Expression* operand2):
    BinaryOperation(operand1,operand2,ICODE_SUBTRACTION)
    {
      
    }
    
    /**
    *copy constructor
    *@param operantion the operation to copy
    */
    Subtraction(const Subtraction& operation):
    BinaryOperation(operation)
    {
      
    }
    
    /**
    *assignment operator
    *@param operantion the operation to copy
    *@return a reference to this
    */
    const Subtraction operator = (const Subtraction& operation)
    {
      BinaryOperation::operator =(operation);
      return *this;
    }
    
    /**
    *virtual destructor does nothing
    */
    virtual ~Subtraction()
    {
      
    }
    
    /**
    * icode string conversion
    * @return a string containing an icode representation of this element
    */
    inline virtual std::string toICode() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->toICode();
      else
	buffer << "NULL element";
      
      buffer << " - ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->toICode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * C code string conversion
    * @return a string containing a C code representation of this element
    */
    inline virtual std::string toCCode() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->toCCode();
      else
	buffer << "NULL element";
      
      buffer << " - ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->toCCode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * cloning function
    * @return a clone of this element
    */
    inline virtual ICodeElement* clone() const
    {
      return new Subtraction(*this);
    }
    
     /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->getKey();
      else
	buffer << "null key";
      
      buffer << " - ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->getKey();
      else
	buffer << "null key";
      
      return buffer.str();
    }
};

/**
*@class Mutliplication is icode multiplication
*/
class Multiplication: public BinaryOperation
{
  public:
    
    /**
    *default constructor
    *@param operand1 the first operand
    *@param operand2 the second operand
    */
    Multiplication(Expression* operand1, Expression* operand2):
    BinaryOperation(operand1,operand2,ICODE_MULTIPLICATION)
    {
      
    }
    
    /**
    *copy constructor
    *@param operantion the operation to copy
    */
    Multiplication(const Addition& operation):
    BinaryOperation(operation)
    {
      
    }
    
    /**
    *assignment operator
    *@param operantion the operation to copy
    *@return a reference to this
    */
    const Multiplication& operator = (const Multiplication& operation)
    {
      BinaryOperation::operator =(operation);
      return *this;
    }
    
    /**
    *virtual destructor does nothing
    */
    virtual ~Multiplication()
    {
      
    }
    
    /**
    * icode string conversion
    * @return a string containing an icode representation of this element
    */
    inline virtual std::string toICode() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->toICode();
      else
	buffer << "NULL element";
      
      buffer << " * ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->toICode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * C code string conversion
    * @return a string containing a C code representation of this element
    */
    inline virtual std::string toCCode() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->toCCode();
      else
	buffer << "NULL element";
      
      buffer << " * ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->toCCode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * cloning function
    * @return a clone of this element
    */
    inline virtual ICodeElement* clone() const
    {
      return new Multiplication(*this);
    }
    
     /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->getKey();
      else
	buffer << "null key";
      
      buffer << " * ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->getKey();
      else
	buffer << "null key";
      
      return buffer.str();
    }
};

/**
*@class Division is icode division
*/
class Division: public BinaryOperation
{
  public:
    
    /**
    *default constructor
    *@param operand1 the first operand
    *@param operand2 the second operand
    */
    Division(Expression* operand1, Expression* operand2):
    BinaryOperation(operand1,operand2,ICODE_DIVISION)
    {
      
    }
    
    /**
    *copy constructor
    *@param operantion the operation to copy
    */
    Division(const Division& operation):
    BinaryOperation(operation)
    {
      
    }
    
    /**
    *assignment operator
    *@param operantion the operation to copy
    *@return a reference to this
    */
    const Division& operator = (const Division& operation)
    {
      BinaryOperation::operator =(operation);
      return *this;
    }
    
    /**
    *virtual destructor does nothing
    */
    virtual ~Division()
    {
      
    }
    
    /**
    * icode string conversion
    * @return a string containing an icode representation of this element
    */
    inline virtual std::string toICode() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->toICode();
      else
	buffer << "NULL element";
      
      buffer << " / ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->toICode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * C code string conversion
    * @return a string containing a C code representation of this element
    */
    inline virtual std::string toCCode() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->toCCode();
      else
	buffer << "NULL element";
      
      buffer << " / ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->toCCode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * cloning function
    * @return a clone of this element
    */
    inline virtual ICodeElement* clone() const
    {
      return new Division(*this);
    }
    
     /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const
    {
      std::stringstream buffer;
      
      if(getOperand1() != NULL)
	buffer << getOperand1()->getKey();
      else
	buffer << "null key";
      
      buffer << " / ";
      
      if(getOperand2() != NULL)
	buffer << getOperand2()->getKey();
      else
	buffer << "null key";
      
      return buffer.str();
    }
};

/**
 * @class Assignment is icode assignement
 */
class Assignment: public ICodeStatement
{
  public:
    
    /**
     *default constructor
     *@param target the target of the assignement
     *@param expression the expression to assign
     */
    Assignment(Identity* target, Expression* expression):
    ICodeStatement(ICODE_ASSIGNMENT),mTarget(target),mExpression(expression)
    {
      
    }
    
    /**
     *copy constructor
     *@param expression the assignement that will be copied
     */
    Assignment(const Assignment& expression):
    ICodeStatement(expression)
    {
   
      
      if(expression.mTarget != NULL)
	mTarget = static_cast<Identity*> (expression.mTarget->clone());
      else
	mTarget = NULL;
      
      if(expression.mExpression != NULL)
	mExpression = static_cast<Expression*> (expression.mExpression->clone());
      else
	mExpression = NULL;
    }
    
     /**
     *assignment operator
     *@param expression the assignement that will be copied
     *@return a reference to this
     */
    const Assignment& operator = (const Assignment& expression)
    {
      ICodeStatement::operator =(expression);
      
      if(mTarget != NULL)
	delete mTarget;
      
      if(mExpression != NULL)
	delete mExpression;
      
      if(expression.mTarget != NULL)
	mTarget = static_cast<Identity*> (expression.mTarget->clone());
      else
	mTarget = NULL;
      
      if(mExpression != NULL)
	mExpression = static_cast<Expression*> (expression.mExpression->clone());
      else
	mExpression = NULL;
      
      return *this;
    }
    
    /**
     *virtual destructor deletes the target and expression
     */
    virtual ~Assignment()
    {
      
      if(mTarget != NULL)
	delete mTarget;
      if(mExpression != NULL)
	delete mExpression;
    }
    
    /**
     *Target getter
     *@return the Target of the assignment
     */
    inline Identity* getTarget()
    {
      return this->mTarget;
    }
    
     /**
     *Target getter
     *@return the Target of the assignment
     */
    inline const Identity* getTarget() const
    {
      return this->mTarget;
    }
    
     /**
     *Expression getter
     *@return the Expression to be assigned
     */
    Expression* getExpression()
    {
      return this->mExpression;
    }
    
    /**
     *Expression getter
     *@return the Expression to be assigned
     */
    const Expression* getExpression() const
    {
      return this->mExpression;
    }
    
    /**
     *Target setter
     *@param target the target to be assigned
     */
    void setTarget(Identity* target)
    {
      if(this->mTarget != NULL)
	delete mTarget;
      this->mTarget = target;
    }
     /**
     *Expression setter
     *@param expression the expression to be assigned
     */
    void setExpression(Expression* expression)
    {
      if(this->mExpression != NULL)
	delete mExpression;
      this->mExpression = expression;
    }
    
     /**
    * icode string conversion
    * @return a string containing an icode representation of this element
    */
    inline virtual std::string toICode() const
    {
      std::stringstream buffer;
      
      if(mTarget != NULL)
	buffer << mTarget->toICode();
      else
	buffer << "NULL target";
      
      buffer << " = ";
      
      if(mExpression != NULL)
	buffer << mExpression->toICode();
      else
	buffer << "NULL element";
      
      return buffer.str();
    }
    
    /**
    * C code string conversion
    * @return a string containing a C code representation of this element
    */
    inline virtual std::string toCCode() const
    {
      std::stringstream buffer;
      
      if(mTarget != NULL)
	buffer << mTarget->toCCode();
      else
	buffer << "NULL target";
      
      buffer << " = ";
      
      if(mExpression != NULL)
	buffer << mExpression->toCCode();
      else
	buffer << "NULL Expression";
      
      return buffer.str();
    
    }
    
    /**
    * cloning function
    * @return a clone of this element
    */
    inline virtual ICodeElement* clone() const
    {
      return new Assignment(*this);
    }
    
    /**
     * populate the symbol table
     *@param symbols the symbol table to populate
     */
    virtual void populateSymbols(SymbolTable& symbols) const
    {
      if(mTarget != NULL)
	mTarget->populateSymbols(symbols);
      
      if(mExpression != NULL)
	mExpression->populateSymbols(symbols);
    }
    
      /**
     * test for symbol definition
     * @param symbol the symbol to test for
     * @return true if the statement defines the arguement
     */
    virtual bool definesSymbol(const ICodeSymbol& symbol) const
    {
      return mTarget != NULL && mTarget->getSymbol() != NULL && mTarget->getSymbol()->getKey() == symbol.getKey();
    }
    
    /**
     * test for symbol use
     * @param symbol the symbol to test for
     * @return true if the statement uses the arguement
     */
    virtual bool usesSymbol(const ICodeSymbol& symbol) const
    {
      if(mExpression != NULL && mExpression->usesSymbol(symbol))
	return true;
      else if(mTarget != NULL && mTarget->usesSymbol(symbol))
	return true;
      else
	return false;
    }
    
    /**
     * replace a symbol
     * @param target the symbol to replace
     * @param symbol the symbol to replace target with
     */
    virtual void replaceSymbol(const ICodeSymbol& target, ICodeSymbol* symbol)
    {
      if(mExpression != NULL)
	
	mExpression->replaceSymbol(target,symbol);
      
      if(mTarget != NULL)
	mTarget->replaceSymbol(target,symbol);
    }
    
    /**
     * replace a symbol with a constant
     * @param target the symbol to replace
     * @param value the value to replace the symbol with
     */
    virtual void evaluateSymbol(const ICodeSymbol& target, ICodeValue* value)
    {
      if(mExpression != NULL && mExpression->getStatementType() == ICodeStatement::ICODE_IDENTITY)
      {
	Identity* ident = static_cast<Identity*>(mExpression);
	if(ident->getSymbol() != NULL)
	  if(ident->getSymbol()->getKey() == target.getKey())
	    mExpression = new Evaluation(static_cast<ICodeValue*>(value->clone()));
	  else
	    ident->evaluateSymbol(target,value);
      }
      else if(mExpression != NULL)
      {
	mExpression->evaluateSymbol(target,value);
      }
      
      if(mTarget != NULL)
	mTarget->evaluateSymbol(target,value);
    }
  private:
    Identity* mTarget;
    Expression* mExpression;
};

/**
 *@class Do represents an icode loop construct
 */
class Do: public ICodeStatement
{
  public:
    /**
     *default constructor
     *@param index the index of the loopo
     *@param begin the initializer of index
     *@param end the termination condition
     */
    Do(Identity* index, Expression* begin, Expression* terminate):
    ICodeStatement(ICODE_DO),
    mIndex(index), mBegin(begin), mTerminate(terminate)
    {
      
    }
    
    /**
     *copy constructor
     *@param statement the do statement to be copied
     */
    Do(const Do& statement)
    :ICodeStatement(statement)
    {
      if(statement.mIndex != NULL)
	 mIndex = static_cast<Identity*>(statement.mIndex->clone());
      else
	mIndex = NULL;
      
      if(statement.mBegin!= NULL)
	 mBegin = static_cast<Expression*>(statement.mBegin->clone());
      else
	mBegin = NULL;
      
      if(statement.mTerminate != NULL)
	mTerminate = static_cast<Expression*>(statement.mTerminate->clone());
      else
	mTerminate = NULL;
    }
    
    /**
     *copy constructor
     *@param statement the do statement to be copied
     *@return a reference to this
     */
    const Do& operator = (const Do& statement)
    {
      if(this->mIndex != NULL)
	delete this->mIndex;
      if(this->mBegin != NULL)
	delete this->mBegin;
      if(this->mTerminate != NULL)
	delete this->mTerminate;
      
      ICodeStatement::operator =(statement);
      
        if(statement.mIndex != NULL)
	 mIndex = static_cast<Identity*>(statement.mIndex->clone());
      else
	mIndex = NULL;
      
      if(statement.mBegin!= NULL)
	 mBegin = static_cast<Expression*>(statement.mBegin->clone());
      else
	mBegin = NULL;
      
      if(statement.mTerminate != NULL)
	mTerminate = static_cast<Expression*>(statement.mTerminate->clone());
      else
	mTerminate = NULL;
      
      return *this;
    }
    
    /**
     *virtual destructor deletes Index, Begin, and Terminate
     */
    virtual ~Do()
    {
      if(this->mIndex != NULL)
	delete this->mIndex;
      if(this->mBegin != NULL)
	delete this->mBegin;
      if(this->mTerminate != NULL)
	delete this->mTerminate;
    }
    
    /**
     *Index getter
     *@return the Index of the loop
     */
    inline Identity* getIndex()
    {
      return this->mIndex;
    }
    
    /**
     *Index getter
     *@return the Index of the loop
     */
    inline const Identity* getIndex() const
    {
      return this->mIndex;
    }
    
    /**
     *Begin getter
     *@return the Begin initializer of the loop
     */
    inline Expression* getBegin()
    {
      return this->mBegin;
    }
    
    /**
     *Begin getter
     *@return the Begin initializer of the loop
     */
    inline const Expression* getBegin() const
    {
      return this->mBegin;
    }
    
    /**
     *Terminate getter
     *@return the Terminate condition of the loop
     */
    inline Expression* getTerminate()
    {
      return this->mTerminate;
    }
    
    /**
     *Terminate getter
     *@return the Terminate condition of the loop
     */
    inline const Expression* getTerminate() const
    {
      return this->mTerminate;
    }
    
    /**
     *Index setter
     *@param index the Index of the loop
     */
    inline void setIndex(Identity* index)
    {
      if(this->mIndex != NULL)
	delete this->mIndex;
      this->mIndex = index;
    }
    
    /**
     *Begin setter
     *@param expression the Begin initializer of the loop
     */
    inline void setBegin(Expression* expression)
    {
      if(this->mBegin != NULL)
	delete this->mBegin;
      this->mBegin = expression;
    }
    
    /**
     *Terminate getter
     *@return the Terminate condition of the loop
     */
    inline void setTerminate(Expression* expression)
    {
      if(this->mTerminate != NULL)
	delete this->mTerminate;
      this->mTerminate = expression;
    } 
   
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    inline virtual std::string toICode() const
    {
      std::stringstream buffer;
      buffer << "do ";
      
      if(mIndex != NULL)
	buffer << mIndex->toICode();
      else
	buffer << "null index";
      
      buffer <<" = ";
      
      if(mBegin != NULL)
	buffer << mBegin->toICode();
      else
	buffer << "null begin";
      
      buffer <<" , ";
      
      if(mTerminate != NULL)
	buffer << mTerminate->toICode();
      else
	buffer << "null terminate";
      
      return buffer.str();
      
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    inline virtual std::string toCCode() const
    {
       std::stringstream buffer;
      buffer << "for( ";
      
      if(mIndex != NULL)
	buffer << mIndex->toCCode();
      else
	buffer << "null index";
      
      buffer <<" = ";
      
      if(mBegin != NULL)
	buffer << mBegin->toCCode();
      else
	buffer << "null begin";
      
      buffer <<" ; ";
      
       if(mIndex != NULL)
	buffer << mIndex->getSymbol()->getName();
      else
	buffer << "null index";
      
      buffer << " < ";
      
      if(mTerminate != NULL)
	buffer << mTerminate->toCCode();
      else
	buffer << "null terminate";
      
      buffer << "; ";
      
      if(mIndex != NULL)
	buffer << mIndex->toCCode();
      else
	buffer << "null index";
      
      buffer << "++ ) {";
      
      return buffer.str();
    }
    /**
     * cloning function
     * @return a clone of this element
     */
    inline virtual ICodeElement* clone() const
    {
      return new Do(*this);
    }
    
    /**
     * populate the symbol table
     *@param symbols the symbol table to populate
     */
    inline virtual void populateSymbols(SymbolTable& symbols) const
    {
      if(mIndex != NULL);
	mIndex->populateSymbols(symbols);
      
      if(mBegin != NULL);
	mBegin->populateSymbols(symbols);
      
      if(mTerminate != NULL)
	mTerminate->populateSymbols(symbols);
    }
    
      /**
     * test for symbol definition
     * @param symbol the symbol to test for
     * @return true if the statement defines the arguement
     */
    virtual bool definesSymbol(const ICodeSymbol& symbol) const
    {
      return mIndex != NULL && mIndex->getSymbol() != NULL && mIndex->getSymbol()->getKey() == symbol.getKey();
    }
    
    /**
     * test for symbol use
     * @param symbol the symbol to test for
     * @return true if the statement uses the arguement
     */
    virtual bool usesSymbol(const ICodeSymbol& symbol) const
    {
      return (mBegin != NULL && mBegin->usesSymbol(symbol)) ||
      (mTerminate != NULL && mTerminate->usesSymbol(symbol));
    }
    
    /**
     * replace a symbol
     * @param target the symbol to replace
     * @param symbol the symbol to replace target with
     */
    virtual void replaceSymbol(const ICodeSymbol& target, ICodeSymbol* symbol)
    {
      if(mBegin != NULL)
	mBegin->replaceSymbol(target,symbol);
      if(mTerminate != NULL)
	mTerminate->replaceSymbol(target,symbol);
    }
    
    /**
     * replace a symbol with a constant
     * @param target the symbol to replace
     * @param value the value to replace the symbol with
     */
    virtual void evaluateSymbol(const ICodeSymbol& target, ICodeValue* value)
    {
      if(mBegin != NULL && mBegin->getStatementType() == ICodeStatement::ICODE_IDENTITY)
      {
	Identity* ident = static_cast<Identity*>(mBegin);
	 if(ident->getSymbol()->getKey() == target.getKey())
	    mBegin = new Evaluation(static_cast<ICodeValue*>(value->clone()));
	  else
	    ident->evaluateSymbol(target,value);
      }
      else if(mBegin != NULL)
      {
	mBegin->evaluateSymbol(target,value);
      }

      if(mTerminate != NULL && mTerminate->getStatementType() == ICodeStatement::ICODE_IDENTITY)
      {
	Identity* ident = static_cast<Identity*>(mTerminate);
	 if(ident->getSymbol()->getKey() == target.getKey())
	    mTerminate =new Evaluation(static_cast<ICodeValue*>(value->clone()));
	  else
	    ident->evaluateSymbol(target,value);
      }
      
      else if(mTerminate!= NULL)
      {
	mTerminate->evaluateSymbol(target,value);
      }
      
    }
  private:
    Identity* mIndex;
    Expression* mBegin;
    Expression* mTerminate;
    
};

/**
 *@class EndDo is a loop termination statement
 */
class EndDo: public ICodeStatement
{
  public:
    /**
     *default constructor
     */
    EndDo():ICodeStatement(ICODE_END_DO)
    {
      
    }
    
    /**
     *copy constructor
     *@param endDo the end statement to be copied
     */
    EndDo(const EndDo& endDo):ICodeStatement(endDo)
    {
      
    }
    
    /**
     *assignment operator
     *@param endDo the end statement to be copied
     *@return a reference to this
     */
    inline const EndDo& operator = (const EndDo& endDo)
    {
      ICodeStatement::operator =(endDo);
      return *this;
    }
    
    /**
     *virtual destructor does nothing
     */
    virtual ~EndDo()
    {
      
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    inline virtual std::string toICode() const
    {
      return "end";
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    inline virtual std::string toCCode() const
    {
      return "}";
    }
    
    /**
     * cloning function
     * @return a clone of this element
     */
    inline virtual ICodeElement* clone() const
    {
      return new EndDo(*this);
    }
    
    
    /**
     * populate the symbol table
     *@param symbols the symbol table to populate
     */
    virtual void populateSymbols(SymbolTable& symbols) const
    {
      return;
    }
    
      /**
     * test for symbol definition
     * @param symbol the symbol to test for
     * @return true if the statement defines the arguement
     */
    virtual bool definesSymbol(const ICodeSymbol& symbol) const
    {
      return false;
    }
    
    /**
     * test for symbol use
     * @param symbol the symbol to test for
     * @return true if the statement uses the arguement
     */
    virtual bool usesSymbol(const ICodeSymbol& symbol) const
    {
      return false;
    }
    
    /**
     * replace a symbol
     * @param target the symbol to replace
     * @param symbol the symbol to replace target with
     */
    virtual void replaceSymbol(const ICodeSymbol& target, ICodeSymbol* symbol)
    {
      return;
    }
    
    /**
     * replace a symbol with a constant
     * @param target the symbol to replace
     * @param value the value to replace the symbol with
     */
    virtual void evaluateSymbol(const ICodeSymbol& target, ICodeValue* value)
    {
      return;
    }
};

class TW: public Expression
{
  public:
    TW(Expression* m, Expression* n, Expression* k):
    Expression(ICODE_TW),mM(m),mN(n),mK(k)
    {
    }
    TW(const TW& tw):Expression(tw)
    {
      if(tw.mM != NULL)
	mM = static_cast<Expression*> (tw.mM->clone());
      if(tw.mN != NULL)
	mN = static_cast<Expression*> (tw.mN->clone());
      if(tw.mK != NULL)
	mK = static_cast<Expression*> (tw.mK->clone());
    }
    
    const TW& operator = (const TW& tw)
    {
      if(mM != NULL)
	delete mM;
      if(mN != NULL)
	delete mN;
      if(mK != NULL)
	delete mK;
      
      if(tw.mM != NULL)
	mM = static_cast<Expression*> (tw.mM->clone());
      if(tw.mN != NULL)
	mN = static_cast<Expression*> (tw.mN->clone());
      if(tw.mK != NULL)
	mK = static_cast<Expression*> (tw.mK->clone());
      
      return *this;
    }
    
    virtual ~TW()
    {
      if(mM != NULL)
	delete mM;
      if(mN != NULL)
	delete mN;
      if(mK != NULL)
	delete mK;
    }


    /**
     * populate the symbol table
     *@param symbols the symbol table to populate
     */
    virtual void populateSymbols(SymbolTable& symbols) const
    {
       if(mM != NULL)
	mM->populateSymbols(symbols);
      if(mN != NULL)
	mN->populateSymbols(symbols);
      if(mK != NULL)
	mK->populateSymbols(symbols);
    }
    
    ICodeElement* clone() const
    {
      return new TW(*this);
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    virtual std::string toICode() const
    {
      std::stringstream buffer;
      buffer << "W( ";
       if(mM != NULL)
	buffer << mM->toICode(); 
       else
	 buffer << "NULL M";
       
       buffer << " , ";
      if(mN != NULL)
	buffer << mN->toICode();
       else
	 buffer << "NULL N";
      buffer << " , ";
      if(mK != NULL)
	buffer << mK->toICode();
       else
	 buffer << "NULL K";
      buffer << ")";
      return buffer.str();
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    virtual std::string toCCode() const
    {
       std::stringstream buffer;
      buffer << "W( ";
       if(mM != NULL)
	buffer << mM->toCCode(); 
       else
	 buffer << "NULL M";
       
       buffer << " , ";
      if(mN != NULL)
	buffer << mN->toCCode();
       else
	 buffer << "NULL N";
	buffer << " , ";
      if(mK != NULL)
	buffer << mK->toCCode();
       else
	 buffer << "NULL K";
      buffer << ")";
      return buffer.str();
    }
     /**
     * Key getter
     * @return a hash key for the expression
     */
    virtual std::string getKey() const
    { std::stringstream buffer;
      buffer << "W( ";
       if(mM != NULL)
	buffer << mM->getKey(); 
       else
	 buffer << "null key";
       
       buffer << " , ";
      if(mN != NULL)
	buffer << mN->getKey();
       else
	 buffer << "null key";
	buffer << " , ";
      if(mK != NULL)
	buffer << mK->getKey();
       else
	 buffer << "null key";
      buffer << ")";
      return buffer.str();
    }
    
      /**
     * test for symbol definition
     * @param symbol the symbol to test for
     * @return true if the statement defines the arguement
     */
    virtual bool definesSymbol(const ICodeSymbol& symbol) const
    {
      return false;
    }
    
    /**
     * test for symbol use
     * @param symbol the symbol to test for
     * @return true if the statement uses the arguement
     */
    virtual bool usesSymbol(const ICodeSymbol& symbol) const
    {
      return (mM != NULL && mM->usesSymbol(symbol)) ||
      (mN != NULL && mN->usesSymbol(symbol)) ||
      (mK != NULL && mK->usesSymbol(symbol));
    }
    
    /**
     * replace a symbol
     * @param target the symbol to replace
     * @param symbol the symbol to replace target with
     */
    virtual void replaceSymbol(const ICodeSymbol& target, ICodeSymbol* symbol)
    {
      if(mM != NULL)
	mM->replaceSymbol(target,symbol);
      if(mN != NULL)
	mN->replaceSymbol(target,symbol);
      if(mK != NULL)
	mK->replaceSymbol(target,symbol);
    }
    
    /**
     * replace a symbol with a constant
     * @param target the symbol to replace
     * @param value the value to replace the symbol with
     */
    virtual void evaluateSymbol(const ICodeSymbol& target, ICodeValue* value)
    {
      if(mM != NULL && mM->getStatementType() == ICodeStatement::ICODE_IDENTITY)
      {
	Identity* ident = static_cast<Identity*>(mM);
	 if(ident->getSymbol()->getKey() == target.getKey())
	    mM = new Evaluation(static_cast<ICodeValue*>(value->clone()));
	  else
	    ident->evaluateSymbol(target,value);
      }
      else if(mM != NULL)
      {
	mM->evaluateSymbol(target,value);
      }

      if(mN != NULL && mN->getStatementType() == ICodeStatement::ICODE_IDENTITY)
      {
	Identity* ident = static_cast<Identity*>(mN);
	 if(ident->getSymbol()->getKey() == target.getKey())
	    mN =new Evaluation(static_cast<ICodeValue*>(value->clone()));
	  else
	    ident->evaluateSymbol(target,value);
      }
      
      else if(mN!= NULL)
      {
	mN->evaluateSymbol(target,value);
      }
      
      if(mK != NULL && mK->getStatementType() == ICodeStatement::ICODE_IDENTITY)
      {
	Identity* ident = static_cast<Identity*>(mK);
	 if(ident->getSymbol()->getKey() == target.getKey())
	    mK = new Evaluation(static_cast<ICodeValue*>(value->clone()));
	  else
	    ident->evaluateSymbol(target,value);
      }
      
      else if(mK!= NULL)
      {
	mK->evaluateSymbol(target,value);
      }
    }
  private:
    Expression* mM;
    Expression* mN;
    Expression* mK;
};

#endif
