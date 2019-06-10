#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
//--------------------------------------------------
typedef struct ttNode
{
    int data;
    struct ttNode *pNext;
    struct ttNode *pPrev;
    int pos;
}Node;
//--------------------------------------------------
typedef struct ttList
{
    Node *pHead;
    Node *pTail;
    int number;
}List;
//--------------------------------------------------
void Init(List &list)
{
    list.pHead = list.pTail = NULL;
    list.number = 0;
}
//--------------------------------------------------
void InputX(int &x)
{
    printf("Nhap x (0 de dung) : ");
    scanf("%d",&x);
}
//--------------------------------------------------
void OutputX(int x)
{
    printf("%d\n",x);
}
//--------------------------------------------------
void UpdatePos(List &list,Node *pX)
{
    for(Node *pi = pX;pi != NULL;pi=pi->pNext)
        if(pi == list.pHead) pi->pos = 0;
        else
            pi->pos = pi->pPrev->pos + 1;
}
//--------------------------------------------------
Node *CreateNode(int temp)
{
    Node *pNew = new Node;
    if(pNew == NULL)
    {
        printf("Loi cap phat bo nho!");
        exit(0);
    }
    pNew->data = temp;
    pNew->pos = -1;
    pNew->pNext = NULL;
    pNew->pPrev = NULL;
    return pNew;
}
//--------------------------------------------------
int isEmty(List list)
{
    if(list.pHead == NULL) return 1;
    return 0;
}
//--------------------------------------------------
void AddHead(List &list,Node *pNew)
{
    if(isEmty(list))
    {
        list.pHead = list.pTail = pNew;
    }
    else
    {
        pNew->pNext = list.pHead;
        list.pHead->pPrev = pNew;
        list.pHead = pNew;
    }
    list.number++;
}
//--------------------------------------------------
void AddTail(List &list,Node *pNew)
{
    if(isEmty(list))
    {
        list.pHead = list.pTail = pNew;
    }
    else
    {
        pNew->pPrev = list.pTail;
        list.pTail->pNext = pNew;
        list.pTail = pNew;
    }
    list.number++;
}
//-------------------------------------------------
void CoppyList(List listA,List &listB)
{
    for(Node *pa = listA.pHead;pa != NULL;pa = pa->pNext)
        AddTail(listB,CreateNode(pa->data));
    listB.number = listA.number;
}
//--------------------------------------------------

