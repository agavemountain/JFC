#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>

#include <iostream>
#include <string>

#include <fstream>
#include <cstdlib>

#include <file_utilities.hpp>

namespace JFC
{

void touch(const std::string& pathname)
{
    int fd = open(pathname.c_str(),
                  O_WRONLY|O_CREAT|O_NOCTTY|O_NONBLOCK,
                  0666);
    if (fd<0) // Couldn't open that path.
    {
        std::cerr
            << __PRETTY_FUNCTION__
            << ": Couldn't open() path \""
            << pathname
            << "\"\n";
        return;
    }
    int rc = utimensat(AT_FDCWD,
                       pathname.c_str(),
                       nullptr,
                       0);
    if (rc)
    {
        std::cerr
            << __PRETTY_FUNCTION__
            << ": Couldn't utimensat() path \""
            << pathname
            << "\"\n";
        return;
    }

}

bool stringToFile(const std::string& pathname, const std::string &data, bool create = false)
{

    if (doesFileExist(pathname))
    {
        // if the file exists, but we aren't allowed to create it.. return error.
        if (create == false)
        {
            return false;
        }
        else
        {
            remove(pathname.c_str());
        }
    }

    std::ofstream out(pathname);
    out << data;
    out.close();

    return true;
}

std::string fileToString(const std::string &pathname);
} // namespace
