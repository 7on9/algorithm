#include <iostream>
#include <algorithm>
using namespace std;
long long sum[300001],*Mang,maxn;
int main()
{
    int n;
    cin >> n;
    Mang = new long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Mang[i];
        if(i > 1)
        {
            sum[i] = Mang[i] + Mang[i-1] + Mang[i-2]; //sum[i] = tong 3 so  lien tiep nhau
            if(i == 2)
                maxn = sum[i];
            if(i > 2)
                sum[i] = max(sum[i],sum[i]+sum[i-3]); //xet tong 3 so lien tiep ngay gan +  them tong 3 so lien tiep trc do co > hon hay khong thi moi lay
            maxn = max(maxn,sum[i]); //tim max
        }
    }
    cout << maxn << endl;
    delete Mang;
    return 0;
}
