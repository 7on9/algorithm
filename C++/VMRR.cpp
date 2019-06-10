#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
//    char *S = nullptr;
//    gets(S);
    string S,X;
    getline(cin,S);
    char x,y;
    long long d =0;
    int cx=0;
    getline(cin, X);
    x = X[0];
    y = X[1];
    for (int i = 0; i < S.size(); i++)
    {
        //char r = S[i];
        if(S[i] == x)
            cx++;
        if(S[i] == y)
            d += cx;
    }
    if(x==y) d-=cx;
    cout << d << endl;
    return 0;
}
