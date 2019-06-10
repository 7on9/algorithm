
//week 3 task 2 page 118
import java.io.*;
import java.util.Scanner;
import java.lang.*;

public class W3_2 {
    public static void main(String[] args) {
        PhanSo a = new PhanSo();
        PhanSo b = new PhanSo();
        a.input();
        b.input();
        a.output(a.cong(b));
        a.output(a.tru(b));
        a.output(a.nhan(b));
        a.output(a.chia(b));
    }
}

class PhanSo {
    private int tu;
    private int mau;

    PhanSo() {
        tu = 0;
        mau = 1;
    }

    PhanSo(int tu, int mau) {
        this.tu = tu;
        this.mau = mau;
    }

    PhanSo(PhanSo phanSo) {
        this.tu = phanSo.tu;
        this.mau = phanSo.mau;
    }

    public void setTu(int tu) {
        this.tu = tu;
    }

    public void setMau(int mau) {
        this.mau = mau;
    }

    public int getTu() {
        return tu;
    }

    public int getMau() {
        return mau;
    }

    public void input() {
        Scanner kb = new Scanner(System.in);
        System.out.print("Tu : ");
        tu = kb.nextInt();
        System.out.print("Mau : ");
        mau = kb.nextInt();
    }

    public void output() {
        System.out.println(tu + "/" + mau);
    }

    public void output(PhanSo a) {
        System.out.println(a.tu + "/" + a.mau);
    }

    public int ucln(int a, int b) {
        if (a % b == 0)
            return b;
        return ucln(b, a % b);
    }

    public void rutGon() {
        int uc = ucln(this.tu, this.mau);
        this.mau /= uc;
        this.tu /= uc;
    }

    public PhanSo cong(PhanSo a) {
        PhanSo sum = new PhanSo();
        sum.tu = (this.tu * a.mau) + (a.tu * this.mau);
        sum.mau = this.mau * a.mau;
        sum.rutGon();
        return sum;
    }

    public PhanSo tru(PhanSo a) {
        PhanSo sub = new PhanSo();
        sub.tu = (this.tu * a.mau) - (a.tu * this.mau);
        sub.mau = this.mau * a.mau;
        sub.rutGon();
        return sub;
    }

    public PhanSo nhan(PhanSo a) {
        PhanSo mul = new PhanSo();
        mul.tu = this.tu * a.tu;
        mul.mau = this.mau * a.mau;
        mul.rutGon();
        return mul;
    }

    public PhanSo chia(PhanSo a) {
        PhanSo div = new PhanSo();
        div.tu = this.tu * a.mau;
        div.mau = this.mau * a.tu;
        div.rutGon();
        return div;
    }
}