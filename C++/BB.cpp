//dãy ngoặc đúng
#include <iostream>
#include <algorithm>
#include <string.h>
//using namespace std;
struct Chuoi
{
    char str[1003];
};
int main()
{
  //  ios::sync_with_stdio(0);
    Chuoi S[1003];
    int n,j;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%s",S[i].str);
    for (int i = 1;i <= n; i++)
    {
        unsigned long len = strlen(S[i].str);
        if (len % 2  != 0)
        {
            printf("NO\n");
            continue;
        }
       bool n_equal = false;
        int x,x2,vc[1003],c;
        memset(vc, 0, len);
        x = x2 = c = 0;
        for (j = 0 ; j < len; j++)
        {
            if(S[i].str[j] == '(' )
            {
                x +=1;
                c++;
                vc[c] = 1;
            }
            if(S[i].str[j] == '{')
            {
                x +=2;
                c++;
                vc[c] = 2;
            }
            if(S[i].str[j] == '[')
            {
                x +=3;
                c++;
                vc[c] =3;
            }
            if(S[i].str[j] == ')' )
            {
                if (vc[c] != 1)
                {
                    n_equal = true;
                    break;
                }
                x2 +=1;
                c--;
            }
            if(S[i].str[j] == '}')
            {
                if (vc[c] != 2)
                {
                    n_equal = true;
                    break;
                }
                x2 +=2;
                c--;
            }
            if(S[i].str[j] == ']')
            {
                if (vc[c] != 3)
                {
                    n_equal = true;
                    break;
                }
                x2 +=3;
                c--;
            }
            if (x < x2)
            {
                n_equal = true;
                break;
            }
        }
        if(x == x2 && !n_equal) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
