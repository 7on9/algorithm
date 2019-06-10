#include <stdio.h>

struct StructPhanSo
{
    int tuSo;
    int mauSo;
};
typedef StructPhanSo PhanSo;
void NhapPhanSo(PhanSo &phanso)
{
    printf("Nhập tử số : ");
    scanf("%d",&phanso.tuSo);
    do
    {
        printf("Nhập mẫu số : ");
        scanf("%d",&phanso.mauSo);
        if(phanso.mauSo == 0) printf("Mẫu số phải khác 0 !\n");
    } while (phanso.mauSo == 0);
}
void XuatPhanSo(PhanSo phanSo)
{
    if(phanSo.mauSo != 1 && phanSo.mauSo != -1)
        printf("%d / %d \n",phanSo.tuSo,phanSo.mauSo);
    else printf("%d\n",phanSo.tuSo/phanSo.mauSo);
}
int UCLN(int lon,int be)
{
    for(int i = be;;i--)
        if(lon % i == 0 && be % i == 0) return i;
}
void RutGon(PhanSo &phanso)
{
    int UC;
    if(phanso.tuSo > phanso.mauSo)
    {
        UC = UCLN(phanso.tuSo, phanso.mauSo);
    } else  UC = UCLN(phanso.mauSo, phanso.tuSo);
    phanso.tuSo = phanso.tuSo / UC ;
    phanso.mauSo = phanso.mauSo / UC;
}
void Cong(PhanSo &phanso)
{
    printf("Nhập phân số muốn cộng thêm : \n");
    PhanSo phansoc;
    NhapPhanSo(phansoc);
    phanso.tuSo = (phanso.tuSo * phansoc.mauSo) + (phansoc.tuSo * phanso.mauSo);
    phanso.mauSo *= phansoc.mauSo;
    RutGon(phanso);
}
void Nhan(PhanSo &phanso)
{
    printf("Nhập phân số muốn nhân vào : \n");
    PhanSo phanson;
    NhapPhanSo(phanson);
    phanso.tuSo *= phanson.tuSo;
    phanso.mauSo *= phanson.mauSo;
    RutGon(phanso);
}
int main()
{
    PhanSo phanso;
    NhapPhanSo(phanso);
    XuatPhanSo(phanso);
    Cong(phanso);
    XuatPhanSo(phanso);
    Nhan(phanso);
    XuatPhanSo(phanso);
    return 0;
}
