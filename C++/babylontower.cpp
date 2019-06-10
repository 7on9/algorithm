//https://www.hackerrank.com/contests/free-contest/challenges/babylontower
#include <iostream>
#include <algorithm>
#define MAX 605
using namespace std;

class Brick
{
  public:
    Brick()
    {
        x = y = z = 0;
    }
    Brick(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    int x;
    int y;
    int z;
};

Brick brick[MAX];
int arr[MAX], total;

void reset()
{
    for (int i = 0; i < MAX; i++)
        arr[i] = 0;
}

int solve(int i)
{
    if (arr[i])
        return arr[i];
    int maxHeight, j;
    for (maxHeight = j = 0; j < total; j++)
        if (brick[j].x < brick[i].x && brick[j].y < brick[i].y)
            maxHeight = max(solve(j), maxHeight);
    return arr[i] = maxHeight + brick[i].z;
}

void solveTest()
{
    int n, i, k, x, y, z, maxHeight;
    cin >> n;
    if (!n)
        return;
    reset();
    for (i = k = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        brick[k++] = (x < y) ? Brick(x, y, z) : Brick(y, x, z);
        brick[k++] = (x < z) ? Brick(x, z, y) : Brick(z, x, y);
        brick[k++] = (y < z) ? Brick(y, z, x) : Brick(z, y, x);
    }
    total = k;
    for (i = maxHeight = 0; i < total; i++)
        maxHeight = max(solve(i), maxHeight);
    cout << maxHeight << endl;
    solveTest();
}
int main()
{
    solveTest();
    return 0;
}
