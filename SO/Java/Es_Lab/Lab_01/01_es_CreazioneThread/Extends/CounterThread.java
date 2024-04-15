public class CounterThread extends Thread {
    Accumulatore accumulatore = new Accumulatore(0);

    public CounterThread (Accumulatore accumulatore) {
        this.accumulatore = accumulatore;
    }

    public void run () {
        double num = Math.random();
        accumulatore.addValue(num);
    }

}
