#include <bits/stdc++.h>

using namespace std;

class Line
{
  public:
    double dx, dy, dz;
    double tx, ty, tz;
    double x;
    double y;
    double z;
};
void accepted()
{
    Line A, B, C;
    cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;

    Line vtcpBC;

    vtcpBC.x = (B.x - C.x);
    vtcpBC.y = (B.y - C.y);
    vtcpBC.z = (B.z - C.z);

    //H = lineBC
    Line lineBC;

    lineBC.dx = C.x;
    lineBC.dy = C.y;
    lineBC.dz = C.z;

    lineBC.tx = vtcpBC.x;
    lineBC.ty = vtcpBC.y;
    lineBC.tz = vtcpBC.z;

    // cout << vtcpBC.x << " " << vtcpBC.y << " " << vtcpBC.z << endl;

    Line vtcpA_BC;

    vtcpA_BC.dx = A.x - lineBC.dx;
    vtcpA_BC.dy = A.y - lineBC.dy;
    vtcpA_BC.dz = A.z - lineBC.dz;

    vtcpA_BC.tx = lineBC.tx;
    vtcpA_BC.ty = lineBC.ty;
    vtcpA_BC.tz = lineBC.tz;

    //cái này đang tính tích vô hướng
    double b = vtcpA_BC.dx * vtcpBC.x + vtcpA_BC.dy * vtcpBC.y + vtcpA_BC.dz * vtcpBC.z;
    double a = vtcpA_BC.tx * vtcpBC.x + vtcpA_BC.ty * vtcpBC.y + vtcpA_BC.tz * vtcpBC.z;

    // cout << a << " " << b << endl;
    double t = -b / (1.0 * a);

    double res = sqrt(pow(vtcpA_BC.tx * t + vtcpA_BC.dx, 2) + pow(vtcpA_BC.ty * t + vtcpA_BC.dy, 2) + pow(vtcpA_BC.tz * t + vtcpA_BC.dz, 2));

    cout << setprecision(2) << fixed << res << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        accepted();
    }
    // cout << "53976.34\n45196.79\n4108.63\n106105.99\n86042.72" << endl;
    return 0;
}

/*
// Cho tam giac ABC
// Gia su: a=BC, b=AC, c=AB
//         p la nua chu vi tam giac ABC
//         S la dien tich tam giac ABC
// Cong thuc Herong: S=sqrt(p*(p-a)*(p-b)*(p-c))
// Ve duong cao h=AH cua tam giac ABC, ta co:
//      S=1/2*BC*AH=1/2*a*h
//   => h=2*S/a
// h chinh la khoang cach tu A den BC

#include <bits/stdc++.h>
using namespace std;

int T;
double xa,ya,za,xb,yb,zb,xc,yc,zc;

double Dist(double xa,double ya,double za,double xb,double yb,double zb)
{
    return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)+(za-zb)*(za-zb));
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("01.in","r",stdin);
    freopen("01.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>xa>>ya>>za;
        cin>>xb>>yb>>zb;
        cin>>xc>>yc>>zc;
        double c=Dist(xa,ya,za,xb,yb,zb);
        double b=Dist(xa,ya,za,xc,yc,zc);
        double a=Dist(xc,yc,zc,xb,yb,zb);
        double p=(a+b+c)/2.0;
        double S=sqrt(p*(p-a))*sqrt((p-b)*(p-c));
        double h=2.0*S/a;
        cout<<setprecision(2)<<fixed<<h<<'\n';
    }
}
*/