#include <stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}


int pop() {
   int data;
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   }else {
      printf("Khong the thu thap du lieu, ngan xep (Stack) la trong.\n");
   }
    return 0;
}

void push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
       //return 1;
   }else {
      printf("Khong the chen du lieu, ngan xep (Stack) da day.\n");
   }
    //return 0;
}

int main() {
   // chen cac phan tu vao ngan xep
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);
   
   printf("Phan tu tai vi tri tren cung cua ngan xep: %d\n" ,peek());
   printf("Cac phan tu: \n");

   // in cac phan tu trong ngan xep
   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }

   printf("Ngan xep da day: %s\n" , isfull()?"true":"false");
   printf("Ngan xep la trong: %s\n" , isempty()?"true":"false");
   
   return 0;
}
