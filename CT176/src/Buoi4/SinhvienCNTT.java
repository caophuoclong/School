package Buoi4;

import Buoi3.SinhVien;

import java.util.Scanner;

public class SinhvienCNTT extends SinhVien {
    private String email, tk, mk;
    public SinhvienCNTT(){
        super();
        this.email = "longb1906709@student.ctu.edu.vn";
        this.tk = "B1906709";
        this.mk = "******";
    }
    public SinhvienCNTT(SinhvienCNTT svcntt){
        super(svcntt);
        this.email = svcntt.email;
        this.tk = svcntt.tk;
        this.mk  = svcntt.mk;
    }
    public void Nhap(){
        super.nhapInfor();
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap email: ");
        this.email = sc.nextLine();
        System.out.print("Nhap tai khoan: ");
        this.tk = sc.nextLine();
        System.out.print("Nhap mat khau: ");
        this.mk = sc.nextLine();
        super.nhapDiem();
        
    }
    public String toString(){
        String s = super.toString() + "Email: " + this.email + "\nTai khoan: " + this.tk + "\nMat khau: " + this.mk +"\n";
        return s;
    }
    public void changePass(String newPass){
        this.mk = newPass;
    }

    public String getEmail(){
        return this.email;
    }
    
}
