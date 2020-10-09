package Buoi1;

import java.util.Scanner;
public class Lession_Eight {
    public static Scanner sc = new Scanner(System.in);
    public static int input() {
        int x = Integer.MAX_VALUE;
        while(x == Integer.MAX_VALUE){
            try{
                
                String s = sc.nextLine();
                x = Integer.parseInt(s);
            }
            catch(Exception e){
                System.out.print("So ban nhap khong hop le! Nhap lai: ");
                x = Integer.MAX_VALUE;
            }
        }
        return x;
        
    }
    public static int [] arr_int() {
        System.out.println("Ban muon nhap bao nhieu so nguyen?  ");
        int n = sc.nextInt();
        int arr[] = new int [n];
        sc.nextLine();
        for (int i = 0; i < n;i++){
            System.out.println("Nhap so nguyen thu: " + (i+1));
            arr[i] = input();
        }
        return arr;
    }
    public static void Count(int [] arr) {
        System.out.println("Nhap so x can dem: ");
        int x = input();
        int count = 0;
        for (int i = 0; i < arr.length;i++){
            if (arr[i] == x)
                count++;
        }
        System.out.println("Co "+count+" so "+ x +" trong mang.");
        sc.close();  
    }
    public static void Sort(int [] arr) {
        for (int i = 0; i < arr.length;i++)
            for(int j = i+1; j < arr.length;j++)
                if (arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
    }
    public static void main(String[] args) {
        int arr[] =arr_int();
        Count(arr);
        Sort(arr);
        System.out.println("Mang da duoc sap xep la: ");
        for (int i = 0; i < arr.length;i++)
            System.out.print(arr[i]+" ");

        
    }
}
