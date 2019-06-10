#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class Bloc
{
  public:
    int h;
    int c;
    Bloc()
    {
        h = 0;
        c = 0;
    };

    Bloc(int h, int c)
    {
		this->h = h;
		this->c = c;
    };
	Bloc(Bloc const &a)
	{
		this->h = a.h;
		this->c = a.c;
	};
};

queue<Bloc> que;
vector<Bloc> go;

Bloc start, flag;

int s, x;
bool square[33][33];
bool visited[33][33];
Bloc trace[33][33];
bool found = false;

void init()
{
    cin >> s >> start.h >> start.c >> flag.h >> flag.c;
	
	for (int i = 1; i <= s; i++)
		for (int j = 1; j <= s; j++)
		{
			cin >> x;
			square[i][j] = (x > 0) ? false : true;
		}
	
    for (int i = 0; i <= s+1; i++)
		for (int j = 0; j <= s+1; j++)
		{
			if (i == 0 || i == s+1 || j == 0 || j == s+1){
                visited[i][j] = true;
				square[i][j] = false;
			}
            else
				visited[i][j] = false;
		}
}

void prin(){
	Bloc temp = Bloc(flag);
	go.push_back(temp);
	do{
		temp = Bloc(trace[temp.h][temp.c]);
		go.push_back(temp);
		if(temp.c == start.c && temp.h == start.h)
			break;
	} while (1);
	
	cout << go.size() << endl;
	
	for (int i = go.size() - 1; i >= 0; i--) {
		cout << go[i].h << " " << go[i].c << endl;
	}
	
}

bool isValid(int h, int c){
	if(h == 0 || c == 0 || found)
		return false;
	if(h > s || c > s)
		return false;
	if (!square[h][c] || visited[h][c])
		return false;
	return true;
}
void bfs(int h, int c)
{
	que.pop();
	if (!isValid(h, c) || found)
		return;
//	go.push_back({h, c});
	visited[h][c] = true;

	if(flag.c == c && flag.h == h){
		found = true;
        prin();
		return;
	}
	Bloc temp = Bloc(h + 1, c);
	if(isValid(h + 1, c)){
		que.push(temp);
		trace[h + 1][c] = Bloc({h, c});
	}
	temp = Bloc(h - 1, c);
	if(isValid(h - 1, c)){
		que.push(temp);
		trace[h - 1][c] = Bloc({h, c});
	}
	temp = Bloc(h, c + 1);
	if(isValid(h, c + 1)){
		que.push(temp);
		trace[h][c + 1] = Bloc({h, c});
	}
	temp = Bloc(h, c - 1);
	if(isValid(h, c - 1)){
		que.push(temp);
		trace[h][c - 1] = Bloc({h, c});
	}
	
//	go.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(0);
    init();

	visited[start.h][start.c] = false;
	square[start.h][start.c] = true;
	
	que.push(start);
	
	while (!que.empty()) {
		bfs(que.front().h, que.front().c);
	}
	
	if(!found)
		cout << "0" << endl;
	
	return 0;
}
