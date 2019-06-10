#include<iostream>
#include <string.h>
using namespace std;
bool solve(string S)
{
    for (int i = 1; i < S.size(); i++)
    {
        if(S[i] < S[i-1]) return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    string S[n];
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (solve(S[i])) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
