#include <spl_program.h>

std::ostream& operator << (std::ostream& out, const spl_program& program)
{
  for(spl_program::const_iterator it = program.begin(); it != program.end(); it++)
    out << it->second << std::endl;
  if(!program.empty())
  out <<"F"<<(--program.end())->second.size()<<std::endl;
  return out;
}

bool operator == (const spl_program& lhs, const spl_program& rhs)
{
  if(lhs.size() != rhs.size())
    return false;
  
  for(spl_program::const_iterator it = lhs.begin(); it != lhs.end(); it++)
  {
    if(!rhs.contains_rule(it->second))
      return false;
  }
  
  return true;
}
/*
void get_rules(std::vector<dft_rule>& rules, const dft_rule& rule)
{
  std::vector<dft_rule> children = rule.rules();
  for(size_t i = 0; i < children.size(); i++)	
    get_rules(rules,children[i]);
  rules.push_back(rule);
}
void create_rule_map(rule_map& rule_map, const size_t& size)
{
    std::vector<dft_rule> rules;
    if(size > 2)
    {
      for(size_t i = 2; i < size; i++)
      {
	if(size % i == 0)
	{
	  if(gcd(size/i,i) == 1)
	    get_rules(rules,dft_rule(dft_rule::GOOD_THOMAS,size,size/i,i));
	  else
	    get_rules(rules,dft_rule(dft_rule::COOLEY_TOOKEY,size,size/i,i));
	}
      }
      if(rules.size() == 0)
	get_rules(rules,dft_rule(dft_rule::RADERS,size,size-1,size-1));
    }
    
    for(size_t i = 0; i < rules.size(); i++)
    {
      rule_map[rules[i].size()].push_back(rules[i]);
    }
}

void create_program_list(spl_program_list& program_list, const rule_list& rules)
{

  for(size_t i = 0; i < rules.size(); i++)
  {
    for(size_t j = 0; j < program_list.size(); j++)
    {
      if(!program_list[j].contains_rule(rules[i]))
      {
	if(!program_list[j].contains_key(rules[i].size()))
	  program_list[j].add(rules[i]);
	else
	{
	  spl_program new_program = program_list[j].clone();
	  new_program[rules[i].size()] = rules[i];
	  program_list.push_back(new_program);
	}
      }
    }
    create_program_list(program_list,rules[i].rules());
  }
}
void create_program_list(spl_program_list& program_list, const size_t& size)
{
  rule_map rule_map;
  create_rule_map(rule_map,size);
  rule_list rules = rule_map[size];
    for(size_t i = 0; i < rules.size(); i++)
    {
      spl_program new_program;
      new_program.add(rules[i]);
      program_list.push_back(new_program);
      create_program_list(program_list, rules[i].rules());
    }
}*/