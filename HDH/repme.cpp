#include <iostream>
using namespace std;
char input[100], tel,te2, te3;
bool check1()
{
  unsigned int v1; // [rsp+8h] [rbp-8h]
  signed int i; // [rsp+Ch] [rbp-4h]

  v1 = 0;
  for ( i = 0; i <= 9; ++i )
  {
    *(&te1 + i) = input[i] ^ a1[i];
    v1 += *(&te1 + i);
  }
  printf("\n%d\n", v1);
  return v1 == 0x251;
}
bool check2()
{
  unsigned int v1; // [rsp+8h] [rbp-8h]
  signed int i; // [rsp+Ch] [rbp-4h]

  v1 = 0;
  for ( i = 0; i <= 9; ++i )
  {
    *(&te2 + i) = input[i + 10] ^ a2[i];
    v1 += *(&te2 + i);
  }
  printf("%d\n", v1);
  return v1 == 502;
}
bool check3()
{
  unsigned int v1; // [rsp+8h] [rbp-8h]
  signed int i; // [rsp+Ch] [rbp-4h]

  v1 = 0;
  for ( i = 0; i <= 9; ++i )
  {
    *(&te3 + i) = input[i + 20] ^ a3[i];
    v1 += *(&te3 + i);
  }
  printf("%d\n", v1);
  return v1 == 476;
}
int final()
{
  char dest; // [rsp+0h] [rbp-30h]
  unsigned long long v2; // [rsp+28h] [rbp-8h]

  v2 = (0x28u);
  strcat(&dest, &te1);
  strcat(&dest, &te2);
  strcat(&dest, &te3);
  if ( te1 + byte_602101 != '�'
    || byte_602101 + byte_602102 != 't'
    || byte_602102 + byte_602103 != 'D'
    || byte_602103 + byte_602104 != 'H'
    || byte_602108 + byte_602109 != '�'
    || byte_602108 + byte_602104 != '�' )
  {
    puts("check1 not pass");
  }
  else
  {
    puts("check1 pass");
  }
  if ( te2 + byte_6020E1 != 161
    || byte_6020E1 + byte_6020E2 != '^'
    || byte_6020E2 + byte_6020E3 != 81
    || byte_6020E7 + byte_6020E3 != '='
    || byte_6020E7 + byte_6020E8 != '='
    || byte_6020E8 + byte_6020E9 != 'M' )
  {
    puts("check2 not pass");
  }
  else
  {
    puts("check2 pass");
  }
  if ( te3 + byte_6020F1 != 180
    || byte_6020F1 + byte_6020F2 != 174
    || byte_6020F2 + byte_6020F3 != 'V'
    || byte_6020F3 + byte_6020F4 != 'I'
    || byte_6020F5 + byte_6020F4 != '\\' )
  {
    puts("check3 not pass");
  }
  else
  {
    puts("check3 pass");
  }
  return flag();
}
int main()
{
  puts("Your name plzz ? :");
  char str[1000];
  //gets(input, argv);
  char str [] = {'m','e','{','-','1','s','-','F', 'R', 'C','1','}'};
  byte_6020C5 = 'm';
  byte_6020C6 = 'e';
  byte_6020C7 = '{';
  byte_6020CF = '1';
  byte_6020D0 = 's';

  byte_6020D1 = 'F';
  byte_6020DC = 'R';
  byte_6020DD = 'C';
  byte_6020DE = '1';
  byte_6020DF = '}';
  printf("your name is :%s", input);
  if ( byte_6020CA != '-' || byte_6020D5 != '-' )
  {
    puts("wrong");
    exit(0);
  }
  if ( (unsigned int)check1() && (unsigned int)check2() && (unsigned int)check3() )
    final();
  exit(0);
}
