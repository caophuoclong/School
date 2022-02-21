import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SquareEquationTest {
    private SquareEquation ptb2;
    @BeforeEach
    void setUp(){
        ptb2 = new SquareEquation(0,-4,4);

    }
    @Test
    void getA() {
        assertEquals(4, ptb2.getA());

    }

    @Test
    void setA() {
        ptb2.setA(5);
        assertEquals(5, ptb2.getA());
    }

    @Test
    void squareCalculate() {
        ptb2.squareCalculate();
        assertEquals(2, ptb2.getX1());
        assertEquals(2, ptb2.getX2());
    }
    @Test
    void squareCalculateA0(){
        ptb2.squareCalculate();
        assertEquals(1,ptb2.getX1());
    }
}
