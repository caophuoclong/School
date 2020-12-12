package Buoi5;
import Buoi2.Date;

public class MyDate extends Date {
	
	public MyDate(){
		super();
	}
	public MyDate(MyDate md){
		super(md);
	}
	public void  nhap(){
		super.Nhap();
	}
	public String toString(){
		return super.toString();
	}
	
}
