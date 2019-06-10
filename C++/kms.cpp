//
//  kms.cpp
//  CoMiIc
//
//  Created by Ống Tre on 2/6/18.
//  Copyright © 2018 Nguyen Long. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;
string s,s2;
set <char> sa;
int main()
{
    s ="TESTINGDEVELOPMENTJAVASCRIPTINNOVATIONKATALONINTEGRITYARCHITECTURE";
    s2="TESTINGDEVELOPMENTJAVASCRIPTINNOVATIONKATALONINTEGRITYARCHITECTUREKMS TECHNOLOGY";
    for(int i = 0; i < s2.size();i++)
        sa.insert(s2[i]);
    cout << sa.size() << endl;
    return 0;
}
/*
TESTINGDEVELOPMENTJAVASCRIPTINNOVATIONKATALONINTEGRITYARCHITECTUREKMS TECHNOLOGY
 
 2T + ESING = 69
 D + 3E + VLOPMNT = 120
 J + 2A + VSCRIPT = 110
 2I + 3N + 2O + VAT = 97
 K + 2A + TLON = 84
 2I + N + 2T + EGRY = 85
 AR + 2C + HI + 2T + 2E + UR = 144
 KMS TECHN + 2O + LGY =

*/
