import java.io.*;
import java.util.Scanner;
import java.lang.*;

public class B4105 {
    public static void main(String args[]) {
        int matrix[][], hang, cot;
        Scanner keyBoard = new Scanner(System.in);

        System.out.print("Nhap so hang : ");
        hang = keyBoard.nextInt();
        System.out.print("Nhap so cot : ");
        cot = keyBoard.nextInt();

        matrix = new int[hang][cot];
        int sum = 0;
        for (int i = 0; i < hang; i++)
            for (int j = 0; j < cot; j++) {
                matrix[i][j] = Math.abs((int) (Math.random()*100) - 49); // Math.random() tạo ra 1 số thực trong khoảng [0..1)
                sum += matrix[i][j];
            }
        System.out.println("--------------------\nMa tran vua tao : ");
        for (int i = 0; i < hang; i++){
            for (int j = 0; j < cot; j++) 
                System.out.print(matrix[i][j]+"\t");
            System.out.println();
        }
        System.out.println("Tong cac phan tu = " + sum);
    }
}