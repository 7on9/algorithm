#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int a, b;
    long long k, temp;
    vector<long long> arrA;
    multiset<long long> mapB;
    multiset<long long, long long>::iterator x;
    cin >> a >> b >> k;
	bool aBiggerThanB = false;
    long long total = 0;
    if (a < b)
    {
        for (int i = 1; i <= a; i++)
        {
            cin >> temp;
            if (temp == 0 || k == 0)
                arrA.push_back(temp);
            else if (k % temp == 0)
                arrA.push_back(temp);
        }
        for (int i = 1; i <= b; i++)
        {
            cin >> temp;
            mapB.insert(temp);
        }
    }
    else
    {
		aBiggerThanB = true;
        for (int i = 1; i <= a; i++)
        {
            cin >> temp;
            mapB.insert(temp);
        }
        for (int i = 1; i <= b; i++)
        {
            cin >> temp;
            if (temp == 0 || k == 0)
                arrA.push_back(temp);
            else if (k % temp == 0)
                arrA.push_back(temp);
        }
    }
    for (int i = 0; i < arrA.size(); i++)
    {
        if (arrA[i] != 0)
            total += mapB.count(k / arrA[i]);
        else
        {
            if (k == 0)
			{
				total += aBiggerThanB ? a : b;
			}
//                total += mapB.count(0)
        }
    }
    cout << total << endl;
    return 0;
}
