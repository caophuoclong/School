package Buoi4;
import java.util.Scanner;
import Buoi2.Diem;

public class DiemMau extends Diem {
    private String colors;
    public DiemMau(){
        super();
        colors = "Black";

    }
    public DiemMau(int x, int y, String colors){
        super(x,y);
        this.colors = colors;
    }
    public DiemMau(DiemMau dm){
        super(dm);
        this.colors = dm.colors;
    }
    public void GanMau(String mau){
        this.colors = mau;
    }
    public void nhap(){
        super.Nhap();
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap mau sac: ");
        this.colors = sc.nextLine();
    }
    public void hienthi(){
        super.Show();
        System.out.print("Mau sac: " + this.colors +"\n");
    }
    public String toString(){
        return super.toString() + "\nMau sac: " + this.colors;
    }

}
