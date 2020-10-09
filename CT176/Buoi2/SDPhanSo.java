package Buoi2;

import java.util.Scanner;

public class SDPhanSo {
    /* public static void Sort(int n){
        for (int i = 0 ; i < n;i++){
            if()
        }
    } */
    public static void main(String[] args) {
        System.out.print("Nhap so phan tu: ");
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        PhanSo Ary[] = null;
        for(int i = 0; i < n;i++){
            Ary[i] = new PhanSo();
            Ary[i].Nhap();
        }
        for (int i = 0 ;i < Ary.length;i++){
            Ary[i].HienThi();
        }
        
        

        sc.close();
    }
}
