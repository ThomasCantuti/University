package WrapperClass;

public class Main {
    public static void main(String[] args){
        // classi wrapper -> trasformano i tipi primitivi in oggetti equivalenti
        Boolean a; // boolean a;
        Character b; // char b;
        Byte c; // byte c;
        Short d; // short d;
        //Integer e = new Integer(0); // int e;
        Long f; // long f;
        Float g; // float g;
        Double h; // double h;

        int x = 2;
        Integer e = new Integer(x);
        x = 2*e.intValue();
        System.out.println("x = " + x);

        // da stringa a intero
        String stringa = "45";
        x = Integer.parseInt(stringa);
        System.out.println("Numero = " + x);

        // libreria math -> classe di servizio
        x = Math.abs(-2);
        double pi = Math.PI;
    }
}
