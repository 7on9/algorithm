/*This source belong to 7on9 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <long long> Height;
vector <int> A;
int main()
{
    int n,i;
    long long sum = 0;
    cin >> n;
    Height.assign(n+1,0);
    A.clear();
    for(i = 0;i < n;i++)
        cin >> Height[i];
   // Height[i] = 0;
    int t; 
    for(i = 0;i <= n;)
    {
        if(!A.empty())
            t = A.back();
        else t = 0;
        if(A.empty() || Height[i] > Height[t])
        {
            A.push_back(i);
            i++;
        }
        else
        {
            A.pop_back();
            sum = max(sum,Height[t] * (A.empty() ? i : i- A.back() - 1));
        }
    }
    cout << sum << endl;
    return 0;
}