#include <iostream>

using namespace std;
int gt(int n)
{
    int a = 1;
    for(int i = 2;i <= n ;i++)
        a *= i;
    return a;
}
int C(int n,int k)
{
    return (gt(n)/((gt(k)*gt(n-k))));
}

int main ()
{
//    string x , y ,z;
//    cin >> x >> y;
//    int i ,j = 0;
//    while (i < x.size() || j < y.size())
//    {
//        if(x[i] >= y[j] && (x[i]>='0' && x[i] <= '9'))
//        {
//            z += x[i];
//            i++;
//        }
//        else
//        {
//            z += y[j];
//            j++;
//        }
//        if(i == x.size())
//        {
//            do
//            {
//                z += y[j];
//                j++;
//            } while (j < y.size());
//            break;
//        }
//        if(j == y.size())
//        {
//            do
//            {
//                z += x[i];
//                i++;
//            } while (i < x.size());
//            break;
//        }
//    }
//    i = j = 0;
//    string z2;
//    while (i < x.size() || j < y.size())
//    {
//        if(x[i] <= y[j] &&(x[i]>='0' && x[i] <= '9'))
//        {
//            z2 += x[i];
//            i++;
//        }
//        else
//        {
//            z2 += y[j];
//            j++;
//        }
//        if(i == x.size())
//        {
//            do
//            {
//                z2 += y[j];
//                j++;
//            } while (j < y.size());
//            break;
//        }
//        if(j == y.size())
//        {
//            do
//            {
//                z2 += x[i];
//                i++;
//            } while (i < x.size());
//            break;
//        }
//
//    }
//    cout << z2 << endl;
//    cout << z << endl;
    // DISTANCE
    int n, m,x,y;
    int road[100005] = {};
    cin >> n >> m;
    for(int i = 1 ;i <= m; i++ )
    {
        cin >> x >> y;
        if(x != y)
        {
            road[x]++;
            road[y]++;
        }
    }
    int d = 0;
    for(int i = 1 ;i <= n; i++ )
        if(road[i] > 1) d += C(road[i],2);
    cout << d;
    return 0;
}
