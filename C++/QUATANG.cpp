#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n,m,a[51];
ll f[51][251];
void Process()
{
	cin>>m>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	f[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++)
			if (a[i]>m) f[i][j]=f[i-1][j];
			else f[i][j]=f[i-1][j]+f[i][j-a[i]];
	cout<<f[n][m];
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Process();
	return 0;
}