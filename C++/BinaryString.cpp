#include <iostream>
using namespace std;
int sumdigit(long long n)
{
    int sum = 0;
    while(n)
    {
        sum += (n%2);
        n /= 2;
    }
    sum += n;
    return sum;
}
int main()
{
    long long n;
    cin >> n;
    cout << sumdigit(n)%2 << sumdigit(n+1)%2 << sumdigit(n+2)%2 << endl;
    return 0;
}