#include <iostream>
#include <stack>
using namespace std;
class Block
{
public:
    char c ='.';
    bool visited = false;
    Block *left;
    Block *right;
    Block *up;
    Block *down;
};
void dfs(int &snake,Block *sna)
{
    sna->visited = true;
    if (sna->right!= NULL )
    {
        if(sna->right->c == '#' && !sna->right->visited)
        {
            snake--;
            dfs(snake, sna->right);
        }
    }
    else
        if (sna->left!= NULL)
        {
            if( sna->left->c == '#' && !sna->left->visited)
                {
                    snake--;
                    dfs(snake, sna->left);
                }
        }
    
    if (sna->down!= NULL )
            {
                if( sna->down->c == '#'&& !sna->down->visited)
                {
                    snake--;
                    dfs( snake, sna->down);
                }
            }
            else
                if (sna->up!= NULL )
                {
                    if(sna->up->c == '#' && !sna->up->visited)
                    {
                        snake--;
                        dfs( snake, sna->up);
                    }
                }
    return;
}
bool solve()
{
    int n,snake = 0;
    cin >> n;
    Block B[2][n];
    for(int i = 0;i < 2;i++)
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j].c;
            if(i == 0) B[i][j].down =&B[i+1][j];
            else  B[i][j].up =&B[i-1][j];
            if(j < n-1) B[i][j].right =&B[i][j+1];
            if (j > 0) B[i][j].up = &B[i][j-1];
            if(B[i][j].c == '#')
                snake++;
        }
    for(int i = 0;i < 2;i++)
        for (int j = 0; j < n; j++)
        {
            if(B[i][j].c == '#')
            {
                snake--;
                Block *sna;
                sna = new Block;
                sna = &B[i][j];
                dfs(snake,sna);
                if(snake == 0) return true;
                else return false;
            }
        }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (; t>0; t--)
    {
        if(solve()) cout << "yes" << endl;
        else cout << "no" << endl;    }
    return 0;
}
