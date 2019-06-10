#include <iostream>
using namespace std;
class Point
{
public:
    float x;
    float y;
    Point midPoint(Point a,Point b)
    {
        Point o;
        o.x = (a.x+b.x)*1.0/2;
        o.y = (a.y+b.y)*1.0/2;
        return o;
    }
};

class Vector
{
public:
    int x;
    int y;
    void getVector(Point a,Point b)
    {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    int multiVector(Vector ab,Vector ac)
    {
        return (ab.x*ac.x + ab.y*ac.y);
    }
};
int cacul(float a ,float b)
{
    return b*2-a;
}
Point solve(Point A,Point B,Point C)
{
    Point D;
    Point o;
    o = o.midPoint(A,C);
    D.x = cacul(B.x, o.x);
    D.y = cacul(B.y, o.y);
    return D;
}
int main()
{
    Point a,b,c,d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    Vector ac,bc,ab;
    ac.getVector(a, c);
    bc.getVector(b, c);
    ab.getVector(b, a);
    if(ac.multiVector(ac, bc) == 0) d= solve(a,c,b);
        else
            if(ac.multiVector(bc, ab) == 0)
                d = solve(a,b,c);
            else d = solve(b,a,c);
    cout << d.x << " " << d.y << endl;
    return 0;
}
