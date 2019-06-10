//2 con rắn giống nhau
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Point
{
public:
    int x;
    int y;
};
bool cmpPoint(Point a,Point b)
{
    if(a.x == b.x && a.y == b.y) return true;
    return false;
}
bool isSameSnake(Point a,Point b,Point c,Point d)
{
    if(cmpPoint(a, c) || cmpPoint(a, d) || cmpPoint(b, d)||cmpPoint(b, c)) return true;
    else
    {
        int A[3],B[3];
        if (a.x == b.x && b.x == c.x && c.x == d.x) {
            A[0] = a.y;
            A[1] = b.y;
            B[0] = c.y;
            B[1] = d.y;
            sort(A, A+2);
            sort(B, B+2);
            if((A[0] >= B[0] && A[0] <= B[1])||(A[0] <= B[0] && A[1] >= B[0])) return true;
        }
        else
            if (a.y == b.y && b.y == c.y && c.y == d.y)
        {
            A[0] = a.x;
            A[1] = b.x;
            B[0] = c.x;
            B[1] = d.x;
            sort(A, A+2);
            sort(B, B+2);
            if((A[0] >= B[0] && A[0] <= B[1])||(A[0] <= B[0] && A[1] >= B[0])) return true;
        }
        
    }
    return false;
}
void solve()
{
    Point a,b,c,d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >>c.x >> c.y >> d.x >> d.y;
    if(isSameSnake(a,b,c,d)) cout << "yes" <<endl;
    else cout << "no" << endl;
}
int main()
{
    int T;
    cin >> T;
    for(;T>0; T--)
        solve();
    return 0;
}
