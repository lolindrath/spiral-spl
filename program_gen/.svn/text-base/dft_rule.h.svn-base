#ifndef DFT_RULE_H
#define DFT_RULE_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
template<typename T>
T gcd(T x, T y) {
  while ( y != 0 ) {
    T z = x % y;
    x = y;
    y = z;
  }
  return x;
}

class dft_rule
{
  public:
    typedef enum DEF_RULE_TYPE
    {
      BASE,
      COOLEY_TOOKEY,
      GOOD_THOMAS,
      RADERS
    } dft_rule_type;
    
    static std::string to_string(const dft_rule_type& rule_type);
    
    dft_rule(const dft_rule_type& rule_type = BASE, const size_t& size = 2, const size_t& factor1 = 0, const size_t& factor2 = 0):
    m_rule_type(rule_type), m_size(size), m_factor1(factor1), m_factor2(factor2)
    {
    }
    
    dft_rule(const dft_rule& rule):
    m_rule_type(rule.m_rule_type), m_size(rule.m_size), m_factor1(rule.m_factor1), m_factor2(rule.m_factor2)
    {
    }
    
    inline const dft_rule& operator = (const dft_rule& rule)
    {
      m_rule_type = rule.m_rule_type;
      m_size = rule.m_size;
      m_factor1 = rule.m_factor1;
      m_factor2 = rule.m_factor2;
      return *this;
    }
    
    virtual ~ dft_rule()
    {
    }
    
    inline dft_rule_type rule_type() const
    {
      return m_rule_type;
    }
    
    inline size_t size() const
    {
      return m_size;
    }
    
    inline size_t factor1() const
    {
      return m_factor1;
    }
    
    inline size_t factor2() const
    {
      return m_factor2;
    }
    
    inline void rule_type(const dft_rule_type& rule_type)
    {
      m_rule_type = rule_type;
    }
    
    inline void size(const size_t& size)
    {
      m_size = size;
    }
    
    inline void factor1(const size_t& factor1)
    {
      m_factor1 = factor1;
    }
    
    inline void factor2(const size_t& factor2)
    {
      m_factor2 = factor2;
    }
    
    inline dft_rule clone() const
    {
      return dft_rule(*this);
    }
    
    inline bool is_base_case() const
    {
      return m_factor1 == 2 && m_factor2 == 2;
    }
     
    std::vector<dft_rule> rules() const;
      
  private:
    
    dft_rule_type m_rule_type;
    size_t m_size;
    size_t m_factor1;
    size_t m_factor2;
};

bool operator == (const dft_rule& lhs, const dft_rule& rhs);
std::ostream& operator << (std::ostream& out, const dft_rule& rule);

#endif