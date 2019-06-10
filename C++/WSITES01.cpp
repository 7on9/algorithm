//Bài cơ bản về trie
#include <iostream>
#include <string>
#include <set>
using namespace std;
multiset <string> Filter;
multiset <string>::iterator it;
string s = "";
class Node
{
  public:
    Node()
    {
        block = true;
        isEndOfBlock  = false;
        for (int i = 0; i < 26; i++)
            Arr[i] = NULL;
    }
    void addString(string str, bool block)
    {
        Node *temp = this;
        for (int i = 0; i < str.size(); i++)
        {
            if (temp->Arr[str[i] - 97] == NULL)
                temp->Arr[str[i] - 97] = new Node();
            if (!block)
                temp->Arr[str[i] - 97]->block = false;
            temp = temp->Arr[str[i] - 97];
        }
        temp->isEndOfBlock = block;
    }
    void addFilter()
    {
        for(int i = 0; i < 26; i++)
        {
            if(this->Arr[i])
            {
                s += char(i + 97);
                if(this->Arr[i]->block)
                {
                    Filter.insert(s);
                    s.erase(s.length()-1);
                    continue;
                }
                else
                    if(this->isEndOfBlock)
                    {
                        cout << "-1" <<endl;
                        exit(0);
                    }
                this->Arr[i]->addFilter();
                s.erase(s.length()-1);
            }
        }
    }
    // -97 de giam so luong
    bool isEndOfBlock;
    bool block;
    Node *Arr[26];
};
void solve(int n, Node *root)
{
    char req;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> req >> str;
        if (req == '+')
            root->addString(str, false);
        else
            root->addString(str, true);
    }
    root->block = false;
    root->addFilter();
    cout << Filter.size() << endl;
    for(it = Filter.begin();it != Filter.end();it++)
        cout << *it << endl;
}
int main()
{
    Node *root = new Node();
    int n;
    cin >> n;
    solve(n, root);
    return 0;
}
