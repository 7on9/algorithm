#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    int a[16];
    a[0] = 2;
    for(int i = 1; i <= x; i++) 
    {
      a[i] = a[i - 1] + a[i - 1] - 1;
    }
    cout << a[x] * a[x];
    return 0;
}

