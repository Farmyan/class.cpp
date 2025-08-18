#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main() 
    {
        int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) 
            {
                std::cerr << "Error opening file\n";
                return 1;
            }
        dup2(fd, STDOUT_FILENO);  // redirect cout to file
        std::cout << "Hello, file!\n";
        std::cout << "This is written using cout and open/close.\n";
        close(fd); 
        return 0;
    }
