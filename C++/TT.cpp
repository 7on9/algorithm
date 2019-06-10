//chia tiền
#include <iostream>
#include <algorithm>
using namespace std;
int n,A;
int bag[21],bag2[21],have,money[501];
int own[501][2];
int binsearch(int left,int right,int need)
{
    if (left > right) return -1;
    int mid = (left+right)/2;
    if (bag[mid] == need) return mid;
    if (need > bag[mid]) return binsearch(mid+1, right, need);
    return binsearch(left, mid - 1, need);
}
void solve(int i)
{
    if (A == n/2) return;
    A += bag[i];
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> bag[i];
        bag2[i]= bag[i];
        money[bag[i]]++;
        have += bag[i];
    }
    if (have%2 != 0 || have == 0)
    {
        cout << "khong chia duoc" << endl;
        return 0;
    }
    sort(bag, bag+n+1);
    for (int j = 0; j < n;j++)
    {
        solve(j);
    }
    return 0;
}
