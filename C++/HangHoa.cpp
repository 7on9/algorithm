
#include <stdio.h>

struct StructHangHoa
{
    char ID[10];
    char Name[50];
    int cost;
    char origin[20];
};
typedef StructHangHoa HangHoa;
void NhapMonHang(HangHoa hang)
{
    printf("Nhap ma mon hang: \n");
    scanf("%s",hang.ID);
    
}
