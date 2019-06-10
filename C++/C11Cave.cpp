#include <iostream>
#include <algorithm>
#include <math.h>
#define MAX 1000000002
#define ar 500001
using namespace std;
long long H[ar+1],posmin = ar;
int main()
{
    int n,h,c;
    cin >> n >> h;
    for(int i = 1;i <= n;i++)
        {
            cin >> c;
            if(i%2) //mang
            {
                H[1]++;
                H[c+1]--;
            }
            else //nhu
                H[h-c+1]++;
        }
    c = 0;
    H[ar] = MAX;
    for(int i = 1;i <= h;i++)
    {
        H[i] += H[i-1];
        if(H[posmin] > H[i])
            posmin = i;
    }
    for (int i = 1; i <= h; i++)
        if(H[i] == H[posmin]) c++;
    cout << H[posmin] << " " << c << endl;
    return 0;
}
