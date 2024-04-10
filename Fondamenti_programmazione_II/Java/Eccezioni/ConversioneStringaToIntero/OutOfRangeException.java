package Eccezioni.ConversioneStringaToIntero;

public class OutOfRangeException extends IllegalArgumentException {
    
    public OutOfRangeException () {
        super();
    }

    public OutOfRangeException (String s) {
        super(s);
    }

    public static Double parseDouble (String s) 
        throws OutOfRangeException {
            if (Double.parseDouble(s) < -10 || Double.parseDouble(s) > 10) {
                OutOfRangeException re = new OutOfRangeException();
                throw re;
            } 
            else
                return Double.parseDouble(s);
    }

}
