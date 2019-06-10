//Bài cơ bản về trie
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    Node()
    {
        numOfNode = 0;
        for(int i = 0;i < 28;i++)
            Arr[i] = NULL;
    }
    void addString(string s)
    {
        Node *temp = this;
        for(int i = 0;i < s.size();i++)
        {
            if(temp->Arr[s[i]-97] == NULL)
                temp->Arr[s[i]-97] = new Node();
            temp = temp->Arr[s[i]-97];
            temp->numOfNode++;
        }
    }
    void findString(string s)
    {
        int i = 0;
        int len = s.size();
        Node *temp = this;
        while( i < len)
        {
            if(temp->Arr[s[i]-97] != NULL)
                temp = temp->Arr[s[i]-97];
            else
            {
                cout << "0\n";
                return;
            }
            i++;
        }
        cout << temp->numOfNode << endl;
    }
    // -97 de giam so luong
    int numOfNode;    
    Node *Arr[28];
};
void solve(int n, Node *root)
{
    string req, str;
    for(int i = 0;i < n;i++)
    {
        cin >> req >> str;
        if(req == "add")
            root->addString(str);
        else   
            root->findString(str);
    }   
}
int main()
{
    Node *root = new Node();
    int n;
    cin >> n;
    solve(n, root);
    return 0;
}