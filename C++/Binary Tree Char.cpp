#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100
//Ham tien ich
int NgauNhien(int a,int b)
{
    if(a >= b) return 0;
    return (rand()%(b-a+1)+a);
}
//Ket thuc ham tien ich
//--------------------------------------------------------------------------------
struct node
{
    char info;
    node *pLeft ;
    node *pRight ;
};
typedef node Node;
typedef Node *Tree;
//--------------------------------------------------------------------------------
//Ham khoi tao cay
void Init(Tree &tree)
{
    tree = NULL;
}
//--------------------------------------------------------------------------------
//tao Node
Node *CreateNode(char x)
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
int insertNode(Tree &tree,char x)
{
    if(tree != NULL)
    {
        if (tree->info < x) 
            return insertNode(tree->pRight, x); //neu node goc be hon -> node lon hon -> dua ve ben phai
        if (tree->info > x) 
            return insertNode(tree->pLeft, x);
        return 0;  //Trung khoa
    }
    tree = CreateNode(x);
    if (tree != NULL) return 1; //them thanh cong
    return -1; //them that bai - khong du bo nho
}
//--------------------------------------------------------------------------------
void OutputNLR(Tree tree)
{
    if (tree == NULL) return;
    printf("%c\t",tree->info);
    OutputNLR(tree->pLeft);
    OutputNLR(tree->pRight);
    //printf("\n");
}
//--------------------------------------------------------------------------------
void OutputLNR(Tree tree)
{
    if (tree == NULL) return;
    OutputLNR(tree->pLeft);
    printf("%c\t",tree->info);
    OutputLNR(tree->pRight);
    //printf("\n");
}
//--------------------------------------------------------------------------------
void OutputLRN(Tree tree)
{
    if (tree == NULL) return;
    OutputLRN(tree->pLeft);
    OutputLRN(tree->pRight);
    printf("%c\t",tree->info);
    //printf("\n");
}
//--------------------------------------------------------------------------------
//TIm node
Node *searchNode(Tree tree,int x)
{
    if (tree == NULL) return NULL;
    if (tree->info == x) return tree;
    if (tree->info > x) return searchNode(tree->pLeft, x);
    if (tree->info < x) return searchNode(tree->pRight, x);
    return NULL;
}
//--------------------------------------------------------------------------------
// Tim phan tu pX bi xoa, cho phan tu pTM len thay the
void TimTheMang(Tree &pX, Tree &pTM)
{
    // tim phan tu trai nhat cua cay ben phai
    //if(tree==NULL) return;
    if(pTM->pLeft!=NULL){
        TimTheMang(pX,pTM->pLeft);
    }
    else
    {
        pX->info = pTM->info;
        pX=pTM;
        pTM=pTM->pRight;
    }
}
// xoa phan tu
int DelNode(Tree &tree, int x)
{
    if(tree==NULL) return -1;
    if(tree->info > x) return DelNode(tree->pLeft,x);
    if(tree->info < x) return DelNode(tree->pRight,x);
    if(tree->info == x) 
    { // khi tim ra phan tu do roi
        // xoa Node la hoac Node co 1 phan tu
        Node *pX = tree;// xoa phan tu bang con tro
        if(tree->pLeft==NULL)
        {// neu ma ben traiphan tu do bang NULL
            tree=tree->pRight; // cho tree tro toi tree->pRight
        }
        else if(tree->pRight==NULL)
        {
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
void CountNodeLeaf(Tree tree,int &count)
{
   if(tree!=NULL)
   {
      CountNodeLeaf(tree->pLeft,count);
      if(tree->pLeft == NULL && tree->pRight == NULL)
         count++;
      CountNodeLeaf(tree->pRight,count);
   }
}
//--------------------------------------------------------------------------------
//chieu cao cay
int HeightTree(Tree tree)
{
   if(tree==NULL)
    return 0;
   int HeightLeft = HeightTree(tree->pLeft);
   int HeightRight = HeightTree(tree->pRight);
   return (HeightLeft >= HeightRight ? HeightLeft : HeightRight)+1;
}
//--------------------------------------------------------------------------------
void GenerateTree(Tree &tree,int n,char A[])
{
    for(int i = 0;i < n;i++ )
        insertNode(tree,A[i]);
}
//--------------------------------------------------------------------------------
void Output(Tree tree)
{
    printf("\nXuat NLR :\n");
    OutputNLR(tree);
    //--------------------------------------------------------------------------------
    printf("\nXuat LNR :\n");
    OutputLNR(tree);
    //--------------------------------------------------------------------------------
    printf("\nXuat LRN :\n");
    OutputLRN(tree);
}
//--------------------------------------------------------------------------------
void GenerateArray(char A[],int n)
{
    for(int i = 0;i < n;i++)
        A[i] = NgauNhien(65,90);
}
//--------------------------------------------------------------------------------
int main()
{
    srand((unsigned int)time(NULL));
    Tree tree ;
    Init(tree);
    int n;
    // printf("Nhap so ki tu muon khoi tao : ");
    // scanf("%d",&n);
    // char A[n];
    // GenerateArray(A,n);
    n = 9;
    char A[] = {'G','K','M','A','E','C','O','I','B'};
    //--------------------------------------------------------------------------------
    GenerateTree(tree,n,A);
    //--------------------------------------------------------------------------------
    printf("Mang ki tu ban dau : \n");
    for(int i = 0;i < n;i++)
        printf("%c\t",A[i]);
    Output(tree);
    //--------------------------------------------------------------------------------
    printf("\nChieu cao cay : %d\n",HeightTree(tree));
    //--------------------------------------------------------------------------------
    int d = 0;
    CountNodeLeaf(tree,d);
    printf("So node la : %d\n",d);
    //--------------------------------------------------------------------------------
    //char c;
    // printf("Nhap node muon xoa : ");
    // fflush(stdin);
    // scanf("%c",&c);
    // d = DelNode(tree,n);
    // if(d == 1) Output(tree);
    // else printf("Khong co %c trong cay\n",c);
    //--------------------------------------------------------------------------------
    printf("\n");
    return 0;
}
