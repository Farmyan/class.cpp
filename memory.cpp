#include <stdio.h>

void f(int x)
{


    char* f_ptr = (char*)&f;   
    char smth = 42;            
    char* ptr = &smth;         

    printf("f_ptr:%p\n", (char*)&f_ptr);
    printf("smth:%p\n", (char*)&smth);
    printf("f():%p\n", (char*)f_ptr);
   
    for (int i = 1; i <= 40; i++) {
        printf("%p ", (0xFF & *(ptr - i)));
        if (i % 8 == 0) printf("\n");
    }

}

int main()
{
    f(5);
    return 0;
}


   
