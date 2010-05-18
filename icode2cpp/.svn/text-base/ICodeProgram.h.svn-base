#ifndef ICODE_PROGRAM_H_
#define ICODE_PROGRAM_H_
#include <ICodeStatementList.h>
#include <SymbolTable.h>
class ICodeProgram
{
  public:
    ICodeProgram():mNextTemp(0)
    {
    }
    
    ICodeProgram(const ICodeProgram& program):
    mStatements(program.mStatements),
    mNextTemp(0)
    {
      populateSymbols();
    }
    
    const ICodeProgram& operator = (const ICodeProgram& program)
    {
      mStatements = program.mStatements;
      mNextTemp = 0;
      populateSymbols();
      
    }
    
    void populateSymbols()
    {
      mSymbols.clear();
      for(size_t i =0; i < mStatements.size(); i++)
	mStatements[i]->populateSymbols(mSymbols);
      for(SymbolTable::iterator it = mSymbols.begin(); it != mSymbols.end(); it++)
      {
	 if(it->second->getValueType() == ICodeValue::NULL_VALUE_TYPE)
	   it->second->setValueType(ICodeValue::ICODE_COMPLEX);
      }
    }
    
    const SymbolTable& getSymbols() const
    {
      return mSymbols;
    }
    
    SymbolTable & getSymbols()
    {
      return mSymbols;
    }
    
    const ICodeStatementList& getStatements() const
    {
      return mStatements;
    }
    
    ICodeStatementList& getStatements()
    {
      return mStatements;
    }
    
    void setSymbols(const SymbolTable& symbols)
    {
      mSymbols = symbols;
    }
    
    void setStatements(const ICodeStatementList& statements)
    {
      mStatements = statements;
      populateSymbols();
    }
    
     void printICode(std::ostream& out)
   {
     for(size_t i = 0; i < mStatements.size(); i++)
       out << mStatements[i]->toICode() << std::endl;
   }
   
   void printCCode(std::ostream& out)
   {
     std::string indent = "\t";
     
     printProgramHeader(out);
     for(SymbolTable::iterator it = mSymbols.begin(); it != mSymbols.end(); it++)
       if(it->second->getSymbolType() != ICodeSymbol::ICODE_VECTOR_REF && it->second != NULL)
       out << (it->second->getCCodeDecl()) << ";" << std::endl;
     
     for(size_t i = 0; i < mStatements.size(); i++)
     {
       if(mStatements[i]->getStatementType() == ICodeStatement::ICODE_DO)
       {
	
	out << indent << mStatements[i]->toCCode() << std::endl;
	indent += "\t";
       }
       else if(mStatements[i]->getStatementType() == ICodeStatement::ICODE_END_DO)
       {
	indent.erase(indent.find_last_of("\t"));
	out << indent << mStatements[i]->toCCode() << std::endl; 
       }
       else
       {
	out << indent << mStatements[i]->toCCode() <<";" << std::endl; 
       }
	 
     }
     printProgramTail(out);
     
   }
   
   void setVectorSize(const size_t& size)
   {
      for(SymbolTable::iterator it = mSymbols.begin(); it != mSymbols.end(); it++)
       if(it->second->getSymbolType() == ICodeSymbol::ICODE_VECTOR)
	 (static_cast<Vector*>(it->second))->size(size);
   }
   
    
    void printProgramHeader(std::ostream& out)
    {
      out << "#include <cstdlib>" <<std::endl
          << "#include <complex>" <<std::endl
	  << "#include <cstdio>" <<std::endl
	  << "#include <iostream>" <<std::endl
	  << "#include <papi.h>" <<std::endl
	  <<std::endl
	  <<std::endl
	  <<"std::complex<double> W(int m, int n, int k) { " <<std::endl
	  << 	"\t return std::polar(1.0,2 *M_PI*k/n);" <<std::endl
	  <<"}"<<std::endl
	  <<std::endl
	  <<std::endl
	  <<"#define EVENT_COUNT 4"<<std::endl
	  <<"#define ITERS 10000"<<std::endl
	  <<"int events[] = {PAPI_TOT_INS, PAPI_TOT_CYC, PAPI_FP_OPS, PAPI_L1_DCM};"<<std::endl
	  <<"long_long values[EVENT_COUNT], event_avg[EVENT_COUNT], runtimes = 0, runtime_avg = 0, t0, t1;"<<std::endl
	  <<std::endl
	  <<"int main(int argc, const char** argv){"<<std::endl
	  <<	"\tif (PAPI_library_init(PAPI_VER_CURRENT) != PAPI_VER_CURRENT)" << std::endl
          <<    "\t{" << std::endl
          <<    	"\t\tstd::cerr << \"Failed to load papi libraries\" << std::endl;" <<std::endl
          <<		"\t\treturn EXIT_FAILURE;"<< std::endl
          <<     "\t}" <<std::endl
          <<std::endl
          <<	"\tfor(int i = 0; i < ITERS; i++){" << std::endl
	  <<    	"\t\tif(PAPI_OK != PAPI_start_counters(events, EVENT_COUNT))" <<std::endl
	  <<    	"\t\t{" << std::endl
          <<    		"\t\t\tstd::cerr << \"Failed start counters\" << std::endl;" <<std::endl
          <<			"\t\t\treturn EXIT_FAILURE;"<< std::endl
          <<     	"\t\t}" <<std::endl
          <<		"\t\tt0 = PAPI_get_real_usec();"<<std::endl;
    }
    
    void printProgramTail(std::ostream& out)
    { out <<		"\t\tt1 = PAPI_get_real_usec();"<<std::endl
	  <<		"\t\tif(PAPI_OK != PAPI_stop_counters(values, EVENT_COUNT))" <<std::endl
	  <<    	"\t\t{" << std::endl
          <<    		"\t\t\tstd::cerr << \"Failed stp[ counters\" << std::endl;" <<std::endl
          <<			"\t\t\treturn EXIT_FAILURE;"<< std::endl
          <<     	"\t\t}" <<std::endl
	  <<		"\t\truntimes += (t1-t0);"<<std::endl
	  <<std::endl
	  <<		"\t\tfor(int i = 0; i < EVENT_COUNT; i++)"<<std::endl
	  <<		"\t\t{"<<std::endl
	  <<			"\t\t\tevent_avg[i] += values[i];"<<std::endl
	  <<		"\t\t}"<<std::endl
	  <<	"\t}"<<std::endl
	  <<std::endl
	  <<	"\truntime_avg = runtimes / ITERS;"<<std::endl
	  <<	"\tfor(int i = 0; i < EVENT_COUNT; i++)"<<std::endl
	  <<	"\t{"<<std::endl
	  <<		"\t\tevent_avg[i] /= ITERS;"<<std::endl
	  <<	"\t}"<<std::endl
	  <<	"\tfloat mflops = ((float)event_avg[2] * 1.0e-6) / ((float)runtime_avg * 1.0e-6);"<<std::endl
	  <<	"\tprintf(\"%lld,%lld,%lld,%lld,%f\\n\",runtime_avg, event_avg[0], event_avg[1], event_avg[3], mflops);"<<std::endl
	  <<	"\treturn (EXIT_SUCCESS);" <<std::endl
          << "}" << std::endl;
    }
    
    std::string getNextTemp()
    {
      std::stringstream buffer;
      do
      {
	buffer.str("");
	buffer << "$t" << mNextTemp++;
	
      }while(mSymbols.containsKey(buffer.str()));
      return buffer.str();
    }
    
  private:
    SymbolTable mSymbols;
    ICodeStatementList mStatements;
    size_t mNextTemp;
};
#endif