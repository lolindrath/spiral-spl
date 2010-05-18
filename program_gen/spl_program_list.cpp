#include <spl_program_list.h>

void spl_program_list::extend_program_list(const rule_list& rules)
{

  for(size_t i = 0; i < rules.size(); i++)
  {
	
	for(size_t j = 0; j < size(); j++)
	{
	if(!at(j).contains_key(rules[i].size()))
	  at(j).add(rules[i]);
	
	else
	{
	  spl_program new_program = at(j).clone();
	  new_program[rules[i].size()] = rules[i];
	  if(!contains_program(new_program))
		push_back(new_program);
	}
	}
	extend_program_list(rules[i].rules());
  }
}

void spl_program_list::init_program_list(const size_t& size)
{
		rule_list rules;
		if(size > 2)
		{
				for(size_t i = 2; i < size; i++)
				{
						if(size % i == 0)
						{
								if(gcd(size/i,i) == 1)
										rules.push_back(dft_rule(dft_rule::GOOD_THOMAS,size,size/i,i));
								else
										rules.push_back(dft_rule(dft_rule::COOLEY_TOOKEY,size,size/i,i));
						}
				}
				if(rules.size() == 0)
						rules.push_back(dft_rule(dft_rule::RADERS,size,size-1,size-1));
		}

		for(size_t i = 0; i < rules.size(); i++)
		{
				spl_program new_program;
				new_program.add(rules[i]);
				push_back(new_program);
				extend_program_list(rules[i].rules());
		}
}
