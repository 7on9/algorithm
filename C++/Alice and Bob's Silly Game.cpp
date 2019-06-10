#include <iostream>
#include <vector>
#define MAXN 100002
using namespace std;

/*
 * Complete the sillyGame function below.
 */
bool mark[MAXN+2];
int numOfPrime[MAXN+2];
void prepare(){
	mark[0] = mark[1] = false;
	int nt = 0;
	for(int i = 2; i <= MAXN; i++)
	{
		mark[i] = true;
	}
	for(int i = 2; i <= MAXN; i++) {
		if (mark[i]) {
			nt++;
			for(int j = i*i; j <= MAXN; j+=i) {
				if(j > MAXN || j < 0)
					break;
				else
				mark[j] = false;
			}
		}
		numOfPrime[i] = nt;
	}
}
string sillyGame(int n) {
	
	return (numOfPrime[n]%2==1) ? "Alice": "Bob";
}

int main()
{
	
	int g, n;
	prepare();
	cin >> g;
	while(g--){
		cin >> n;
		cout << sillyGame(n) << "\n";
	}
	
	return 0;
}
