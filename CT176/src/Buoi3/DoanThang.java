package Buoi3;
import Buoi2.Diem;
public class DoanThang {
	private Diem d1;
	private Diem d2;
	public DoanThang(){
		this.d1 = new Diem();
		this.d2 = new Diem();
	}
	public DoanThang(Diem x, Diem y){
		this.d1 = new Diem(x);
		this.d2 = new Diem(y);
		
	}
	public DoanThang(int ax, int ay, int bx, int by){
		this.d1 = new Diem(ax, ay);
		this.d2 = new Diem(bx,by);
		
	}
	public void nhap(){
		System.out.print("Nhap toa do cua doan thang: \n");
		System.out.print("Diem a: ");
		this.d1.Nhap();
		System.out.print("\nDiem b: ");
		this.d2.Nhap();
	}
	public void hienthi(){
		System.out.print(d1.toString() + "----" + d2.toString());
	}
	public void tinhtien(int dx, int dy){
		this.d1.doiDiem(dx,dy);
		this.d2.doiDiem(dx, dy);
		
	}
	public float lengthDT(){
		return (float) this.d1.khoangCach(this.d2);
	}
	//public float goc(){
		
	//}
	

}
