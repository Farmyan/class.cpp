#include <stdio.h>


int global = 5;


int  t(  int localInt)
{
     localInt = 9;
    return 0;
}

int f()
{
    int LocalInt;
    t( LocalInt);
   char* t_ptr = (char*)&t;  
    int x = 3;
   int *p = &x;
   int array[10];
    int *array1 = &array[0];
    int *array2 = &array[1];
    int *array5 = &array[5];
    int *array10 = &array[10];
   printf("&x=%p\n" , &x);
   printf("&x-3=%p\n" , &x-3);//p and x-3 are same
   printf("&p=%p\n" , &p); 
   printf("global=%p\n" , &global);
   printf("array0=%p\n" , &array[0]);
   printf("array1=%p\n" , &array[1]);
   printf("array5=%p\n" , &array[5]);
   printf("array10=%p\n" , &array[10]);
   printf("&t=%p\n" , &t);
   printf("t_ptr=%p\n" , t_ptr);
   printf("t_ptr=%p\n" ,  0xFF & *(p - 1));
   printf("&f=%p\n" , &f);
   printf("&localInt=%p\n", LocalInt);
   

   return 0;
}


int main( )
{
    f();
   
   return 0;
}

   