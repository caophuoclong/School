package Buoi3;

import java.util.Scanner;

public class Date {
    private int dd, mm ,yy;
    public Date(int d, int m, int y){
        dd = d;
        mm = m;
        yy = y;

    };
    public Date(){
        dd = 1;
        mm = 1;
        yy = 2020;
    }
    public void Show(){
        System.out.println(dd+"/"+mm+"/"+yy);
    }
    public boolean checkDate(int dd, int dx){
        
        if (dd > 0 && dd <= dx) return true;
        return false;
    }
    public boolean isLeapYear(int yy){
        if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0))
            return true;
        return false;
    }
    public void Nhap(){
        int []date = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        @SuppressWarnings("resource")

        Scanner sc = new Scanner(System.in);
        do {
            System.out.print("Nhap nam: ");
            yy = sc.nextInt();
        }while(yy <= 0 );
        if (isLeapYear(yy))
            date[2] = 29;
        do {
            System.out.print("\nNhap thang: ");
            mm = sc.nextInt();
        } while(mm <= 0 || mm > 12);
        do {
            System.out.print("\nNhap ngay: ");
            dd = sc.nextInt();
        } while(!checkDate(dd, date[mm]));
        
    }
    public boolean isRightDate(){
        int []date = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if (yy > 0){
            if (isLeapYear(yy))
                date[2] = 29;
            if(mm > 0 && mm <= 12){

                if (checkDate(dd, date[mm])){
                    return true;
                }
                return false;

            }
            return false;
            
        }
        return false;
    }
    public void nextDate(){
        //Date d = new Date();
        int []date = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapYear(yy))
            date[2] = 29;
        if (checkDate(dd, date[mm])){
            dd = logDay() + 1;
        if (!checkDate(dd, date[mm])){
            dd = 1;
            mm += 1;
            if(mm > 12){
                mm = 1;
                yy += 1;
            }
        }
        //return d;
        }
        //return d;

        
    }
    public void nextNDate(int n){
        for (int i = 0; i < n;i++){
            nextDate();
        }
    }
    public int logDay(){
        return dd;
    }
    public int logMonth(){
        return mm;
    }
    public int logYear(){
        return yy;
    }

}
