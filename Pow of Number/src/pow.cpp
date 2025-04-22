double power(double x, int n) 
{
    if (x == 0 && n == 0) 
    {
        return 1; 
    }
    double number = x;
    int times = n;
    if (n < 0) 
    {
        number = 1 / x;
        times = -n;
    }
    double result = 1;
    for (int i = 0; i < times; i++) 
    {
        result *= number;
    }
    return result;
}
