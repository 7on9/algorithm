#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int **Area=new int*[1001];
	for(int i=0;i<1001;++i)
		Area[i]=new int[1001];
    int n,m,d = 0,i,j;
    cin >> n >> m;
    for(i = 0;i < n;i++)
        for(j = 0;j < m;j++)
            cin >> Area[i][j];
    int c = 0,h = 0;
    h = (n%2==0) ? (n/2) : (n/2+1);
    c = (m%2==0) ? (m/2) : (m/2+1);
    for(i = 0;i < h;i++)
        for(j = 0;j < c;j++)
            {
                int dif = 0,dif2 = 0,dif3 = 0;
                {
                    //goc tren trai
                    if(Area[i][j] != Area[i][m-j-1]) dif++;  //goc phai tren
                    if(Area[i][j] != Area[n-i-1][m-j-1]) dif++;  //goc phai duoi
                    if(Area[i][j] != Area[n-i-1][j]) dif++;  //goc trai duoi
                    //goc duoi phai
                    if(Area[n-i-1][m-j-1] != Area[i][j]) dif2++;  //goc trai tren
                    if(Area[n-i-1][m-j-1] != Area[i][m-j-1]) dif2++;  //goc phai tren
                    if(Area[n-i-1][m-j-1] != Area[n-i-1][j]) dif2++;  //goc trai duoi
                    //goc tren trai
                    if(Area[i][m-j-1] != Area[i][j]) dif3++;  //goc trai tren
                    if(Area[i][m-j-1] != Area[n-i-1][m-j-1]) dif3++;  //goc phai duoi
                    if(Area[i][m-j-1] != Area[n-i-1][j]) dif3++;  //goc trai duoi
                    
                    if (j == m-j-1|| i == n-i-1)
                    {
                        dif2 = min(1,dif2);
                        dif = min(1,dif);
                        dif3 = min(1,dif3);
                    }
                }
                d += (min(min(dif,dif2),dif3));
            }
    cout << d << endl;
    return 0;
}
