#include <iostream>
#include <algorithm>
using namespace std;
struct StructFood
{
    int weight;
    int value;
};
typedef StructFood Food;
int n;
long long minimize,maximum,total;
bool cmp(Food A,Food B)
{
    
}
int main()
{
    Food *food;
    cin >> n;
    food = new Food[n+1];
    for (int i = 0; i < n; i++)
        cin >> food[i].weight >> food[i].value;
    
      
    delete food;
    return 0;
}
