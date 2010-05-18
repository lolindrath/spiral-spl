#ifndef SPL_PROGRAM_LIST_H_
#define SPL_PROGRAM_LIST_H_
#include <vector>
#include <iostream>
#include <string>
#include <dft_rule.h>
#include <spl_program.h>

class spl_program_list : public std::vector<spl_program>
{
  public:
    spl_program_list(const size_t& size): std::vector<spl_program>()
    {
      init_program_list(size);
    }
    
    inline bool contains_program(const spl_program& program)
    {
      for(size_t i = 0; i < size(); i++)
	if(at(i) == program)
	  return true;
      return false;
    }
  private:
    void init_program_list(const size_t& size);
    void extend_program_list(const rule_list& rules);
  
};
#endif