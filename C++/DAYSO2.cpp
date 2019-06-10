//tìm 3n phần tử max 
#include <iostream>
using namespace std;
long long A[100001], F[100001];
//long long sum;
int main()
{
    ios::sync_with_stdio(0);
    int  n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        //F[i] = F[i-1] + A[i];
    }
    //F[] = F[1] =
    F[3] = A[1]+ A[2] + A[3];
    //tính điểm khởi tạo dầu tiên có 3 phần tử
    long long maxn = F[3];
    for (int i = 4; i <= n; i++)
    {
        F[i] = max(A[i]+A[i-1]+A[i-2], F[i-3] + A[i-1] + A[i-2] + A[i]);
        //so sánh tổng 3 phần tử liền kề và tổng 3n phần tử trước nó
        if (F[i] >= maxn) maxn =F[i];
    }
    cout << maxn << endl;
    return 0;
}
