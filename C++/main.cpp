#include <iostream>

using namespace std;
int main()
{
    int n, m, i, num, j,max = 1;
    char A[400][400];
    cin >> n >> m;
    int n2 = n, m2 = n;
    string s2;
    for(i = 1;i <= n;i++)
    {
        cin >> s2;
        for(j = 1;j <= m;j++)
            A[i][j] = s2[j-1];
    }
    for(i = 1;i <= n2;i++)
        for(n2 = n;n2 >= i ;n2--)
            for(j = 1; j >= i; j++)
                for(m2 = m; m2 >= j ; m2 --)
                {
                    bool kt = true;
                    for(int h = i;h <= n2 ; h++)
                    {
                        for(int c = j;c <= m2 ; c++)
                            if(A[h][c] == 'X')
                            {
                                kt = false;
                                break;
                            }
                        if(!kt) break;
                    }
                    if(kt)
                    {
                        num = (n2 - i + 1)*2 + (m2 - j + 1)*2 - 1;
                        if(num >= max) max = num;
                    }
                }
    cout << max ;
    return 0;
}
