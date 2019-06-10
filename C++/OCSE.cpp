#include <iostream>
using namespace std;
int Map[101][101];
bool Map2[101][101];

void move(int y,int x)
{
    
}
int main()
{
    int n,m,x,y;
    cin >> n >> m >> y >> x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 0) Map2[i][j] = true;
        }
    
    return 0;
}
