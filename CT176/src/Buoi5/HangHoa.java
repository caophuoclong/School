package Buoi5;

import java.util.Scanner;

public class HangHoa {
	int maso;
	String ten;
	MyDate ngaysanxuat;
	MyDate ngayhethan;
	public HangHoa(){
		maso = 0;
		ten = new String();
		ngaysanxuat = new MyDate();
		ngayhethan = new MyDate();
		
	}
	public HangHoa(HangHoa hh){
		maso = hh.maso;
		ten = hh.ten;
		ngaysanxuat = hh.ngaysanxuat;
		ngayhethan = hh.ngayhethan;
		
	}
	public void nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ma so hang hoa: ");
		int n = 0;
		do{
			try{
				String s;
				s = sc.nextLine();
				maso = Integer.parseInt(s);
			}
			catch(Exception e){
				System.out.print("Nhap lai ma so hang hoa: ");
				maso = Integer.MAX_VALUE;
				n++;
			}
		}
		while(maso == Integer.MAX_VALUE && n < 1000);
			
		
		
		sc.nextLine();
		System.out.print("Nhap ten hang hoa: ");
		ten = sc.nextLine();
		System.out.print("Nhap ngay san xuat: ");
		ngaysanxuat.nhap();
		System.out.print("Nhap ngay het han: ");
		ngayhethan.nhap();
	}
	public void in(){
		System.out.print("Ma so hang hoa: "+ maso + "\nTen hang hoa: " + ten +"\nNgay san xuat: " + ngaysanxuat +"\nNgay het han: " + ngayhethan + "\n" );
	}
	
}
