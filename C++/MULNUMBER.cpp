#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main()
{
//    string X,Y;
//    int *S;
//    cin >> X >> Y;
//    int lenx = X.size();
//    int leny = Y.size();
//    S = new int[lenx+leny];
//    for (int i = 0; i < lenx+ leny; i++)
//        S[i] = 0;
//    int s = 0 ,pos=0 ;
//    for(int y = 0,s=0; y < leny ;y++,s++)
//    {
//        int p = s-1;
//        for (int x = 0; x < lenx; x++)
//        {
//            p++;
//            S[p] += (X[x]-'0')*(Y[y]-'0');
//        }
//    }
//    for (s=leny+lenx-1; s > 0; s--)
//    {
//        S[s-1] += S[s] / 10;
//        S[s] %= 10;
//    }
//    for (s= 0; s <= leny+lenx-2; s++)
//        cout << S[s];
//    cout << endl;
    int s= 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < 4; ++j) {
            s+=3;
        }
    }
    cout << s << endl;
    return 0;
}
