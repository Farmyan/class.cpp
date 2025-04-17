double power(double x , int n)
{
    if( x == 0 && n == 0)
        {
            return 1;   
        }
    double result = 1;
        if(n>0)
        {
            for(int i = 0 ; i < n ; i++)
              {
                 result *= x;
              }
        } 
    double reversed = 1/x;
        for(int i = 0 ; i > n ; i--)
            {
                result *= reversed; 
            }

     return result;
}

