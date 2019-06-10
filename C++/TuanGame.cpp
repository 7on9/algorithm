#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n ;
    cin >> n;
    int *A = new int[n];
    int minchange = 10e9;
    for(int i = 0;i < n;i++)
        {
            cin >> A[i];
            if(A[i] < A[i-1]) minchange = min(minchange,A[i]);
        }
    
    return 0;
}