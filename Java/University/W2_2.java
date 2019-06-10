import java.io.*;
import java.util.Scanner;
import java.lang.*;

public class W2_2 {
    public static void main(String args[]) {

        Array mang = new Array();
        mang.inputData();
        mang.outputData();
        System.out.println("Trung binh cong cac so le = " + mang.averageOdd());
        System.out.println("Phan tu lon nhat = " + mang.maxMember());
        mang.sortAsc();
        mang.outputData();
    }
}

class Array {
    private int size, arr[];

    public int getSize() {
        return size;
    }

    public int[] getArr() {
        return arr;
    }

    public int getMember(int i) {
        return arr[i];
    }

    public void setMember(int i, int value) {
        arr[i] = value;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public void setArr(int arr[]) {
        this.arr = arr;
    }

    public void inputData() {
        Scanner kb = new Scanner(System.in);
        System.out.print("Nhap kich thuoc mang : ");
        size = kb.nextInt();
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            System.out.print("Array[" + i + "] = ");
            arr[i] = kb.nextInt();
        }
    }

    public void outputData() {
        System.out.println("Kich thuoc mang : " + size);
        System.out.print("Array : ");
        for (int i = 0; i < size; i++)
            System.out.print(arr[i] + " ");
        System.out.println("\nSo phan tu trong mang : " + size);
    }

    public float averageOdd() {
        int sum = 0;
        int numOfOdd = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 1) {
                sum += arr[i];
                numOfOdd++;
            }
        }
        return (float) sum / (float) numOfOdd;
    }

    public int maxMember() {
        int max = arr[0];
        for (int i = 0; i < size; i++)
            max = (max < arr[i]) ? arr[i] : max;
        return max;
    }

    private void swapById(int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    public void sortAsc() {
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (arr[i] > arr[j])
                    swapById(i, j);
    }
}
