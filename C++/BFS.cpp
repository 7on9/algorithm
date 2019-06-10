#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int matrix[MAX][MAX];
FILE *f;
int u, v;

int intArray[MAX];
int front = 0;
int back = -1;
int itemCount = 0;
//queue
int peek()
{
    return intArray[front];
}
bool isEmpty()
{
    return itemCount == 0;
}
bool isFull()
{
    return itemCount == MAX;
}
int size()
{
    return itemCount;
}
void insert(int data)
{

    if (!isFull())
    {

        if (back == MAX - 1)
        {
            back = -1;
        }
        intArray[++back] = data;
        itemCount++;
    }
}
void pop()
{
    int data = intArray[front++];

    if (front == MAX)
    {
        front = 0;
    }
    itemCount--;
}
void getReady(int A[MAX][MAX],int n)
{
    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= n;j++)
            A[i][j] = 0;
}
void getMatrix(int A[MAX][MAX],int &n)
{
    fscanf(f,"%d",&n);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            {
                fscanf(f,"%d %d", &u, &v);
                A[u][v]++; 
            }
}
int main()
{
    int n;
    f = fopen("IN.inp","rw");
    getMatrix(matrix, n);
        
    return 0;
}
