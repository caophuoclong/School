package Test;

import java.util.Scanner;

public class SinhvienNN extends Sinhvien {
	private String user, password, email;
	public SinhvienNN(){
		super();
		this.user = "b1906709";
		this.email = "caophuoclong1@gmail.com";
		this.password = "*****";
	}
	public SinhvienNN(SinhvienNN sv){
		super(sv);
		this.user = sv.user;
		this.password = sv.password;
		this.email = sv.email;
	}
	public void Nhap(){
		Scanner sc =  new Scanner(System.in);
		System.out.print("Nhap tai khoan: ");
		this.user = sc.nextLine();
		System.out.print("Nhap mat khau: ");
		this.password = sc.nextLine();
		System.out.print("Nhap email: ");
		this.email = sc.nextLine();
	}
	public String toString(){
		String s = super.toString() + "Tai khoan: " + this.user +"\nMat khau: "+ this.password + "\nEmail: " + this.email +"\n";
		return s;
	}
	
	String getEmail() {
		
		return this.email;
	}

	
	void changePass(String newPass) {
		this.password = newPass;
		
	}

	
	String getUsername() {
		return this.user;
	}

	
	String getPass() {
		return this.password;
	}
	

}
