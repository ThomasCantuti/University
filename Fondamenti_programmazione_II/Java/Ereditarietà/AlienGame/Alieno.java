package Ereditarietà.AlienGame;

public class Alieno {

    protected static final int ALIENO_SERPENTE = 0;
    protected static final int ALIENO_ORCO = 1;
    protected static final int ALIENO_UOMO_MARSHMALLOW = 2;
    protected int tipo; // Memorizza uno dei tre tipi sopra indicati
    protected int salute; // 0=morto, 100=forza piena
    protected String nome;

    public Alieno(int t, int s, String n) {
        tipo = t;
        salute = s;
        nome = n;
    }

    public int getDanno(int tipo){

        int danno = 0;
        
        if (tipo == Alieno.ALIENO_SERPENTE)
            danno = 10;
        else if (tipo == Alieno.ALIENO_ORCO)
            danno = 6;
        else if (tipo == Alieno.ALIENO_UOMO_MARSHMALLOW)
            danno = 1;
        
        return danno;
    }
}
