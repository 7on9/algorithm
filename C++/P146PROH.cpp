//
//sàng nguyên tố
//#include <bits/stdc++.h>

#include <iostream>
#include <Math.h>
using namespace std;

void SangNT(int N[],int length)
{
    int t = 1;
    for(int i = 2;i <= length;i++)
        if(N[i] != 1)
        {
            for (int j = 2; i*j <= length; j++)
                N[i*j] = 1;
            t++;
            N[i] = t;
        }
}
int KhoangCachSNT(int N[],int dau,int cuoi,int k)
{
    int length = 0;
    for(int i = dau;i < cuoi; i++)
    {
        for(int j = i+1;j <= cuoi; j++)
            if(N[j]-N[i]+1 == k && j - i  > length) length = j - i;
    }
    return length;
}
int main()
{
    int a,b,k,x ,l = 0 ,d;
    int N[1000003]= {};
    cin >> a >> b >> k;
    SangNT(N,b+b-a + 1);
    //l la kc it nhat de co k so nguyen to
    for(int dau = a ; dau <= b; dau++)
    {
        if(N[dau] != 1 && a > 1)
        {
            int cuoi = b;
            int sl = 0;
            do
            {
                for(;;cuoi++)
                    if (N[cuoi] != 1) break;
                //tìm SNT gần nhất
                sl = N[cuoi] - N[dau] + 1;
            }while (sl < k);
            int length = KhoangCachSNT(N, dau, cuoi, k);
            if(l < length) l = length;
        }
    }
    if (l == 0) l = -1;
    else if(N[b + l] == 1) l++;
    cout << l;
    return 1;
}
