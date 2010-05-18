#ifndef SPL_PROGRAM_H_
#define SPL_PROGRAM_H_
#include <dft_rule.h>
#include <vector>
#include <map>
#include <iostream>
#include <string>

typedef std::vector<dft_rule> rule_list;

typedef std::map<size_t,rule_list> rule_map;

class spl_program: public std::map<size_t,dft_rule>
{
  public:
    spl_program():std::map<size_t,dft_rule>()
    {
    }
    spl_program(const spl_program& program):std::map<size_t,dft_rule>()
    {
      for(spl_program::const_iterator it = program.begin(); it != program.end(); it++)
	add(it->second.clone());
    }
    
    inline const spl_program& operator = (const spl_program& program)
    {
     clear();
     for(spl_program::const_iterator it = program.begin(); it != program.end(); it++)
	add(it->second.clone());
      return * this;
    }
    
    virtual ~spl_program()
    {
    }
    
    inline bool add(const dft_rule& rule)
    {
      if(find(rule.size()) == end())
      {
	(*this)[rule.size()] = rule;
	return true;
      }
      return false;
      
    }
    
    inline bool contains_key(const size_t& key) const
    {
      return find(key) != end();
    }
    
    inline bool contains_rule(const dft_rule& rule) const
    {
      spl_program::const_iterator it = find(rule.size());
      if(it == end())
	return false;
      else
	return it->second == rule;
    }
    
    inline spl_program clone() const
    {
      return spl_program(*this);
    }
    
};

std::ostream& operator << (std::ostream& out, const spl_program& program);

bool operator == (const spl_program& lhs, const spl_program& rhs);



/*
void get_rules(std::vector<dft_rule>& rules, const dft_rule& rule);
void create_rule_map(rule_map& rule_map, const size_t& size);
void create_program_list(spl_program_list& program_list, const rule_list& rules);
void create_program_list(spl_program_list& program_list, const size_t& size);*/
#endif