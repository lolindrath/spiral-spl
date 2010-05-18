#ifndef ICODE_OPTIMIZATION_H_
#define ICODE_OPTIMIZATION_H_
#include <iostream>
#include <ICodeProgram.h>

class ICodeOptimization
{
  public :
    ICodeOptimization()
    {
    }
    
    ICodeOptimization(const ICodeOptimization& optimization)
    {
    }
    
    const ICodeOptimization& operator = (const ICodeOptimization& optimization)
    {
      return *this;
    }
    
    virtual ~ICodeOptimization()
    {
    }
    
    virtual void operator()(ICodeProgram& program) = 0;
};

class ICodeSSA: public ICodeOptimization
{
  public :
    ICodeSSA(): ICodeOptimization()
    {
    }
    
    ICodeSSA(const ICodeSSA& ssa):ICodeOptimization(ssa)
    {
    }
    
    const ICodeSSA& operator = (const ICodeSSA& ssa)
    {
      ICodeOptimization::operator = (ssa);
      return *this;
    }
    
    virtual ~ICodeSSA()
    {
    }
    
    inline virtual void operator()(ICodeProgram& program)
    {
      for(size_t i = 0; i < program.getStatements().size(); i++)
      {

	if(program.getStatements()[i]->getStatementType() == ICodeStatement::ICODE_ASSIGNMENT)
	  ssaHelper(program,i,(static_cast<Assignment*>(program.getStatements()[i]))->getExpression());
      }
      program.populateSymbols();
    }
  private:
    inline void ssaHelper(ICodeProgram& program, const size_t& pos, Expression* expression)
    {
      if(expression->getStatementType() == ICodeStatement::ICODE_DECREMENT || 
	expression->getStatementType() == ICodeStatement::ICODE_INCREMENT)
      {
	UnaryOperation* unary = static_cast<UnaryOperation*>(expression);
	if(unary->getOperand()->getStatementType() != ICodeStatement::ICODE_EVALUATE && unary->getOperand()->getStatementType() != ICodeStatement::ICODE_IDENTITY)
	{
	  ssaHelper(program,pos,unary->getOperand());
	
	  Identity* identity = new Identity(new Scalar(program.getNextTemp()));
	  Assignment* assignment = new Assignment(identity,unary->getOperand());
	  unary->setOperand(static_cast<Identity*>(identity->clone()));
	  program.getStatements().insert(program.getStatements().begin() + pos,assignment);
	  
	}
      }
      
      else if(expression->getStatementType() == ICodeStatement::ICODE_ADDITION || 
	expression->getStatementType() == ICodeStatement::ICODE_SUBTRACTION ||
	expression->getStatementType() == ICodeStatement::ICODE_MULTIPLICATION ||
	expression->getStatementType() == ICodeStatement::ICODE_DIVISION)
      {
	BinaryOperation* binary = static_cast<BinaryOperation*>(expression);
	if(binary->getOperand1()->getStatementType() != ICodeStatement::ICODE_EVALUATE && binary->getOperand1()->getStatementType() != ICodeStatement::ICODE_IDENTITY)
	{
	  ssaHelper(program,pos,binary->getOperand1());
	
	  Identity* identity = new Identity(new Scalar(program.getNextTemp()));
	  Assignment* assignment = new Assignment(identity,binary->getOperand1());
	  binary->setOperand1(static_cast<Identity*>(identity->clone()));
	  program.getStatements().insert(program.getStatements().begin() + pos,assignment);
	  
	}
	if(binary->getOperand2()->getStatementType() != ICodeStatement::ICODE_EVALUATE && binary->getOperand2()->getStatementType() != ICodeStatement::ICODE_IDENTITY)
	{
	  ssaHelper(program,pos,binary->getOperand2());
	
	  Identity* identity = new Identity(new Scalar(program.getNextTemp()));
	  Assignment* assignment = new Assignment(identity,binary->getOperand2());
	  binary->setOperand2(static_cast<Identity*>(identity->clone()));
	  program.getStatements().insert(program.getStatements().begin() + pos,assignment);
	  
	}
	
      }
    }
};

class ICodeConstantFolding: public ICodeOptimization
{
  public :
    ICodeConstantFolding(): ICodeOptimization()
    {
    }
    
    ICodeConstantFolding(const ICodeConstantFolding& fold):ICodeOptimization(fold)
    {
    }
    
    const ICodeConstantFolding& operator = (const ICodeConstantFolding fold)
    {
      ICodeOptimization::operator = (fold);
      return *this;
    }
    
    virtual ~ICodeConstantFolding()
    {
    }
    
