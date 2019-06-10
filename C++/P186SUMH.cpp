#include <iostream>
#include <math.h>
using namespace std;
const int N = 1e5; // giới hạn của mảng
int n, m;             // kích thước mảng
int t[2 * N];

void build()
{ // khởi tạo cây
    for (int i = n - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int p, int value)
{ // gán giá trị tại vị trí p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

int query(int l, int r)
{ // tính tổng đoạn [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
		t[n + i] = int((pow(2, n - i)*(s[i]-'0')) % 5.0);
		t[n+i] %= 5;
    }
	cin >> m;
	int z,x, y;
	for(int i = 0; i < m;i++)
	{
		cin >> z >> x >> y;
		if(z == 1)
		{
			
		}
	}
    build();
    modify(0, 1);
	
    return 0;
}
