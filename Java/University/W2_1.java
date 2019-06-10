//week 2 task 1 page 111
import java.io.*;
import java.util.Scanner;
import java.lang.*;

public class W2_1{
    public static void main(String args[]) {
        
        Student student = new Student();
        student.setId("1611062117");
        student.setName("Nguyen Thanh Long");
        student.setPoint((float)9.87);
        System.out.println("Thong tin hoc sinh 1 : ");
        student.outputData();
        
        System.out.println("-----------------------------\nSua thong tin hoc sinh 1 : ");
        student.inputData   ();
        System.out.println("Thong tin hoc sinh 1 sau khi sua: ");
        student.outputData();

        Student student2 = new Student();
        System.out.println("-----------------------------\nNhap tin hoc sinh 2 : ");
        student2.inputData();
        System.out.println("Thong tin hoc sinh 2 : ");
        student2.outputData();

        System.out.print("-----------------------------\nHoc sinh co so diem cao hon la : ");
        if(student.getPoint() > student2.getPoint()) System.out.println(student.getName());
        else 
            if (student2.getPoint() > student.getPoint()) System.out.println(student2.getName());
                else 
                    System.out.println("Khong co! Diem bang nhau!");
    }
}
class Student{
    private String name, id;
    private float point;

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
        if(point >= 9) return "Gioi";
        if(point >= 7) return "Kha";
        if(point >= 5) return "Trung binh";
        if(point >= 3) return "Yeu";        
        return "Kem";
    }
}
