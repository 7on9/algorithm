//Dịch chuyển số học bên trái n lần tương đương nhân với 2^n
//vd : 3 << 8 = 3x2^8
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#define limit 30000
using namespace std;
class Vector
{
public:
    int x, y;
    Vector()
    {
        this->x = 0;
        this->y = 0;
    }
    void reset()
    {
        this->x = 0;
        this->y = 0;
    }
    void getData(Vector i)
    {
        this->x = i.x;
        this->y = i.y;
    }
    void add(Vector i)
    {
        this->x += i.x;
        this->y += i.y;   
    }
    void sub(Vector i)
    {
        this->x -= i.x;
        this->y -= i.y;   
    }
};
struct cmp
{
    bool operator()(const Vector &x, const Vector & y) const
    {if(x.x == y.x)return x.y < y.y;
        return x.x < y.x;}
};

int n;
bool isEqual(Vector U, Vector V)
{
    if((V. x == U.x) && (U.y == V.y))
        return true;
    return false;
}
bool isSmaller(Vector U, Vector V)
{
    if((U.x <= V.x) && (U.y <= V.y))
        return true;
    return false;
}
Vector U;
Vector *Temp = new Vector();
int caculateNormal(Vector vector[])
{
    int dem = 0;
    for (int b = 0; b < (1 << n); ++b) //b < 2^n
    {
        Vector *S = new Vector();
        for (int i = 0; i < n; ++i)
            if ((b & (1 << i)) != 0)
                S->add(vector[i]);
        if (isEqual(*S, U))
            ++dem;
    }
    return dem;
}
int caculateNew(Vector vector[])
{
    Vector temp;
    int dem = 0;
    int lengthSet = n/2;
    map<Vector, int, cmp> mapVector;
    for (int b = 0; b < (1 << lengthSet); ++b)
    {
        Vector *S = new Vector();
        for (int i = 0; i < lengthSet; ++i)
            if ((b & (1 << i)) != 0)
                S->add(vector[i]);
        mapVector[*S]++;
    }
    lengthSet = n - lengthSet;
    for (int b = 0; b < (1 << lengthSet); ++b)
    {
        Vector *S = new Vector();
        for (int i = 0; i < lengthSet; ++i)
            if ((b & (1 << i)) != 0)
                S->add(vector[n - 1 - i]);
        temp.getData(U);
        temp.sub(*S);
        dem += mapVector[temp];
    }
    return dem;
}
void getData(Vector vector[])
{
    cin >> n ;
    for (int i=0; i < n; i++)
        cin >> vector[i].x >> vector[i].y;
    cin >> U.x >> U.y;
    if(abs(U.x) > limit || abs(U.y) > limit)
    {
        cout << "0" << endl;
        exit(0);
    }
}
int main()
{
    Vector vector[33];
    getData(vector);
    if(n <= 15)
        cout << caculateNormal(vector) << endl;
    else    
    cout << caculateNew(vector) << endl;
    return 0;
}
