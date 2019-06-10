#include <iostream>
#include <algorithm>
#define MAX 100005
using namespace std;
int n,k;
int price[MAX][102], S[MAX], event[102];
int day = 0, x;
void proccess()
{
    for(int i = 1;i <= n; i++)
    {
        int l = 0;
        for(int j = 1; j <= k; j++)
        {
            l += event[j];
            if(i >= l)
            {
                if(price[i-1][j] > 0)
                    price[i][j] = min(price[i-1][j],price[i - event[j]][j-1] + (S[i] - S[i - event[j]]));
                else
                    price[i][j] =price[i - event[j]][j-1] + (S[i] - S[i - event[j]]);
                    //price[i - event[j]][j-1] + (S[i] - S[i - event[j]]);
            }
            else price[i][j] = price[i-1][j];
        }
    }
//    for(int i = 0;i <= n; i++)
//    {
//         for(int j = 0 ; j <= k; j++)
//            cout << "[" << i  <<  j << "]"<< price[i][j] << " ";
//        cout << endl;
//    }
    cout << price[n][k] << endl;
}
void getData()
{
    S[0] = price[0][0] = 0;
    cin >> n >> k;
    for(int i = 1; i <= n;i++)
    {
        cin >> x;
        S[i] = S[i-1] + x;
        //price[i][0] = x;
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> event[i];
        //price[0][i] = event[i];
        day += event[i];
    }
    if(day > n) 
    {
        cout << -1 << endl;
        exit(0);
    }
}
int main()
{
    getData();
    proccess();
    return 0;
}
//8 8
//2 3 4 5 7 8 9 10
//1 1 1 1 1 1 1 1





