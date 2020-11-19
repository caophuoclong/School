package Buoi4;
import java.util.Scanner;
public class SDConVat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.print("Nhap so luong con vat: ");
        n = sc.nextInt();
        sc.nextLine();
        ConVat cv[] = new ConVat[n];
        for(int i = 0 ; i < n;i++){
            int x = 0;
            boolean j = false;
            do{
                System.out.print("Con Bo: 1... Con De: 2... Con Heo: 3\nChon giong: ");
                try{
                    String s = sc.nextLine();
                    x = Integer.parseInt(s);

                } catch (Exception e) {
                    System.out.print("Ban nhap khong hop le... \nNhap lai: ");
                    x = Integer.MAX_VALUE;
                }

            } while (x == Integer.MAX_VALUE);

            if (x == 1)
                cv[i] = new Bo();
            else if (x == 2)
                cv[i] = new De();
            else if (x == 3)
                cv[i] = new Heo();
            else
                continue;
            cv[i].Nhap();
        }
        for (int i = 0; i < n; i++) {
            cv[i].HienThi();;
            cv[i].keu();
        }
    }
}
