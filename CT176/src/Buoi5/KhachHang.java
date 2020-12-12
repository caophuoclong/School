package Buoi5;
import java.util.Scanner;

import Buoi2.Date;
public class KhachHang {
	private String name;
	private MyDate nsinh;
	private String addr;
	private String phone;
	private HoaDon hd;
	public KhachHang(){
		name = new String();
		nsinh = new MyDate();
		addr = new String();
		phone = new String();
		hd = new HoaDon();

	}
	public KhachHang(KhachHang kh){
		name = kh.name;
		nsinh = kh.nsinh;
		addr = kh.addr;
		phone = kh.phone;
		hd = kh.hd;
	}
	public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ten: ");
		name = sc.nextLine();
		System.out.print("Nhap ngay thang nam sinh: \n");
		nsinh.Nhap();
		System.out.print("Nhap dia chi: ");
		addr = sc.nextLine();
		System.out.print("Nhap so dien thoai: ");
		phone = sc.nextLine();
		hd.nhap();
	}
	public void in(){
		System.out.print("Ten: "+name+"\nNgay sinh: " + nsinh.toString() + "\nDia chi: " + addr + "\nSo dien thoai: " + phone +"\n");
		hd.in();
	}
	public String toString(){
		String s;
		s = "Ten: "+ name +"\nNgay sinh: " + nsinh.toString() + "\nDia chi: " + addr + "\nSo dien thoai: " + phone;
		return s;
		
	}
	

}
