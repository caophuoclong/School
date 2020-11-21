package Buoi2;

import java.util.Scanner;

public class SDDiem {
    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);
        Diem a = new Diem(3,4);
        Diem b = new Diem();
        b.Nhap();
        b.Show();
        Diem c = b.DoiXung();
        c.Show();
        float khoangCachO = b.khoangCach();
        float khoangCachAB = a.khoangCach(b);
        System.out.print("Khoang cach diem b den O la: "+khoangCachO+"\n");
        System.out.print("Khoang cach AB: "+khoangCachAB+"\n");
        int n;
        System.out.print("Nhap so phan tu danh sach diem: ");
        
        n = sc.nextInt();
        Diem ary[] = new Diem[n];
        for(int i = 0 ; i < n ; i++){
        	System.out.print("Nhap toa do diem thu "+i+": ");
        	ary[i] = new Diem();
        	ary[i].Nhap();
        	
        }
        int i = 0;
        for(Diem e : ary){
        	System.out.print("Toa do diem thu "+ i + ": ");
        	e.Show();
        	i++;
        }
    }
    
}
