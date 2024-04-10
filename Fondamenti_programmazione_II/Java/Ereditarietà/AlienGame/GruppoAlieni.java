package Ereditarietà.AlienGame;

public class GruppoAlieni extends Alieno{

    private Alieno[] alieno;

    public GruppoAlieni(int alieniNum) {
        super(0, 0, null);
        alieno = new Alieno[alieniNum];
    }

    public void aggiungiAlieno(Alieno nuovoAlieno, int indice) {
        alieno[indice] = nuovoAlieno; 
    }

    public Alieno[] getAlieni() {
        return alieno; 
    }

    public int calcolaDanno() {

        int danno = 0;
        
        for (int i = 0; i < alieno.length; i++) {
            if (alieno[i].tipo == Alieno.ALIENO_SERPENTE)
                danno += getDanno(Alieno.ALIENO_SERPENTE);

            else if (alieno[i].tipo == Alieno.ALIENO_ORCO)
                danno += getDanno(Alieno.ALIENO_ORCO);

            else if (alieno[i].tipo == Alieno.ALIENO_UOMO_MARSHMALLOW)
                danno += getDanno(Alieno.ALIENO_UOMO_MARSHMALLOW);
        }
        return danno;
    }
}
