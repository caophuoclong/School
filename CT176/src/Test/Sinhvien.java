package Test;
import java.util.Scanner;

import Buoi2.Date;
public abstract class Sinhvien {
	private String name, id;
	private Date nsinh;
	public Sinhvien(){
		this.name = "Long";
		this.id = "1";
		this.nsinh = new Date();
		
	}
	public Sinhvien(Sinhvien sv){
		this.name = sv.name;
		this.nsinh = sv.nsinh;
		this.id = sv.id;
	}
	public String toString(){
		String s = "Ten: " + this.name +"\nID: " +this.id +"\n" + "Ngay sinh: "+ nsinh.toString();
		return s;
	}
	public void Nhap(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ten: ");
		this.name = sc.nextLine();
		System.out.print("Nhap ID: ");
		this.id = sc.nextLine();
		this.nsinh.Nhap();
	}
	abstract String getEmail();
	abstract void changePass(String args);
	abstract String getUsername();
	abstract String getPass();

}
