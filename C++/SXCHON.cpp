#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void swap(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
}
void print(int *B,int n,int i,int j)
{
    for (int a = 0; a < n; a++)
    {
        if(a == i || a == j)    cout << "[" << B[a] << "] " ;
        else cout << B[a] << " ";
    }
    cout << endl;
}
int main()
{
    int *B;
    //mảng A hàng đợi ưu tiên , top là phần tử bé nhất
    priority_queue<int, vector<int>, greater<int> > A;
    int n;
    cin >> n;
    //mảng B là mảng chính
    B = new int[n];
    //Nhập dữ liệu
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
        A.push(B[i]);
    }
    
    for (int i = 0; i < n-1; i++)
    {
        int j;
        //Tìm vị trí phần tử bé nhất trong B
        for ( j = i; j < n; j++)
            if(B[j]==A.top()) break;
        A.pop(); // loại bỏ phần tử bé nhất
        swap(B[i], B[j]); //đảo 2 vị trí
        print(B, n, i, j);
    }
    return 0;
}
