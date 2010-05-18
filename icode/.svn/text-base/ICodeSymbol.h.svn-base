
#ifndef ICODE_SYMBOL_H_
#define ICODE_SYMBOL_H_

#include <ICodeElement.h>
#include <ICodeValue.h>
#include <string>
#include <sstream>


/**
 *class ICodeSymbol repersents a symbol (e.g. a scalar, vector, or function)
 */
class ICodeSymbol : public ICodeValue
{
  public:
    
    ///enumeration of symbol types
    typedef enum ICODE_SYMBOL_TYPE
    {
      ICODE_SCALAR, ///scalar variable
      ICODE_VECTOR,  ///vector
      ICODE_VECTOR_REF,
      ICODE_FUNCTION, ///function
      ICODE_MATRIX,  ///matrix
    } SYMBOL_TYPE; 
    
    /**
     *default constructor
     *@param name name of the symbol
     *@param symbolType type of the symbol
     *@param valueType value type of the symbol
     */
    ICodeSymbol(const std::string& name, const SYMBOL_TYPE& symbolType, const VALUE_TYPE& valueType):
    ICodeValue(valueType), mName(name), mSymbolType(symbolType)
    {
    }
    
    /**
     * copy constructor
     *@param symbol the symbol that will have its properties copied to this symbol
     */
    ICodeSymbol(const ICodeSymbol& symbol):
    ICodeValue(symbol),mName(symbol.mName),mSymbolType(symbol.mSymbolType)
    {
    }
    
    /**
     * assignment operator
     *@param symbol the symbol that will have its properties copied to this symbol
     *@return a reference to this
     */
    
    inline const ICodeSymbol& operator = (const ICodeSymbol& symbol)
    {
      ICodeValue::operator = (symbol);
      mName = symbol.mName;
      mSymbolType = symbol.mSymbolType;
      return *this;
    }
    
    /**
     *virtual destructor does nothing
     */
    virtual ~ICodeSymbol()
    {
    }
    
    /**
     *Name getter
     *@return the Name of the symbol
     */
    inline const std::string& getName() const
    {
      return mName;
    }
    
    /**
     *SymolType getter
     *@return the SymbolType of this symbol
     */
    inline SYMBOL_TYPE getSymbolType() const
    {
      return mSymbolType;
    }
    
    /**
     *Name setter
     *@param name the Name of this symbol
     */
    inline void setName(const std::string& name)
    {
      mName = name;
    }
    
    /**
     *SymbolType setter
     *@param symbolType the SymbolType of this symbol
     */
    inline void setSymbolType(const SYMBOL_TYPE& symbolType)
    {
      mSymbolType = symbolType;
    }
    
    /**
     * gets a key for the symbol
     */
    inline virtual std::string getKey() const
    {
      return getName();
    }
    
    /**
     * C code declaration getter
     *@return a string containing the C code declaration of this symbol
     */
    virtual std::string getCCodeDecl() const = 0;
    
  private:
    std::string mName;
    SYMBOL_TYPE mSymbolType;  
};

/**
 *class Scalar repersents a scalar symbol
 */
class Scalar : public ICodeSymbol
{
  public:
    
    /**
     *default constructor
     *@param name name of the scalar
     *@param valueType value type of the scalar
     */
    Scalar(const std::string& name = "scalar", const VALUE_TYPE& valueType = NULL_VALUE_TYPE):
    ICodeSymbol(name,ICODE_SCALAR,valueType)
    {
    }
    
    /**
     * copy constructor
     *@param scalar the scalar that will have its properties copied to this scalar
     */
    Scalar(const Scalar& scalar):
    ICodeSymbol(scalar)
    {
    }
    
    /**
     * assignment operator
     *@param scalar the scalar that will have its properties copied to this scalar
     *@return a reference to this
     */
    
    inline const Scalar& operator = (const Scalar& scalar)
    {
      ICodeSymbol::operator = (scalar);
      return *this;
    }
    
    /**
     *virtual destructor does nothing
     */
    virtual ~Scalar()
    {
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    inline virtual std::string toICode() const
    {
      return getName();
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    inline virtual std::string toCCode() const
    {
      return getName();
    }
    
    /**
     * cloning function
     * @return a clone of this element
     */
    virtual ICodeElement* clone() const
    {
      return new Scalar(*this);
    }
    
    /**
     * C code declaration getter
     *@return a string containing the C code declaration of this symbol
     */
    virtual std::string getCCodeDecl() const
    {
      return toCValueTypeString(getValueType()) + " " + getName(); 
    }
     
};

/**
 *class Vector repersents a vector symbol
 */
class Vector : public ICodeSymbol
{
  public:
    
    /**
     *default constructor
     *@param name name of the vector
     *@param valueType value type of the vector
     */
    Vector(const std::string& name = "vector", const size_t& size = 0, const VALUE_TYPE& valueType = NULL_VALUE_TYPE):
    ICodeSymbol(name,ICODE_VECTOR,valueType), mSize(size)
    {
    }
    
    /**
     * copy constructor
     *@param scalar the vector that will have its properties copied to this vector
     */
    Vector(const Vector& vector):
    ICodeSymbol(vector), mSize(vector.mSize)
    {
    }
    
    /**
     * assignment operator
     *@param scalar the vector that will have its properties copied to this vector
     *@return a reference to this
     */
    
    inline const Vector& operator = (const Vector& vector)
    {
      ICodeSymbol::operator = (vector);
      mSize = vector.mSize;
      return *this;
    }
    
    /**
     *virtual destructor does nothing
     */
    virtual ~Vector()
    {
    }
    
    /**
     * Size getter
     * @return Size of this vector
     */
    inline size_t size() const
    {
      return mSize;
    }
    
    /**
     *Size setter
     *@param size the Size of this vector
     */
    inline void size(const size_t& size)
    {
      mSize = size;
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    inline virtual std::string toICode() const
    {
      return getName();
    }
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    inline virtual std::string toCCode() const
    {
      return getName();
    }
    
    /**
     * cloning function
     * @return a clone of this element
     */
    inline virtual ICodeElement* clone() const
    {
      return new Vector(*this);
    }
    
    /**
     * C code declaration getter
     *@return a string containing the C code declaration of this symbol
     */
    inline virtual std::string getCCodeDecl() const
    {
      std::stringstream buffer;
      buffer << toCValueTypeString(getValueType()) << ' ' << getName() << '[' << mSize << ']';
      return buffer.str();
    }
    
  private:
    size_t mSize; 
};



#endif