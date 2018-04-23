#ifndef _FILE_UTILITIES_HPP_
#include <sys/stat.h>
#include <string>
namespace JFC
{

//! \brief checks to see if a file exists
//!
//! \param filename     path and filename of the file to look for
//! \returns
//!     true if the file exists, else false.
inline bool doesFileExist (const std::string& filename) {
  struct stat buffer;
  return (stat (filename.c_str(), &buffer) == 0);
}

//! \brief An implementation of the unix touch command
//!
//! \param  pathname    file to create or touch
//!
void touch(const std::string& pathname);

//! \brief Take a string and push it to a file
//!
//! \param  pathname    file to create or touch
//! \param  data        text to push into the file.
//!
bool stringToFile(const std::string& pathname, const std::string &data);

}

#endif
