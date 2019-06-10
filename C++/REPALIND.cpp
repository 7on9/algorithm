#include <bits/stdc++.h>
using namespace std;
string s;
long long k;
void solve(){
  cin >> s;
  cin >> k;
  bool rep = true;
  if(s.length() == 1) 
  {
    cout << "YES"<< endl;
    return;
  }
  for(int i = 0; i <= s.length()/2; i++)
  {
    if(s[i] != s[s.length()-i-1]){
      rep = false;
      break;
    }
  }
  if(rep){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    solve();
  }
  return 0;
}