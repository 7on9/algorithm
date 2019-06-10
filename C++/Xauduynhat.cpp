#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
bool check[150];
int main()
{
    ios::sync_with_stdio(0);
    string S ;
    int d = 0,maxn = 1;
    cin >>  S;
    for(int j = 0; j < S.size();j++)
    for (int i = j; i < S.size(); i++)
    {
        if(!check[S[i]+0])
        {
            d++;
            check[S[i]+0] = true;
            if (d > maxn) maxn = d;
        }
        else
        {
            d = 0;
            memset(check, false,150);
            break;
        }
    }
    cout << maxn << endl;
    return 0;
}
