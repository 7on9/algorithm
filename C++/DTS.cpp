#include <iostream>

using namespace std;
int main()
{
    int n,d,num = 0;
//    int num0[] = { 0, 8},num1[] = { 0, 3, 4, 7, 8, 9};
    cin >> n;
    for(int i = 1; i <= 2;i++)
    {
        int m = n%10;
        switch (m)
        {
            case 1: d = 6; break;
            case 2: case 3: case 4: case 6: d = 1 ; break;
            case 5: d = 2; break;
            case 7: d = 3; break;
            case 8: d = 0; break;
            case 9: case 0: d = 1; break;
        }
        if(m != 8) d *= 2;
        num += d;
        n /= 10;
    }
    cout << num;
    return 0;
}
