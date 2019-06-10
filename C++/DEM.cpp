#include <iostream>
#include <vector>
#define mod 4294967296
using namespace std;
string s;
int i, len;
vector <int> num;
unsigned int res = 0;
class Item
{
public:
    Item()
    {
        mod0 = mod1 = mod2 = 0;
    }
    Item(unsigned int mod0, unsigned int mod1, unsigned int mod2)
    {
        this->mod0 = mod0;
        this->mod1 = mod1;
        this->mod2 = mod2;
    }
    Item(Item *a)
    {
        mod0 = a->mod0;
        mod1 = a->mod1;
        mod2 = a->mod2;
    }
    Item operator+(Item const &b)
    {
        Item item;
        item.mod0 = (this->mod0*b.mod0)+(this->mod1*b.mod2)+(this->mod2*b.mod1)%mod;
        item.mod1 = (this->mod0*b.mod1)+(this->mod1*b.mod0)+(this->mod2*b.mod2)%mod;
        item.mod2 = (this->mod0*b.mod2)+(this->mod2*b.mod0)+(this->mod1*b.mod1)%mod;
        return item;
    }
    unsigned int mod0;
    unsigned int mod1;
    unsigned int mod2;
    
};
void getData()
{
    cin >> s;
    len = s.size();
    num.resize(len + 1);
    for(i = 0; i < len; i++)
        num[i + 1] = s[i] - '0';
}
Item ans(int left, int right)
{
    if(left > right) return new Item(0, 0, 0);
    if(left == right)
    {
        switch (num[left]%3)
        {
            case 0:
                return new Item(2, 0 , 0);
                break;
            case 1:
                return new Item(1, 1 , 0);
                break;
            case 2:
                return new Item(1, 0 , 1);
                break;
        }
    }
    Item l = ans(left, (left + right)/2);
    Item r = ans((left + right)/2 + 1, right);
    return r+l;
}
int main()
{
    getData();
    Item temp = ans(1, len);
    cout << temp.mod0-1 << endl;
    //cout << res + max(((temp.mod0-1)*(temp.mod0-1)), 0) << endl;
    return 0;
}

