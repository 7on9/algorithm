#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#define OO 2000000001

using namespace std;
unsigned n, m, k, x, *A, *B;
class Pos
{
public:
    Pos(){}
    Pos(unsigned short x, unsigned short y)
    {
        a = x;
        b = y;
        sum = A[a] + B[b];
    }
    union 
    {
        struct
        {
            unsigned short a;
            unsigned short b;
            unsigned sum;
        };
        int int32val;
    };
};

bool operator<(const Pos&X, const Pos&Y)
{
    return X.sum>Y.sum;
}
/*
class cmp
{
public:
    bool operator() (Pos x, Pos y)
    {
        return (x.unsigned64dval < y.unsigned64dval);
    }
};
*/
priority_queue <Pos> C;
set <int> *check;

int main()
{
   // FILE *f;
    //f = freopen("in.inp","rw",stdin);
    //f = freopen("out2.out","w+",stdout);
    ios_base::sync_with_stdio(0);
    check=new set<int>();
    cin >> m >> n >> k;
    A = new unsigned[m+1];
    B = new unsigned[n+1];
    A[m] = B[n] = OO;
    for(unsigned i = 0; i < m; i++)
        cin >> A[i];
    for(unsigned j = 0; j < n; j++)
        cin >> B[j];
    sort(B, B+n);
    sort(A, A+m);
    C.push(Pos(0, 0));
    Pos temp1;
    //check.insert(Pos(0,0));
    while (k)
    {
        Pos temp = C.top();
        C.pop();
        if (check->insert(temp.int32val).second)
        {
                cout << temp.sum << endl;
                temp1.a=temp.a+1;
                temp1.b=temp.b;
                temp1.sum = A[temp1.a] + B[temp1.b];
                C.push(temp1);
                temp1.a=temp.a;
                temp1.b=temp.b+1;
                temp1.sum = A[temp1.a] + B[temp1.b];
                C.push(temp1);
                k--;
        }
    }
    return 0;
}
