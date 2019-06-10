#include <iostream>
#include <algorithm>
using namespace std;
long long remin(long long a,long long b)
{
    if(a < b) return a;
    return b;
}
int main() {
    long long A[200006], N, i, T, T_min, V;
    
    cin >> N;
    for (i = 0; i < N; ++i)
        cin >> A[i];
    
    T = V = A[0];
    T_min = remin(0, T);
    for (i = 1; i < N; ++i)
    {
        T += A[i];
        if (T - T_min > V)
            V = T - T_min;
        if (T < T_min)
            T_min = T;
    }
    
    cout << V << endl;
    return 0;
}
