package Buoi3;
import Buoi2.Diem;
public class SDHPT {
	public static void main(String []args){

		Diem d1 = new Diem(2,5);
		Diem d2 = new Diem(20,35);
		HePT a = new HePT(d1,d2);
		Diem x = new Diem(a.result());
		x.Show();
		
		
	}

}
