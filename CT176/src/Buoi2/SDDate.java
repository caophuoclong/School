package Buoi2;

import Buoi3.Date;

public class SDDate {
    public static void main(String[] args) {
        Date d1 = new Date(15,6,2000);
        d1.nextNDate(20);
        if (d1.isRightDate())
            d1.Show();
        else
            System.out.print("Xinchao");
        
    }
}
