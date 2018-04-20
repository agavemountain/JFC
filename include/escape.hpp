#ifndef _ESCAPE_HPP_
#define _ESCAPE_HPP_
#include <string>
/**
 \section Escaping
 In most modern computer languages, an escape character is a special character that forces
 the compiler or interpreter to invoke alternative interpretation of a character sequence.

 Normally, this comes into play when you want to print a string with embedded quotation
 characters.  This becomes problematic because the double quote character (") is often used
 as a delimiter for string literals.  As a result, they double quote has to be escaped
 in order to tell the compiler or interpreter that the double quote is part of the string.

 */


namespace JFC
{

//! Detect is the specified character is a control character.  This is a
//! a faster version of the regex [:cntrl:].
//!
//! @param a_ch character to test
//!
//! @returns
//!     true    this is an ASCII control character (0x00 -1xF)
//!     false   this is not an ASCII control character
//!
bool isControl(char a_ch);

//! Detect if the specified character is a printable ASCII character.
//!
//! @param a_ch character to test
//!
//! @returns
//!     true    this is an ASCII printable latin character
//!     false   this is not an ASCII printable latin character
//!
bool isPrintableASCII(char a_ch);

//! Translate any characters that require escaping when encoding into
//! a string literal.
//!
//! @param r_data   reference to string data.
std::string  encode_cpp(const std::string& r_data);

}


#endif

