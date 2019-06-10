#include <iostream>
using namespace std;
//hau = hang
int hau[8];
int dem;
bool cot[8],cheo_chinh[15],cheo_phu[15];
void Xuat()
{
    cout << ++dem << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            if(hau[i] != j) cout << ".    ";
            else cout << "w    ";
        cout << endl;
    }
    cout << "_______________________________" << endl;
}
void solve(int x)
{
    for(int  i = 0;i < 8;i++)
            if(!cot[i] && !cheo_chinh[i+x] && !cheo_phu[i-x+8])
            {
                //dat hau
                hau[x] = i;  // datt hau thu x cot i
                
                cot[i] = true;
                cheo_chinh[x+i] = true;
                cheo_phu[i-x+8] = true;
                //
                
                if( x == 7) Xuat();
                else solve(x+1);
                
                cot[i] = false;
                cheo_chinh[x+i] = false;
                cheo_phu[i-x+8] = false;
            }
}
int main()
{
   solve(0);
//    int i;
//    for (i=0; i<8; i++) {
//        cot[i]  = 1;
//    }
//    for (i=0; i<2*8; i++) {
//        cheo_phu[i] = 1;
//        cheo_chinh[i] = 1;
//    }
//    Try(0);
    return 0;
}
