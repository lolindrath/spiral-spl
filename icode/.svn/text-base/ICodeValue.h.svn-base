#ifndef ICODE_VALUE_
#define ICODE_VALUE_
#include <string>
#include <sstream>
#include <ICodeElement.h>
#include <complex>



class ICodeValue : public ICodeElement
{
  public:
    ///enumeration of icode value types
    typedef enum ICODE_VALUE_TYPE
    {
      NULL_VALUE_TYPE = 0, ///NULL value type
      ICODE_INTEGER, ///integer value type
      ICODE_REAL, ///real value type
      ICODE_COMPLEX ///complex value type
    } VALUE_TYPE;
    
    /**
     *converts VALUE_TYPEs to string representation
     *@param valueType the VALUE_TYPE that will be converted to a string
     *@return string representation of valueType
     */
    static std::string toCValueTypeString(const VALUE_TYPE& valueType)
    {
      switch(valueType)
      {
	case ICODE_INTEGER: return "int";
	case ICODE_REAL: return "double";
	case ICODE_COMPLEX: return "std::complex<double>";
	default: return "NULL";
      }
    }
    /**
     * default constructor
     * creates an ICodeValue with ElementType == ICODE_VALUE
     * @param valueType the type of the ICodeValue
     */
    ICodeValue(const VALUE_TYPE& valueType = NULL_VALUE_TYPE):
    ICodeElement(ICodeElement::ICODE_VALUE),mValueType(valueType)
    {
    }
    
    /**
     * copy constructor
     * creates an ICodeValue with ElementType == ICODE_VALUE
     * and ValueType == value.ValueType
     * @param value the value that will have its type copied to this
     * ICodeValue
     */
    ICodeValue(const ICodeValue& value):
    ICodeElement(value), mValueType(value.mValueType)
    {
    }
    
    /**
     * assignemnt operator
     * @param value the ICodeValue that will have its ValueType copied to this ICodeValue
     * @return a reference to this
     */
    inline const ICodeValue& operator = (const ICodeValue& value)
    {
      mValueType = value.mValueType;
      return *this;
    }
    
    /**
     * virtual destructor does nothing
     */
    virtual ~ICodeValue()
    {
    }
    
    /**
     * ValueType getter
     * @return the ValueType of this ICodeValue
     */
    inline VALUE_TYPE getValueType() const
    {
      return mValueType;
    }
    
    /**
     * ValueType setter
     * @param valueType the ValueType of this ICodeValue
     */
   inline void setValueType(const VALUE_TYPE& valueType)
   {
     mValueType = valueType;
   }
   
  
  private:
    VALUE_TYPE mValueType; 
};

/**
 *@class ValueTypeTemplate is a template for all ICodeValues
 */
template <class T> class ValueTypeTemplate
{
  public:
    /**
     *default constructor
     *@param value the value contained by this ValueTypeTemplate
     */
    ValueTypeTemplate(const T& value):mValue(value)
    {
    }
    
    ValueTypeTemplate(const std::string& stringValue)
    {
      std::stringstream buffer;
      buffer << stringValue;
      buffer >> mValue;
    }
    
    /**
     *copy constructor
     *@param value the ValueTypeTemplate that will have its value copied to this ValueTypeTemplate
     */
    ValueTypeTemplate(const ValueTypeTemplate<T>& value):mValue(value.mValue)
    {
    }
    
    /**
     *assignment operator
     *@param value the ValueTypeTemplate that will have its value copied to this ValueTypeTemplate
     */
    inline const ValueTypeTemplate<T>& operator = (const ValueTypeTemplate<T> value)
    {
      mValue = value;
    }
    
    /**
     *virtual destructor does nothing
     */
    virtual ~ValueTypeTemplate()
    {
    }
    
    /**
     * Value getter
     *@return this ValueTypeTemplates Value
     */
    inline T getValue() const
    {
      return mValue;
    }
    
    /**
     *string Value getter
     *@return Value as string
     */
    inline virtual std::string toString() const
    {
      std::stringstream buffer;
      buffer << mValue;
      return buffer.str();
    }
    
    /**
     * Value setter
     *@param value ValueTypeTemplates Value
     */
    inline void setValue(const T& value)
    {
      mValue = value;
    }
    
    /**
     * Value setter
     *@param valueString string containing ValueTypeTemplates Value
     */
    inline void setValue(const std::string& valueString)
    {
      std::stringstream buffer;
      buffer << valueString;
      buffer >> mValue;
    }
    
  private:
    T mValue;
};

/**
 *@class Null represents a null value
 */
class Null: public ICodeValue, public ValueTypeTemplate<int>
{
  
  public:
    /**
     * default constructor
     */
    Null():ICodeValue(NULL_VALUE_TYPE),ValueTypeTemplate<int>(0)
    {
    }
    
    /**
     *copy constructor
     *@param null the Null that will be copied
     */
    Null(const Null& null):ICodeValue(null),ValueTypeTemplate<int>(0)
    {
    }
    
