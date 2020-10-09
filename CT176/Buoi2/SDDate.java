package Buoi2;

public class SDDate {
    public static void main(String[] args) {
        Date d1 = new Date(29,2,2012);
        Date d2 = new Date();
        d2.Show();
        d1.nextNDate(5);
        if (d1.isRightDate())
            d1.Show();
        else
            System.out.print("Xinchao");
        
    }
}
