#include <iostream>
using namespace std;
int a[100005];
int ta[100005];
int b[100005];

void xoa(int a[], int &na,int b[],int &nb)
{
    if(na==nb)
    {
        //di tu trai sang phai, xoa so be nhat
        int i=1; int v=0;
        while (i<na)
        {
            if(a[i]<a[v]) v=i;
            i++;
        }
        //xoa vi tri v
        int na1=na-1;
        for(int i=v;i<na1;i++)
            a[i]=a[i+1];
        na=na-1;
        return;
    }
    //na > nb
    int ia,ib;
    ia=ib=0;
    //truong hop co chuoi bang
    //xet ib theo ia
    int be=0;
    int toiluon=0;
    int tia=0;
    int maxaa=-1;
    
    for(ib=0;ib<nb;ib++)
    {
        
        if(toiluon!=1)
        {
            tia=ia;
            ta[ib]=ia;
            int vt=-1;
            int maxa=-1;
            while (ia<na && (na-ia)>=(nb-ib-1))
            {
                //tim max a[ia]<=b[ib], ia>=(nb-ib)
                if(a[ia]<=b[ib] && a[ia]>maxa )
                {  vt=ia; maxa=a[ia];}
                
                ia++;
                
                
            }
            
            //   cout<<"--\n";
            //    cout<<vt<<"\n";
            if(vt==-1) {
                while(vt==-1 && ib>0)
                {
                    ib--;
                    ia=ta[ib];
                    
                    
                    int maxa=-1;
                    while (ia<na && (na-ia)>=(nb-ib-1))
                    {
                        //tim max a[ia]<=b[ib], ia>=(nb-ib)
                        if(a[ia]<b[ib] && a[ia]>maxa )
                        {  vt=ia; maxa=a[ia];}
                        
                        ia++;
                    }
                    //     cout<<"**\n";
                    //    cout<<vt<<"\n";
                    if(vt>-1) break;
                    
                }
                // cout<<ib<<","<<vt<<"\n";
                if(ib==0) {be=1; break;}
                
            }
            //    cout<<"----\n";
            //     cout<<vt<<"\n";
            a[ib]=a[vt];
            
            // if(vt==-1) {ib--; maxaa=b[ib]-1;  ia=tia; continue;}
            if(b[ib]>a[ib]) toiluon=1;
            
            ia=vt+1;
        }else
        {
            int vt=ia;
            while (ia<na && (na-ia)>=(nb-ib))
            {
                //tim max a[ia]<=b[ib], ia>=(nb-ib)
                if(a[ia]>a[vt])
                {  vt=ia;}
                ia++;
                
                
            }
            //  cout<<a[vt]<<"\n";
            a[ib]=a[vt];
            ia=vt+1;
            
        }
        
        
        
    }
    
    if(be==1)
    {
        ia=0;
        int nb1=nb-1;
        for(ib=0;ib<nb1;ib++)
        {
            int vt=ia;
            
            while (ia<na && (na-ia)>=(nb-ib-1))
            {
                //tim max a[ia]<=b[ib], ia>=(nb-ib)
                if(a[ia]>a[vt])
                {  vt=ia;}
                ia++;
                
                
            }
            //  cout<<a[vt]<<"\n";
            a[ib]=a[vt];
            ia=vt+1;
            
        }
        na=nb-1;
        
        
    }else
        na=nb;
    
}
void xuat(int a[], int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i];
    cout<<"\n";
}

int main()
{
    //a[0]=4; a[1]=5; a[2]=6; a[3]=9; a[4]=2;
    // b[0]=1; b[1]=4; b[2]=5; b[3]=9;
    int na,nb;
    //na=5;nb=4;
    na=0;nb=0;
    string s1,s2;
    string s;
    cin>>s;
    s1=s;
    na=s.size();
    for(int i=0;i<na;i++)
        a[i]=s[i]-'0';
    
    cin>>s;
    s2=s;
    nb=s.size();
    for(int i=0;i<nb;i++)
        b[i]=s[i]-'0';
    
    if(s1>s2)
        xoa(a,na,b,nb);
    xuat(a,na);
    xuat(b,nb);
    int n;
    cin>>n;
    return 0;
}

