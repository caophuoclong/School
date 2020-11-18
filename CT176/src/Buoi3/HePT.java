package Buoi3;
import Buoi2.Diem;
public class HePT {
	// y = ax + b;
	// a2 = a1.a + b;
	// c = a1.x + b.y;
	// a1*a + b = a2;
	// b1*a + b = b2;
	// b2 = b1.a + b;
	private Diem d1,d2;
	public HePT(Diem d1, Diem d2){
		this.d1 = new Diem(d1);
		this.d2 = new Diem(d2);
		
	}
	public int det(){
		//System.out.print(this.d1.giatriX());
		//System.out.print(this.d2.giatriX());
		int asad =   Math.abs(this.d1.giatriX() - this.d2.giatriX());
		
		return asad;
		
	}
	public Diem result(){
		int a,b;
		Diem x;
		System.out.print("Xin chao");
		int det = det();
		//System.out.print(det());
		if (det != 0){
			a = (this.d1.giatriY() - this.d2.giatriY())/det();
			b = (this.d1.giatriX()*this.d2.giatriY() - this.d2.giatriX()*this.d1.giatriY());
			System.out.print(a);
			x = new Diem(a,b);
			
			return x;
		}
		x = new Diem();
		return x;
	}
}
