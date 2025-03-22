#include <vector>
std::vector<int>FactorsTest(int n)
{
    std::vector<int>factors;
    int num=2;
    while(n>1)
    {
        
        while(n % num == 0)
       
        {
            factors.push_back(num);
            n/=num; 
        }
      num++;
     }
        
    return factors;
}