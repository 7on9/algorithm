#include <iostream>
#include <algorithm>
#include <vector>
#define MAX (1<<16)*4
using namespace std;
long long n, u ,v, maxValue;
class Food
{
public:
    void add(Food x)
    {
        this->weight += x.weight;
        this->value += x.value;        
    }
    void sub(Food x)
    {
        this->weight -= x.weight;
        this->value -= x.value;
    }
    long long weight, value;
    bool operator < (Food x)const
    {
        if(weight == x.weight) return value < x.value;
        return weight < x.weight;
    }
};
vector <Food> Arr, Arr2;
vector <Food> ArrS, Arr2S;
Food temp;
struct cmp
{
    bool operator()(const Food &x, const Food & y) const
    {if(x.weight == y.weight)return x.value < y.value;
        return x.weight < y.weight;}
};
long long tree[MAX];
void build(int k,int l,int r)
{
    if (l==r)
    {
        tree[k]=ArrS[l].value;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    tree[k]=max(tree[k<<1],tree[(k<<1)+1]);
}
long long get(int k,int left,int right,int u,int v)
{
    if (right < u || left>v) return 0;
    if (u<=left && right<=v) return tree[k];
    int mid=(left+right)>>1;
    return max(get(k<<1,left,mid,u,v),get((k<<1)+1,mid+1,right,u,v));
}

int find(int left,int right, long long value)
{
    int mid = (left+right)/2;
    cout << " vt : " << left << mid << right << endl;
    if(left >= right) return mid;
    if(ArrS[mid].weight >= value) return find(left, mid, value);
    return find(mid+1, right, value);
}
void getData()
{
    cin >> n >> u >> v;
    for(int i = 0; i < n/2; i++)
    {
        cin >> temp.weight >> temp.value;
        Arr.push_back(temp);
    }
    n -= (n/2);
    for(int i = 0; i < n; i++)
    {
        cin >> temp.weight >> temp.value;
        Arr2.push_back(temp);
    }
}
void solve()
{
    for(int i = 0; i < (1 << Arr.size()); i++)
    {
        temp.value = temp.weight = 0;
        for(int j = 0; j < Arr.size(); j++)
            if(i&(1 << j)) 
                temp.add(Arr[j]);
        if(temp.weight <=v) ArrS.push_back(temp);
        //cout << temp.weight << endl;
    }
    for(int i = 0; i < (1 << Arr2.size()); i++)
    {
        temp.value = temp.weight = 0;
        for(int j = 0; j < Arr2.size(); j++)
            if(i&(1 << j)) 
                temp.add(Arr2[j]);
        if(temp.weight <= v) Arr2S.push_back(temp);
       // cout << temp.weight << endl;
    }
    sort(ArrS.begin(), ArrS.end(), cmp());
    build(1,1,ArrS.size()-1);
    // build tree 
    int d = 0,c = 0;
    for(int  i  = 0; i < Arr2S.size();i++)
    {
        if((u - Arr2S[i].weight) >= 0 && (v - Arr2S[i].weight) >= 0)
        {
                d = find(1,ArrS.size()-1, u - Arr2S[i].weight);
                c = find(1,ArrS.size()-1, v - Arr2S[i].weight);
                if(ArrS[c].weight + Arr2S[i].weight> v) c--;
                maxValue = max(maxValue,get(1,1,ArrS.size()-1,d,c)+Arr2S[i].value);
        }
    }
    //tìm 1 dãy trong A thỏa đk
    cout << maxValue << endl;
}
using namespace std;
int main()
{
    getData();
    solve();
    return 0;
}










