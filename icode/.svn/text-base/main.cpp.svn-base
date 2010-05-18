/* 
* File:   main.cpp
*/
#include <cstdlib>
#include <cstdio>
#include <ICodeProgram.h>
#include <ICodeOptimization.h>
#include <ICode.tab.hpp>
// #include "general_exception.h"
// #include "icodestatements.h"
// #include <complex>
#include <cstdarg>
#include <cstdio>
// #include "icode.tab.hpp"
extern int yylineno;
/*
* 
*/

void yyerror(char *s, ...)
{
	va_list ap;
	va_start(ap, s);

	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
	va_end(ap);
}

ICodeProgram gProgram;
int vectorSize;

void eval(ICodeStatementList *sl)
{
  ICodeSSA ssa;
  ICodeConstantFolding constantFold;
  ICodeCopyPropegation copyPropegation;
  gProgram.setStatements(*sl);
  gProgram.populateSymbols();
  gProgram.getSymbols()["$in"] = new Vector("$in",vectorSize,ICodeValue::ICODE_COMPLEX);
  
   gProgram.getSymbols()["$out"] = new Vector("$out",vectorSize,ICodeValue::ICODE_COMPLEX);
  
  
  //gProgram.printCCode(std::cout);
  ssa(gProgram);
  constantFold(gProgram);
  //copyPropegation(gProgram);
  gProgram.setVectorSize(vectorSize);
  gProgram.printCCode(std::cout);
  
  //gProgram.printICode(std::cout);
  
}
extern FILE* yyin;

void print_usage()
{
  std::cout << "usage: icode2c SIZE generates a timed fft of size SIZE." << std::endl;
}
int main(int argc, char** argv) 
{
  if(argc < 2)
  {
    print_usage();
    return EXIT_FAILURE;
  }
  
  std::stringstream buffer;
  
  buffer << argv[1];
  buffer >> vectorSize;
  
  if(vectorSize < 2)
  {
    print_usage();
    return EXIT_FAILURE;
  }
  
  yy::icode_parser parser;
  parser.parse();
  
  
  return EXIT_SUCCESS;
  

}

