class Counter {
    private int val;
    public Counter(){
        val = 0;
    }
    public Counter(int n){
        val = n;
    }
    public void reset(){
        val = 0;
    }
    public void inc(){
        val++;
    }
    public void inc(int n){
        val = val + n;
    }
    public int getValue(){
        return val;
    }
    public void copy(Counter x){
        val = x.val;
    }
    public boolean equals(Counter x){
        return val == x.val;
    }
}

public class Esempio3 {
    public static void main(String[] args){
        int n;
        Counter c1, c2;
        c1 = new Counter();
        c2 = new Counter(5);
        c1.reset();
        c1.inc();
        c2.equals(c1);
        c2.copy(c1);
        c2.equals(c1);
        c1.inc(5);
        n = c1.getValue();
        System.out.println(n);
    }
}
