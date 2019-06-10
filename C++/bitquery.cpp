
#include <bits/stdc++.h>
using namespace std;

int n, a, b, q, place;
map <int, int> ma;
long long x = 1;
void accepted()
{
	string task;
	int num;
	cin >> q;
	for(int i = 0;i < q; i++){
		cin >> task >> num;
		if(task == "add"){
			ma[num]++;
		}else{
			if(task == "del"){
				ma[num]--;
			}else{
					// cout << "task " << task << " " << num << endl;
				map <int, int>::iterator temp;
				int s = 0;
				for (temp = ma.begin(); temp != ma.end(); temp++)
				{
						// cout << temp->first << " " << temp->second << endl;
					if((temp->first & num) == temp->first)
						s += temp->second;
				}
				cout << s << endl;
			}
		}
	}
}
int main()
{
	accepted();
	return 0;
}

