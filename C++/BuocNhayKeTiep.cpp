#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;
int S[]={4,1, 2, 3, 1, 2, 3, 1, 2, 3, 4};
int main()
{
    //prepare();
    int n;
    cin >> n;
    cout << S[n%10] << endl;
    return 0;
}
