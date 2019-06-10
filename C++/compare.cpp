#include <iostream>
using namespace std;
int A[28];
int main()
{
    freopen("out.out","r",stdin);
    for(int i = 0;i < 26;i++)
        cin >> A[i];
    freopen("out2.out","r",stdin);
    for(int i = 0;i < 26;i++)
    {
        int b;
        cin >> b;
        if(A[i] != b) cout << i << " " << A[i] << " " << b << endl;
    }
    return 0;
}