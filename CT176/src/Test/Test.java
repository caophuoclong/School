package Test;
import java.util.Scanner;
import java.lang.*;
public class Test {
	public static void Ham1(int x){
		Scanner sc = new Scanner(System.in);
		x = sc.nextInt();
		System.out.print(x);
	}
	public static int	 Ham4(long a){
		return ((int)a + 10001);
	}
	public static void Ham2(float y){
		float z = 15;
		z += y;
		System.out.print(z);
		//return y;
	}
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
		Ham2(11);
	}

}
