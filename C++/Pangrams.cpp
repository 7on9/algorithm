//có xuất hiện tất cả các phần tử ?
#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int check[200];
int main()
{
    getline(cin,s);
    for(int i = 0 ;i < s.size();i++)
            check[ tolower(s[i])]=1;
    bool res=true;
    for(int i='a';i<='z';++i)
        res&=check[i];
    if(res) cout << "pangram" << endl;
    else cout << "not pangram" << endl;
    return 0;
}
/*
 #include <cmath>
 #include <cstdio>
 #include <string>
 #include <iostream>
 #include <algorithm>
 using namespace std;
 string s;
 int check[200],sum=2847;
 int main()
 {
 getline(cin,s);
 for(int i = 0 ;i < s.size();i++)
 {
 if(s[i] != 32)
 {
 int j = int( tolower(s[i]));
 check[j]++;
 if(check[j]==1)
 sum-=j;
 }
 }
 if(sum == 0) cout << "pangram" << endl;
 else cout << "not pangram" << endl;
 return 0;
 }
*/
