#include <iostream>
using namespace std;
int a,b;
int main()
{
    int A[4],B[4];
    cin >> A[0]>>A[1] >> A[2];
    cin >> B[0]>>B[1] >> B[2];
    for(int i = 0;i < 3; i++)
    {
        if(A[i] > B[i]) a++;
        if(A[i] < B[i]) b++;
    }
    cout << a << " " << b<<endl;
    return 0;
}
