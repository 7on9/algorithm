#include <iostream>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
int mapHCM[5005][5005];
ll n, numOfVlt, maxVlt;
//bool visited[505][505];
map <ll, ll> vlt;
typedef pair<int, int> hole;
void dfs(hole a)
{
    if(mapHCM[a.first][a.second])
    {
        vlt[numOfVlt]++;
        mapHCM[a.first][a.second] = 0;
        for(int i = 1; i <= 4; i++)
        {
            switch(i)
            {
                case 1 : 
                    if(mapHCM[a.first][a.second+1])
                        dfs(make_pair(a.first, a.second+1));
                    break;
                case 2 : 
                    if(mapHCM[a.first+1][a.second])
                        dfs(make_pair(a.first+1, a.second));
                    break;
                case 3 : 
                    if(mapHCM[a.first-1][a.second])
                        dfs(make_pair(a.first-1, a.second));
                    break;
                case 4 : 
                    if(mapHCM[a.first][a.second-1])
                        dfs(make_pair(a.first, a.second-1));
                    break;
            }   
        }
    }
}
void diemNgap()
{
    int n;
    string s;
    cin >> n;
    for(int i = 1; i <= n;i++)
    {
        cin >> s;
        for(int j = 0; j < n; j++)
            mapHCM[i][j+1] = (s[j] == '1') ? 1 : 0;
    }
    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= n; j++)
        {
            if(mapHCM[i][j])
            {
                numOfVlt++;
                dfs(make_pair(i, j));
                maxVlt = max(maxVlt, vlt[numOfVlt]);
            }
        }
    cout << numOfVlt <<  " " << maxVlt << endl;
}
int main()
{
    diemNgap();
    return 0;
}
