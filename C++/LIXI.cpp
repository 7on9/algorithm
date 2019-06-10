//struct So
//{
//    int x,y;
//} a[10];
//
//bool cmp(So xx,So yy)
//{
//    if(xx.y==yy.y) return(xx.x>yy.x); -> nếu đuôi bằng nhau sắp ưu tiên đầu lớn
//    return(xx.y>yy.y); -> sắp ưu tiên đuôi lớn
//}
//bool cmp(int x,int y)
//{
//    return (x>y);
//}
//sort(a,a+n,cmp);
#include <iostream>
#include <algorithm>
using namespace std;
struct LiXi
{
    int value;
    int more;
};
bool cmp(LiXi a,LiXi b)
{
    if (a.more == b.more) return (a.value > b.value);
    return (a.more > b.more);
}
int main()
{
    int n,more = 1,value = 0;
    LiXi Bao[110];
    cin >> n;
    for(int i = 0;i < n; i++)
        cin >> Bao[i].value >> Bao[i].more;
    sort(Bao, Bao+n, cmp);
    int i = -1;
    do
    {
        i++;
        more--;
        value += Bao[i].value;
        more += Bao[i].more;
    }while (i < n-1 && more > 0);
    cout << value;
    return 0;
}

