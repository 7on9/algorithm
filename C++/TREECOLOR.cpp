#include <iostream>
#include <set>
using namespace std;
#define MAX 10//0005
int N;
int cha[MAX], arr[MAX], ranki[MAX];

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void init() {
    for (int i=1; i<=N; i++) {
        cha[i] = i;
        ranki[i] = 0;
    }
}

int find(int u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (ranki[u] == ranki[v]) ranki[u]++;
    if (ranki[u] < ranki[v]) cha[u] = v;
    else cha[v] = u;
}
int main()
{
    //init
    int x, y;
    cin >> N;
    init();
    for(int i = 1;i < N;i++)
    {
        cin >> x >> y;
        join(x, y);
    }
    set <int> maping[MAX];
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        maping[find(i)].insert(arr[i]);
    }
    //cout << cha[3] << " " << cha[4] << " " << cha[5] << endl;
    for(int i = 1; i <= N; i++)
        cout << maping[find(i)].size() << endl;
    return 0;
}
