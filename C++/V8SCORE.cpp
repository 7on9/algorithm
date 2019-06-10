#include <iostream>
using namespace std;
int s, k, n, tempS;
bool found;
int data[22][22];
int score[22];
void swap(int &a, int &b)
{
    a ^= b;
    b = a ^ b;
    a ^= b;
}

void getReady()
{
    score[0] = -1;
    found = false;
    cin >> s >> k >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            cin >> data[i][j];

    for (int i = 1; i <= k; i++)
        for (int j = 1; j < n; j++)
            for (int l = j + 1; l <= n; l++)
                if (data[j][i] < data[l][i])
                    swap(data[j][i], data[l][i]);
}

void print(void)
{
    if (s != tempS)
        return;
    cout << "YES\n";
    for (int i = 1; i <= k; i++)
        cout << score[i] << " ";
    found = true;
}

void findScore(int prob)
{
    for (int i = 1; i <= n; i++)
    {
        if (data[i][prob] < score[prob - 1])
            break;
        score[prob] = data[i][prob];
        tempS += data[i][prob];
        if (s - tempS >= score[prob] * (k - prob))
        {
            if (prob == k)
                print();
            else 
                if (!found)
                    findScore(prob + 1);
        }
        tempS -= data[i][prob];
    }
}

int main()
{
    getReady();
    findScore(1);
    if (!found)
        cout << "NO\n";
    return 0;
}