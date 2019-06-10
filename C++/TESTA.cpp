#include <iostream>
#include <string>
using namespace std;
int A[2001];
int main()
{
    int n;
    char c;
    string s="";
    char *temp = NULL;
    cin >> n;
    temp = new char[n];
    for(int i = 1;i <= n;i++)
        {
            cin >> c;
            temp[i-1] = c;
            A[i] += (A[i-1] + int(c));
        }
    int j = 0,mid = 0,k=0;
    n--;
    do
    {
        if(temp[0] < temp[n])
        { 
            s+= temp[0];
            temp++;
            n--;
            mid++;
            j++;
            k++;
        }
        else 
            if(temp[0] > temp[n])
            {
                s+= temp[n];
                n--;
                k++;
            }
            else
                {
                    mid += (n)/2;
                    if((A[mid+k-1]-A[j]) < (A[n+k]-A[mid+k-1]))
                    { 
                        s+= temp[0];
                        temp++;
                        n--;
                    }
                    else 
                        {
                            s+= temp[n];
                            n--;
                        }
                }
    }while(n>0);
    s+=temp[0];
    cout << s << endl;
    return 0;
}
