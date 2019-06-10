//số đoạn con có trong dãy
#include <set>
#include <cstdio>
#include <string>

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n;
    multiset <string> S;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        S.insert(s);
    }
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        cout << S.count(s) << endl;
    }

    //gets(S);
    return 0;
}
