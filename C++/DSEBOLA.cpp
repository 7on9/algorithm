#include <iostream>
#include <stack>
#include <set>
using namespace std;
class Man
{
public:
    int meet;
    set <int> Meet;
    bool sick = false;
    bool visited = false;
};
void dfs(set <int> &Result,Man *man,int node)
{
    Result.insert(node);
    man[node].sick = man[node].visited = true;
    for(set<int>::iterator i = man[node].Meet.begin();i != man[node].Meet.end();i++)
    {
        if(!man[*i].visited) dfs(Result, man, *i);
    }
}
int main()
{
    set <int> Result;
    int n,k;
    cin >> n >> k;
    
    //Read data
    Man* man;
    man = new Man[n+1];
    for(int i = 1; i<= n;i++)
    {
        cin >> man[i].meet ;
        for (int j = 0; j < man[i].meet; j++)
        {
            int a;
            cin >> a;
            man[i].Meet.insert(a);
        }
    }
    man[k].sick = true;
    //DFS
    dfs(Result, man, k);
    cout << Result.size() <<endl;
    for(set<int>::iterator i = Result.begin();i != Result.end();i++)
        cout << *i << " " ;
    cout << endl;
    return 0;
}
