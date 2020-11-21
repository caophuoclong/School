package Buoi4;
import java.util.Scanner;

import Buoi3.SinhVien;
public class SDSVCNTT {
    public static boolean  compareEmail(String email, SinhVien sv){
        if (email.equals(sv.getEmail()))
               	
        
            return true;
        else
        	
            return false;
    }
    public static void main(String[] args) {
        SinhVien []svcntt;
        int n;
    	int count = 0;

        System.out.print("Nhap so luong sinh vien: ");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int chose = -1;
        sc.nextLine();
        svcntt = new SinhVien[n];
        for (int i = 0; i < n;i++){
        	System.out.print("Nhap lua chon: (SV = 0 , SVCNTT = 1) ");
        	do{
        		try{
        			String s = sc.nextLine();
        			chose = Integer.parseInt(s);
        		}
        		catch(Exception e){
        			System.out.print("Nhap lai: ");
        			chose = Integer.MAX_VALUE;
        		}
        		
        	}
        	
        	while(chose == Integer.MAX_VALUE);
        	System.out.print("Lua chon: "+chose +"\n");
        	if(chose == 1){
        		svcntt[i] = new SinhvienCNTT();
        		svcntt[i].Nhap();
        		
        		
        		count++;
        	}
        	else if (chose == 0){
        		svcntt[i] =   new SinhVien();
        		count++;
        	}
        		
        	
        	else{
        		System.out.print("Error\n");
        	}
        	
        }
        for(int i = 0 ; i < count; i++){
        	try{
        		System.out.print(svcntt[i].toString());
        	}
        	catch(Exception e){}
        
        	
        }
        //System.out.print(svcntt[0].log_name());
        String infor;
        System.out.print("Nhap email can tim: ");
        String email = sc.nextLine();
        if (email != "None")
        	
        for (int i = 0;i < count; i++){
        	if (compareEmail(email,svcntt[i]))
        		infor = svcntt[i].toString() +"Diem trung binh: " + Float.toString(svcntt[i].dtb()) ;
        	else
        		infor = "N";
        	if (infor != "N")
        		System.out.print(infor);

        	
        }
        
    }
}
