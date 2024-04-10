package Eccezioni.ConversioneStringaToIntero;

public class ConversioneStringToInt {
    
    private String[] s;
    private int count;
    private double n;

    public ConversioneStringToInt (String[] args) {
        count = args.length;
        s = new String[count];
        s = args;
    }

    public void Conversione () 
        throws OutOfRangeException {

        for (int i = 0; i < count; i ++) {
            try {
                n = OutOfRangeException.parseDouble(s[i]);
                stampa();
            } catch (OutOfRangeException re) {
                // re = range exception
                re = new OutOfRangeException();
                throw re;
            }
        }
    }

    public void stampa () {
        System.out.println("Num: " + n);
    }
}
