package Buoi1;

import java.util.Scanner;
public class IsPrime {
    public static boolean Prime(int a) {
        for (int i = 2; i < a/2;i++){
            if (a % i == 0)
                return false;
        }
        return true;
    }
    public static void binary(int a) {
        String s = new String();
        while(a != 0){
            s+= a % 2;
            a /=2;

        }
        byte []x = s.getBytes();
        byte []result = new byte[x.length];
        for (int i =0;i < s.length();i++)
            result[i] = x[x.length-1-i];
        System.out.println(new String(result));
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        if (Prime(a)){
            System.out.println("So " + a + " la so nguyen to.");
            System.out.print("Chuyen sang so nhi phan: ");
            binary(a);
        }
        else    
            System.out.println("So "+a+" khong phai la so nguyen to.");
        sc.close();

        
    }
}
