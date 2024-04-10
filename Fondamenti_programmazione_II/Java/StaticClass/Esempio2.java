package StaticClass;
public class Esempio2 {
    public static void main(String[] args){
        int n;
        CounterStatic.reset();
        CounterStatic.inc();
        n = CounterStatic.getValue();
        System.out.println(n);
    }
}
