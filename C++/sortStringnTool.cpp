#include <iostream>
#include <string>
using namespace std;
int main()
{
    string S;
    getline(cin, S);
    int len = S.size();

    for(int  i = 0;i < len; i++)
        cout << "S["<< i <<"] = " << S[i] <<endl;
    int A[]={3,9,10,3,21,18,6,7,11,9,18,10,7,18,17,15,5,22};
    for (int i = 0; i< 18; i++)
    {
        cout << S[A[i]] ;
    }
    cout << endl;
    return 0;
}
