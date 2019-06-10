#include <iostream>
#include <string.h>
using namespace std;
int B[1002];
int n,q,k,as;
int answer(int A[],int n,int q,int as)
{
    int s=0;
    for(int i = 1; i <= n;i++)
    {
        B[i] = A[as+i];
        if(B[i] == 1)
        {
            B[i] += B[i-1];
            s = min(max(B[i],s),q);
        }
    }
    return s;
}
/*void move(int *A,int n)
{
    A -=1;
    A[0] = A[n-1];
}*/
int main()
{
    int d = 0;
    for(int i=97; i <= 122;i++)
        d+= i;
    cout << d << endl;
//    cin >> n >> q >> k;
//    int A[11];
//    as=k;
//    //memset(A, 0, n+k);
//    for (int i = 0; i < n; i++)
//        cin >> A[i+k];
//    string s;
//    cin >> s;
//    for(int i = 0;i < k;i++)
//    {
//        if(s[i] == '?')
//            cout << answer(A,n,q,as) << endl;
//        else
//        {
//            as --;
//            A[as] = A[as+n];
////            for (int j = 0; j < n; j++)
////                cout << A[j] << " " ;
////            cout<<endl;
//        }
//    }

    return 0;
}
