//robot ăn điểm

#include <iostream>
const int maxn  = 1e9;
using namespace std;
bool check[maxn];
int n,l,r,go,dem;
void Caculate(bool check[],int k,int pos)
{
    if(k < 0) return;
    if(!check[pos])
    {
        check[pos]= true;
        dem++;
    }
    if (pos - l > 0  && !check[pos-l])
    {
        // if((check[pos-l] && pos+r <= n && check[pos-r])||(!check[pos+r] && !check[pos-l]) || check[pos+r])
        return Caculate(check, k-1, pos-l);
    }
    else
    if (pos + r <= n)
    {
       // if((check[pos+r] && pos-l >= 0 && check[pos-l])||(!check[pos+r] && !check[pos-l]) || check[pos-l])
        return Caculate(check, k-1, pos+r);
    }
    else  if (pos - l > 0) return Caculate(check, k-1, pos-l);
}
int main()
{
    cin >> n >> r >> l >> go;

    //check = new bool(n);
    Caculate(check, go, 1);
    cout <<n- dem <<endl;
    //free(check);
    return 0;
}
