#include <gtest/gtest.h>
#include "LibOS.h"
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <vector>

// ------------------ File Tests ------------------

TEST(File, Open_CreateFile) {
    File f;
    try { 
        f.open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); 
    } catch (const File::OpenFileException& e) { 
        FAIL() << "Expected successful open, got exception: " << e.what(); 
    }
}

TEST(File, Write_FileContent) {
    File f;
    f.open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    try { 
        f.write("Hello"); 
    } catch (const File::WriteFileException& e) { 
        FAIL() << "Expected successful write, got exception: " << e.what(); 
    }
}

TEST(File, Append_FileContent) {
    File f;
    f.open("testfile.txt", O_WRONLY | O_APPEND);
    try { 
        f.write(" World"); 
    } catch (const File::WriteFileException& e) { 
        FAIL() << "Expected successful append, got exception: " << e.what(); 
    }
}

TEST(File, Read_FileContent) {
    File f;
    f.open("testfile.txt", O_RDONLY);
    char buffer[1024] = {0};
    int bytesRead = 0;
    try { 
        bytesRead = f.read(buffer, sizeof(buffer)); 
    } catch (const File::ReadFileException& e) { 
        FAIL() << "Expected successful read, got exception: " << e.what(); 
    }
    std::string content(buffer, bytesRead);
    EXPECT_EQ(content, "Hello World");
}

TEST(File, OpenNonExistingFile) {
    File f;
    try { 
        f.open("nonexisting.txt", O_RDONLY); 
        FAIL() << "Expected OpenFileException";
    } catch (const File::OpenFileException& e) { 
        EXPECT_EQ(std::string(e.what()), "Failed to open file"); 
    }
}

TEST(File, WriteClosedFile) {
    File f;
    try { 
        f.write("Data"); 
        FAIL() << "Expected WriteFileException";
    } catch (const File::WriteFileException& e) { 
        EXPECT_EQ(std::string(e.what()), "Write called on closed file"); 
    }
}

TEST(File, ReadClosedFile) {
    File f;
    char buffer[10];
    try { 
        f.read(buffer, sizeof(buffer)); 
        FAIL() << "Expected ReadFileException";
    } catch (const File::ReadFileException& e) { 
        EXPECT_EQ(std::string(e.what()), "Read called on closed file"); 
    }
}