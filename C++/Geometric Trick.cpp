#include <iostream>
//#include <bits/stdc++.h>

using namespace std;
int d;
int BinarySearch(int a[], int N, int x)
{
    int left = 0, right = N - 1;
    int mid;
    do
    {
        mid = (left + right) / 2;
        if (x == a[mid])
            return mid;
        else
            if (x < a[mid])
                right = mid - 1;
            else
                left = mid + 1;
    } while (left <= right);
    
    return -1;
}
int geometricTrick(string s,int *A,int *B,int *C,int a,int b,int c){
    //cout << "fdfsdfaf" << endl;
    for(int i = 0;i < a;i++)
        for(int j = 0;j < b;j++)
        {
            int q = ((B[j]*B[j] +2*B[j] -A[i])/(A[i]+1));
            //cout << q << endl;
            if(((B[j]*B[j] +2*B[j] -A[i] *1.0)/(A[i]+1))==q)
                if(BinarySearch(C,c,q)!= -1) d++;
        }
    return d;
}

int main() {
    int n;
    cin >> n;
    int *A,*B,*C;
    A = new int[n];
    B = new int[n];
    C = new int[n];
    string s;
    int a=-1,b=-1,c=-1;
    for(int i=0;i<n;i++)
    {
        char cha;
        cin >> cha;
        s+=cha;
        if (cha=='a')
        {
            a++;
            A[a] = i;
        }
        else
            if (cha=='b')
            {
                b++;
                B[b] = i;
            }
            else
            {
                c++;
                C[c] = i;
            }
    }
    //cout << s <<endl;
    if(a >= 0&& b>=0 &&c>=0)
        cout << geometricTrick(s,A,B,C,++a,++b,++c) << endl;
    else cout << "0" << endl;
    return 0;
}
