//Robot có hợp lệ sau khi đi
#include <iostream>
#include <stdlib.h>
using namespace std;
int n,m,t;
bool solve(string s)
{
    int x = 1,y = 1;
    for(int i = 0;i < s.size(); i++)
    {
        switch (s[i])
        {
            case 'U': y++;
                break;
            case 'D': y--;
                break;
            case 'L': x--;
                break;
            case 'R': x++;
        }
        if(x == 0)  x = -2;
        if(y == 0) y = -2;
        if(m < abs(x) || n < abs(y)) return false;
    }
    return true;
}
int main()
{
    string s;
    cin >> t;
    for(int i = 0 ; i < t; i++)
    {
        cin >> n >> m;
        cin >> s;
        if(solve(s)) cout <<"safe"<< endl;
        else cout << "unsafe" <<endl;
    }
    return 0;
}
