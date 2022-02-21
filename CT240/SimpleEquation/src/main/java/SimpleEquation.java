public class SimpleEquation {
    public double c;
    public double b;
    public double result;
    public SimpleEquation() {
        this.c = 0;
        this.b = 0;
        this.result = 0;
    }
    public SimpleEquation(double b, double c){
        this.c = c;
        this.b = b;
        this.result = 0;
    }
    public double getC() {
        return c;
    }

    public void setC(double c) {
        this.c = c;
    }

    public double getB() {
        return this.b;
    }

    public void setB(double b) {
        this.b = b;
    }

    public double getResult(){
        return this.result;
    }
    public void setResult(double result){
        System.out.println(result);
        this.result = result;
    }

    @Override
    public String toString() {
        return "SimepleEquation{" +
                "result=" + result +
                '}';
    }

    public String calculate(){
        if(this.b == 0){
            return "PT VN";
        }
        else if (this.c == 0 ){
            return "PT VSN";

        }else{
            this.result = (this.c * -1) / this.b;
            return toString();
        }
    }


}