Node *FindNode(List list,int x)
{
    while(list.pHead)
    {
        if(list.pHead->data == x)
            return list.pHead;
        list.pHead = list.pHead->pNext;
    }
    return NULL;
}
//--------------------------------------------------
Node *NodePos(List list,int pos)
{
    if(pos > list.number)
        printf("Vuot qua so node \n");
    else 
        for(Node *pi = list.pHead;pi != NULL;pi = pi->pNext)
        {
            if(pi->pos == pos) return pi;        
        }
    return NULL;
}
//--------------------------------------------------
Node *NodeBefore(List list,Node *px)
{
    if(px == list.pHead) 
    {
        //printf("Node khong ton tai !\n");
        return NULL;
    }
    return px->pPrev;
}
//--------------------------------------------------
Node *FindNodeMax(List list)
{
    Node *pMax = list.pHead;
    while(list.pHead)
    {
        if(list.pHead->data > pMax->data)
            pMax = list.pHead;
        list.pHead = list.pHead->pNext;
    }
    return pMax;
}
//--------------------------------------------------
Node *FindNodeMin(List list)
{
    Node *pMin = list.pHead;
    while(list.pHead)
    {
        if(list.pHead->data < pMin->data)
            pMin = list.pHead;
        list.pHead = list.pHead->pNext;
    }
    return pMin;
}
//--------------------------------------------------
void InsertAfter(List list,Node *px,int x)
{
    if(px == NULL)
    {
        //printf("Node khong ton tai !\n");
        return;
    }
    Node *pNew = CreateNode(x);
    if(px == list.pTail)
        AddTail(list,pNew);
    else
    {
        pNew->pNext = px->pNext;
        px->pNext->pPrev = pNew;
        pNew->pPrev = px;
        px->pNext = pNew;
        list.number++;
    }
}
//--------------------------------------------------
void DeleteFirst(List &list)
{
    if(list.pHead == list.pTail)
    {
        list.pHead = list.pTail = NULL;
        list.number--;
        return;
    }
    Node *pTemp = list.pHead;
    list.pHead = list.pHead->pNext;
    list.pHead->pPrev = NULL;
    list.number--;
    delete(pTemp);
}
//--------------------------------------------------
void DeleteLast(List &list)
{
    if(list.pHead == list.pTail) 
    {
        list.pHead = list.pTail = NULL;
        list.number--;
        return;
    }
    Node *pLast = list.pTail;
    list.pTail = NodeBefore(list,list.pTail);
    free(pLast);
    list.pTail->pNext = NULL;
    list.number--;
}
//--------------------------------------------------
void DeleteAfter(List &list,Node *px)
{
    if(px == NULL|| px->pNext == NULL)
    {
        //printf("Node khong ton tai !\n");
        return;
    }
    else
    {
        if(px == list.pTail)
            list.pTail = px;
        Node *pAfter = px->pNext;
        px->pNext = pAfter->pNext;
        pAfter->pNext->pPrev = px;
        delete(pAfter);
        list.number--;
    }
}
//--------------------------------------------------
void DeleteNode(List &list,Node *px)
{
    if(list.pHead == list.pTail)
    {
        list.pHead = list.pTail = NULL;
        list.number--;
        return;
    }
    if(px == list.pHead) 
        DeleteFirst(list);
    else 
        DeleteAfter(list,NodeBefore(list,px));
    list.number--;
    
}
//--------------------------------------------------
void DeleteAll(List &list)
{
    DeleteFirst(list);
    list.pHead = list.pTail = NULL;
}
//--------------------------------------------------
void Input(List &list)
{
    int x;
    do
    {
        InputX(x);
        if(x == 0) break;
        Node *pNew = CreateNode(x);
        AddTail(list,pNew);
    }while(1);
}
//--------------------------------------------------
void Output(List list)
{
    if(isEmty(list))
    {
        printf("Danh sach rong !\n");
        return;
    }
    printf("Danh sach :\n");
    for(Node *pi = list.pHead;pi != NULL;pi = pi->pNext)
        printf("%5d",pi->data);
    printf("\n");
}
//--------------------------------------------------
void Swap(int &a,int &b)
{
    int tam=a;
    a=b;
    b=tam;
}
//-------------------------------------------------
void InterchangeSortTang(List &list)
{
    for(Node *pi = list.pHead;pi != list.pTail;pi = pi->pNext)
        for(Node *pj = pi->pNext;pj != NULL;pj = pj->pNext)
            if(pi->data > pj->data) Swap(pi->data,pj->data);
}
//-------------------------------------------------
void SelectionSortTang(List &list)
{
    for(Node *pi = list.pHead;pi != list.pTail;pi = pi->pNext)
    {
        Node *pMin = pi;
        for(Node *pj = pi->pNext;pj != NULL;pj = pj->pNext)
            if(pMin->data > pj->data) pMin = pj;
        Swap(pMin->data,pi->data);
    }
}
//-------------------------------------------------
void InsertionSortTang(List &list)
{
    Node *pos, *x,*temp;
    for (Node *pi = list.pHead->pNext;pi != NULL;pi = pi->pNext)
    {
        x = pi;   // giu vi tri A[i]
        pos = NodeBefore(list,pi); //xet tu vi tri trc
        while (pos != NULL && pos->data > x->data) //tim vi tri thich hop de chen x
        {
            pos = NodeBefore(list,pos); // doi post
        }
        temp = x;
        DeleteNode(list,x);
        if(pos == NULL)
            AddHead(list,temp);
        else 
            InsertAfter(list,pos,temp->data);
    }
}
//-------------------------------------------------
void BubbleSortTang(List &list)
{
    for(Node *pi = list.pHead;pi->pNext != NULL;pi = pi->pNext)
        for(Node *pj = list.pTail;pj != pi;pj = pj->pPrev)
            if(pj->data<pj->pPrev->data) Swap(pj->data,pj->pPrev->data);
}

