import java.io.*;
import java.util.Scanner;
import java.lang.*;

public class W3_3 {
    public static void main(String[] args) {
        Coodinate a = new Coodinate();
        System.out.print("A");
        a.output();
        Coodinate b = new Coodinate(3f, 4f);
        System.out.print("\nB");
        b.output(); 
        System.out.print("\nC = A + B | C");
        a.output(a.add(b));
        System.out.print("\nB'");
        a.output(b.dxCoodinate());
    }
}
class Coodinate{
    private float x;
    private float y;
    Coodinate(){
        x = 0f;
        y = 0f;
    }
    Coodinate(float x, float y){
        this.x = x;
        this.y = y;
    }
    Coodinate(Coodinate p){
        this.x = p.x;
        this.y = p.y;
    }
    public void setX(float x){
        this.x = x;
    }
    public void setY(float y){
        this.y = y;
    }
    public float getX(){
        return x;
    }
    public float getY(){
        return y;
    }
    public Coodinate add(Coodinate a){
        Coodinate sum = new Coodinate();
        sum.x = this.x + a.x;
        sum.y = this.y + a.y;
        return sum;
    }
    public Coodinate dxCoodinate(){
        Coodinate rev = new Coodinate();
        rev.x = -(this.x);
        rev.y = -(this.y);
        return rev;
    }
    public void output(){
        System.out.print("("+ x + ";" + y +")");
    }
    public void output(Coodinate a){
        System.out.print("("+ a.x + ";" + a.y +")");
    }
}