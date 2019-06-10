#include <iostream>

using namespace std;
struct Can
{
    int num = 0;
};
int main()
{
    int n,d=0;
    Can A[1001];
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int a,b;
        cin >> a >> b;
        A[b].num--;
        if(a != b)
        {
            A[a].num++;
        }
    }
    for(int i = 1;i <= 1000;i++)
        if(A[i].num>0) d+=A[i].num;
    cout << d;
    return 0;
}
