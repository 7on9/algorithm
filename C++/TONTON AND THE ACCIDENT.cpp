#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct MAN
{
    int h;
    int l;    
};
vector <MAN> peop, sMan;
MAN temp;
bool cmp(const MAN &a, const MAN &b)
{
    if(a.h == b.h) return (a.l < b.l);
    return (a.h > b.h);
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp.h >> temp.l;
        peop.push_back(temp);
    }
    sort(peop.begin(), peop.end(), cmp);
    for(int i = 0; i < n; i++)
        
}
int main()
{
    
    return 0;
}