    /**
     *assignment operator
     *@param null the Null that will be copied
     *@return a reference to this
     */
    inline const Null& operator = (const Null& null)
    {
      return *this;
    }
    
    /**
     * virtual destructor does nothing
     */
    virtual ~Null()
    {
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    virtual std::string toICode() const
    {
      return "NULL";
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    virtual std::string toCCode() const
    {
      return "NULL";
    }
    
    /**
     * cloning function
     * @return a clone of this element
     */
    virtual ICodeElement* clone() const
    {
      return new Null();
    }
};

/**
 *@class Integer represents an interger value
 */
class Integer: public ICodeValue, public ValueTypeTemplate<int>
{
  
  public:
    /**
     * default constructor
     * @param value the value of the integer
     */
    Integer(const int& value = int()):
    ICodeValue(ICODE_INTEGER),ValueTypeTemplate<int>(value)
    {
    }
    
    /**
     *string constructor
     *@param valueString the string containing the value of this integer
     */
    Integer(std::string& valueString):
    ICodeValue(ICODE_INTEGER),ValueTypeTemplate<int>(valueString)
    {
      setValue(valueString);
    }
    
    /**
     *copy constructor
     *@param integer the integer that will be copied
     */
    Integer(const Integer& integer):
    ICodeValue(integer),ValueTypeTemplate<int>(integer)
    {
    }
    
    /**
     *assignment operator
     *@param integer the integer that will be copied
     *@return a reference to this
     */
    inline const Integer& operator = (const Integer& integer)
    {
      setValue(integer.getValue());
      return *this;
    }
    
    /**
     * virtual destructor does nothing
     */
    virtual ~Integer()
    {
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    virtual std::string toICode() const
    {
      return toString();
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    virtual std::string toCCode() const
    {
      return toString();
    }
    
    /**
     * cloning function
     * @return a clone of this element
     */
    virtual ICodeElement* clone() const
    {
      return new Integer(*this);
    }
};

/**
 *@class Real represents an real value
 */
class Real: public ICodeValue, public ValueTypeTemplate<double>
{
  
  public:
    /**
     * default constructor
     * @param value the value of the real
     */
    Real(const double& value = double()):
    ICodeValue(ICODE_REAL),ValueTypeTemplate<double>(value)
    {
    }
    
     /**
     *string constructor
     *@param valueString the string containing the value of this real
     */
    Real(std::string& valueString):
    ICodeValue(ICODE_REAL),ValueTypeTemplate<double>(valueString)
    {
     
    }
    
    /**
     *copy constructor
     *@param real the real that will be copied
     */
    Real(const Real& real):
    ICodeValue(ICODE_REAL),ValueTypeTemplate<double>(real)
    {
    }
    
    /**
     *assignment operator
     *@param real the real that will be copied
     *@return a reference to this
     */
    inline const Real& operator = (const Real& real)
    {
      setValue(real.getValue());
      return *this;
    }
    
    /**
     * virtual destructor does nothing
     */
    virtual ~Real()
    {
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    virtual std::string toICode() const
    {
      return toString();
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    virtual std::string toCCode() const
    {
      return toString();
    }
    
    /**
     * cloning function
     * @return a clone of this element
     */
    virtual ICodeElement* clone() const
    {
      return new Real(*this);
    }
};

/**
 *@class Compelex represents an complex value
 */
class Complex: public ICodeValue, public ValueTypeTemplate< std::complex<double> >
{
  
  public:
    /**
     * default constructor
     * @param complex the value of the complex
     */
    Complex(const std::complex<double>& value = std::complex<double>()):
    ICodeValue(ICODE_COMPLEX),ValueTypeTemplate< std::complex<double> >(value)
    {
    }
    
     /**
     *string constructor
     *@param valueString the string containing the value of this complex
     */
    Complex(std::string& valueString):
    ICodeValue(ICODE_COMPLEX),ValueTypeTemplate< std::complex<double> >(valueString)
    {
     
    }
    
    /**
     *copy constructor
     *@param complex the complex that will be copied
     */
    Complex(const Complex& complex):
    ICodeValue(ICODE_COMPLEX),ValueTypeTemplate< std::complex<double> >(complex)
    {
    }
    
    /**
     *assignment operator
     *@param complex the complex that will be copied
     *@return a reference to this
     */
    inline const Complex& operator = (const Complex& complex)
    {
      setValue(complex.getValue());
      return *this;
    }
    
    /**
     * virtual destructor does nothing
     */
    virtual ~Complex()
    {
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    virtual std::string toICode() const
    {
      return toString();
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    virtual std::string toCCode() const
    {
      std::stringstream buffer;
      buffer <<"std::complex<double>("<<getValue().real()<<","<<getValue().imag()<<")";
      return buffer.str();
    }
    
    /**
     * cloning function
     * @return a clone of this element
     */
    virtual ICodeElement* clone() const
    {
      return new Complex(*this);
    }
};
#endif