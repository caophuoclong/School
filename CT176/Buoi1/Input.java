package Buoi1;
import java.util.Scanner;

public class Input {
    public static int [] nhap_3_so() {
        System.out.println("Nhap 3 so a,b,c: ");
        Scanner sc = new Scanner(System.in);
        int a = Integer.MAX_VALUE;
        int b = Integer.MAX_VALUE;
        int c = Integer.MAX_VALUE;
        while(a == Integer.MAX_VALUE || b == Integer.MAX_VALUE || c == Integer.MAX_VALUE){
            try {
                String s = sc.nextLine();
                a = Integer.parseInt(s);
                s = sc.nextLine();
                b = Integer.parseInt(s);
                s = sc.nextLine();
                c = Integer.parseInt(s);
            } catch (Exception e) {
                System.out.println("Nhap lai: ");
                a = Integer.MAX_VALUE;
                b = Integer.MAX_VALUE;
                c = Integer.MAX_VALUE;
    
            }
        }
        sc.close();
        return new int [] {a,b,c};
        
    }
    public static int [] nhap_2_so() {
        System.out.println("Nhap 2 so a,b: ");
        Scanner sc = new Scanner(System.in);
        int a = Integer.MAX_VALUE;
        int b = Integer.MAX_VALUE;
        while(a == Integer.MAX_VALUE || b == Integer.MAX_VALUE){
            try {
                String s = sc.nextLine();
                a = Integer.parseInt(s);
                s = sc.nextLine();
                b = Integer.parseInt(s);
            } catch (Exception e) {
                System.out.println("Nhap lai: ");
                a = Integer.MAX_VALUE;
                b = Integer.MAX_VALUE;
    
            }
        }
        sc.close();
        return new int [] {a,b};
        
    }
}
