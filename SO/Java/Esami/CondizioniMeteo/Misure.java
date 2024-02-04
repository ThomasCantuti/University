package SO.Java.Esami.CondizioniMeteo;

import java.io.Serializable;

public class Misure implements Serializable {

    private float temperatura;
    private int umidita;
    
    public Misure (float temperatura, int umidita) {
        this.temperatura = temperatura;
        this.umidita = umidita;
    }

    public float getTemperatura () {
        return temperatura;
    }

    public int getUmidita () {
        return umidita;
    }

    public void setTemperatura (float temperatura) {
        this.temperatura = temperatura;
    }

    public void setUmidita (int umidita) {
        this.umidita = umidita;
    }

}
