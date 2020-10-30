package Buoi2;

import java.util.Scanner;


public class SDPhanSo {
    /* public static void Sort(int n){
        for (int i = 0 ; i < n;i++){
            if()
        }
    } */
    public static void main(String[] args) {
        PhanSo a = new PhanSo(3,7);
        PhanSo b = new PhanSo(4,9);
        a.HienThi();
        b.HienThi();
        PhanSo x = new PhanSo();
    
        PhanSo y = new PhanSo();
        x.Nhap();
        y.Nhap();
        PhanSo z = x.NgichDao();
        z.HienThi();
        PhanSo xy = x.congPhanSo(y);
        xy.HienThi();
        
        
       
        int n;
        PhanSo ary[];
        @SuppressWarnings("resource")

        Scanner  sc = new Scanner(System.in);
        System.out.print("Nhap so phan tu: \n");
        n = sc.nextInt();
        ary = new PhanSo[n];
        for(int i = 0;i < n;i++){
        	ary[i] = new PhanSo();
        	System.out.print("Nhap phan tu thu " + i +": \n");
        	ary[i].Nhap();
            
        }
        for(int i = 0;i <n;i++){
        	System.out.print("Phan so thu " + i + ": " ); 
        	ary[i].HienThi();
        }
        PhanSo sum = new PhanSo();
        for(PhanSo e : ary){
        	sum = sum.congPhanSo(e);
        }
        sum.HienThi();
        

    }
}
