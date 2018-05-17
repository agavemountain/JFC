/*
 * @(#) string_utilities.hpp
 *
 * @author Joe Turner (joe@agavemountain.com)
 *
 * Copyright (c) 2018 Joe Turner
 * All rights reserved.
 *
 */
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <string>
#include <vector>

/**
 \page strutil String Handling Utility Functions

	This is a collection of string handling functions.

	Whatever the reason, I've had to hand-roll string handling
	functions that should have been included in the standard library
	years ago.

	Note, some of the functions are template functions, and others
	are concrete.  The template functions will handle basic_string, string, and
	wstring templates, but nobody really uses wstring.  If you are,
	then you are doing something wrong.  Best practices is to use
	string then transform to UTF-8/UTF-16...

*/

namespace JFC
{

/**
 * \brief Search and replace text within a string
 *
 * This function will search for the exact text string specified and
 * replace all instances within a string.
 *
 * \param source        string to be modified
 * \param findstr 	 	text to be searched for and replaced, (this is old substring to be replaced).
 * \param replacestr	text to replace the original found text
 *
 */
template <class T>
void replace(T& source, const T& findstr, const T& replacestr)
{
    size_t j;
    //! special case: findstr = ""
    if (findstr.length()==0) return;

    for (; (j = source.find( findstr )) != T::npos;)
    {
        source.replace( j, findstr.length(), replacestr );
    }
}

/**
 * \brief Search and replace text within a string, returning the resulting string.
 *
 * This function will search for the exact text string specified and
 * replace all instances within a string.  Unlike the replace function, this
 * function will NOT modify the original string and will return the resultant
 * string.
 *
 * \param source        string to be modified
 * \param findstr 	 	text to be searched for and replaced, (this is old substring to be replaced).
 * \param replacestr	text to replace the original found text
 *
 * \returns
 * 		modified string object.
 */
std::string replace_copy(const std::string& source, const std::string& findstr, const std::string& replacestr);

/**
 * \note : I don't remember where this came from, but it needs some
 * work.
 *
 * This is a word wrap function that will add line breaks.
 *
 * Word wrap is the additional feature of most text editors, word processors,
 * and web browsers, of breaking lines between and not within words, except
 * when a single word is longer than a line.
 *
 * My implementation uses a greedy algorithm, the pseudocode is as
 * follows:
 *
 *	SpaceLeft := LineWidth
 *	for each Word in Text
 *    if Width(Word) > SpaceLeft
 *        insert line break before Word in Text
 *        SpaceLeft := LineWidth - Width(Word)
 *    else
 *        SpaceLeft := SpaceLeft - (Width(Word) + SpaceWidth)
 *
 */
std::string wordwrap( std::string str, int width ) ;

/**
 * \brief Center justify referenced string object.
 *
 * \param str           string to be center justified
 * \param width         number of characters in resultant string
 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
 *
 * \code
 * string tmp = "C is awesome";
 * center_justify(tmp, 24);
 * print("Centered String: ", tmp)
 *
 * Centered String:          C is awesome
 * \endcode
 */
void center_justify(std::string &str, int width, char fill = ' ');

/**
 * \brief Left justify referenced string object.
 *
 * \param str           string to be center justified
 * \param width         number of characters in resultant string
 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
 *
 * \code
 * string tmp = "hello";
 * left_justify(tmp, 10, '.');
 * print("String: ", tmp)
 *
 * String: hello.....
 * \endcode      */
void left_justify(std::string &str, int width, char fill = ' ');

/**
 * \brief Right justify referenced string object.
 *
 * \param str           string to be center justified
 * \param width         number of characters in resultant string
 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
 */
void right_justify(std::string &str, int width, char fill = ' ');

/**
 * \brief Center justify a string and return a copy
 *
 * \param str           string to be center justified
 * \param width         number of characters in resultant string
 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
 *
 * \returns
 *      This function returns the formatted string.
 */
std::string center_justify_copy(const std::string &str, int width, char fill = ' ');

/**
 * \brief Left justify a string and return a copy
 *
 * \param str           string to be center justified
 * \param width         number of characters in resultant string
 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
 *
 * \returns
 *      This function returns the formatted string.
 */
std::string left_justify_copy(const std::string &str, int width, char fill = ' ');

/**
 * \brief Right justify a string and return a copy
 *
 * \param str           string to be center justified
 * \param width         number of characters in resultant string
 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
 *
 * \returns
 *      This function returns the formatted string.
 */
std::string right_justify_copy(const std::string &str, int width, char fill = ' ');


//! To be implemented (merged from other projects) with unit tests.
namespace unimplemented
{



/**
 * \brief Remove the last character from a string.
 *
 * Chops off the last character of a string and returns the character chopped. It's
 * used primarily to remove the newline from the end of an input record, but is much
 * more efficient than s/\n// because it neither scans nor copies the string.
 *
 * \param str	string to be modified
 */
char chop(std::string &str);

/**
 * \brief Remove a trailing record separator from a string
 *
 * This is a slightly safer version of chop. It removes any line ending and returns the total
 * number of characters removed from all its arguments. It's often used to remove the
 * newline from the end of an input record when you're worried that the final
 * record may be missing its newline.
 *
 * \param str	string to be modified
 */
int chomp(std::string &str);

/**
 * \brief Transform a string into only lower case characters.
 *
 * \param str	string to be modified
 */
void to_lower_case(std::string &str);

/**
 * \brief Transform a string into only UPPER case characters.
 *
 * \param str	string to be modified
 */
void to_upper_case(std::string &str);

/**
 * \brief Capitalize first character in a string.
 *
 * \param str	string to be modified
 */
void ucfirst(std::string &str);

/**
 * \brief Reverse characters in a string
 *
 * \param str	string to be modified
 */
void reverse(std::string &str);

/**
 * \brief Change first character to lower case in a string.
 */
void join(std::string &str, std::vector<std::string> vec);



std::string trim_left( std::string & src );
std::string ltrim_copy(std::string &src);
std::string trim_right( std::string & src );
std::string rtrim_copy(std::string &src);
std::string trim( std::string & src );
std::string trim_copy(std::string &src);

} // namespace unimplemented

};


