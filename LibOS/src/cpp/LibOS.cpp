#include "LibOS.h"
#include <sys/stat.h>

void File::open(const std::string& path, int flags, int mode) 
    {
        fd = ::open(path.c_str(), flags, mode);
        if (fd < 0) 
            {
                throw OpenFileException();
            }
        filename = path;
    }

int File::write(const std::string& data) 
    {
        if (fd < 0) throw WriteFileException();
        return ::write(fd, data.c_str(), data.size());
    }

int File::read(char* buffer, int size) 
    {
        if (fd < 0) throw ReadFileException();
        return ::read(fd, buffer, size);
    }

void File::close() 
    {
        if (fd >= 0) 
            {
                ::close(fd);
                fd = -1;
            }
    }

void Directory::create(const std::string& path) 
    {
        if (::mkdir(path.c_str(), 0755) < 0) throw CreateDirException();
    }

void Directory::remove(const std::string& path) 
    {
        if (::rmdir(path.c_str()) < 0) throw RemoveDirException();
    }

void Directory::list(const std::string&) 
    {
        throw ListDirException();
    }
