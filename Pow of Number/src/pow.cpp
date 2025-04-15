double power(double x , int n)
{
    if(n>0)
    {
        if( x == 0)
        {
           if(n == 0)
           {
            return 1;
           }
           else
            {
            return 0;
            }
        }
        else
        {    
        double result1 = 1;
        for(int i = 0 ; i < n ; i++)
        {
            result1 *= x; 
        }
        return result1;
        }
    }
    else 
    {
        double result2 = 1 ;
        double reversed = 1/x;
        for(int i = 0 ; i > n ; i--)
        {
            result2 *= reversed; 
        }
        return result2;
         
    }
}
