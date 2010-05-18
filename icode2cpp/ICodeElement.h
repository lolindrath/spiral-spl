/**
 * @file ICodeElement.h
 * @author Kenneth Owens
 * @author Andy Williams
 * Contains the declaration of ICodeElement.h which is an interface for all ICode Elements
 */

#ifndef ICODE_ELEMENT_
#define ICODE_ELEMENT_

#include<string>

class ICodeElement
{
  public:
    
    ///Enumerates the type of ICodeElements
    typedef enum ICODE_ELEMENT_TYPE
    {
      NULL_ELEMENT_TYPE = 0,
      ICODE_SYMBOL, ///Type of icode symbols i.e. vectors, scalars, matrices
      ICODE_VALUE,  ///Type of icode values e.g. complex, real, integer
      ICODE_STATEMENT ///Type of icode statements, e.g. expressions, assignments, comments
    } ELEMENT_TYPE;
    
    /**
     * default constructor 
     * @param elementType the type of the element
     */
    ICodeElement(const ELEMENT_TYPE& elementType = NULL_ELEMENT_TYPE):
    mElementType(elementType)
    {
      
    }
    
    /**
     * copy constructor
     * @param element has its type to construct this ICodeElement
     */
    ICodeElement(const ICodeElement& element):mElementType(element.mElementType)
    {
    }
    
    /**
     * assignment operator
     * @param element has its type copied to this ICodeElement
     */
    inline const ICodeElement& operator = (const ICodeElement& element)
    {
      mElementType = element.mElementType;
      return *this;
    }
    
    /**
     * virtual destructor does nothing
     */
    virtual ~ICodeElement()
    {
    }
    
    /**
     * element type getter
     * @return the ICodeElement's type
     */
    inline ELEMENT_TYPE getElementType() const
    {
      return mElementType;
    }
    
    /**
     * element type setter
     * @param  elementType the ICodeElement's type
     */
    inline void setElementType(const ELEMENT_TYPE& elementType)
    {
      mElementType = elementType;
    }
    
    /**
     * icode string conversion
     * @return a string containing an icode representation of this element
     */
    virtual std::string toICode() const = 0;
    
    /**
     * C code string conversion
     * @return a string containing a C code representation of this element
     */
    virtual std::string toCCode() const = 0;
    
    /**
     * cloning function
     * @return a clone of this element
     */
    virtual ICodeElement* clone() const = 0;
  
  protected:
   
    ELEMENT_TYPE mElementType;
};

#endif 