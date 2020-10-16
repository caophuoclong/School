package Buoi1;

public class Ptbac2 {
    public static double ptb1(double a, double b) {
        try {
           
            return (double) -b/a;
        } catch (Exception e) {
            return 0;
        }
    }
    public static void ptb2(double a, double b, double c) {
        double x1,x2;
        if (a == 0)
            if (ptb1(b, c) == 0)
                System.out.println("Phuong trinh vo nghiem.");
            else
                System.out.println("Phuong trinh co 1 nghiem la: "+ptb1(b, c));
        else{
            double delta = b*b - (4*a*c);
            if (delta > 0){
                x1 = (double)(-b + Math.sqrt(delta)) / (2 * a);
                x2 = (double) ( -b - Math.sqrt(delta)) / (2*a);
                System.out.println("Phuong trinh co 2 nghiem la: \nx1: " + x1 + "\nx2: "+x2);
            }
            else if (delta == 0){
                x1 = -b / (2 *a);
                System.out.println("Phuong trinh co 1 nghiem la: " + x1);


            }
            else    
                System.out.println("Phuong trinh vo nghiem");

        }
        
    }
    public static void main(String[] args) {
        int arr[] = Input.nhap_3_so();
        ptb2(arr[0], arr[1], arr[2]);
        
    }
}
