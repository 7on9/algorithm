#include <stdio.h>

struct  StructTime
{
    int Gio;
    int Phut;
    int Giay;
};
typedef StructTime Time;
void NhapThoiGian(Time &tg)
{
    do
    {
        printf("Nhập giờ : ");
        scanf("%d",&tg.Gio);
        if(tg.Gio > 24 || tg.Gio < 0) printf("Nhập sai !\n");
        
    }while (tg.Gio > 24 || tg.Gio < 0);
    do
    {
        printf("Nhập phút : ");
        scanf("%d",&tg.Phut);
        if(tg.Phut > 60 || tg.Phut < 0) printf("Nhập sai !\n");
    }while (tg.Phut > 60 || tg.Phut < 0);
    do
    {
        printf("Nhập giây : ");
        scanf("%d",&tg.Giay);
        if(tg.Giay > 60 || tg.Giay < 0) printf("Nhập sai !\n");
    }while (tg.Giay > 60 || tg.Giay < 0);
}
void XuatThoiGian(Time tg)
{
    printf("%.2d : %.2d : %.2d\n",tg.Gio,tg.Phut,tg.Giay);
}
int ConvertToSecond(Time tg)
{
    int giay = tg.Giay + tg.Phut * 60 + tg.Gio * 3600 ;
    return giay;
}
void ConvertToTime(Time &tg,int giay)
{
    tg.Gio = giay / 3600;
    giay %= 3600;
    tg.Phut = giay / 60;
    giay %= 60;
    tg.Giay = giay;
}
int KhoangCach(Time tg,Time tg2)
{
    //this is place where the "margik" happen !
    if(tg.Gio > tg2.Gio)
    {
        tg.Gio -= 12;
        tg2.Gio += 12;
    }
    return (ConvertToSecond(tg2)-ConvertToSecond(tg));
}
int main()
{
    Time tg,tg2,tg3;
    printf("Nhập t1 : \n");
    NhapThoiGian(tg);
    printf("Nhập t2 : \n");
    NhapThoiGian(tg2);
    printf("%d giây !\n",KhoangCach(tg,tg2));
    ConvertToTime(tg3, KhoangCach(tg, tg2));
    XuatThoiGian(tg3);
    return 0;
}
