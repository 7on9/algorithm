#include <iostream>
#include <map>
using namespace std;
map<string, int> word;
int cost = 0;
int solve()
{
	//leftHand['d'-'a'] = leftHand['f' - 'a'] = rightHand['j' - 'a'] = rightHand['k' - 'a'] = false;
	int cost_word = 0;
    string s;
    cin >> s;
	map<string, int>::iterator it;
	it = word.find(s);
	if(it != word.end()) return (it->second)/2;
	word.insert(make_pair(s, 0));
	cost_word = 2;
    for(int i = 1; i < s.size(); i++)
    {
        switch(s[i])
        {
            case 'd': case 'f' : 
            {
				if(s[i-1] != 'j' && s[i-1] != 'k') cost_word += 4;
				else cost_word += 2;
            } 
            break;
            default : 
            {
				if(s[i-1] != 'd' && s[i-1] != 'f') cost_word += 4;
				else cost_word += 2;
            } 
		}
    }
	word[s] = cost_word;
	return cost_word;
}
int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
		word.clear();
        cost = 0;
		cin >> n;
		while(n--)
		{
			cost += solve();
		}
        cout << cost << endl;
    }
	
    return 0;
}