//--------------------------------------------------
void QuickSortTang(List &list,int left,int right)
{
    int mid = (left+right)/2;
    Node *a_mid = NodePos(list,mid);
    //int i = left,j = right;
    Node *pi = NodePos(list,left),*pj = NodePos(list,right);
    do
    {
        while (pi->data < a_mid->data) pi = pi->pNext; //Tim phan tu ben trai ma >= A[mid]
        while (pj->data > a_mid->data) pj = pj->pPrev;
        if(pi->pos <= pj->pos)
        {
            Swap(pi->data,pj->data);
            pi = pi->pNext;
            pj = pj->pPrev;
        }
    }while (pi->pos < pj->pos);
    if(left < pj->pos) QuickSortTang(list,left,pj->pos); // Van con phan tu ben trai
    if(right > pi->pos) QuickSortTang(list,pi->pos,right);
}
//-------------------------------------------------
Node *BinarySearchList(List list,int left,int right,int key)
{
    if(left > right) return NULL;
    int mid = (left+right)/2;
    Node *a_mid = NodePos(list,mid);
    if(a_mid->data == key) return a_mid;
    if(a_mid->data < key) return BinarySearchList(list,mid+1,right,key);
    if(a_mid->data > key) return BinarySearchList(list,left,mid-1,key);
    return 0;
}
//-------------------------------------------------
int Menu()
{
    int chose;
    printf("\tXIN MOI CHON TAC VU :\n");
    printf("\t0 : Thoat\n");
    printf("\t1 : Tim kiem tuyen tinh\n");
    printf("\t2 : Tim kiem nhi phan\n");
    printf("\t3 : Inter Change Sort Tang\n");
    printf("\t4 : Selection Sort Tang\\n");
    printf("\t5 : Bubble Sort Tang\\n");
    printf("\t6 : Quick Sort Tang\\n");
    printf("\t7 : Xoa node dau tien\n");
    printf("\t8 : Xoa node cuoi cung\n");
    printf("\t9 : Xoa node sau 1 node\n");
    printf("\t10 : Xoa 1 node\n");
    printf("\t11 : Xoa toan bo danh sach\n");
    printf("\t12 : Chen truoc\n");
    printf("\t11 : Chen sau\n");
    printf("\t14 : In node lon nhat\n");
    printf("\t15 : In node be nhat\n");
    printf("Ban chon -> ");
    scanf("%d",&chose);
    return chose;
}
//--------------------------------------------------

