package Buoi5;

import java.util.Scanner;

public class ChiTiet {
	private int soluong;
	private long dongia;
	private HangHoa hh;
	public ChiTiet(){
		hh = new HangHoa();
		soluong = 0;
		dongia = 0;
	}
	public ChiTiet(ChiTiet ct){
		hh = ct.hh;
		soluong = ct.soluong;
		dongia = ct.dongia;
	}
	public void nhap(){
		Scanner sc = new Scanner(System.in);
		hh.nhap();
		System.out.print("Nhap so luong hang hoa: ");
		soluong = sc.nextInt();
		System.out.print("Nhap don gia: ");
		dongia = sc.nextLong();
	}
	public void in(){
		hh.in();
		System.out.print("So luong: " + soluong + "\nDon gia: " + dongia +"\n");
	}
	public int getSL(){
		return this.soluong;
	}
	public long getDG(){
		return this.dongia;
	}

}
