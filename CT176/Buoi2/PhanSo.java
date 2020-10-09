package Buoi2;

import java.util.Scanner;

public class PhanSo {
    private int tu, mau;
    public PhanSo(){
        tu = 1;
        mau = 1;
    }
    public PhanSo(int x, int y){
        tu = x;
        mau = y;
    }
    public void Nhap(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap tu so: ");
        tu = sc.nextInt();
        do {
            System.out.print("\nNhap mau so: ");
            mau = sc.nextInt();
        } while(mau == 0);
        sc.close();
    }
    public void HienThi(){
        if ((tu < 0 && mau > 0) ||(tu > 0 && mau < 0))
            System.out.println("-"+ (int) Math.abs(tu)+"/"+(int) Math.abs(mau));
        else
            System.out.println(tu+"/"+mau);
    }
    public void NgichDao(){
        int temp;

        temp = mau;
        mau = tu;
        tu = temp;
    }
    public PhanSo giatriNgichDao(){
        PhanSo nd = new PhanSo();
        nd.mau = this.mau;
        nd.tu = this.tu;
        return nd;
    }
    public float giaTriThuc(){
        return (float) tu/mau;
    }
    public boolean comparePhanSo(PhanSo a){
        if (this.tu / this.mau > a.tu / a.mau)
            return true;
        return false;
    }
    public PhanSo congPhanSo(PhanSo a){
        PhanSo b = new PhanSo();
        b.mau = this.mau * a.mau;
        b.tu = this.tu * a.mau + this.mau *a.tu;
        return b;
    }
    public PhanSo nhanPhanSo(PhanSo a){
        PhanSo b = new PhanSo();
        b.tu = this.tu * a.tu;
        b.mau = this.mau * a.mau;
        return b;
    }
    public PhanSo truPhanSo(PhanSo a){
        PhanSo b = new PhanSo();
        b.mau = this.mau * a.mau;
        b.tu = this.tu*a.mau - this.mau*a.tu;
        return b;
    }
    public PhanSo chiaPhanSo(PhanSo a){
        PhanSo b = new PhanSo();
        a.NgichDao();
        b.tu = this.tu * a.tu;
        b.mau = this.mau * a.mau;
        return b;
    }
    public PhanSo congNguyenPhanSo(int a){
        PhanSo b = new  PhanSo();
        b.mau = this.mau;
        b.tu = this.tu + a*this.mau;
        return b;
    }
    public PhanSo truNguyenPhanSo(int a){
        PhanSo b = new PhanSo();
        b.mau = this.mau;
        b.tu = this.tu - a*this.mau;
        return b;
    }
    public PhanSo nhanNguyePhanSo(int a){
        PhanSo b = new PhanSo();
        b.mau = this.mau;
        b.tu = this.tu * a;
        return b;
    }
    public PhanSo chiaNguyenPhanSo(int a){
        PhanSo b = new PhanSo();
        b.mau = this.mau * a;
        b.tu = this.tu;
        return b;
    }
    
}
