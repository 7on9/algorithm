#include <iostream>
//#include <fstream>
#include <vector>
#include <deque>
#define ll long long
using namespace std;
long n, m, a[25][25], x1, y1, c[25][25][10], ok = 0;
struct Point{
	long x, y;
};
vector <Point> v;
void print(){
	//if (de.size() == 0) cout << "NO";
	cout << v.size() << endl;
	for (long i= 0; i < v.size(); i++){
		cout << v[i].x + 1<< " " << v[i].y + 1 << endl;
	}
}

void reset(){
	for (long i = 0; i < 21; i++)
	for (long j = 0; j < 21; j++)
	for (long k = 0; k < 5; k++)
	c[i][j][k] = 0;
}

void dfs(long x, long y, long k, long d){
	if (x < 0 || x >= n || y < 0 || y >= m || d > 2000) return;
	if (a[x][y] != 0) return;
	if (c[x][y][k] || ok) return;
	c[x][y][k] = 1;
	Point P;
	P.x = x, P.y = y;
	v.push_back(P);
	if (x == x1 && y == y1) {
		ok = 1; print(); return;
	}
	// tren xuong
	if (k == 3){
		dfs(x + 1, y, 3, d + 1);
		dfs(x, y + 1, 2, d + 1);	
	}
	// sang trai
	if (k == 4){
		dfs(x, y - 1, 4, d + 1);
		dfs(x + 1, y, 3, d + 1);
	}
	// sang phai
	if (k == 2){
		dfs(x, y + 1, 2, d + 1);
		dfs(x - 1, y, 1, d + 1);
	}
	// duoi len
	if (k == 1){
		dfs(x - 1, y, 1, d + 1);
		dfs(x, y - 1, 4, d + 1);	
	}
	
	v.pop_back();
}


int main(){
	ios_base::sync_with_stdio(0);
	//freopen("test.txt", "r", stdin);
	cin >> n >> m;
	for (long i = 0; i < n; i++){
		for (long j = 0; j < m; j++) cin >> a[i][j];
	}
	cin >> x1 >> y1;
	x1--; y1--;
	c[0][0][3] = 1;
	v.push_back({0, 0});
	dfs(1, 0, 3, 0);
	if (ok) return 0;
	else {
		ok = 0;
		reset();
		v.clear();
		v.push_back({0, 0});
		c[0][0][2] = 1;
		dfs(0, 1, 2, 0);
	}
	if (ok) return 0;
	else cout << 0;

	return 0;
}
    