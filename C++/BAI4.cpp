#include <iostream>
#include <string>
using namespace std;
char *reverseStr(string str)
{
    char *s;
    s = new char[str.length()];
    for(int i = 0,j = str.length()-1;i < str.length(); i++,j--)
    {
        s[j] = str[i];
    }
    return s;
}
int main()
{
    string s;
    getline(cin, s);
    cout << s << endl;
    cout << reverseStr(s) << endl;
    return 0;
}
