package Buoi3;
import java.util.Scanner;
import Buoi2.Date;
public class SinhVien {
	private String id, name;
	private Date nsinh;
	private int soluongHP;
	private String tenHP[];
	private String diemHP[];
	public SinhVien(){
		this.id = "B1906709";
		this.name = "Tran Cao Phuoc Long";
		this.nsinh = new Date(26,03,2001);
		this.soluongHP = 0;
		this.tenHP = new String[soluongHP];
		this.diemHP = new String[soluongHP];
	}
	public SinhVien(String id, String name, int sl, String tenHP[], String diemHP[], Date ns){
		this.id = id;
		this.name = name;
		this.soluongHP = sl;
		this.tenHP = tenHP;
		this.diemHP = diemHP;
		this.nsinh = ns;
	}
	public SinhVien(SinhVien sv){
		this.id = sv.id;
		this.name = sv.name;
		this.soluongHP = sv.soluongHP;
		this.tenHP = sv.tenHP;
		this.diemHP = sv.diemHP;
		this.nsinh = sv.nsinh;
	}
	public void nhapInfor(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap id: ");
		this.id = sc.nextLine();
		System.out.print("\nNhap ten: ");
		this.name = sc.nextLine();
		this.nsinh.Nhap();
		System.out.print("\nNhap so luong hoc phan: ");
		this.soluongHP = sc.nextInt();
		this.tenHP = new String[soluongHP];
		this.diemHP = new String[soluongHP];
		sc.nextLine();
		System.out.print("\nNhap ten tung hoc phan: \n");
		for(int i = 0 ; i < this.soluongHP ; i++){
			System.out.print("Nhap ten HP " + (i+1)+":");
			tenHP[i] = sc.nextLine();
			//System.out.print("\n");
		}

	
	}
	public void nhapDiem(){
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap diem tung hoc phan: \n");
		for(int i = 0 ; i  < soluongHP;i++){
			System.out.print("Diem HP " + tenHP[i] +": ");
			this.diemHP[i] = sc.nextLine();
			//System.out.print("\n");
		}

	}
	public void Nhap() {
	}
	public String toString(){
		String x = "ID: " + this.id + "\nName: " + this.name + "\nNgay sinh: " + this.nsinh.toString();
		String y = "Cac hoc phan da dang ky: ";
		for(int i = 0 ; i < this.soluongHP ; i++){
			y += "\n" + (i+1) + ". " + tenHP[i] + "-" + diemHP[i];
		}
		y += "\n";
		x += "\n";
		if (this.soluongHP == 0)
			return x ;
		else
			return x + y ;
	}
	public float getPoint(String a){
		String s = a;
		if (a.compareTo("A") == 0){
			return (float) 4;
							
			}
		else if (a.compareTo("B+") == 0){
			float min = (float)3.5;
			float max = (float)4;
			return (float) (min + Math.random() * (max - min));
		
		}
		else if (a.compareTo("B") == 0){
			float min = (float)3;
			float max = (float)3.5;
			return (float) (min + Math.random() * (max - min));
			
		}
		else if (a.compareTo("C+") == 0){
			float min = (float)2.5;
			float max = (float)3;
			return (float) (min + Math.random() * (max - min));
		}
		else if (a.compareTo("C") == 0){
			float min = (float)2;
			float max = (float)2.5;
			return (float) (min + Math.random() * (max - min));
		}
		else if (a.compareTo("D+") == 0){
			float min = (float)1.5;
			float max = (float)2;
			return (float) (min + Math.random() * (max - min));
		}
		else if (a.compareTo("D") == 0){
			float min = (float)1;
			float max = (float)1.5;
			return (float) (min + Math.random() * (max - min));
		}
		else if (a.compareTo("F") == 0){
			float min = (float)0;
			float max = (float)1;
			return (float) (min + Math.random() * (max - min));
		}
		else{
			return (float) 0;
		}
	}
	public float dtb(){
		float diem = 0;
		for(int i = 0 ; i  < soluongHP;i++){
			String s = diemHP[i].trim();
			System.out.print("\n"+s);
			diem += getPoint((String)s);
		}
		return (float) (diem/soluongHP);
		
	}
	public String getEmail(){
		String s = "Long";
		return s;
	}
	public void add_newHP(){
		Scanner sc = new Scanner(System.in);
		System.out.print("\nNhap ten hoc phan can them: ");
		String ten =  sc.nextLine();
		this.tenHP[soluongHP] =ten;
		System.out.print("\nNhap diem hoc phan can them: ");
		String diem =  sc.nextLine();
		this.diemHP[soluongHP] =diem;
		this.soluongHP++;
		
	}
	public int getSoluongHP(){
		return this.soluongHP;
	}
	public String log_name(){
		return this.name;
	}
	public void xoa_HP(){
		this.soluongHP--;
	}
	
	
}
