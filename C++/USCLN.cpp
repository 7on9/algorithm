#include <iostream>
long UCLN(long x, long y)
{
    if(x > y)
    {
        long long temp=x;
        x = y;
        y = temp;
    }
    long r = y%x;
    while(r != 0)
    {
        y = x;
        x = r;
        r = y%x;
    }
    return x;
}
int main()
{
    long a,b;
    std::cin >> a >> b;
    std::cout << UCLN(a, b)<<std:: endl;
    return 0;
}
