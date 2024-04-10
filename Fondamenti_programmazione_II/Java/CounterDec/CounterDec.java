package CounterDec;

public class CounterDec {

    private Counter c;

    public CounterDec(int n){
        c = new Counter(n);
    }

    public CounterDec(){
        c = new Counter();
    }
    
    public void dec(){
        c = new Counter(c.getValue()-1);
    }
    
    public void reset(){
        c.reset();
    }

    public void inc(){
        c.inc();
    }

    public int getValue(){
        return c.getValue();
    }
}
