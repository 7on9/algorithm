//phân tích số
#include <iostream>
#include <math.h>
using namespace std;
bool check[100005];
void phanTich(long in,long A[],long &d)
{
    long tich;
    if (check[in]) return;
    check[in] = true;
    for(int i = 1 ; i <=sqrt(in);i++)
    {
        if(in%i == 0)
        {
            tich = (i-1)*(in/i+1);
            if(tich != 0)
            {
                A[tich]++;
                if(A[tich]== 1) d++;
                phanTich(tich, A, d);
            }
            //else phanTich(tich, A,d);
        }

    }
}
int main()
{
    long n,A[100005] = {},d = 0;
    cin >> n;
    phanTich(n, A,d);
    cout << d+1 << endl ;
    cout << "0 " ;
    for(long i = 0;i <= n;i++)
        if(A[i] != 0)
            cout << i << " ";
    return 0;
}
