#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int len, R;
vector<string> dataSet;
string Res[100005];
string tempAns;
class Trie
{
    public:
    bool isEndOfString;
    Trie *Arr[26];
    Trie()
    {x
        for(int i = 0; i < 26;i++)
            Arr[i] = NULL;
        isEndOfString = false;
    }
    void addString(string s){
        len = s.length();
        Trie *cloneRoot;
        cloneRoot = this;
        for(int i = 0; i < len; i++)
        {
            if(cloneRoot->Arr[s[i] - 97] == NULL)
                cloneRoot->Arr[s[i]-97] = new Trie();
            cloneRoot = cloneRoot->Arr[s[i] - 97];
        }
        cloneRoot->isEndOfString = true;
    }
    string search(string s)
    {
        len = s.length();
        Trie *cloneRoot;
        cloneRoot = this;
        string temp = "";
        for(int i = 0 ;i < len;i++)
        {
            if(cloneRoot->Arr[s[i] - 97])
            {
                temp += (s[i]);
                cloneRoot = cloneRoot->Arr[s[i] - 97];
            }
            else break;
        }
        while(!cloneRoot->isEndOfString)
        {
            for(int i = 0; i < 26;i++)
                if(cloneRoot->Arr[i])
                {
                    cloneRoot = cloneRoot->Arr[i];
                    temp += (i + 97);
                    //if(cloneRoot->isEndOfString)
                    break;
                }
        }
        return temp;
    }
};
Trie *root;
class Query
{
    public:
    int num;
    string s;
    int pos;
};
bool cmp(Query &a, Query &b)
{
    if(a.num == b.num) return a.s < b.s;
    return a.num < b.num;
}
void getData()
{
    int n, Q;
    cin >> n;
    string temp;
    root = new Trie();
    for(int j = 0; j < n; j++)
    {
        cin >> temp;
        dataSet.push_back(temp);
    }
    cin >> Q;
    Query tempQ;
    vector <Query> Que;
    for(int i = 0;i < Q; i++)   
    {
        cin >> tempQ.num >> tempQ.s;
        tempQ.pos = i;
        Que.push_back(tempQ);
    }
    sort(Que.begin(),Que.end(),cmp);
    
    int j = 0;
    for(int i = 0; i < Que.size();i++)
    {
        if(j < Que[i].num)
        { 
            for(int k = j; k < Que[i].num;k++)
                root->addString(dataSet[k]);
            j = Que[i].num;
        }
        Res[Que[i].pos] = root->search(Que[i].s);
    }
    for(int i = 0; i < Q;i++)
        cout << Res[i] << endl;
}

int main()
{
    getData();
    return 0;
}
