package Orologio;

public class Orologio {
    Counter min, ore;

    public Orologio(){
        ore = new Counter();
        min = new Counter();
    }

    public void reset(){
        ore.reset();
        min.reset();
    }

    public int getMin(){
        return min.getValue();
    }

    public int getOre(){
        return ore.getValue();
    }

    public void tic(){
        min.inc();
        if(min.getValue() == 60){
            min.reset();
            ore.inc();
        }
        if(ore.getValue() == 24)
            ore.reset();
    }
}
