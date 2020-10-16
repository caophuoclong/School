package Buoi2;

public class SDDate {
    public static void main(String[] args) {
        Date d1 = new Date(1,1,2012);
        d1.nextNDate(60);
        if (d1.isRightDate())
            d1.Show();
        else
            System.out.print("Xinchao");
        
    }
}
