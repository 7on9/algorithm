#include <iostream>
#include <string>
#define MOD 1337377
using namespace std;
int sum[300001];
class Node
{
public:
    Node()
    {
        isEndOfString = false;
        for(int i = 0;i < 26;i++)
            Arr[i] = NULL;
    }
    Node *newNode()
    {
        Node *node = new Node();
        return node;
    }
    void addString(string s)
    {
        Node *temp = this;
        int l  = s.size();
        for(int i = l - 1;i >= 0;i--)
        {
            if(temp->Arr[s[i]-97] == NULL)
                temp->Arr[s[i]-97] = newNode();
            temp = temp->Arr[s[i]-97];
        }
        temp->isEndOfString = true;
    }
    // -97 de giam so luong
    bool isEndOfString;    
    Node *Arr[26];
};
void solve(Node *root)
{
    int n;
    string str, s;
    cin >> s >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> str;
        root->addString(str);
    }
    sum[0] = 1;
    for(int i = 1;i <= s.size(); i++)
    {
        Node *temp = root;
        for(int j = i; j && temp->Arr[s[j-1]-97];j--)
        {
            temp = temp->Arr[s[j-1] - 97];
            if(temp->isEndOfString)
                sum[i] = (sum[j-1] + sum[i]) % MOD;
        }
    }
    cout << sum[s.size()] << endl;
}
int main()
{
    Node *root = new Node();
    solve(root);
    return 0;
}
