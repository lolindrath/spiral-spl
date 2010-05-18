#include <dft_rule.h>

std::string dft_rule::to_string(const dft_rule_type& rule_type)
{
  switch(rule_type)
  {
    case BASE: return "BASE";
    case COOLEY_TOOKEY: return "COOLEY_TOOKEY";
    case GOOD_THOMAS: return "GOOD_THOMAS";
    case RADERS: return "RADERS";
    default : return "NONE";
  }
}

std::vector<dft_rule> dft_rule::rules() const
{
  std::vector<dft_rule> rules;
  if(m_factor1 > 2)
  {
    for(size_t i = 2; i < m_factor1; i++)
    {
      if(m_factor1 % i == 0)
      {
	if(gcd(m_factor1/i,i) == 1)
	  rules.push_back(dft_rule(GOOD_THOMAS,m_factor1,m_factor1/i,i));
	else
	  rules.push_back(dft_rule(COOLEY_TOOKEY,m_factor1,m_factor1/i,i));
      }
    }
    if(rules.size() == 0)
      rules.push_back(dft_rule(RADERS,m_factor1,m_factor1 - 1, m_factor1 -1));
  }
  
  size_t factor_1_rules = rules.size();
  if(m_factor2 > 2)
  {
    for(size_t i = 2; i < m_factor2; i++)
    {
      if(m_factor2% i == 0)
      {
	if(gcd(m_factor2/i,i) == 1)
	  rules.push_back(dft_rule(GOOD_THOMAS,m_factor2,m_factor2/i,i));
	else
	  rules.push_back(dft_rule(COOLEY_TOOKEY,m_factor2,m_factor2/i,i));
      }
    }
    if(rules.size() == factor_1_rules)
      rules.push_back(dft_rule(RADERS,m_factor2,m_factor2 - 1, m_factor2 - 1));
    
  }
  return rules;	  
}
bool operator == (const dft_rule& lhs, const dft_rule& rhs)
{
  return lhs.rule_type() == rhs.rule_type() &&
  lhs.size() == rhs.size() &&
  lhs.factor1() == rhs.factor1() &&
  lhs.factor2() == rhs.factor2();
}

std::string compose(const std::string& op1, const std::string& op2, const std::string& op3, const std::string& op4, const std::string& op5)
{
  return "(compose " + op1 + " " + op2 + " "  + op3 + " " + op4 + " " + op5 + " )";
}

std::string compose(const std::string& op1, const std::string& op2, const std::string& op3, const std::string& op4)
{
  return "(compose " + op1 + " " + op2 + " "  + op3 + " " + op4 + " )";
}

std::string tensor(const std::string& lhs, const std::string& rhs)
{
  return "(tensor " + lhs + " " + rhs + " )";
}

std::string define(const std::string& decl, const std::string& def)
{
  return "(define " + decl + " " + def + " )";
}

std::string I(const size_t& n)
{
  std::stringstream buffer;
  buffer  <<"(I " << n << ")";
  return buffer.str();
}

std::string L(const size_t& m, const size_t& n)
{
  std::stringstream buffer;
  buffer  <<"(L " << m << " " << n << ")";
  return buffer.str();
}

std::string T(const size_t& m, const size_t& n)
{
  std::stringstream buffer;
  buffer  <<"(T " << m << " " << n << ")";
  return buffer.str();
}

std::string F(const size_t& n)
{
  std::stringstream buffer;
  buffer  <<"F"<< n;
  return buffer.str();
}

std::string PI(const size_t& n, const size_t& k, const size_t& m)
{
  std::stringstream buffer;
  buffer  <<"(PI " << n << " " << k << " " << m <<")";
  return buffer.str();
}

std::string P(const size_t& n, const size_t& k, const size_t& m)
{
  std::stringstream buffer;
  buffer  <<"(P " << n << " " << k << " " << m <<")";
  return buffer.str();
}

std::string RI(const size_t& n)
{
  std::stringstream buffer;
  buffer  <<"(RI " << n << ")";
  return buffer.str();
}

std::string R(const size_t& n)
{
  std::stringstream buffer;
  buffer  <<"(R " << n << ")";
  return buffer.str();
}

std::string E(const size_t& n)
{
  std::stringstream buffer;
  buffer  <<"(E " << n << ")";
  return buffer.str();
}

std::ostream& operator << (std::ostream& out, const dft_rule& rule)
{
  
  if(rule.rule_type() == dft_rule::COOLEY_TOOKEY)
    out << define(
      F(rule.size()),
      compose(
	  tensor(F(rule.factor1()),I(rule.factor2())),
	  T(rule.size(),rule.factor2()),
	  tensor(I(rule.factor1()),F(rule.factor2())),
	  L(rule.size(),rule.factor1())));
  else if(rule.rule_type() == dft_rule::GOOD_THOMAS)
    out << define(
      F(rule.size()),
      compose(
	  PI(rule.size(), rule.factor1(), rule.factor2()),
	  tensor(F(rule.factor1()),I(rule.factor2())),
	  tensor(I(rule.factor1()),F(rule.factor2())),
	  P(rule.size(), rule.factor1(), rule.factor2())));
   else if(rule.rule_type() == dft_rule::RADERS)
     out << define(
      F(rule.size()),
      compose(
	  RI(rule.size()),
	  tensor(I(1),F(rule.factor1())),
	  E(rule.size()),
	  tensor(I(1),F(rule.factor2())),
	  R(rule.size())));
   ;
  //out << "rule(" << dft_rule::to_string(rule.rule_type()) << "," << rule.size()<<"->"<<rule.factor1() << "x" <<rule.factor2() <<")";
  return out;
}