#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n,d = 0;
    int *A;
    cin >> n;
    A=new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i+=2)
    {
        cin >> A[i];
    free(A);
    return 0;
}
