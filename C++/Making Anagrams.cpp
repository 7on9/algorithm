//số phần tử dư thừa
#include <string>
#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    /*Enter your code here. Read input from STDIN. Print output to STDOUT */
    int d = 0;
    char a[1001],b[1001];
    gets(a);
    gets(b);
    int len = strlen(a);
    for(int i = 0; i < len;i++)
    {
        if(/*strchr(a,a[i])!= NULL && */strchr(b,a[i])!= NULL)
        {
            *strchr(b,a[i])= '*';
            a[i] ='*';
            d++;
        }
    }
    len+=strlen(b);
    cout << len - d << endl;
    return 0;
}
