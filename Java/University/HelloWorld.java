import java.io.*;
import java.util.Scanner;
import java.lang.*;

public class HelloWorld{
    public static void main(String [] args){
        Student student = new Student();
        student.nhapInfo();
        student.xuatInfo();
        student.setId("12345");
        student.xuatInfo();
    }
}
class Student{
    Scanner kb = new Scanner(System.in);
    String id;
    String name;
    float point;
    int age;
    int ns;
    public void setId(String id){
        this.id = id;
    }
    public void nhapInfo(){
        System.out.print("Nhap id : ");
        this.id = kb.nextLine();
        System.out.print("Nhap ten : ");
        this.name = kb.nextLine();
        System.out.print("Nhap tuoi : ");
        this.age = kb.nextInt();
        System.out.print("Nhap nam sinh : ");
        this.ns = kb.nextInt();
        System.out.print("Nhap diem trung binh : ");
        this.point = kb.nextFloat();
    }
    public void xuatInfo(){
        System.out.println("id : "+ id +" | ten : " + name + " | tuoi : "+ age + " | nam sinh : " + ns +" | diem : "+ point);
    }
}