package Buoi3;
import Buoi2.Diem;
public class SDDoanthang {
	public static void main (String []args){
		Diem A = new Diem(2,5);
		Diem B = new Diem(20,35);
		DoanThang AB = new DoanThang(A,B);
		AB.hienthi();
		AB.tinhtien(5, 3);
		AB.hienthi();
		DoanThang CD = new DoanThang();
		CD.nhap();
		CD.hienthi();
		float dodai = CD.lengthDT();
	}

}
