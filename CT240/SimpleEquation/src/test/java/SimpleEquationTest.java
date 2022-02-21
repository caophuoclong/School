import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SimpleEquationTest {
    private SimpleEquation simpleEquation;
    @BeforeEach
    void setUp() {
        simpleEquation = new SimpleEquation(3,5);
    }

    @Test
    void getC() {
        assertEquals(5, simpleEquation.getC());
    }

    @Test
    void setC() {
        simpleEquation.setC(3.5);
        assertEquals(3.5, simpleEquation.getC());
    }

    @Test
    void getB() {
        assertEquals(3, simpleEquation.getB());
    }

    @Test
    void setB() {
        simpleEquation.setB(5.5);
        assertEquals(5.5, simpleEquation.getB());
    }
    @Test
    void calculateVN(){
        simpleEquation.setB(0);
        assertEquals("PT VN", simpleEquation.calculate());
    }
    @Test
    void calculateVSN() {
        simpleEquation.setC(0);
        assertEquals("PT VSN", simpleEquation.calculate());
    }
    @Test
    void calculate(){
        simpleEquation.calculate();
        assertEquals(-5.0/3, simpleEquation.getResult());
    }
}
