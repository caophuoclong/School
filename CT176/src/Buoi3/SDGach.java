package Buoi3;
import java.util.Scanner;
public class SDGach {
    
    public static void main(String []args){
        int n;
        @SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
        System.out.print("Nhap so luong hop gach: ");
        n = sc.nextInt();
        Gach g[] = new Gach[n];
        for (int i = 0; i < n;i++){
            g[i] = new Gach();
            g[i].nhap();
        }
        for (int i = 0 ; i < n ; i++){
            g[i].in();
            System.out.print("\n");
        }
        int max = 0;
        Gach best = new Gach();
        int best_choice = 0;
        for (int i = 0 ; i < n ; i++){
            int price = g[i].getPrice();
            int  S = g[i].MaxDientichNen();
            best_choice = price / S;
            if (best_choice > max)
                max = 1;
            else
                max = 0;
            if (max == 1){
                best = new Gach(g[i]);
            }
                
            
        }
        System.out.print("\n\nBest choice \n\n");
        best.in();
        int best_price = best.Giathanh(5, 20);
        System.out.print("\n\nGia thanh: " + best_price);


    }

    
}
