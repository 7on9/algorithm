//số kí tự khác nhau trong dãy
#include <iostream>
using namespace std;
bool *check;
int main()
{
    int n,*S,t,count=0,q , in[3][200001];
    cin >> n;
    check = new bool[sizeof(int)];
    S = new int (n);
    
    for(int i = 1;i <= n ;i ++)
    {
        cin >> t;
        if(!*(check+t))
        {
            count++;
            S[i] = count;
            * (check + t) = true;
        }
        else S[i] = count;
    }
    cin >> q;
    for(int k = 1;k <= q; k++)
        cin >> in[1][k] >>in[2][k];
    for(int k = 1;k <= q; k++)
    {
        if(in[2][k] - in[1][k] > 1)
        {
            if(S[in[2][k]]-S[in[1][k]] <= 2 ) cout << S[in[2][k]]-S[in[1][k]] + 1<<endl;
            else
            if(2 + S[in[2][k]]-S[in[1][k]] > S[in[2][k]]) cout  << S[in[2][k]] << endl;
            else cout <<  2 + S[in[2][k]]-S[in[1][k]] << endl;
        }
        else cout << 1 + S[in[2][k]]-S[in[1][k]] << endl;
    }
}
//8
//1 1 2 3 4 1 1 5
//10
//1 5
//4 8
//2 7
//1 8
//2 5
//4 7
//4 6
//1 5
//2 8
//5 8

