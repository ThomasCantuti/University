package Array;

public class Main{
    public static void main(String[] args){
        int[] a;
        double[] b = {1.5, 2.6, 3.9};
        a = new int[50];
        // se fuoriesco dall'intervallo di a genera errore e blocca programma
        int n = a.length; // solo lettura -> restituisce dim di array
        n = b.length;

        Counter[] c;
        c = new Counter[4];
        for(int i = 0; i < 4; i ++)
            c[i] = new Counter();
    }
}