package Buoi4;

public class SDDiemMau {
    public static void main(String[] args) {
        DiemMau A = new DiemMau(5,10,"White");
        A.hienthi();
        DiemMau B = new DiemMau();
        B.nhap();
        B.hienthi();
        B.doiDiem(10,8);
        B.GanMau("Vang");
        B.hienthi();
    }
}
