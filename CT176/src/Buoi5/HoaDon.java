package Buoi5;

import java.util.Scanner;

public class HoaDon {
	private String maso;
	private String tench;
	private ChiTiet ct[];
	private MyDate ngayxuathoadon;
	public HoaDon(){
		maso = new String();
		tench = new String();	
		ngayxuathoadon = new MyDate();
	}
	public HoaDon(HoaDon hd){
		maso = hd.maso;
		tench = hd.tench;
		ngayxuathoadon = hd.ngayxuathoadon;
		
		
	}
	public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ten cua hang: ");
		tench = sc.nextLine();
		System.out.print("Nhap ma so hoa don: ");
		maso = sc.nextLine();
		System.out.print("Nhap ngay xuat hoa don: ");
		ngayxuathoadon.nhap();
		System.out.print("Nhap so luong hang hoa: ");
		int n;
		n = sc.nextInt();
		ct = new ChiTiet[n];
		for(int i = 0; i < n;i++){
			ct[i] = new ChiTiet();
			System.out.print("Nhap mon do thu " + (i+1) +": \n");
			ct[i].nhap();
		}
		
		
	}
	public void in(){
		System.out.print( "Ten cua hang: " + tench + "\nMa so hoa don: " + maso +"\nNgay xuat hoa don: " + ngayxuathoadon +"\n");
		for (int i = 0; i < ct.length;i++){
			ct[i].in();
		}
	}
	public String toString(){
		String s;
		s = "Ten cua hang: " + tench + "\nMa so: " + maso +"\n";
		return s;
		
	}
//	public void tong(){
//		int sumSL;
//		long sumDG;
//		
//		System.out.print("Tong so luong: " + sumSL + "Tong tien: " + sumDG);
//	}

}
