#include <stdio.h>
//danh sach lien ket don
struct node
{
    int value;
    struct node *pNext;
};
typedef struct node NODE;
//cau truc list
struct structList
{
    NODE *pHead,*pTail;
};
typedef struct  structList LIST;
//khoi tao danh sach
void init(LIST &List)
{
    List.pHead = NULL;
    List.pTail = NULL;
}
int IsEmty(LIST &List)
{
    if(List.pHead != NULL) return 1;
    return 0;
}
NODE *GetNode(int x)
{
    NODE *p=new NODE;
    if (p==NULL) return NULL;
    p->value=x;
    p->pNext=NULL;
    return p;
}
void AddHead(LIST &List, NODE *pNew)
{
    if(IsEmty(List))
        List.pHead = List.pTail = pNew;
    else
    {
        pNew->pNext = List.pHead;
        List.pHead = pNew;
    }
}
void AddTail(LIST &List,NODE *pNew)
{
    List.pTail->pNext = pNew;
    List.pTail = pNew;
}
int main()
{
    return 0;
}
