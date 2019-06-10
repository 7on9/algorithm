#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
//int check[10005];
int main()
{
    int n,k,d;
    cin >> n >> k;
    d= n - k;
    if(d == 0) cout << "1" <<endl;
    else
    {
        long long i=pow(10, n-k-1)*8 + pow(10, n-k);
        cout << i % 1000000007 << endl;
    }
    return 0;
}
//1.1.1.9.9
