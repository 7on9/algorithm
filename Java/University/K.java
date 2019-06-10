import java.io.*;
import java.util.Scanner;
import java.lang.*;
import java.math.BigInteger;

class K {
    private static final BigInteger BIG_INTEGER = new BigInteger("0");

    public static void main(String args[]) {
        BigInteger p = new BigInteger("1");
        BigInteger q = new BigInteger("1");
        Scanner kb = new Scanner(System.in);
        int m = kb.nextInt();
        int n = kb.nextInt();
        BigInteger M = kb.nextBigInteger();
        for (int i = 0; i < m; i++) {
            p = p.multiply(kb.nextBigInteger());
        }
        for (int i = 0; i < n; i++) {
            q = q.multiply(kb.nextBigInteger());
        }
        BigInteger uc = new BigInteger("1");
        uc = UCLN(p, q);
        p = p.divide(uc);
        q = q.divide(uc);
        p = p.mod(M);
        q = q.mod(M);
        System.out.println(p);
        System.out.println(q);
    }
    static BigInteger UCLN(BigInteger a, BigInteger b) {
        if (a.mod(b).equals(BIG_INTEGER))
            return b;
        return UCLN(b, a.mod(b));
    }
}