#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Gold
{
    public:
    long long weight;
    long long value;
    Gold()
    {
        weight = 0;
        value = 0;
    }
    void reset()
    {
        weight = 0;
        value = 0;
    }
    void add(Gold gold)
    {
        weight += gold.weight;
        value += gold.value;
    }
};
struct cmp
{
    bool operator()(const Gold &x, const Gold & y) const
    {if(x.weight == y.weight)return x.value < y.value;
        return x.weight < y.weight;}
};
int n, m;
long long maxValue = 0;
vector<Gold> goldPackA, goldPackB;
vector<Gold> goldPackASum, goldPackBSum;
void makeSum(vector<Gold> &pack, vector<Gold> &goldPackSum)
{
    Gold *sum = new Gold;
    for(int i = 0;i < (1 << pack.size());i++)
    {
        sum->reset();
        for(int j = 0;j < pack.size();j++) 
            if(i&(1<<j)) sum->add(pack[j]);
        if(sum->weight <= m) goldPackSum.push_back(*sum);
    }
    sort(goldPackSum.begin(), goldPackSum.end(), cmp());
}
void getData()
{
    cin >> n >> m;
    Gold temp;
    for(int i = 0;i < n/2;i++)
    {
        cin >> temp.weight >> temp.value;
        goldPackA.push_back(temp);
    }
    n -= (n/2);
    for(int i = 0;i < n;i++)
    {
        cin >> temp.weight >> temp.value;
        goldPackB.push_back(temp);
    }
}
void solve()
{
    makeSum(goldPackA, goldPackASum);
    makeSum(goldPackB, goldPackBSum);
    long long res = 0;
    for(int i = goldPackASum.size()-1, j = 0; i >= 0;i--)
    {
        while(j < goldPackBSum.size() && (goldPackASum[i].weight + goldPackBSum[j].weight) <= m)
        {
            maxValue = max(maxValue, goldPackBSum[j].value);
            j++;
        }
        res = max(res, maxValue + goldPackASum[i].value);
    }
    cout << res << endl;  
}
int main()
{
    getData();
    solve();
    return 0;
}