int main()
{
    List list;
    Init(list);
    Input(list);
    //InterchangeSortTang(list);
    //SelectionSortTang(list);
    //InsertionSortTang(list);
    //BubbleSortTang(list);
    //QuickSortTang(list, 0, list.number-1);
    Output(list);
    int chose = 0;
    do
    {
        chose = Menu();
        //chuyen mang A vao Acopy
        switch(chose)
        {
            case 0 : break;
            //---------------------------------------------------FindNode
            case 1 : 
            {
                printf("Tim tuyen tinh : \n");
                int x;
                InputX(x);
                Node *px = FindNode(list,x);
                if(px == NULL) printf("Khong co !\n");
                else OutputX(px->data);
            }break;
            //---------------------------------------------------FindNodeBin
            case 2 : 
            {
                List listB;
                Init(listB);
                CoppyList(list,listB);
                UpdatePos(listB,listB.pHead);
                printf("Tim nhi phan - day da duoc sap xep : \n");
                QuickSortTang(listB, 0, listB.number-1);
                Output(listB);
                int x;
                InputX(x);
                Node *px = BinarySearchList(listB,0,listB.number-1,x);
                if(px == NULL) printf("Khong co !\n");
                else OutputX(px->data);
            }break;
            //---------------------------------------------------InterchangeSortTang
            case 3 :
            {
                List listB;
                Init(listB);
                CoppyList(list,listB);
                InterchangeSortTang(listB);
                printf("Sap xep mang tang theo Interchange Sort :\n");
                Output(listB);
                DeleteAll(listB);
            }break;
            //---------------------------------------------------SelectionSortTang
            case 4 :
            {
                List listB;
                Init(listB);
                CoppyList(list,listB);
                SelectionSortTang(listB);
                printf("Sap xep mang tang theo Selection Sort :\n");
                Output(listB);
                DeleteAll(listB);
            }break;
            //---------------------------------------------------BubbleSortTang
            case 5 :
            {
                List listB;
                Init(listB);
                CoppyList(list,listB);
                BubbleSortTang(listB);
                printf("Sap xep mang tang theo Bubble Sort :\n");
                Output(listB);
                DeleteAll(listB);
            }break;
            //---------------------------------------------------QuickSortTang
            case 6 :
            {
                List listB;
                Init(listB);
                CoppyList(list,listB);
                UpdatePos(listB, listB.pHead);
                QuickSortTang(listB,0,listB.number);
                printf("Sap xep mang tang theo Quick Sort :\n");
                Output(listB);
                DeleteAll(listB);
            }break;
            //---------------------------------------------------DeleteFirst
            case 7 :
            {
                printf("Xoa Node dau\n");
                DeleteFirst(list);
                Output(list);
            }break;
            //---------------------------------------------------DeleteLast
            case 8 :
            {
                printf("Xoa Node cuoi\n");
                DeleteLast(list);
                Output(list);
            }break;
            //---------------------------------------------------DeleteAfter
            case 9 :
            {
                printf("Xoa Node sau node dau\n");
                DeleteAfter(list,list.pHead);
                Output(list);
            }break;
            //---------------------------------------------------DeleteNode
            case 10 :
            {
                printf("Nhap node muon xoa :\n");
                int f;
                InputX(f);
                Node *p = FindNode(list,f);
                if(p == NULL) printf("Khong co !\n");
                else 
                {
                    DeleteNode(list,p);
                    Output(list);
                }
            }break;
            //---------------------------------------------------DeleteAll
            case 11 :
            {
                printf("Xoa toan bo list\n");
                DeleteAll(list);
                Output(list);
            }break;
            //---------------------------------------------------Insert Before
            case 12 : 
            //{
            //     printf("Nhap so muon chen :\n");
            //     int x;
            //     InputX(x);
            //     printf("Nhap node muon chen vao truoc :\n");
            //     int f;
            //     InputX(f);
            //     Node *p = FindNode(list,f);
            //     if(p == NULL) printf("Khong co !\n");
            //     else 
            //     {
            //         InsertBefore(list,p,f);
            //         Output(list);
            //     }
            // }break;
            //---------------------------------------------------Insert After
            case 13 : 
            {
                printf("Nhap so muon chen :\n");
                int x;
                InputX(x);
                printf("Nhap node muon chen vao sau :\n");
                int f;
                InputX(f);
                Node *p = FindNode(list,f);
                if(p == NULL) printf("Khong co !\n");
                else 
                {
                    InsertAfter(list,p,x);
                    Output(list);
                }
            }break;
            //---------------------------------------------------FindNodeMax
            case 14 : 
            {
                Node *pMax = FindNodeMax(list);
                printf("Node lon nhat : ");
                OutputX(pMax->data);
            }break;
            //---------------------------------------------------FindNodeMin
            case 15 : 
            {
                Node *pMin = FindNodeMin(list);
                printf("Node be nhat : ");
                OutputX(pMin->data);
            }break;
        }
    }while(chose != 0);
    return 0;
}
