#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int x[540000];
int m,n,i;
void out()
{
    for (int i = 0; i < n; i++)
        cout << x[i];
    cout << endl;
}
void Attem(int i)
{
    for(int j = 1;j <= m;j++)
    {
        x[i] = j;
        if (i == n-1) out();
        else Attem(i+1);
    }
}
int main()
{
    cin >> m >> n;
    cout << pow(m, n) << endl;
    Attem(0);
    return  0 ;
}
