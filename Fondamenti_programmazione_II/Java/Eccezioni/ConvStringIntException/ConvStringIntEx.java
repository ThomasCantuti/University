package Eccezioni.ConvStringIntException;

public class ConvStringIntEx {
    public ConvStringIntEx (String[] args) throws
    NumberFormatException, IllegalArgumentException {
        for (int i = 0; i < args.length; i ++) {
            String num = args[i];
            int n = Integer.parseInt(num);
            if ((n < -10) || (n > 10))
                throw new IllegalArgumentException("Fuori intervallo");

            System.out.println("Numero: " + n);
        }
    }
}
