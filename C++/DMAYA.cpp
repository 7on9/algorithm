//tìm số lần xuất hiện của X trong S
#include <iostream>
#include <string>
using namespace std;
int Check[256];
int Checkb[256];
bool cmp(int A[],int B[])
{
    for(int i = 65;i <= 122;i++)
        if(A[i] != B[i]) return false;
    return true;
}
int main()
{
    char c;
    int a,b;
    string S;
    int d = 0;
    cin >> a >> b;
    for(int i = 0;i < a;i++)
    {
        cin >> c;
        Check[int(c)]++;
    }
    for(int i = 0;i < b;i++)
    {
        cin >> c;
        S+=c;
        Checkb[int(c)]++;
        if(i > a-1)
            Checkb[S[i-a]]--;
        if(cmp(Check,Checkb)) d++;    
    }
    cout << d << endl;
    return 0;
}
//  012345
