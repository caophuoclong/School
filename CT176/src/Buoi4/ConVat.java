package Buoi4;

import java.util.Scanner;


public abstract class  ConVat {
    private String giong, maulong;
    private float cannag;
    public ConVat(){
        this.giong = "Long";
        this.maulong = "Den";
        this.cannag = 10f;


    }
    public ConVat(ConVat cv){
        this.giong = cv.giong;
        this.cannag = cv.cannag;
        this.maulong = cv.maulong;
    }
    public void Nhap(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap giong: ");
        this.giong = sc.nextLine();
        System.out.print("Nhap mau long: ");
        this.maulong = sc.nextLine();
        System.out.print("Nhap can nang: ");
        this.cannag = sc.nextFloat();

    }
    public void HienThi(){
        System.out.print("\nGiong: "+ this.giong + "\nMau long: "+this.maulong+"\nCan nang: "+this.cannag+"KG\n");
    }
    abstract void keu();
}
