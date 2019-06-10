#include <iostream>
#include <math.h>
using namespace std;

int fun02(char *a1)
{
	size_t i; // [esp+18h] [ebp-10h]
	int v3; // [esp+1Ch] [ebp-Ch]
	
	v3 = 0;
	for ( i = 0; i < strlen(a1); ++i )
		v3 += 3 * a1[i];
	return v3;
}

int fun01(char *a1)
{
	size_t i; // [esp+14h] [ebp-14h]
	int v3; // [esp+18h] [ebp-10h]
	signed int v4; // [esp+1Ch] [ebp-Ch]
	
	v3 = 0;
	for ( i = 0; i < strlen(a1); ++i )
	{
		if ( i )
			v4 = abs(a1[i] - a1[i - 1]);
		else
			v4 = 12;
		v3 += v4;
	}
	return v3;
}

int main()
{
	int v3; // eax
	int v4; // eax
	int result; // eax
	int v6; // [esp+1Bh] [ebp-7E5h]
	int v7; // [esp+1Fh] [ebp-7E1h]
	int v8; // [esp+23h] [ebp-7DDh]
	char v9; // [esp+27h] [ebp-7D9h]
	char v10; // [esp+28h] [ebp-7D8h]
	char v11; // [esp+410h] [ebp-3F0h]
	int v12; // [esp+7F8h] [ebp-8h]
	size_t v13; // [esp+7FCh] [ebp-4h]
	
		//__main();
	v6 = 1986095938;
	v7 = 1969448275;
	v8 = 2037672306;
	char a[] = "BkavSecurity";
	v9 = 0;
	printf("Enter the password: ");
		//gets(&v11);
	v13 = 2488978 * 12/ 3;
	v3 = fun01(a);
	v12 = (signed int)(v13 * v3) >> 10;
	v4 = fun02(a);
	v12 ^= v4;
	sprintf(&v10, "%i-0x123456789", v12);
	cout << &v10 << endl;;
	strcpy(&v11,&v10);
	//scanf("%s", &v11);
	if ( !strcmp(&v10, &v11) )
	{
		printf("Your Password Is A Flag!");
		result = 0;
	}
	else
	{
		printf("Invalid Password. Pleas try again!");
		result = 1;
	}
	return result;
}
