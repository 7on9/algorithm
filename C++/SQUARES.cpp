#include <iostream>
#include <stdlib.h>
#define MAX 1000000007
using namespace std;
long mu(int a,int n)
{
    if(n == 0 || (n == 0 && a== 0)) return 1;
    long t = mu(a, n/2);
    if(n%2 == 0) return (t*t)%MAX;
    return (a*t*t)%MAX;
}
int main()
{
    int n,l;
    cin >> n >> l;
    cout << ((mu(4,0)-mu(4, l+1))*l/-3)%MAX <<endl;
    return 0;
}
