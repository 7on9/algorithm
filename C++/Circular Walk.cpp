#include <iostream>
#include <stdlib.h>
using namespace std;
int t;
void solve(int *check,int i,int F[],int S[],int n)
{
    if(check[i] == 1) return;
    check[i] = 1;
    
}
int main()
{
    int n,s,p,seed;
    int jean,jb;
    cin >> n >> jean >> jb;
    int R[10],F[10];
    int *check;
    check = new int[n];
    cin >> R[0] >> s >> seed >> p;
    if(jean==jb)
    {
        cout << "0" << endl;
        return 0;
    }
    F[0] = min(jb,abs(n-jb));
    for(int i = 1;i < n;i++)
    {
        R[i] = (R[i-1]*s + seed) % p;
        F[i] = min(abs(jb-i),abs(n-i+jb));
    }
    if(
    return 0;
}
