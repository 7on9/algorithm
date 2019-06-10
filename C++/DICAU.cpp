// #include <iostream>
// #include <string>
// #include <math.h>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;
int t,res= 0;
class Point
{
public:
    int x;
    int y;
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
int main()
{
    Point *S, *E;
    Point *need;
    vector<int> dong, tay, nam,bac;
    string s;
    int t, res;
    S = new Point();
    E = new Point();
    cin  >> t >> S->x >> S->y >> E->x >> E->y;
    cin >> s;
    int len = s.size();
    need = new Point(E->x - S->x,E->y - S->y);
    dong.push_back(0);
    tay.push_back(0);
    nam.push_back(0);
    bac.push_back(0);
    for(int i = 0;i < len; i++)
    {
        switch (s[i]) {
            case 'E':
                dong.push_back(i+1);
                break;
            case 'S':
                nam.push_back(i+1);
                break;
            case 'W':
                tay.push_back(i+1);
                break;
            case 'N':
                bac.push_back(i+1);
                break;
        }
    }
    res = 0;
    if(abs(need->x) <= dong.size() && dong.size() > 1 && need->x >=0)
        res = max(res, dong[abs(need->x)]);
    if(abs(need->x) <= tay.size() && tay.size() > 1&& need->x <= 0)
        res = max(res, tay[abs(need->x)]);
    if(abs(need->y) <= nam.size() && nam.size() > 1&& need->y <= 0)
        res = max(res, nam[abs(need->y)]);
    if(abs(need->y) <= bac.size() && bac.size() > 1&& need->y >= 0)
        res = max(res, bac[abs(need->y)]);
    if(res !=0 && res <= t)
        cout << res << endl;
    else    cout << -1 << endl;
    return 0;
}
