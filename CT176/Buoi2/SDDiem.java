package Buoi2;
public class SDDiem {
    public static void main(String[] args) {
        Diem a = new Diem(3,5);
        a.Show();
        Diem b = new Diem();
        b.Nhap();
        b.Show();
        System.out.print(b.khoangCach());
        System.out.print(a.khoangCach(b));
        
    }
    
}
