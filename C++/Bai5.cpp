#include <iostream>
#include <math.h>
using namespace std;
int Loc(int A[],int n,int m,int &c)
{
    for(int i = 1;i <= m ;i++)
    {
        
    }
    
    return c;
}
int main()
{
    int n,m,A[300],c=0;
    cin >> n  >> m;
    for(int i = 1;i <= m;i++)
        cin >> A[i];
    for(int i = 1;i <= m;i++)
    {
        int sd = n % A[i];
        if(sd == 0) c++;
        for(int j = 1;j <= n / A[j];j++)
            for(int k = i+1; k <= m; k++)
            {
                if(A[k] == n-A[i]*j) c++;
            }
    }
    cout << c ;
    return 0;
}
