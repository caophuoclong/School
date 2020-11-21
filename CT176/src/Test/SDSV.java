package Test;

import java.util.Scanner;

import Buoi3.SinhVien;
import Buoi4.SinhvienCNTT;

public class SDSV {
	public static void main(String []args){
		Sinhvien sv[];
		int n ;
		System.out.print("Nhap so luong sinh vien: ");
		Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int count = 0;
        int chose = -1;
        sv = new Sinhvien[n];
        for (int i = 0; i < n;i++){
        	System.out.print("Nhap lua chon: ");
        	do{
        		try{
        			String s = sc.nextLine();
        			chose = Integer.parseInt(s);
        		}
        		catch(Exception e){
        			chose = Integer.MAX_VALUE;
        		}
        		
        	}
        	
        	while(chose == Integer.MAX_VALUE);
        	System.out.print("Lua chon: "+chose +"\n");
        	if(chose == 1){
        		sv[i] = new SinhvienNN();
        		//sv[i].Nhap();
        		
        		
        		count++;
        	}
        	else if (chose == 0){
        		sv[i] =   new SinhvienNor();
        		count++;
        	}
        		
        	
        	else{
        		System.out.print("Error\n");
        	}
        	
        }
        for(int i = 0 ; i < count;i++){
        	System.out.print(sv[i].toString());
        }
	        
		
	}

}
