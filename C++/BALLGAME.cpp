#include <iostream>
#include <algorithm>
#include <math.h>
#define mod 1000000007;

using namespace std;
unsigned long long P(unsigned long long a,unsigned long long n)
{
    if(n == a)  return 1;
    return a*P(a, a-1);
}
unsigned long long power(unsigned long long a,unsigned long long n)
{
    if(n == 0) return 1;
    return a*power(a, n-1) % mod ;
}
int  main ()
{
    unsigned long long  m , n ,k;
    cin >> m >> n >> k;    //cout << C(4*k,n) << C(4*k+n -1,n) << endl;
    
    cout << P(4,3);
    return 0;
}
