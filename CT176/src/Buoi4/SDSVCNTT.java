package Buoi4;
import java.util.Scanner;
public class SDSVCNTT {
    public static String  compareEmail(String email, SinhvienCNTT sv){
        if (email.equals(sv.getEmail()))
            return "long";
        else
            return "Ngan";
    }
    public static void main(String[] args) {
        SinhvienCNTT []svcntt;
        int n;
        System.out.print("Nhap so luong sinh vien: ");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        svcntt = new SinhvienCNTT[n];
        for (int i = 0; i < n;i++){
            svcntt[i] = new SinhvienCNTT();
        }
        System.out.print("Nhap email can tim: ");
        sc.nextLine();
        String email = sc.nextLine();
        for (int i = 0;i < n; i++){
            System.out.print(compareEmail(email,svcntt[i]));
        }

    }
}
