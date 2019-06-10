#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

void thirdPos()
{
    int n;
    cin >> n;
    vector <ll> a(n), b(n);
    vector <ll> sum;
    for(int i = 0;i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i < n; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            sum.push_back(a[i] + b[j]);
    sort(sum.begin(), sum.end());
//    for(int i = 0;i < n*n;i++)
//        cout << sum[i] << " ";
    cout << sum[2] << endl;
}
int main() {
    thirdPos();
    return 0;
}
