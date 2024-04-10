package CounterDec;

public class EsempioDec {
    public static void main(String[] args){
        CounterDec cd;
        int n;
        cd = new CounterDec();
        cd.reset();
        cd.inc();
        cd.inc();
        n = cd.getValue();
        System.out.println(n);
        cd.dec();
        n = cd.getValue();
        System.out.println(n);
    }
}
