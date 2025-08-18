#pragma once
#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>

class File 
{
private:
    int fd;
    std::string filename;

public:
    File() : fd(-1) {}
    ~File() { close(); }

    File(const File&) = delete;
    File& operator=(const File&) = delete;

    File(File&& other) noexcept : fd(other.fd), filename(std::move(other.filename)) {
        other.fd = -1;
    }

    File& operator=(File&& other) noexcept {
        if (this != &other) {
            close();
            fd = other.fd;
            filename = std::move(other.filename);
            other.fd = -1;
        }
        return *this;
    }

    // Exceptions
    class OpenFileException {
    public:
        const char* what() const { return "Failed to open file"; }
    };

    class WriteFileException {
    public:
        const char* what() const { return "Write called on closed file"; }
    };

    class ReadFileException {
    public:
        const char* what() const { return "Read called on closed file"; }
    };

    // Methods
    void open(const std::string& path, int flags = O_WRONLY | O_CREAT | O_TRUNC, int mode = 0644);
    int write(const std::string& data);
    int read(char* buffer, int size);
    void close();
    bool is_open() const { return fd >= 0; }
};

class Directory 
{
public:
    // Exceptions
    class CreateDirException {
    public:
        const char* what() const { return "Directory creation failed"; }
    };
    class RemoveDirException {
    public:
        const char* what() const { return "Directory removal failed"; }
    };
    class ListDirException {
    public:
        const char* what() const { return "Directory listing failed"; }
    };

    // Methods
    void create(const std::string& path);
    void remove(const std::string& path);
    void list(const std::string& path);
};
