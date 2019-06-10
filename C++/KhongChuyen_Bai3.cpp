#include <iostream>
#define MAX 100001 
using namespace std;
bool Sang[MAX];
int x,y,r,c;
int TableC[MAX][MAX];//cot
int TableR[MAX][MAX];//hang
void SangNT()
{
    Sang[0] = Sang[1] = true;
    for(int i = 2,j = 2;i*j <= MAX;i++)
    {
        if(!Sang[i]) 
            while(i*j <= MAX)
            {
                Sang[i*j] = true;
                j++;
            }
    }
}
void ScanData(int &n,int &m,int &Q)
{
    cin >> n >> m >> Q;
    for(int i = 1;i < m;i++)
        for(int j = 1;j < n;j++)
        {
            cin >> TableC[i][j];
            TableR[i][j] = (!Sang[TableC[i][j]]) ? (1+TableR[i-1][j]) : (TableC[i-1][j]); 
            TableC[i][j] = (!Sang[TableC[i][j]]) ? (1+TableC[i][j-1]) : (TableC[i][j-1]); 
        }
}
int BinSearchC(int R,int left,int right,int key)
{
    if(left > right) return -1;
    int mid = (left+right)/2;
    if(TableC[R][mid] == key) return mid;
    if(TableC[R][mid] > key) BinSearchC(R,left,mid-1,key);
    if(TableC[R][mid] < key) BinSearchC(R,mid+1,right,key);
    return -1;
}
int BinSearchR(int C,int left,int right,int key)
{
    if(left > right) return -1;
    int mid = (left+right)/2;
    if(TableR[mid][C] == key) return mid;
    if(TableR[mid][C] > key) BinSearchR(C,left,mid-1,key);
    if(TableR[mid][C] < key) BinSearchR(C,mid+1,right,key);
    return -1;
}
bool Answer()
{
    cin >> x >> y >> r >> c;
    long s = r*c;
    for(int R = x;R <= y;R++)
    {
        int a = BinSearchC(R,1,n,s);
        int b = BinSearchR(C,1,m,s);
    }
    return false;
}
int main()
{
    int n,m,Q;
    SangNT();
    ScanData(n,m,Q);
    while(Q)
    {
        if(Answer()) cout << 1 << endl;
        else cout << 0;
        Q--;
    }
    return 0;
}
