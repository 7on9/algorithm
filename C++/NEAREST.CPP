//tìm 2 điểm gần nhau nhất trong mặt phẳng
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <algorithm>
#define MAX 100005
#define oo 1e9
using namespace std;
typedef pair<double, double> point;
typedef pair<double, int> rec;
int n;
point *arr;
set <rec> T;
void getData()
{
	cin >> n;
	arr = new point[n];
	for (int i = 0;i < n; i++)
		cin >> arr[i].first >> arr[i].second;
}
double mu2(double a)
{
    return a*a;
}
double distance(const point &a,  const point &b)
{
    return sqrt(mu2(a.first - b.first) + mu2(a.second - b.second));
}
void solve()
{
    sort(arr, arr + n);
    double ans = oo;
    for(int i = 0, j = 0; i < n; i++)
    {
        while(arr[i].first - arr[j].first > ans)
        {
            T.erase(T.find(make_pair(arr[j].second, j)));
            j++;     
        }
        set<rec> :: iterator it = T.lower_bound(make_pair(arr[i].second - ans, 0));
        set<rec> :: iterator ed = T.upper_bound(make_pair(arr[i].second + ans, 0));
        while (it != ed) 
        {
            ans = min(ans, distance(arr[i], arr[it->second]));
            it++;
        }
        T.insert(make_pair(arr[i].second, i));
    }
	printf("%.3lf", ans);
}
int main()
{
    ios_base :: sync_with_stdio(0); 
    cin.tie(0);
    getData();
    solve();
    return 0;
}
