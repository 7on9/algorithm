#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
void solve()
{
    int a,b,c;
    long long *SA,*SB,*SC;
    cin >> a >> b >> c;
    SA = new long long [a+1];
    SB = new long long [b+1];
    SC = new long long [c+1];
    multiset<int> A,B,C;
    for(int i = 1;i <= a; i++)
    {
        int m;
        cin >> m;
        A.insert(m);
    }
    int j =1;
    SA[0] = SC[0] = SB[0] = 0;
    for (multiset<int>::iterator i = A.begin(); i !=A.end(); i++,j++) {
        SA[j] = SA[j-1] + *i;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t) {
        t--;
        
    }
    return 0;
}
