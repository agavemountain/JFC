#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <string>

/**
 \page strutil String Handling Utility Functions

	This is a collection of string handling functions.

	Whatever the reason, I've had to hand-roll string handling
	functions that should have been included in the standard library
	years ago.

 \section Examples

 For the following examples, we assume we are using the following imaginary example file (named myfile),
 with the following content:
 \code
 This is a test
 This is a comment
 \endcode

*/

namespace JFC
{

	/**
	 * \brief Center justify referenced string object.
	 *
	 * \param str		string to be center justified
	 * \param width		number of characters in resultant string
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
	 * \param str		string to be center justified
	 * \param width		number of characters in resultant string
	 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
	 *
	 * \code
	 * string tmp = "hello";
	 * left_justify(tmp, 10, '.');
	 * print("String: ", tmp)
	 *
	 * String: hello.....
	 * \endcode	 */
	void left_justify(std::string &str, int width, char fill = ' ');

	/**
	 * \brief Right justify referenced string object.
	 *
	 * \param str		string to be center justified
	 * \param width		number of characters in resultant string
	 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
	 */
	void right_justify(std::string &str, int width, char fill = ' ');

	/**
	 * \brief Center justify a string and return a copy
	 *
	 * \param str		string to be center justified
	 * \param width		number of characters in resultant string
	 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
	 *
	 * \returns
	 * 	This function returns the formatted string.
	 */
	std::string center_justify_copy(const std::string &str, int width, char fill = ' ');

	/**
	 * \brief Left justify a string and return a copy
	 *
	 * \param str		string to be center justified
	 * \param width		number of characters in resultant string
	 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
	 *
	 * \returns
	 * 	This function returns the formatted string.
	 */
	std::string left_justify_copy(const std::string &str, int width, char fill = ' ');

	/**
	 * \brief Right justify a string and return a copy
	 *
	 * \param str		string to be center justified
	 * \param width		number of characters in resultant string
	 * \param fill      character to pad the resulting string.  If not specified, default is spaces.
	 *
	 * \returns
	 * 	This function returns the formatted string.
	 */
	std::string right_justify(const std::string &str, int width, char fill = ' ');

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

	void replace(std::string &str, std::string &replaceThis, std::string &withThis);

	std::string trim_left( std::string & src );
	std::string ltrim_copy(std::string &src);
	std::string trim_right( std::string & src );
	std::string rtrim_copy(std::string &src);
	std::string trim( std::string & src );
	std::string trim_copy(std::string &src);

};


