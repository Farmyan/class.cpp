#include <stdio.h>

void f() 
{
  int local = 14;
}

int main() 
{
    f();  

 
    char* f_ptr = (char*)&f;

    printf(" %p\n", &f_ptr);
    printf(" %p\n", f);

    for (int i = 0; i < 45; i++) 
    {
        printf("%p ", (0xFF & *(f_ptr - i)));
        if (i % 8 == 7) printf("\n");  
    }

    return 0;
}

   
