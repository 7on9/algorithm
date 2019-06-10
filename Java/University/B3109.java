import java.io.*;
import java.util.Scanner;
import java.lang.*;

public class B3109 {
    public static void main(String args[]) {
        int arr[], n;
        Scanner keyBoard = new Scanner(System.in);
        System.out.print("Nhap so luong phan tu cua mang : ");
        n = keyBoard.nextInt();
        arr = new int[n];
        int x = 2,y = 4;
        if(x = y) System.out.print("Da");
        for (int i = 0; i < n; i++) {
            System.out.print("Nhap Arr[" + i + "] : ");
            arr[i] = keyBoard.nextInt();
        }
        int max = arr[0];
        System.out.println("--------------------\nMang vua nhap : ");
        for (int i = 0; i < n; i++) {
            System.out.println("Arr[" + i + "] = " + arr[i]);
            max = arr[i] > max ? arr[i] : max;
        }
        System.out.println("Phan tu lon nhat trong mang : "+ max);
    }
}
