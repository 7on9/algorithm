
#include <iostream>
#include <string>
using namespace  std;
char toUpper(char c)
{
    if(c >= 'a' && c <= 'z') return c-32;
    return c;
}
char toLower(char c)
{
    if(c >= 'A' && c <= 'Z') return c+32;
    return c;
}

void solve()
{
    string S,S1,S2;
    getline(cin,S1);
    S = " ";
    S += S1;
    int len = S.size() ;
    int d = 0;
    for (int i  = 1; i < len; i++)
    {
        if(S[i-1] == ' ' && S[i] != ' ')
        {
            S[i] = toUpper(S[i]);
            d++;
        }
        else S[i] = toLower(S[i]);
    }
    for (int i  = 1; i < len; i++)
    {
        if(d >= 1)
        {
            if(S[i] >= 'A' && S[i] <= 'Z')
            {
                d--;
                S2+=S[i];
                if(d > 0)
                    S2 +=". ";
            }
        }
        else if(d == 0)
            S2+=S[i];
    }
    cout << S2 << endl;
}
int main()
{
    string S;
    int T;
    cin >> T;
    for (; T >=0; T--) {
        solve();
    }
    return 0;
}
