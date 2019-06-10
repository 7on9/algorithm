//tìm dãy ngoặc đúng có n ngoặc
#include <iostream>
using namespace std;
int n,A[30],dem,s,e;
void print()
{
    dem++;
    for (int i = 0; i < n; i++)
        if(A[i] == -1) cout << "(";
        else cout << ")";
    cout << endl;
}
void Attem(int i)
{
    for(int j = -1;j <= 1; j+=2)
    {
        A[i] = j;
        if(j == 1) e++;
        else s++;
        //if(s == e && i == n-1)
        if(s <= n/2 && e <= s)
            if(i == n-1) print();
            else Attem(i+1);
        if(A[i] == -1) s--; else e--;
    }
}
int main()
{
    cin >> n;
    Attem(0);
    cout << dem;
    return 0;
}
