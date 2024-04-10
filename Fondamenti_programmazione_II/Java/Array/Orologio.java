package Array;

public class Orologio {
    private Counter[] c;

    public Orologio(){
        c = new Counter[2];
        c[0] = new Counter(); // ore
        c[1] = new Counter(); // minuti
    }

    public void reset(){
        c[0].reset();
        c[1].reset();
    }

    public int getMin(){
        return c[1].getValue();
    }

    public int getOre(){
        return c[0].getValue();
    }

    public void tic(){
        c[1].inc();
        if(c[1].getValue() == 60){
            c[1].reset();
            c[0].inc();
        }
        if(c[0].getValue() == 24)
            c[0].reset();
    }
}
