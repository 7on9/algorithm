#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s;
    
    char f[10];
    
    f[0]='a'; f[1]='o'; f[2]='u'; f[3]='e'; f[4]='i'; f[5]='y';
    
    cin >> s;
    string b = "";
    int len=s.size();
    
    for (int i=0;  i<len; i++){
        bool kt = true;
        s[i] = tolower(s[i]);
        for (int j=0; j<6; j++)
            if (s[i]==f[j])  kt = false;
        if(kt){
            b+='.';
            b+= s[i];
        }
    }
    cout << b << endl;
    
}