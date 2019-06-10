
/*ACM VIETNAM SOUTHERN PROGRAMMING CONTEST
Host: University of Science, VNU-HCM
October 28, 2018 */
#include <iostream>
using namespace std;
char a[1001][1001];
int b[1001][1001];
bool check[1001];
void DFS()
{

	check[u]=true;
	for(int i=0;i<v[u].size();i++)
	{
		if(!check[v[u][i]])
		{
			dem++;
			DFS(v[u][i]);
			
		}
			
	}
}
int main()
{
    int m,n;
	cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='S'){
                sx = i;
                sy = j;
            }
            if (a[i][j]=='F'){
                fx = i;
                fy = j;
            }
        }
    b[sx][sy] = -1;
    b[fx][fy] = -1;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++){
            char ch;
            cin>>ch;
            
                if(ch == '.' && a[i][j] == '.') {
                    b[i][j] = 1;
                }
        }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){ 
            cout<<b[i][j]<< " ";
        }
        cout<<"\n";
}
    

    return 0;
}