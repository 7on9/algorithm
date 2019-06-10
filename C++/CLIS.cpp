#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string S;
    int A[201] = {};
    int B[201] = {};
    cin >> S;
    int len = S.size();
    for(int i = 0;i<len;i++)
    {
        int res = i;
        for(int j = i;j<len;j++)
            if(S[j] >= S[res])
            {
                A[i]++;
                res = j;
            }
        A[i] = max(A[i-1],A[i]);
    }
    for(int i = len-1;i>=0;i--)
    {
        int res = i;
        for(int j = i;j>=0;j--)
            if(S[j] < S[res])
            {
                B[i]++;
                res = j;
            }
        B[i] = max(B[i+1],B[i]);
        A[i] = max(B[i],A[i]);
    }
    cout << A[len-1]  << endl;
    return 0;
}
//111222333465443
