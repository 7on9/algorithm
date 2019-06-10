#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    Node()
    {
        endOfString = false;
        for(int i = 0;i < 28;i++)
            Arr[i] = NULL;
    }
    void addString(string s)
    {
        Node *temp = this;
        bool haveNew = false;
        for(int i = 0;i < s.size();i++)
        {
            if(temp->Arr[s[i]-97] == NULL)
            {
                temp->Arr[s[i]-97] = new Node();
                haveNew = true;
            }
            temp = temp->Arr[s[i]-97];
            if(temp->endOfString) 
            {
                cout << "BAD SET\n" << s << endl;
                exit(0);
            }
        }
        if(!haveNew)
        {
            cout << "BAD SET\n" << s << endl;
            exit(0);
        } 
        temp->endOfString = true;
    }
    // -97 de giam so luong
    bool endOfString;    
    Node *Arr[28];
};
void solve(int n, Node *root)
{
    string str;
    for(int i = 0;i < n;i++)
    {
        cin >> str;
        root->addString(str);
    }   
    cout << "GOOD SET\n";
}
int main()
{
    Node *root = new Node();
    int n;
    cin >> n;
    solve(n, root);
    return 0;
}
