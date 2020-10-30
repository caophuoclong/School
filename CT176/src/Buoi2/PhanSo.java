package Buoi2;

import java.util.Scanner;

public class PhanSo {
    private int tu, mau;
    public PhanSo(){
        tu = 0;
        mau = 1;
    }
    public PhanSo(int x, int y){
        tu = x;
        mau = y;
    }
    public void Nhap(){
        @SuppressWarnings("resource")

    	Scanner sc = new Scanner(System.in);
        System.out.print("Nhap tu so: ");
        tu = sc.nextInt();
        do {
            System.out.print("\nNhap mau so: ");
            mau = sc.nextInt();
        } while(mau == 0);
    }
    public void HienThi(){
    	this.ChuanHoa();
        if ((tu < 0 && mau > 0) ||(tu > 0 && mau < 0))
            System.out.println("-"+ (int) Math.abs(tu)+"/"+(int) Math.abs(mau));
        else if (mau == 1)
        	System.out.print(tu + "\n");
        else
            System.out.println(tu+"/"+mau);
    }
    public PhanSo NgichDao(){
        int temp;
        PhanSo b = new PhanSo();
   
        temp = mau;
        mau = tu;
        tu = temp;
        b.tu = this.tu;
        b.mau = this.mau;
        return b;
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
    	a.ChuanHoa();
    	this.ChuanHoa();
        PhanSo b = new PhanSo();
        b.tu = this.tu*(BCNN(this.mau,a.mau)/this.mau) +  a.tu*(BCNN(this.mau,a.mau)/a.mau);
        b.mau = BCNN(this.mau, a.mau);
        return b;
    }
    public PhanSo nhanPhanSo(PhanSo a){
    	a.ChuanHoa();
    	this.ChuanHoa();
        PhanSo b = new PhanSo();
        b.tu = this.tu * a.tu;
        b.mau = this.mau * a.mau;
        return b;
    }
    public PhanSo truPhanSo(PhanSo a){
    	a.ChuanHoa();
    	this.ChuanHoa();
        PhanSo b = new PhanSo();
        b.tu = this.tu*(BCNN(this.mau,a.mau)/this.mau) -  a.tu*(BCNN(this.mau,a.mau)/a.mau);
        b.mau = BCNN(this.mau, a.mau);
        return b;
    }
    public PhanSo chiaPhanSo(PhanSo a){
    	this.ChuanHoa();
    	a.ChuanHoa();
        PhanSo b = new PhanSo();
        a.NgichDao();
        b.tu = this.tu * a.tu;
        b.mau = this.mau * a.mau;
        return b;
    }
    public PhanSo congNguyenPhanSo(int a){
    	this.ChuanHoa();
        PhanSo b = new  PhanSo();
        b.mau = this.mau;
        b.tu = this.tu + a*this.mau;
        return b;
    }
    public PhanSo truNguyenPhanSo(int a){
    	this.ChuanHoa();
        PhanSo b = new PhanSo();
        b.mau = this.mau;
        b.tu = this.tu - a*this.mau;
        return b;
    }
    public PhanSo nhanNguyePhanSo(int a){
    	this.ChuanHoa();
        PhanSo b = new PhanSo();
        b.mau = this.mau;
        b.tu = this.tu * a;
        return b;
    }
    public PhanSo chiaNguyenPhanSo(int a){
    	this.ChuanHoa();
        PhanSo b = new PhanSo();
        b.mau = this.mau * a;
        b.tu = this.tu;
        return b;
    }
    
    public int UCLN(int a, int b){
    	if (a == 0 || b == 0){
            return a + b;
        }
        while (a != b){
            if (a > b){
                a -= b; // a = a - b
            }else{
                b -= a;
            }
        }
        return a;
    }
    
    public int BCNN(int a, int b){
    	int n;
    	n = (int) Math.abs(a*b)/UCLN(a,b);
    	 	
    	
    	return n;
    }
    
    
    public void ChuanHoa(){
    	int n;
    	n = UCLN(this.tu,this.mau);
    	this.tu = this.tu / n;
    	this.mau = this.mau / n;
    }
    
    
}
