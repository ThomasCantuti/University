public class CounterThread implements Runnable {
    Accumulatore accumulatore;

    public CounterThread (Accumulatore accumulatore) {
        this.accumulatore = accumulatore;
    }

    public void run () {
        double num = Math.random();
        accumulatore.addValue(num);
    }

}
