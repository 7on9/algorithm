#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int random(int a,int b)
{
    return rand() % (b-a+1) + a;
}
void GenerateRan(int *A,int n,int a,int b)
{
    for (int i = 0; i < n; i++)
        A[i] = random(a,b);
}
void GenerateInc(int *A,int n)
{
    A[0] = rand() % 10;
    for (int i = 1; i < n; i++)
        A[i] =  A[i-1] + rand()%5+ 1; // khong trung , muon trung bo +1
}
void GenerateString(char S[],int n)
{
    for(int i = 0;i < n;i++)
        S[i] = char(random(97,122));
}
void swap(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
}
void NhapMang(int *A,int n)
{
    for (int i = 0; i < n; i++)
    {
        //do
        //{
            scanf("%d",&A[i]);
        //}while(n != 0);
    }
}
void XuatMang(int A[],int n)
{
    printf("Mang A : \n");
    for (int i = 0; i < n; i++)
        printf("\tA[%d] = %d  \n", i , A[i]);
}
//Sap xep noi bot
void BubbleSort(int *A,int n)
{
    //traditional
    /*
    for(int i = 0;i < n;i++ )
        for (int j = n-1; j > i; j--)
            if(A[j] < A[j-1]) swap(A[j], A[j-1]);
     */
    //Shaker sort
    int left  = 0,right = n;
    for(int i = left;i < right;i++ )
        for (int j = right; j > left; j--)
        {
            if(A[j] < A[j-1])
                {
                    swap(A[j], A[j-1]);
                    left = j;
                }
        }
    printf("Bubble Sort completed ! \n");
    XuatMang(A, n);
}
//doi cho truc tiep
void InterchangeSort(int *A, int n)
{
    for (int i = 0;i < n-1; i++)
        for (int j = i+1;j < n; j++)
            if (A[j] < A[i]) swap(A[i], A[j]);
    printf("Interchange Sort completed ! \n");
    XuatMang(A, n);
}
//Sap xep chon
void SelectionSort(int A[],int n)
{
    for (int i = 0;i < n-1 ; i++)
    {
        int minpos = i;
        for (int j = i+1; j<n ; j++) //Tim vi tri min trong day con lai
            if (A[j] < A[minpos]) minpos = j;
        swap(A[minpos], A[i]);
        printf("Selection Sort completed ! \n");
        XuatMang(A, n);
    }
}
//sap xep chen
void InsertionSort(int *A,int n)
{
    int pos , x;
    for (int i = 1;i < n;i++)
    {
        x = A[i];   // giu vi tri A[i]
        pos = i-1; //xet tu vi tri trc
        while (pos >= 0 && A[pos] > x) //tim vi tri thich hop de chen x
        {
            A[pos+1] = A[pos]; //don phan tu ra sau
            pos--; // doi post
        }
        A[pos+1] = x; //
    }
}
//Shell sort


//Quick Sort
void QuickSort(int *A,int left,int right)
{
    int a_mid = A[(right + left)/2];
    int i = left ,j = right;
    while (A[i]  < a_mid) i++; //tim phan tu ben trai >= A[mid]
    while (A[j]  > a_mid) j--;
    do
    {
        if(i <= j)
        {
            swap(A[i], A[j]);
            i++; //di den phan tu ke
            j--; //di den phan tu tiep theo ben phai
        }
    }while (i < j) ; //lap lai cho den het cac phan tu co moc
    if (left < j)   QuickSort(A, left, j);// con phan tu ben trai chua xep - QSort trai
    if (right > i) QuickSort(A, i, right); // nguoc lai
}

//Merge Sort


//Binary Seach
int BinarySearch(int *A,int left,int right,int key)
{
    if (left > right) return -1; // Bien trai lon hon bien phai la sai
    int mid = (left + right)/2;  // lay phan tu o giua
    if(A[mid] == key) return mid; // tim thay gia tri tra ve vt mid
    if (A[mid] < key) return BinarySearch(A , mid+1, right, key); // neu key lon hon gia tri mid thi tim o phia sau cua mang voi bien trai = mid +1 bien phai giu nguyen
    if (A[mid] > key) return BinarySearch(A, left, mid-1, key); // nguoc lai vs cai tren
}

int main()
{
    srand((unsigned int )time(NULL));
    char S[100];
    GenerateString(S, 100);
    printf("%s\n",S);
//    int *A,a,b;
//    int n;
//    printf("Nhap so phan tu mang : \n");
//    scanf("%d",&n);
//    printf("Tu a -> b : \n");
//    scanf("%d%d",&a,&b);
//    A = new int[n];
//    GenerateRan(A, n,a,b);
//    XuatMang(A, n);
//    
//    BubbleSort(A, n);
    //XuatMang(A, n);
    return 0;
}
