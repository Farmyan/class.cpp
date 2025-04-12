double power(double x , double n)
{
    if(n>0)
    {
        double result0 = 1;
        for(int i = 0 ; i < n ; i++)
        {
            result0 *= x; 
        }
        return result0;
    }
    else 
    {
        double result1 = 1 ;
        double reversed = 1/x;
        for(int i = 0 ; i > n ; i--)
        {
            result1 *= reversed; 
        }
        return result1; 
    }
}