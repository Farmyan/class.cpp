#include <stdio.h>


void f()
{
    
    int local = 15;
    
 
}
int main()
{
  f();
  char* main_ptr = (char*)&main;
  printf("main_ptr=%p\n" , &main_ptr);
  char* ptr = (char*)&f;
  printf("f=%p\n" , &ptr);
  for (int i = 0; i < 64; i++)
  {
    printf("%p\n ", (0xFF & *(ptr-i)));
  }
  
    return 0;
}

   
