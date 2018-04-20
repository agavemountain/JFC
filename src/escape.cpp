#include "escape.hpp"


#define LT             '<'
#define QUOTE          '\"'
#define GT             '>'
#define AMP            '&'
#define APOS           '\''
#define BACKSLASH      '\\'
#define TAB            '\t'
#define BACKSPACE      '\b'
#define SPACE          ' '
#define PERCENT        '%'
#define DOLLAR         '$'
#define QUESTION       '?'


#define DOUBLE_APOS    "\'\'"
#define ESC_DOLLAR     "\\$"
#define ESC_BACKSLASH  "\\\\"

namespace JFC
{

bool isControl(char a_ch)
{
    return (a_ch < 0x20 ? true : false );
}

bool isPrintableASCII(char a_ch)
{
    if ( a_ch < 0x20 || a_ch >0x7E )
    {
        return false;
    }

    return true;
}

std::string encode_cpp(const std::string& r_data) {
    std::string buffer;
    buffer.reserve(r_data.size());
    for(size_t pos = 0; pos != r_data.size(); ++pos) {
        switch(r_data[pos]) {
        case '\'':
            buffer.append("\\\'");
            break;
        case '\"':
            buffer.append("\\\"");
            break;
        case '\?':
            buffer.append("\\\?");
            break;
        case '\r':  // eat MSDOS carriage return.
            break;
        default:
            buffer.append(1, r_data[pos]);
            break;
        }
    }
    return buffer;
}

}


