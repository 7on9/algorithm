#include <iostream>
#include <Math.h>
using namespace std;
const float Pi  = 3.14159;
class Point
{
public:
    float x;
    float y;
    Point()
    {
    };
    Point(float px,float py)
    {
        x = px;
        y = py;
    }
    ~Point()
    {
        
    };
    //Nhập điểm
    void getPoint()
    {
        cout << "\tNhap x : ";
        cin >> x;
        cout << "\tNhap y : ";
        cin >> y;
    }
    //In điểm
    void outPoint(int summit)
    {
        cout <<"Dinh thu " << summit << ":" << endl;
        cout << "\tx = "<< x <<"\ty = "<< y << endl;
    }
    
};
class Polygon
{
public:
    Point point[100];
    //Constructor
    Polygon(int numOfSummit)
    {
        for(int i = 1;i <= numOfSummit; i++)
        {
            cout << "Dinh thu " << i << ":" << endl;
            point[i].getPoint();
        }
    };
    //Xuất đa giác
    void out(int numOfSummit)
    {
        cout << "Da giac gom "<< numOfSummit <<" dinh :"<< endl;
        for(int i = 1;i <= numOfSummit; i++)
            this -> point[i].outPoint(i);
    }
    //dich chuyển tịnh tiến
    void move(Point vector,int numOfSummit)
    {
        for(int i = 1;i <= numOfSummit; i++)
        {
            point[i].x += vector.x;
            point[i].y += vector.y;
        }
        cout << "Da tinh tien theo vector !" << endl;
    }
    //Quay theo tâm O góc a
    void rotate(int numOfSummit, float degree)
    {
        double rad = (degree * Pi) / 180 ;
        for(int i = 1;i <= numOfSummit; i++)
        {
            point[i].x = (point[i].x * cos(rad)) - (point[i].y * sin(rad));
            point[i].y = (point[i].x * sin(rad)) + (point[i].y * cos(rad));
        }
    }
};
//Hàm nhập
void INPUT(int &numOfSummit)
{
    cout << "Nhap so dinh da giac : ";
    cin >> numOfSummit;
}
//Hàm xuất
void OUTPUT(Polygon polygon,int numOfSummit)
{
    polygon.out(numOfSummit);
}
//Gọi Hàm tịnh tiến
void move(Polygon &polygon,int numOfSummit)
{
    cout << "Nhap vector tinh tien : " << endl;
    Point vector;
    vector.getPoint();
    polygon.move(vector, numOfSummit);
}
void rotate(Polygon &polygon,int numOfSummit)
{
    cout << "Nhap goc quay : " ;
    float degree;
    cin >> degree;
    polygon.rotate(numOfSummit, degree);
}
int main()
{
    int numOfSummit;
    //Nhập
    INPUT(numOfSummit);
    Polygon polygon(numOfSummit);
    //Xuất
    OUTPUT(polygon, numOfSummit);
    //Tịnh Tiến
    move(polygon,numOfSummit);
    OUTPUT(polygon, numOfSummit);
    //Quay
    rotate(polygon, numOfSummit);
    OUTPUT(polygon, numOfSummit);
}
