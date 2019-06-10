#include <iostream>
using namespace std;
class Point
{
    public :
    int x;
    int y;
    void getPoint(int a,int b)
    {
        x = a;
        y = b;
    }
};
class Vector
{
public:
    int x;
    int y;
    void getVectorPT(Point A,Point B)
    {
        y = -(B.x-A.x);
        x = B.y-A.y;
    }
};
void solve()
{
    Vector S;
    Point A,B;

}
int main()
{
    int T;
    cin >> T;
    while (T) {
        solve();
        T--;
    }
    return 0;
}
