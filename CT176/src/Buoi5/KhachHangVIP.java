package Buoi5;

import java.util.Scanner;

public class KhachHangVIP extends KhachHang {
	KhachHang kh;
	float tile;
	MyDate ngaybatdau;
	MyDate ngayketthuc;
	public KhachHangVIP(){
		super();
		tile = 0.0f;
		ngaybatdau = new MyDate();
		ngayketthuc = new MyDate();
	}
	public KhachHangVIP(KhachHangVIP khv){
		super(khv);
		tile = khv.tile;
		ngaybatdau =  khv.ngaybatdau;
		ngayketthuc = khv.ngayketthuc;	
		
	}
	public void nhap(){
		Scanner sc = new Scanner(System.in);
		super.nhap();
		System.out.print("Nhap ti le mien giam: ");
		tile = sc.nextFloat();
		System.out.print("Nhap ngay bat dau mien giam: ");
		ngaybatdau.Nhap();
		System.out.print("Nhap ngay het han: ");
		ngayketthuc.Nhap();
	}
}
