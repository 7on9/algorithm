#include <iostream>
#include <string.h>

using namespace std;
struct Chuoi
{
    char chuoi[1000];
};
void swap(char *A,char *B)
{
    char *C ;
    strcpy(C, A);
    strcpy(A, B);
    strcpy(B, C);
}
int main()
{
    int n,q;
    cin >> n >> q;
    Chuoi A[n];
    int B[q];
    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].chuoi;
    }
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
        {
            if(strcmp(A[i].chuoi, A[j].chuoi) == 1)
                swap(A[i].chuoi,A[j].chuoi);
        }
    for (int i = 0; i < q; i++)
    {
        Chuoi Q;
        cin >> Q.chuoi;
        for (int j = 0; j < n; j++)
            if(strstr(A[j].chuoi, Q.chuoi)!= NULL)
            {
                B[i] = j+1;
                break;
            }
            else B[i] = -1;
    }
    for (int i = 0; i < q; i++)
    {
        if(B[i] != -1)
            cout << B[i] << " 0"<<endl;
        else cout << "-1 -1" <<endl;
    }
    return 0;
}
