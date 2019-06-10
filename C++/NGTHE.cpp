#include <iostream>
using namespace std;
int a[100001],n,t[100001];
//mang a luu gia tri, mang t luu cac cap nghich the tai cac node cha
int getBIT(int m)
{
    int result = 0;
    for(; m> 0; m &= m-1)
        result += t[m];
    return result;
    //tra ve tong so cap nghich the tuong ung voi node thu m
}
void updateBIT(int m, int value)
{
    for(; m <= 100000; m += m & -m)
        t[m] += value;
}
int main()
{
    int i;
    long long kq;
    cin>>n;
    for(i= 1; i<= n; i++)
        cin>>a[i];
    kq = 0;
    for(i= n; i >= 1; i--)
    {
        kq += getBIT(a[i]); //tong cac cap nghich the tren cay
        updateBIT(a[i]+1, 1); //update cac cha cua no
    }
    cout<<kq<<endl;
    return 0;
}
