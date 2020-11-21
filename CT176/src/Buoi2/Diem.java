package Buoi2;

import java.util.Scanner;

public class Diem {
    private int x;
	private int y;

	public Diem(Diem d){
		this.x = d.x;
		this.y = d.y;
	}
    public Diem(){
        x = 0;
        y = 0;
    }
    public Diem(int dx, int dy){
        x = dx;
        y = dy;
    }
    public  void Nhap(){
		Scanner  sc = new Scanner(System.in);
        System.out.print("Nhap x: ");
        int dx = sc.nextInt();
        System.out.print("Nhap y: ");
        int dy = sc.nextInt();
        y = dy;
        x = dx;
    }
    public void Show(){
        System.out.print("("+x+","+y+")\n");
    }
    public void doiDiem(int dx, int dy){
        this.x += dx;
        this.y += dy;
    }
    public int giatriX(){
        return this.x;
    }
    public int giatriY(){
        return this.y;
    }
    public float khoangCach(){
        return (float) Math.sqrt(Math.pow(x, 2)+Math.pow(y, 2));
    }
    public float khoangCach(Diem d){
        return (float) Math.sqrt(Math.pow(x-d.giatriX(), 2)+Math.pow(y-d.giatriY(), 2));
    }
    public Diem DoiXung(){
    	Diem b = new Diem();
    	
    	b.x = -this.x;
    	b.y = -this.y;
    	return b;
    }
    public String toString(){
    	return "("+this.x+","+this.y+")";
    }
    
	
    
}