    inline virtual void operator()(ICodeProgram& program)
    {
      for(ICodeStatementList::iterator it = program.getStatements().begin(); it != program.getStatements().end(); it++)
	if((*it)->getStatementType() == ICodeStatement::ICODE_ASSIGNMENT)
	{
	 Expression* expression = (static_cast<Assignment*>(*it))->getExpression();
	 if(expression->getStatementType() == ICodeStatement::ICODE_ADDITION || 
	  expression->getStatementType() == ICodeStatement::ICODE_SUBTRACTION ||
	  expression->getStatementType() == ICodeStatement::ICODE_MULTIPLICATION ||
	  expression->getStatementType() == ICodeStatement::ICODE_DIVISION)
	{
	  BinaryOperation* binary = static_cast<BinaryOperation*>(expression);
	  if(binary->getOperand1()->getStatementType() == ICodeStatement::ICODE_EVALUATE &&
	    binary->getOperand2()->getStatementType() == ICodeStatement::ICODE_EVALUATE)
	  {
	    ICodeValue* lhs = static_cast<Evaluation*>(binary->getOperand1())->getValue();
	    ICodeValue* rhs = static_cast<Evaluation*>(binary->getOperand2())->getValue();
	    Evaluation* evaluation = NULL;
	    if(binary->getStatementType() == ICodeStatement::ICODE_ADDITION)
	      evaluation =  new Evaluation(addition(lhs,rhs));
	    else if(binary->getStatementType() == ICodeStatement::ICODE_SUBTRACTION)
	       evaluation =  new Evaluation(subtraction(lhs,rhs));
	    else if(binary->getStatementType() == ICodeStatement::ICODE_MULTIPLICATION)
	       evaluation =  new Evaluation(multiplication(lhs,rhs));
	    else if(binary->getStatementType() == ICodeStatement::ICODE_DIVISION)
	       evaluation =  new Evaluation(division(lhs,rhs));
	    if(evaluation)
	      static_cast<Assignment*>(*it)->setExpression(evaluation);
	  }
	 
	}
	}
      program.populateSymbols();
    }
    
