#include <string_utilities.hpp>

namespace JFC
{

std::string wordwrap( std::string str, int width = 80 )
{
    size_t curWidth = width;

    while( curWidth < str.length() ) {
        std::string::size_type spacePos = str.rfind( ' ', curWidth );
        if( spacePos == std::string::npos )
            spacePos = str.find( ' ', curWidth );
        if( spacePos != std::string::npos ) {
            str[ spacePos ] = '\n';
            curWidth = spacePos + width + 1;
        }
    }

    return str;
}

std::string replace_copy(const std::string& source, const std::string& findstr, const std::string& replacestr)
{
    std::string result = source;
    replace(result, findstr, replacestr);
    return result;
}

void left_justify(std::string &str, int width, char fill)
{
    std::string::size_type len = str.size();
    if ( (( int ) len ) >= width ) return ;
    str = str + std::string( width - len, ' ' );
}

std::string left_justify_copy(const std::string &str, int width, char fill )
{
    std::string tmp = str;
    left_justify(tmp, width, fill);
    return tmp;
}

void right_justify(std::string &str, int width, char fill)
{
    std::string::size_type len = str.size();
    if ( (( int ) len ) >= width ) return ;
    str = std::string( width - len, ' ' ) + str;
}

std::string right_justify_copy(const std::string &str, int width, char fill )
{
    std::string tmp = str;
    right_justify(tmp, width, fill);
    return tmp;
}

void center_justify(std::string &str, int width, char fill )
{
    int len = (int) str.size();
    int marg, left;
    if ( len >= width ) return ;
    marg = width - len;
    left = marg / 2 + (marg & width & 1);

    str = std::string( left, ' ' ) + str + std::string( marg - left, ' ' );
}

std::string center_justify_copy(const std::string &str, int width, char fill )
{
    std::string tmp = str;
    center_justify(tmp, width, fill);
    return tmp;
}

void reverse_string(std::string &str)
{
    std::reverse(str.begin(), str.end());
}

std::string reverse_string_copy( const std::string &str)
{
    std::string result;
    result.assign(str.rbegin(), str.rend());
    return result;
}

void to_upper_case(std::string &str)
{
    for (std::string::iterator p = str.begin(); p != str.end(); ++p) {
        *p = toupper(*p);
    }
}

void to_lower_case(std::string &str) {
    for (std::string::iterator p = str.begin(); p != str.end(); ++p)
    {
        *p = tolower(*p);
    }
}

char chop(std::string &str)
{
    char ch = 0x00;
    int len = str.length();
    if (len == 0) return ch;
    ch = str[len-1];
    str.pop_back();
    return ch;
}

};
