package SO.Java.Esami.RilevareInquinamento;

import java.io.Serializable;

public class Rilevazione implements Serializable {

    private int valore = 0;
    private long timestamp = 0L;

    public Rilevazione (int valore, long timestamp) {
        this.timestamp = timestamp;
        this.valore = valore;
    }

    public int getValore () {
        return valore;
    }

    public long getTimestamp () {
        return timestamp;
    }

    public void setValore (int valore) {
        this.valore = valore;
    }

    public void setTimestamp (long timestamp) {
        this.timestamp = timestamp;
    }
    
}
