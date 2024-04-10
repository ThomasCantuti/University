package Orologio;

public class Counter {

    private int val;

    public Counter(){
        val = 0;
    }

    public Counter(int v){
        val = v;
    }

    public void reset(){
        val = 0;
    }

    public void inc(){
        val++;
    }

    public int getValue(){
        return val;
    }
    
    public void dec(){
        val --;
    }
}
