#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct KHACHHANG_SIM
{
	unsigned int sdt;
	char hoten[51];
	int tuoi;
}KH;
//--------------------------------------------------------------------------------
struct node
{
    KH info;
    node *pLeft ;
    node *pRight ;
};
typedef node Node;
typedef Node *Tree;
//--------------------------------------------------------------------------------
//Ham khoi tao cay
void Init(Tree tree)
{
    tree = NULL;
}
//--------------------------------------------------------------------------------
void NhapSdt(unsigned int &n)
{
	printf("Nhap sdt : ");
    scanf("%ud",&n);
}
//--------------------------------------------------------------------------------
void NhapTen(char S[])
{
	printf("Nhap ten : ");
	fflush(stdin);
	gets(S);
}
//--------------------------------------------------------------------------------
void InputX(KH &x)
{
	printf("Nhap thong tin kh :\n");
    NhapSdt(x.sdt);
    NhapTen(x.hoten);
    printf("Nhap tuoi : ");
    scanf("%d",&x.tuoi);
}
//--------------------------------------------------------------------------------
void Output1KH(KH a)
{
    printf("%-10d%-40s%d\n",a.sdt,a.hoten,a.tuoi);
}
//--------------------------------------------------------------------------------
//tao Node
Node *CreateNode(KH x)
{
    Node *pTM = new Node;
    if (pTM == NULL) return NULL;//Kiem tra con du bo nho de tao hay khong
    pTM->info = x;
    pTM->pLeft = NULL;
    pTM->pRight = NULL;
    return pTM;
}
//--------------------------------------------------------------------------------
//chen Node
int insertNodesdt(Tree &tree,KH x)
{
    if(tree != NULL)
    {
        if (tree->info.sdt < x.sdt)
            return insertNodesdt(tree->pRight, x); //neu node goc be hon -> node lon hon -> dua ve ben phai
        if (tree->info.sdt > x.sdt)
            return insertNodesdt(tree->pLeft, x);
        return 0;  //Trung khoa
    }
    Node *p = CreateNode(x);
    tree = p;
    if (tree != NULL) return 1; //them thanh cong
    return -1; //them that bai - khong du bo nho
}
//--------------------------------------------------------------------------------
//chen Node
int insertNodeTen(Tree &tree,KH x)
{
    if(tree != NULL)
    {
        if (strcmp(tree->info.hoten,x.hoten) < 0)
            return insertNodeTen(tree->pRight, x); //neu node goc be hon -> node lon hon -> dua ve ben phai
        if (strcmp(tree->info.hoten,x.hoten) > 0)
            return insertNodeTen(tree->pLeft, x);
        return 0;  //Trung khoa
    }
    Node *p = CreateNode(x);
    tree = p;
    if (tree != NULL) return 1; //them thanh cong
    return -1; //them that bai - khong du bo nho
}
//--------------------------------------------------------------------------------
//chen Node
int insertNodeTuoi(Tree &tree,KH x)
{
    if(tree != NULL)
    {
        if (tree->info.tuoi < x.tuoi)
            return insertNodeTuoi(tree->pRight, x); //neu node goc be hon -> node lon hon -> dua ve ben phai
        if (tree->info.tuoi > x.tuoi)
            return insertNodeTuoi(tree->pLeft, x);
        return 0;  //Trung khoa
    }
    Node *p = CreateNode(x);
    tree = p;
    if (tree != NULL) return 1; //them thanh cong
    return -1; //them that bai - khong du bo nho
}
//--------------------------------------------------------------------------------
//Xuat cay
void OutputLNR(Tree &tree) //LNR
{
    if (tree == NULL) return;
    OutputLNR(tree->pLeft);
    Output1KH(tree->info);
    OutputLNR(tree->pRight);
    //printf("\n");
}
//--------------------------------------------------------------------------------
//TIm node
Node *searchNodeSdt(Tree &tree,int x)
{
    if (tree == NULL) return NULL;
    if (tree->info.sdt == x) return tree;
    if (tree->info.sdt > x) return searchNodeSdt(tree->pLeft, x);
    if (tree->info.sdt < x) return searchNodeSdt(tree->pRight, x);
    return NULL;
}
//--------------------------------------------------------------------------------
// Tim phan tu pX bi xoa, cho phan tu pTM len thay the
void TimTheMang(Tree &pX, Tree &pTM)
{
    // tim phan tu trai nhat cua cay ben phai
    //if(tree==NULL) return;
    if(pTM->pLeft!=NULL)
        TimTheMang(pX,pTM->pLeft);
    else 
    {
        pX->info = pTM->info;
        pX = pTM;
        pTM = pTM->pRight;
    }
}
//----------------------------------------------------------------------------
// xoa phan tu
int DelNodesdt(Tree &tree, int x)
{
    if(tree==NULL) return -1;
    if(tree->info.sdt > x) return DelNodesdt(tree->pLeft,x);
    if(tree->info.sdt < x) return DelNodesdt(tree->pRight,x);
    if(tree->info.sdt == x)
    { // khi tim ra phan tu do roi
        // xoa Node la hoac Node co 1 phan tu
        Node *pX = tree;// xoa phan tu bang con tro
        if(tree->pLeft==NULL) { // neu ma ben traiphan tu do bang NULL
            tree=tree->pRight; // cho tree tro toi tree->pRight
        }
        else if(tree->pRight==NULL){
            tree = tree->pLeft;
        }
        // xoa Node co 2 phan tu Trai va Phai
        else TimTheMang(pX,tree->pRight);
        delete pX;
    }
    return 1;
}
//--------------------------------------------------------------------------------
//dem node
int Count(Tree tree)
{
   if(tree==NULL)
      return 0;
   else
      return (1+Count(tree->pLeft)+Count(tree->pRight));
}
//--------------------------------------------------------------------------------
//dem node le
void CountSdtLe(Tree tree,int &count)
{
   if(tree!=NULL)
   {
      CountSdtLe(tree->pLeft,count);
      if((tree->info.sdt)%2!=0)
         count++;
      CountSdtLe(tree->pRight,count);
   }
}
//--------------------------------------------------------------------------------
//chieu cao cay
int HeightTree(Node *tree)
{
   if(tree==NULL)
    return 0;
   int HeightLeft = HeightTree(tree->pLeft);
   int HeightRight = HeightTree(tree->pRight);
   return (HeightLeft >= HeightRight ? HeightLeft : HeightRight)+1;
}
//--------------------------------------------------------------------------------
void getTreeSdt(Tree &tree,KH A[],int n)
{
    for(int i = 0;i < n;i++ )
        insertNodesdt(tree,A[i]);
}
//--------------------------------------------------------------------------------
void getTreeTen(Tree &tree,KH A[],int n)
{
    for(int i = 0;i < n;i++ )
        insertNodeTen(tree,A[i]);
}
//--------------------------------------------------------------------------------
void getTreeTuoi(Tree &tree,KH A[],int n)
{
    for(int i = 0;i < n;i++ )
        insertNodeTuoi(tree,A[i]);
}
//--------------------------------------------------------------------------------
void getData(KH A[],int n)
{
    for(int i = 0;i < n; i++)
    {
        printf("------------------------\nNhap khach hang %d\n",i);
        InputX(A[i]);
    }
}
//--------------------------------------------------------------------------------
int main()
{
    //--------------------------------------------------------------------------------
    int n = 10;
    // printf("Nhap so KH : ");
    // scanf("%d",&n);
    // KH A[n];
    // getData(A,n);
    KH ds[10] = {   {123412,"Hoang Ba Minh",23},
                    {123423,"Nguyen Nam Tu",17},
                    {123416,"Hoang Trung Kien",23},
                    {123498,"Nguyen Hue",18},
                    {123469,"Phan Quan",24},
                    {123496,"Tran Ba Su",54},
                    {123422,"Ho Minh Duc",22},
                    {123452,"Nguyen Anh Dung",15},
                    {123418,"Tran Le Thao Lien",16},
                    {123457,"Le Thinh Phu",19}  };
    //--------------------------------------------------------------------------------
    Tree treeTen,treeTuoi,treeSdt ;
    Init(treeSdt);
    Init(treeTen);
    Init(treeTuoi);
    //--------------------------------------------------------------------------------
    getTreeSdt(treeSdt,ds,n);
    printf("Cay theo sdt :\n");
    OutputLNR(treeSdt);
    //--------------------------------------------------------------------------------
    getTreeTen(treeTen,ds,n);
    printf("Cay theo Ten :\n");
    OutputLNR(treeTen);
    //--------------------------------------------------------------------------------
    getTreeTuoi(treeTuoi,ds,n);
    printf("Cay theo tuoi :\n");
    OutputLNR(treeTuoi);
    //--------------------------------------------------------------------------------
    printf("\nChieu cao cay sdt : %d\n",HeightTree(treeSdt));
    //--------------------------------------------------------------------------------
    int d = 0;
    CountSdtLe(treeSdt,d);
    printf("Sdt le : %d\n",d);
    //--------------------------------------------------------------------------------
    printf("Nhap sdt muon xoa : ");
    scanf("%d",&n);
    d = DelNodesdt(treeSdt,n);
    if(d == 1) OutputLNR(treeSdt);
    else printf("Khong co sdt %d trong cay\n",n);
    //--------------------------------------------------------------------------------
    printf("\n");
    return 0;
}
