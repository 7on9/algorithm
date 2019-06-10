#include <stdlib.h>
#include <stdio.h>
typedef struct strNode
{
    int Data; 
    struct strNode *Next; 
}Node;
typedef struct strStack
{
   Node *Top;
}Stack;
//------------------------------------------------- 
void Init (Stack &stack) //khoi tao Stack rong
{
    stack.Top = NULL;
}
//-------------------------------------------------
int Isempty(Stack stack) //kiem tra Stack rong
{
    return (stack.Top == NULL);
}
//------------------------------------------------- 
int Len (Stack stack)
{
    Node *P = stack.Top;
    int i=0;
    while (P != NULL) //trong khi chua het Stack thi van duyet
    {
        i++;
        P = P->Next;
    }
    return i;
}
//------------------------------------------------- 
Node *CreateNode(int x) //tao 1 Node
{
    Node *P = (Node*) malloc(sizeof(Node));
    P->Next = NULL;
    P->Data = x;
    return P;
}
//------------------------------------------------- 
void Push(Stack &stack, int x) //them phan tu vao Stack
{
    Node *P = CreateNode(x);
    P->Next = stack.Top;
    stack.Top = P;
}
//-------------------------------------------------
int Peak(Stack stack) //Lay phan tu o dau Stack nhung khong xoa
{
    return stack.Top->Data;
}
//-------------------------------------------------
int Pop(Stack &stack) //Loai bo phan tu khoi Stack
{
    if (!Isempty(stack))
    {
        int x = stack.Top->Data; //luu lai gia tri
        stack.Top = stack.Top->Next; //Xoa phan tu Top
        return x;
    }
    return 0;
}
//------------------------------------------------- 
void Input (Stack &stack) //nhap danh sach
{
    int i=0; 
    int x;
    do
    {
        i++;
        printf ("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if (x != 0) Push(stack,x);
    } while(x != 0); //nhap 0 de ket thuc
}
//-------------------------------------------------
void Output(Stack stack)
{
    Node *P = stack.Top;
    while (P != NULL)
    {
        printf("%d   ",P->Data);
        P = P->Next;
    }
    printf("\n");
}
//-------------------------------------------------
int Menu()
{
    int chose;
    printf("\tXIN MOI CHON TAC VU :\n");
    printf("\t0 : Thoat\n");
    printf("\n1: Kiem tra Stack rong");
    printf("\n2: Do dai Stack");
    printf("\n3: Them phan tu vao Stack");
    printf("\n4: Xoa phan tu trong Stack");
    printf("\n5: Xuat Stack");
    printf("Ban chon -> ");
    scanf("%d",&chose);
    return chose;
}
int main()
{
    Stack stack;
    Init(stack);
    Input(stack);
    Output(stack);
    int chose = Menu();
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&chose);
        switch (chose)
        {
            case 1:
            {
                if (Isempty(stack)) printf("Stack rong !");
                else printf ("Stack khong rong !");
                break;
            }
            case 2:
            {
                printf("Do dai Stack: %d",Len(stack));
                break;
            }
            case 3:
            {
                int x;
                printf ("Nhap phan tu can chen vao stack: ");
                scanf("%d",&x);
                Push(stack,x);
                break;
            }
            case 4:
            {
                Pop(stack);
                break;
            }
            case 5: 
            {
                Output(stack);
                break;
            }
            case 0 : break;
        }
    }while (chose != 0);
    return 0;
}
