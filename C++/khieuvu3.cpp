#include <iostream>
#include <algorithm>
using namespace std;
int BinarySearch(int *A,int left,int right,int key)
{
    if (left>right) return -1; // Bien trai lon hon bien phai la sai
    int mid = (left + right)/2;  // lay phan tu o giua
    if(A[mid] == key) return mid; // tim thay gia tri tra ve vt mid
    if (A[mid] < key) return BinarySearch(A , mid+1, right, key); // neu key lon hon gia tri mid thi tim o phia sau cua mang voi bien trai = mid +1 bien phai giu nguyen
    else return BinarySearch(A, left, mid-1, key); // nguoc lai vs cai tren
}
int main()
{
    int n,k,*A,m=0;
    cin>> n >> k;
    A = new int[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A+n);
    for (int i = 0; i < n; i++)
    {
        int pos = BinarySearch(A, 0, n-1, A[i]+k);
        if(pos != -1) m++;
    }
    cout << m << endl;
    return 0;
}
