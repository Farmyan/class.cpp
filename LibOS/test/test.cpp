#include <gtest/gtest.h>
#include "LibOS.h"
#include <fcntl.h>
#include <unistd.h>
#include <string>

TEST(File, Open_CreateFile) 
    {
        File f;
        EXPECT_NO_THROW(f.open("test_rw.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644));
    }

TEST(File, WriteAndRead_FileContent) 
    {
        File f;
        EXPECT_NO_THROW(f.open("test_rw.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644));
        EXPECT_NO_THROW(f.write("Hello World"));
        f.close();

        File f2;
        EXPECT_NO_THROW(f2.open("test_rw.txt", O_RDONLY));
        char buffer[1024] = {0};
        int bytesRead = 0;
        EXPECT_NO_THROW(bytesRead = f2.read(buffer, sizeof(buffer)));
        std::string content(buffer, bytesRead);
        EXPECT_EQ(content, "Hello World");
    }

TEST(File, AppendAndRead_FileContent) 
    {
        File f;
        EXPECT_NO_THROW(f.open("test_rw.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644));
        EXPECT_NO_THROW(f.write("Hello"));
        f.close();

        File f2;
        EXPECT_NO_THROW(f2.open("test_rw.txt", O_WRONLY | O_APPEND));
        EXPECT_NO_THROW(f2.write(" World"));
        f2.close();

        File f3;
        EXPECT_NO_THROW(f3.open("test_rw.txt", O_RDONLY));
        char buffer[1024] = {0};
        int bytesRead = 0;
        EXPECT_NO_THROW(bytesRead = f3.read(buffer, sizeof(buffer)));
        std::string content(buffer, bytesRead);
        EXPECT_EQ(content, "Hello World");
    }

TEST(File, OpenNonExistingFile) 
    {
        File f;
        EXPECT_THROW(f.open("nonexisting.txt", O_RDONLY), File::OpenFileException);
    }

TEST(File, WriteClosedFile) 
    {
        File f;
        EXPECT_THROW(f.write("Data"), File::WriteFileException);
    }

TEST(File, ReadClosedFile) 
    {
        File f;
        char buffer[10];
        EXPECT_THROW(f.read(buffer, sizeof(buffer)), File::ReadFileException);
    }
