//tìm ô giống nhau + binary search
#include <iostream>
#include <algorithm>

using namespace std;
int find(int *N,int left,int right,int a)
{
    if(left > right) return -1;
    int mid = (right+left)/2;
    if(N[mid] == a) return mid;
    if(N[mid] > a) return find(N,left,mid-1,a);
    if(N[mid] < a) return find(N,mid+1,right,a);
    return -1;
}
void in(int *N,int n)
{
    for(int i = 0; i < n-1;i++ )
        cin >> N[n-i-1];
    for(int i = 1; i < n;i++ )
        N[i] += N[i-1];
}
int search(int *N1,int n1,int *N2,int n2,int *N3,int n3)
{
    for(int i = n1-1;i >= 0; i--)
    {
        if(N1[i]==N2[find(N2,0,n2,N1[i])] && N1[i]==N3[find(N3,0,n3,N1[i])])
            return N1[i];
    }
    return 0;
}
int main()
{
    int n1;
    int n2;
    int n3;
    int *N1,*N2,*N3;
    cin >> n1 >> n2 >> n3;
    N1 = new int[++n1];
    N2 = new int[++n2];
    N3 = new int[++n3];
    in(N1,n1);
    in(N2,n2);
    in(N3,n3);
    cout << search(N1,n1,N2,n2,N3,n3)<<endl;
    return 0;
}
