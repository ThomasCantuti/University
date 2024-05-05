public class Macchina {
    private int id;
    private int pezziProdotti;

    public Macchina (int id, int pezziProdotti) {
        this.id = id;
        this.pezziProdotti = pezziProdotti;
    }

    public synchronized void setMacchinaID (int id) {
        this.id = id;
    }

    public synchronized int getMacchinaID () {
        return this.id;
    }

    public synchronized void setPezziProdotti (int pezziProdotti) {
        this.pezziProdotti += pezziProdotti;
    }

    public synchronized int getPezziProdotti () {
        return this.pezziProdotti;
    }
}
