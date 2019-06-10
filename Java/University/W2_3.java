//week 2 task 3 page 111
import java.io.*;
import java.util.Scanner;
import java.lang.*;

public class W2_3{
    public static void main(String args[]) {
        Student student, student2, student3;
        
        student = new Student();
        student.outputData();
        
        student2 = new Student("YoLo", "12345", (float)9.3);
        student2.outputData();

        student3 = new Student(student2);
        student3.outputData();
    }
}
class Student{
    private String name, id;
    private float point;

    Student(){
        name = "";
        id = "";
        point = (float) 0.0;
    }
    Student(String name, String id, float point){
        this.name = name;
        this.id = id;
        this.point = point; 
    }
    Student(Student student){
        this.name = student.name;
        this.id = student.id;
        this.point = student.point;
    }
    public String getName(){
        return name;
    }
    public String getId(){
        return id;
    }
    public float getPoint(){
        return point;
    }
    public void setName(String name){
        this.name = name;
    }
    public void setId(String id){
        this.id = id;
    }
    public void setPoint(float point){
        this.point = point;
    }
    public void inputData(){
        Scanner kb = new Scanner(System.in);
        System.out.print("Nhap id : ");
        id = kb.nextLine();    
        System.out.print("Nhap ten : ");
        name = kb.nextLine();
        System.out.print("Nhap diem : ");
        point = kb.nextFloat();
        kb.nextLine();
    }
    public void outputData(){
        System.out.println("Id : "+ id +" | Ten : " + name + " | Diem : "+ point+" | Xep loai : " + rank());
    }
    public String rank(){
        if(point >= 8) return "Gioi";
        if(point >= 6.5) return "Kha";
        if(point >= 5) return "Trung binh";
        if(point >= 2.5) return "Yeu";        
        return "Kem";
    }
}

class ArrayStudent {
    private int size;
    private Student arr[];

    public int getSize() {
        return size;
    }

    public Student[] getArr() {
        return arr;
    }

    public Student getMember(int i) {
        return arr[i];
    }

    public void setMember(int i, Student value) {
        arr[i] = value;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public void setArr(Student arr[]) {
        this.arr = arr;
    }

    public void inputData() {
        Scanner kb = new Scanner(System.in);
        System.out.print("Nhap kich thuoc mang : ");
        size = kb.nextInt();
        arr = new Student[size];
        for (int i = 0; i < size; i++) {
            System.out.println("Student " + (i + 1) + " : ");
            arr[i] = new Student();
            arr[i].inputData();
        }
    }

    public void outputData() {
        for (int i = 0; i < size; i++)
            arr[i].outputData();   
    }

    private void swapById(int a, int b) {
        Student temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    public void sortDec() {
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (arr[i].getPoint() < arr[j].getPoint())
                    swapById(i, j);
    }
}
