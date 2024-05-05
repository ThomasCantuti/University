public class ControlloProduzione {
    private int semilavoratiDisponibili = 0;
    private int pezziPronti = 0;

    public synchronized void incrementaSemilavorati () {
        semilavoratiDisponibili ++;
    }

    public synchronized void decrementaSemilavorati () {
        semilavoratiDisponibili --;
    }

    public synchronized int getSemilavorati () {
        return semilavoratiDisponibili;
    }

    public synchronized void incrementaPezziPronti () {
        pezziPronti ++;
    }

    public synchronized void decrementaPezziPronti () {
        pezziPronti --;
    }

    public synchronized int getPezziPronti () {
        return pezziPronti;
    }
}
