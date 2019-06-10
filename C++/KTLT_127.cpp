#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructDate
{
    int day;
    int month;
    int year;
};
typedef StructDate Date;
bool validDate(int day,int month,int year)
{
    if(year < 1800)
    {
        printf("Không hợp lệ !\n");
        return false;
    }
    bool kt = true;
    int md;
    
    if(((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) && month == 2) md = 29;
    else
        switch (month)
    {
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
            md = 31; break;
        case 4 : case 6 : case 9 : case 11 :
            md = 30; break;
        case 2 :
            md = 28; break;
        default : md = 0;
    }
    if(day > 0 && day <= md) kt = true;
    else kt = false;
    if(!kt) printf("Không hợp lệ !\n");
    return kt;
}
void InputDate(Date &date)
{
    do
    {
        printf("\tNhập ngày - tháng - năm : ");
        scanf("%d %d %d", &date.day,&date.month,&date.year);
    } while (!validDate(date.day, date.month, date.year));
}
void InputManyDate(Date date[],int &n)
{
    printf("Nhập số phần tử mảng : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("NGÀY [%d] : \n",i);
        InputDate(date[i]);
    }
}
void OutputDate(Date date)
{
    printf("%.2d / %.2d / %d\n", date.day, date.month, date.year);
}
void OutputManyDate(Date date[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Ngày [%d] : ",i);
        OutputDate(date[i]);
    }
}
int DateCmp(Date a,Date b)
{
    if (a.year > b.year) return 1;
    else
        if(b.year > a.year) return -1;
        else
        {
            if (a.month > b.month) return 1;
            else
                if (a.month < b.month) return -1;
                else
                    if (a.day > b.day) return 1;
                    else
                        if(b.day > a.day) return -1;
        }
    // 1 - left > right
    //-1 - right > left
    //0 - equal
    return 0;
}
Date MaxDate(Date date[],int n)
{
    Date max = date[0];
    for (int i = 0; i < n; i++)
        if(DateCmp(date[i], max) == 1) max = date[i];
    return max;
}
void FilterBigger(Date date[],int n,Date B[], int &b,Date today)
{
    for (int i = 0; i < n; i++)
        if(DateCmp(date[i], today) == 1)
        {
            b++;
            B[b] = date[i];
        }
    b++;
}
void FilterSmaller(Date date[],int n,Date B[], int &b,Date today)
{
    for (int i = 0; i < n; i++)
        if(DateCmp(date[i], today) == -1)
        {
            b++;
            B[b] = date[i];
        }
    b++;
}
Date MinDate(Date date[],int n)
{
    Date min = date[0];
    for (int i = 0; i < n; i++)
        if(DateCmp(date[i], min) == -1) min = date[i];
    return min;
}
Date Closest(Date dateSmaller[],int s, Date dateBigger[],int b,Date today)
{
    Date small = MaxDate(dateSmaller, s);
    Date big = MinDate(dateBigger, b);
    Date A,B;
    A.day = today.day - small.day;
    A.month = today.month - small.month;
    A.year = today.year - small.year;
    B.day =  big.day - today.day;
    B.month = big.month - today.month;
    B.year = big.year - today.year;
    if (DateCmp(A, B) == 1)  return big;
    else return small;
}
void DatePlus(Date &date,int day,int month,int year)
{
    int md;
    date.day += day;
    date.month += month;
    date.year += year;
    
    if(((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) && month == 2) md = 29;
    else
        switch (date.month)
    {
        case 0 : case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
            md = 31; break;
        case 4 : case 6 : case 9 : case 11 :
            md = 30; break;
        case 2 :
            md = 28; break;
        default : md = 0;
    }
    if(day >=0 && month >= 0 && year >=0)
    {
        if(date.day > md)
        {
            date.day = 1;
            date.month ++;
        }
        if (date.month > 12)
        {
            date.month -= 12;
            date.year++;
        }
    }
    else
    {
        if(((date.year % 400 == 0) || (date.year % 4 == 0 && date.year % 100 != 0)) && date.month == 2) md = 29;
        else
        switch (date.month-1)
        {
            case 0: case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
                md = 31; break;
            case 4 : case 6 : case 9 : case 11 :
                md = 30; break;
            case 2 :
                md = 28; break;
            default : md = 0;
        }
        if(date.month-1 == 0)
        {
            date.month = 12;
            date.year--;
        }
        if (date.day == 0) date.day = md;
    }
}
void Generate(Date date[],Date nextday[],int n,int m)
{
    for (int i = 0; i < n ; i++)
    {
        nextday[i] = date[i];
        DatePlus(nextday[i], m, 0, 0);
    }
}
int caculate(Date date)
{
    int c = 0;
    for(int i = 1;i < date.month; i++)
    {
        int md;
        if(((date.year % 400 == 0) || (date.year % 4 == 0 && date.year % 100 != 0)) && i == 2) md = 29;
        else
        switch (i)
        {
            case 0: case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
                md = 31; break;
            case 4 : case 6 : case 9 : case 11 :
                md = 30; break;
            case 2 :
                md = 28; break;
            default : md = 0;
        }
        c += md;
    }
    c += date.day-1;
    return c;
}
void Count(Date date[],int countday[],int n)
{
    for(int i = 0;i < n;i++)
    {
        countday[i] = caculate(date[i]);
    }
}
int main()
{
    Date date[100], dateBigger[100], dateSmaller[100],nextDay[100],previusDay[100],today;
    int n ,b = -1,s = -1,countdate[100];
    InputManyDate(date, n);
    OutputManyDate(date, n);
    printf("\n----------------------------------------------------------\nNgày lớn nhất : ");
    OutputDate(MaxDate(date, n));
    printf("Nhập ngày hiện hành : \n");
    InputDate(today);
    printf("\n----------------------------------------------------------\nNgày bé nhất (những ngày lớn hơn ngày hiện hành) : ");
    FilterBigger(date, n, dateBigger, b, today);
    OutputDate(MinDate(dateBigger, b));
    FilterSmaller(date, n, dateSmaller, s, today);
    printf("\n----------------------------------------------------------\nNgày gần nhất : ");
    OutputDate(Closest(dateSmaller, s, dateBigger, b, today));
    printf("\n----------------------------------------------------------\nMảng những ngày kế tiếp : \n");
    Generate(date, nextDay, n, 1);
    OutputManyDate(nextDay, n);
    printf("\n----------------------------------------------------------\nMảng những ngày hôm trước : \n");
    Generate(date, previusDay, n, -1);
    OutputManyDate(previusDay, n);
    Count(date, countdate, n);
    printf("\n----------------------------------------------------------\nMảng khoảng cách từ ngày 1/1 \n");
    for (int i = 0; i <n; i++)
    {
        printf("B[%d] = %d \n", i, countdate[i]);
    }
    return 0;
}
//nghiapt1985@gmail.com
