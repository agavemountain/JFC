#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>

#include <iostream>
#include <string>

#include <cstdlib>

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

} // namespace
