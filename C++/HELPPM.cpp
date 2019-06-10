#include <iostream>
using namespace std;
#define MAX 501
#define INT_MAX 2147483647
int jungle[MAX][MAX], A[MAX], m, n, k;
int rt, ct, rb, cb, minArea;
void reset()
{
    for(int i = 0; i <= m; i++)
        A[i] = 0;
}
void getdata()
{
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
                cin >> jungle[i][j];
}
void solve()
{
    minArea = INT_MAX;
    for(int i = 1; i <= n; i++)
        {
            reset();
            for(int j = i; j <= n; j++)
                {
                    for(int k = 1; k <= m; k++)
                        A[k] += jungle[k][j];
                    int r, c;
                    r = c = 1;
                    int harvest = A[1];
                    while(r <= c && c <= m)
                    {
                        if(harvest < k)
                        {
                            c++;
                            harvest += A[c];
                        }
                        else
                        {
                            int area = (j-i+1)*(c-r+1);
                            if(area > 0 && area < minArea)
                            {
                                rt = r;
                                ct = i;
                                rb = c;
                                cb = j;
                                minArea = area;
                            }
                            harvest -= A[r];
                            r++;
                        }
                    }
                }
        }
    if(minArea == INT_MAX)
        cout << "-1" << endl;
    else   
        cout << minArea << "\n" << rt << " " << ct << " " << rb << " " << cb << endl;     
}
int main()
{
    getdata();
    solve();
    return 0;
}