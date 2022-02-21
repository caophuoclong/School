public class SquareEquation extends SimpleEquation {
    private double a;
    private double Delta;
    private Double X1;
    private Double X2;
    public SquareEquation(){
        super();
        this.a = 0;
    }
    public SquareEquation(double a) {
        this.a = a;
    }

    public double getA() {
        return this.a;
    }

    public void setA(double a) {
        this.a = a;
    }

    public SquareEquation(double a, double b, double c) {
        super(b, c);
        this.a = a;
        this.X1 = 0.0;
        this.X2 = 0.0;
    }
    private void calDelta(){
        double b = getB();
        System.out.println(getC());
        this.Delta = (b * b) - (4 * this.a * getC());
    }
    public double getDelta(){
        return this.Delta;
    }
    private void setResultSquare() {
        this.X1 = this.X2 = getResult();
    }
    private void resolve(){
        if(this.Delta > 0){
            this.X1 = (-getB() + Math.sqrt(this.Delta)) / (2 * this.a);
            this.X2 = (-getB() - Math.sqrt(this.Delta)) / (2 * this.a);
        }
        else if (this.Delta < 0){
            this.X1 = this.X2 = null;
        }
        else {
            this.X1 = this.X2 = -getB() / (2 * a);
        }
    }
    public Double getX1(){
        return this.X1;
    }
    public Double getX2(){
        return this.X2;
    }
    public String squareCalculate(){
        if(this.a == 0){
            String x = calculate();
            setResultSquare();
            return x;
        } else {
            calDelta();
            resolve();
        }
        return "";
    }

}