    ICodeValue* addition(ICodeValue* lhs, ICodeValue* rhs)
    {
      if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX || rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
      {
	std::cerr << "attempt to perform an operation on NULL value" << std::endl;
	return new Null();
      }
      else if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX || rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
      {
	std::complex<double> lhs_val, rhs_val;
	if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX)
	  lhs_val = static_cast<Complex*>(lhs)->getValue();
	else if(lhs->getValueType() == ICodeValue::ICODE_REAL)
	  lhs_val = std::complex<double>(static_cast<Real*>(lhs)->getValue(),0);
	else if(lhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  lhs_val = std::complex<double>(static_cast<Integer*>(lhs)->getValue(),0);
	
	if(rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
	  rhs_val = static_cast<Complex*>(rhs)->getValue();
	else if(rhs->getValueType() == ICodeValue::ICODE_REAL)
	  rhs_val = std::complex<double>(static_cast<Real*>(rhs)->getValue(),0);
	else if(rhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  rhs_val = std::complex<double>(static_cast<Integer*>(rhs)->getValue(),0);
	
	return new Complex(lhs_val + rhs_val);
      }
      else if(lhs->getValueType() == ICodeValue::ICODE_REAL|| rhs->getValueType() == ICodeValue::ICODE_REAL)
      {
	double lhs_val, rhs_val;
	if(lhs->getValueType() == ICodeValue::ICODE_REAL)
	  lhs_val = static_cast<Real*>(lhs)->getValue();
	else if(lhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  lhs_val = (double)static_cast<Integer*>(lhs)->getValue();
	
	if(rhs->getValueType() == ICodeValue::ICODE_REAL)
	  rhs_val = static_cast<Real*>(rhs)->getValue();
	else if(rhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  rhs_val = (double)static_cast<Integer*>(rhs)->getValue();
	
	return new Real(lhs_val + rhs_val);
      }
      else
      {
	int lhs_val, rhs_val;
	lhs_val = static_cast<Integer*>(lhs)->getValue();
	rhs_val = static_cast<Integer*>(rhs)->getValue();
	return new Real(lhs_val + rhs_val);
      }
    }
    
    ICodeValue* multiplication(ICodeValue* lhs, ICodeValue* rhs)
    {
      if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX || rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
      {
	std::cerr << "attempt to perform an operation on NULL value" << std::endl;
	return new Null();
      }
      else if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX || rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
      {
	std::complex<double> lhs_val, rhs_val;
	if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX)
	  lhs_val = static_cast<Complex*>(lhs)->getValue();
	else if(lhs->getValueType() == ICodeValue::ICODE_REAL)
	  lhs_val = std::complex<double>(static_cast<Real*>(lhs)->getValue(),0);
	else if(lhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  lhs_val = std::complex<double>(static_cast<Integer*>(lhs)->getValue(),0);
	
	if(rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
	  rhs_val = static_cast<Complex*>(rhs)->getValue();
	else if(rhs->getValueType() == ICodeValue::ICODE_REAL)
	  rhs_val = std::complex<double>(static_cast<Real*>(rhs)->getValue(),0);
	else if(rhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  rhs_val = std::complex<double>(static_cast<Integer*>(rhs)->getValue(),0);
	
	return new Complex(lhs_val * rhs_val);
      }
      else if(lhs->getValueType() == ICodeValue::ICODE_REAL|| rhs->getValueType() == ICodeValue::ICODE_REAL)
      {
	double lhs_val, rhs_val;
	if(lhs->getValueType() == ICodeValue::ICODE_REAL)
	  lhs_val = static_cast<Real*>(lhs)->getValue();
	else if(lhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  lhs_val = (double)static_cast<Integer*>(lhs)->getValue();
	
	if(rhs->getValueType() == ICodeValue::ICODE_REAL)
	  rhs_val = static_cast<Real*>(rhs)->getValue();
	else if(rhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  rhs_val = (double)static_cast<Integer*>(rhs)->getValue();
	
	return new Real(lhs_val * rhs_val);
      }
      else
      {
	int lhs_val, rhs_val;
	lhs_val = static_cast<Integer*>(lhs)->getValue();
	rhs_val = static_cast<Integer*>(rhs)->getValue();
	return new Real(lhs_val * rhs_val);
      }
    }
    
    ICodeValue* subtraction(ICodeValue* lhs, ICodeValue* rhs)
    {
      if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX || rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
      {
	std::cerr << "attempt to perform an operation on NULL value" << std::endl;
	return new Null();
      }
      else if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX || rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
      {
	std::complex<double> lhs_val, rhs_val;
	if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX)
	  lhs_val = static_cast<Complex*>(lhs)->getValue();
	else if(lhs->getValueType() == ICodeValue::ICODE_REAL)
	  lhs_val = std::complex<double>(static_cast<Real*>(lhs)->getValue(),0);
	else if(lhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  lhs_val = std::complex<double>(static_cast<Integer*>(lhs)->getValue(),0);
	
	if(rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
	  rhs_val = static_cast<Complex*>(rhs)->getValue();
	else if(rhs->getValueType() == ICodeValue::ICODE_REAL)
	  rhs_val = std::complex<double>(static_cast<Real*>(rhs)->getValue(),0);
	else if(rhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  rhs_val = std::complex<double>(static_cast<Integer*>(rhs)->getValue(),0);
	
	return new Complex(lhs_val - rhs_val);
      }
      else if(lhs->getValueType() == ICodeValue::ICODE_REAL|| rhs->getValueType() == ICodeValue::ICODE_REAL)
      {
	double lhs_val, rhs_val;
	if(lhs->getValueType() == ICodeValue::ICODE_REAL)
	  lhs_val = static_cast<Real*>(lhs)->getValue();
	else if(lhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  lhs_val = (double)static_cast<Integer*>(lhs)->getValue();
	
	if(rhs->getValueType() == ICodeValue::ICODE_REAL)
	  rhs_val = static_cast<Real*>(rhs)->getValue();
	else if(rhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  rhs_val = (double)static_cast<Integer*>(rhs)->getValue();
	
	return new Real(lhs_val - rhs_val);
      }
      else
      {
	int lhs_val, rhs_val;
	lhs_val = static_cast<Integer*>(lhs)->getValue();
	rhs_val = static_cast<Integer*>(rhs)->getValue();
	return new Real(lhs_val - rhs_val);
      }
    }
    
    ICodeValue* division(ICodeValue* lhs, ICodeValue* rhs)
    {
      if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX || rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
      {
	std::cerr << "attempt to perform an operation on NULL value" << std::endl;
	return new Null();
      }
      else if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX || rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
      {
	std::complex<double> lhs_val, rhs_val;
	if(lhs->getValueType() == ICodeValue::ICODE_COMPLEX)
	  lhs_val = static_cast<Complex*>(lhs)->getValue();
	else if(lhs->getValueType() == ICodeValue::ICODE_REAL)
	  lhs_val = std::complex<double>(static_cast<Real*>(lhs)->getValue(),0);
	else if(lhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  lhs_val = std::complex<double>(static_cast<Integer*>(lhs)->getValue(),0);
	
	if(rhs->getValueType() == ICodeValue::ICODE_COMPLEX)
	  rhs_val = static_cast<Complex*>(rhs)->getValue();
	else if(rhs->getValueType() == ICodeValue::ICODE_REAL)
	  rhs_val = std::complex<double>(static_cast<Real*>(rhs)->getValue(),0);
	else if(rhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  rhs_val = std::complex<double>(static_cast<Integer*>(rhs)->getValue(),0);
	
	return new Complex(lhs_val / rhs_val);
      }
      else if(lhs->getValueType() == ICodeValue::ICODE_REAL|| rhs->getValueType() == ICodeValue::ICODE_REAL)
      {
	double lhs_val, rhs_val;
	if(lhs->getValueType() == ICodeValue::ICODE_REAL)
	  lhs_val = static_cast<Real*>(lhs)->getValue();
	else if(lhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  lhs_val = (double)static_cast<Integer*>(lhs)->getValue();
	
	if(rhs->getValueType() == ICodeValue::ICODE_REAL)
	  rhs_val = static_cast<Real*>(rhs)->getValue();
	else if(rhs->getValueType() == ICodeValue::ICODE_INTEGER)
	  rhs_val = (double)static_cast<Integer*>(rhs)->getValue();
	
	return new Real(lhs_val / rhs_val);
      }
      else
      {
	int lhs_val, rhs_val;
	lhs_val = static_cast<Integer*>(lhs)->getValue();
	rhs_val = static_cast<Integer*>(rhs)->getValue();
	return new Real(lhs_val / rhs_val);
      }
    } 
};

class ICodeCopyPropegation: public ICodeOptimization
{
  public :
    ICodeCopyPropegation(): ICodeOptimization()
    {
    }
    
    ICodeCopyPropegation(const ICodeCopyPropegation& prop):ICodeOptimization(prop)
    {
    }
    
    const ICodeCopyPropegation& operator = (const ICodeCopyPropegation& prop)
    {
      ICodeOptimization::operator = (prop);
      return *this;
    }
    
    virtual ~ICodeCopyPropegation()
    {
    }
    
    inline virtual void operator()(ICodeProgram& program)
    {
      for(size_t i = 0; i < program.getStatements().size(); i++)
      {
	if(program.getStatements()[i]->getStatementType() == ICodeStatement::ICODE_ASSIGNMENT)
	{
	  Assignment* assignment = static_cast<Assignment*>(program.getStatements()[i]);
	  if(assignment->getExpression()->getStatementType() == ICodeStatement::ICODE_IDENTITY)
	  {
	   
	    Identity* identity = static_cast<Identity*>(assignment->getExpression());
	    ICodeSymbol* symbol = identity->getSymbol();
	    ICodeSymbol* target = assignment->getTarget()->getSymbol();
	    size_t j = i+1;
	    bool defFound = false;
	    while(j < program.getStatements().size() && !defFound)
	    {
	      if(!program.getStatements()[j]->definesSymbol(*target) &&
		program.getStatements()[j]->usesSymbol(*target))
	      {
		std::cerr << "replacing " << target->toCCode() << " with " << symbol->toCCode() << " in statement " << program.getStatements()[j]->toCCode() << std::endl; 
		program.getStatements()[j]->replaceSymbol(*target,symbol);
	      }
	      
	      if(program.getStatements()[j]->definesSymbol(*target))
		defFound = true;
	      ++j;
	    }
	    program.getStatements().erase(program.getStatements().begin() +i);
	    i--;
	  }
	  else if(assignment->getExpression()->getStatementType() == ICodeStatement::ICODE_EVALUATE)
	  {
	   
	    Evaluation* evaluation = static_cast<Evaluation*>(assignment->getExpression());
	    ICodeValue* value = evaluation->getValue();
	    ICodeSymbol* target = assignment->getTarget()->getSymbol();
	    size_t j = i+1;
	    bool defFound = false;
	    while(j < program.getStatements().size() && !defFound)
	    {
	      if(!program.getStatements()[j]->definesSymbol(*target) &&
		program.getStatements()[j]->usesSymbol(*target))
	      {
		std::cerr << "replacing " << target->toCCode() << " with " << value->toCCode() << " in statement " << program.getStatements()[j]->toCCode() << std::endl; 
		program.getStatements()[j]->evaluateSymbol(*target,value);
	      }
	      
	      if(program.getStatements()[j]->definesSymbol(*target))
		defFound = true;
	      ++j;
	    }
	    program.getStatements().erase(program.getStatements().begin() +i);
	    i--;
	  }
	}
      }
      
      for(SymbolTable::iterator it = program.getSymbols().begin(); it != program.getSymbols().end(); it++)
      {
	bool symbolUsed = false;
	for(size_t i = 0; i < program.getStatements().size(); i++)
	  if(program.getStatements()[i]->usesSymbol(*it->second))
	    symbolUsed = true;
	  
	 if(!symbolUsed)
	   program.getSymbols().erase(it);
      }
    }
};

#endif