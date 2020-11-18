package Buoi3;

import java.util.Scanner;

public class SDSinhVIen {
	public static SinhVien max(SinhVien sv[]){
		float MAX = -1;
		SinhVien Max = new SinhVien();
		for (int i = 0 ; i < sv.length;i++){
			if(sv[i].dtb() > MAX){
				MAX = sv[i].dtb();	
				Max = sv[i];
			}
				
		}
		return Max;
		
		
		
	}
	public static SinhVien[] canhcaoHV(SinhVien sv[]){
		
		int j = 0;
		int x = 0;
		for(int i = 0 ;i < sv.length;i++){
			if(sv[i].dtb() < 1){
				x++;
			}
			
						
		}
		SinhVien sv1[] = new SinhVien[x];
		
		for(int i = 0 ;i < sv.length;i++){
			if(sv[i].dtb() < 1){
				sv1[j] = new SinhVien(sv[i]);
				j++;
			}
			
						
		}
		
		return sv1;
	}
	public static String split_name(String args){
		String x[] =  args.trim().split(" ");
		return x[x.length -1];
	}
	public static SinhVien []sort(SinhVien sv[]){
		for (int i = 0 ; i < sv.length;i++){
			for(int j =i+1;j<sv.length;j++){
				String name1 = split_name(sv[i].log_name());
				String name2 = split_name(sv[j].log_name());
				
				if(name1.compareTo(name2) > 0){
					SinhVien temp = new SinhVien(sv[i]);
					sv[i] = sv[j];
					sv[j] = temp;
				}
					
				
			}
			
		}
		return sv;
	}
	
	public static void main (String []args){
		SinhVien sv[];
		System.out.print("Nhap danh sach sinh vien: \n");
		System.out.print("Nhap so luong sinh vien: ");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sv = new SinhVien[n];
		for (int i = 0 ; i < n;i++){
			sv[i] = new SinhVien();
			System.out.print("Nhap thong tin sinh vien thu: " +(i+1) +"\n");
			sv[i].nhapInfor();
			sv[i].nhapDiem();
		}
		SinhVien max = new SinhVien(max(sv));
		System.out.print("Sinh vien co diem cao nhat la: \n");
		System.out.print(max.toString());
		SinhVien canhcao[] = canhcaoHV(sv);
		System.out.print("Sinh vien bi canh cao hoc vu la: \n");
		for(int i = 0 ; i < canhcao.length;i++){
			System.out.print(canhcao[i].toString()+"\n");
		}
		System.out.print("Sap xep theo ten: \n");
		SinhVien sort[] = sort(sv);
		for (int i = 0 ; i < sort.length;i++){
			System.out.print(sort[i].toString()+"\n");
			
		}
	
	}
}
