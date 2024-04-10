package Ereditarietà.AlienGame;

public class Main {
    public static void main(String[] args){

        GruppoAlieni ga=new GruppoAlieni(3);

        ga.aggiungiAlieno(new Alieno(Alieno.ALIENO_SERPENTE,
        100,"Sirbiss"),0);

        ga.aggiungiAlieno(new Alieno(Alieno.ALIENO_ORCO,
        100,"Shrek"),1);

        ga.aggiungiAlieno(new Alieno(Alieno. ALIENO_UOMO_MARSHMALLOW,
        100,"Mork"),2);

        System.out.println("Danno: " + ga.calcolaDanno());

    }
}
