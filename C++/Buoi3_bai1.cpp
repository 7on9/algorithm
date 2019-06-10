#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
//--------------------------------------------------
typedef struct ttNode
{
    int data;
    struct ttNode *pNext;
}Node;
//--------------------------------------------------
typedef struct ttList
{
    Node *pHead;
    Node *pTail;
}List;
//--------------------------------------------------
void Init(List &list)
{
    list.pHead = list.pTail = NULL;
}
//--------------------------------------------------
void InputX(int &x)
{
    printf("Nhap x (0 de dung) : ");
    scanf("%d",&x);
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
    pNew->pNext = NULL;
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
        list.pHead = pNew;
    }
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
        list.pTail->pNext = pNew;
        list.pTail = pNew;
    }
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
Node *FindNodeBefore(const List list,Node *px)
{
    if(px == list.pHead)
    {
        //printf("Node khong ton tai !\n");
        return NULL;
    }
    for(Node *pi = list.pHead;pi->pNext->data != px->data;pi = pi->pNext)
        if(pi->pNext->data == px->data) return pi;
    return NULL;
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
        px->pNext = pNew;
    }
}
//--------------------------------------------------
void DeleteFirst(List &list)
{
    if(list.pHead == list.pTail)
    {
        list.pHead = list.pTail = NULL;
        return;
    }
    Node *pTemp = list.pHead;
    list.pHead = list.pHead->pNext;
    delete(pTemp);
}

//--------------------------------------------------
void DeleteAfter(List &list,Node *px)
{
    if(px == NULL||px->pNext == NULL)
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
        delete(pAfter);
    }
}
//--------------------------------------------------
void DeleteNode(List &list,Node *px)
{
    if(list.pHead == list.pTail)
    {
        list.pHead = list.pTail = NULL;
        return;
    }
    if(px == list.pHead)
        DeleteFirst(list);
    else
        DeleteAfter(list,FindNodeBefore(list,px));
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
void InterchangeSort(List &list)
{
    for(Node *pi = list.pHead;pi != list.pTail;pi = pi->pNext)
        for(Node *pj = pi->pNext;pj != NULL;pj = pj->pNext)
            if(pi->data > pj->data) Swap(pi->data,pj->data);
}
//-------------------------------------------------
void SelectionSort(List &list)
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
void InsertionSort(List &list)
{
    Node *pos, *x,*temp;
    for (Node *pi = list.pHead->pNext;pi != NULL;pi = pi->pNext)
    {
        x = pi;   // giu vi tri A[i]
        pos = FindNodeBefore(list,pi); //xet tu vi tri trc
        while (pos != NULL && pos->data > x->data) //tim vi tri thich hop de chen x
        {
            pos = FindNodeBefore(list,pos); // doi post
        }
        temp = x;
        DeleteNode(list,x);
        if(pos == NULL)
            AddHead(list,temp);
        else
            InsertAfter(list,pos,temp->data);
    }
}
//--------------------------------------------------
int main()
{
    List list;
    Init(list);
    Input(list);
    
    InsertAfter(list,FindNode(list,3),999);//chen sau node 3
    Output(list);
    
    if(!isEmty(list))
        printf("Gia tri max : %d \n",FindNodeMax(list)->data);
    else printf("Danh sach rong !\n");
    
    if(!isEmty(list))
        printf("Gia tri min : %d \n",FindNodeMin(list)->data);
    else printf("Danh sach rong !\n");
    
    DeleteAfter(list,FindNode(list,3));//xoa node sau node 3
    Output(list);
    
    DeleteFirst(list);//xoa vi tri dau tien
    
    //InterchangeSort(list);
    //SelectionSort(list);
    InsertionSort(list);
    Output(list);
    return 0;
}
