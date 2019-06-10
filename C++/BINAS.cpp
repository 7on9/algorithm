//Liệt kê dãy nhị phân
#include <iostream>
using namespace std;
int n,A[21],res;
void Attem(int i)
{
    for(int j = 0; j <= 1; j++)
    {
        A[i] = j;
        if(i == n-1)
        {
            for(int k = 0; k < n; k++)
                cout << A[k];
            cout << endl;
        }
        else Attem(i+1);
    }
}
int main()
{
    cin >> n;
    Attem(0);
    return 0;
}
