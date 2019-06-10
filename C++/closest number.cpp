//tìm 2 số có khoảng cách ngắn nhất

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int *A,*B,n;
    cin >> n;
    A =  new int[n];
    B = new int [n];
    for(int i = 0;i < n;i++)
        cin >> A[i];
    sort(A,A+n);
    int minn;
    B[0] = minn = abs(A[0]);
    for(int i = 1;i < n;i++)
    {
        B[i] = abs(A[i]-A[i-1]);
        minn = min(minn,B[i]);
    }
    for(int i = 1;i < n;i++)
        if(B[i]==minn)
            cout << A[i-1] << " " << A[i] << " ";
    cout << endl;
    return 0;
}
