//liệt kê chuỗi hoán vị
#include <iostream>
#include <stdlib.h>
using namespace  std;
int x[10],t[10];
int n,i;
void prin()
{
    for (int i = 0; i < n; i++)
        cout << x[i];
    //memset(x, 0, sizeof(x));
    cout << endl;
}
void Attem(int i)
{
    if (i == n) prin();
    for (int j = 1; j <= n; j++)
    {
        if(t[j] != 1)// check số j đã xuất hiện chưa
        {
            //chưa xh -> gán
            x[i] = j;
            //gán số j đã xh
            t[j] = 1;
            //thực hiện gán cho đủ số yêu cầu
            Attem(i+1);
            //trả lại trạng thái số đó chưa xuất hiện trong chuỗi mới
            t[j]=0;
        }
    }
}
int main()
{
    cin >> n;
    long m =1;
    for (int i = 2; i <= n; i++)
        m *= i;
    cout << m<<endl;
    Attem(0);
    return 0;
}
