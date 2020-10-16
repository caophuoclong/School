package Buoi1;
public class WhatName {
    public static String Split_Name(String s) {
        s = s.trim();
        String arr[] = s.split(" ");
        return arr[arr.length-1];
        
    }
    public static void main(String[] args) {
        String s = "Tran Cao Phuoc Long" ;
        System.out.println("Ten cua ban la: " + Split_Name(s));
    }
}
