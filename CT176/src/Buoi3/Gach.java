package Buoi3;

import java.util.Scanner;
import Buoi2.Date;
public class Gach  {
	private String id;
	private String color;
	private int item_in_Box;
	private int long_item;
	private int width_item;
	private int price;
	private Date ngaySX;
	public Gach(){
		id = "001";
		color = "black";
		item_in_Box = 10;
		long_item = 15;
		width_item = 15;
		price = 50000;
		ngaySX = new Date();
	}
	public Gach(Gach g) {
		this.id = new String(g.id);
		this.color = new String(g.color);
		this.item_in_Box = g.item_in_Box;
		this.long_item = g.long_item;
		this.width_item = g.width_item;
		this.price = g.price;
		this.ngaySX = g.ngaySX;
		
		
	}
	public Gach(String id1, String color1, int quanity, int long_item1,int width_item1, int price1, Date x){
		this.id = id1;
		this.color = color1;
		this.item_in_Box = quanity;
		this.long_item = long_item1;
		this.width_item = width_item1;
		this.price = price1;
		this.ngaySX = x;
	}
	public void nhap() {
		System.out.print("Nhap ma so: ");
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		this.id = sc.nextLine();
		System.out.print("Nhap mau sac: ");
		this.color = sc.nextLine();
		System.out.print("Nhap so luong: ");
		this.item_in_Box = sc.nextInt();
		System.out.print("Nhap chieu dai cua vien gach: ");
		this.long_item = sc.nextInt();
		System.out.print("Nhap chieu rong cua vien gach: ");
		this.width_item = sc.nextInt();
		System.out.print("Nhap gia cua hop gach: ");
		this.price = sc.nextInt();
		System.out.print("Nhap ngay san xuat:\n ");
		this.ngaySX.Nhap();
		
	}
	public void in() {
		System.out.print("ID: "+this.id +"\nMau sac: " + this.color + "\nSo luong: " + this.item_in_Box + "\n"
				+ "Chieu dai: "+this.long_item+"\nChieu rong: "+this.width_item + "\nGia: "+this.price +"VND\n"
						+ "Ngay san xuat: "+this.ngaySX.logDay()+"/"+this.ngaySX.logMonth()+"/"+this.ngaySX.logYear());
		
	}
	public float giaBanLe() {
		return (float) ((float) (this.price / this.item_in_Box) * 1.2);
	}
	public int SViengach() {
		return this.long_item * this.width_item ;
	}
	public int MaxDientichNen() {
		return SViengach() * this.item_in_Box;
	}
	public int soLuongHop(int D, int N) {
		return (D*N) / MaxDientichNen();
	}
	public int Giathanh(int D, int N) {
		return (D*N) * this.price / MaxDientichNen();
	}
	public int getPrice(){
		return this.price;
	} 
	
	
	
	

}
