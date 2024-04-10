package Stringhe;

public class Counter {

    private int val;

    public Counter(){
        val = 1;
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
    
    /*public void dec(){
        val --;
    }*/

    public String toString(){
        return "Counter di valore " + val;
    }
}
