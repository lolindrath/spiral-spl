#include <cstdlib>
#include <iostream>
#include <fstream>
#include <dft_rule.h>
#include <spl_program.h>
#include <spl_program_list.h>

void print_usage();

void print_program(const std::string& program_name, const spl_program& program);

int main(int argc, const char** argv)
{
  if(argc < 2)
  {
    print_usage();
    return EXIT_FAILURE;
  }
  
  size_t size = 0;
  
  std::stringstream buffer;
  buffer << argv[1];
  buffer >> size;
  
  if(size <= 0)
  {
    print_usage();
    return EXIT_FAILURE;
  }
  
  spl_program_list programs(size);
  
  buffer.str("");
  
 
  for(size_t i = 0; i < programs.size(); i++)
  {
    std::string name;
    std::stringstream buffer;
    buffer << (i + 1);
    buffer >> name;
    print_program(name, programs[i]);
  }
  return EXIT_SUCCESS;
}

void print_usage()
{
  std::cout << "usage - program_gen SIZE" << std::endl;
}

void print_program(const std::string& program_name, const spl_program& program)
{
  const std::string name_prefix = "fft";
  const std::string name_suffix = ".spl";
  std::ifstream fin;
  std::ofstream fout;
  std::string buffer;
  
  fin.open("templates.spl");
  
  if(!fin.is_open())
  {
    std::cerr << "failed to template definitions" << std::endl;
    return;
  }
  fout.open(std::string(name_prefix + program_name + name_suffix).c_str());
  
  if(!fout.is_open())
  {
    std::cerr << "failed to open " << name_prefix + program_name + name_suffix << "for program output" << std::endl;
    return;
  }
  
  while(!fin.eof())
  {
    getline(fin,buffer);
    fout << buffer << std::endl;
  }
  
  fout << program << std::endl;
  fout.close();
}
