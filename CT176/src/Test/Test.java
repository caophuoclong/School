package Test;
import java.lang.*;
public class Test {
	public static String toUpper(String s){
		String []arr_name = s.trim().split(" ");
		String name = "";
		for (String i : arr_name){
			i = i.substring(0,1).toUpperCase() + i.substring(1).toLowerCase();
			name += i + " " ;
		}
		return name;
	}
	public static void main(String []args){
		String s;
		s = "Tran cao phuoc long";
		String [] x = s.trim().split(" ");
		String a = x[x.length-1];
		s = toUpper(s);
		System.out.print(s);
	}

}
