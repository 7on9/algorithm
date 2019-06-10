#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
class Point
{
public:
    int x;
    int y;
    float distance;
    void cclDistance()
    {
        distance = sqrt(pow(x, 2)+pow(y, 2));
    }
};
int main()
{
    int n,k,*B;
    Point *P;
    cin >> n >> k;
    P = new Point[n];
    B = new int [n];
    for(int i = 0;i < n;i++)
        cin >> P[i].x;
    for(int i = 0;i < n;i++)
    {
        cin >> P[i].y;
        P[i].cclDistance();
        B[i] = ceil(P[i].distance);
    }
    sort(B,B+n);
    cout << B[k-1] <<endl;
    return 0;
}
