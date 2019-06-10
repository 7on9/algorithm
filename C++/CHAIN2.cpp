#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int MAX = 0;
class Node
{
public:
    Node()
    {
        endOfString = 0;
        for(int i = 0;i < 26;i++)
            Arr[i] = NULL;
    }
    void addString(string s)
    {
        Node *temp = this;
        for(int i = 0;i < s.size();i++)
        {
            if(temp->Arr[s[i]-97] == NULL)
            {
                temp->Arr[s[i]-97] = new Node();
            }
            temp = temp->Arr[s[i]-97];
        }
        temp->endOfString = 1;
    }
    void dfs()
    {
        if(this->endOfString) this->numOfWord++;
        for(int i = 0;i < 26;i++)
        {
            if (this->Arr[i] != NULL)
            {
                this->Arr[i]->numOfWord = this->numOfWord;
                this->Arr[i]->dfs();
            }
            MAX = max(this->numOfWord, MAX);
        }
    }
    // -97 de giam so luong
    int endOfString, numOfWord;    
    Node *Arr[26];
};
void solve(int n, Node *root)
{
    string str;
    for(int i = 0;i < n;i++)
    {
        cin >> str;
        root->addString(str);
    }
    root->dfs();
    cout << MAX << endl;
}
int main()
{
    Node *root = new Node();
    int n;
    cin >> n;
    solve(n, root);
    return 0;
}
