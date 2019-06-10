import java.io.*;
import java.util.Scanner;
import java.lang.*;

public class B3{
    public static void main(String args[]) {
        Student student = new Student();
        
        student.setId("1611062117");
        student.setName("Nguyen Thanh Long");
        student.setPoint((float)9.87);
        student.outputData();
        
        student.inputData();
        student.outputData();
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
        kb.close();
    }
    public void outputData(){
        System.out.println("Id : "+ id +" | Ten : " + name + " | Diem : "+ point);
    }
}
