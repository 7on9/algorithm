#include <iostream>
#include <vector>
using namespace std;
vector <int> arr;
vector <int> res;
string c;
int n;
void solve()
{
	fflush(stdin);
	cin >> c;
    for(int i = 0; i < n;i++)
    {
        int s = 0;
        if (c[i] == 'E')
            for(int j = 0, s = 0; i + j < n; j++)
            {
                if(arr[i+j] <= arr[i]) s++;
                else break; 
            }
        else
            for(int j = 0, s = 0 ; j <= i; j++)
            {
                if(arr[j] < arr[i]) s++;
				else break;
            }
        res[i] = s;
		
	}
}
void input()
{
    int  temp;
	cin >> n;
    for(int i = 0; i < n;i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

}
int main()
{
	input();
	solve();
    return 0;
}
