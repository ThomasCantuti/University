package EserciziEsame.Es1;

public class Patologie {

    private String nomePatologia;
    private int gravità; // 1 : 10 (1 = guarito, 10 = molto grave)

    public Patologie (String nomePat, int grav) {
        nomePatologia = nomePat;
        gravità = grav;
    }

    public String getNomePatologia () {
        return nomePatologia;
    }

    public int getGravità () {
        return gravità;
    }

    public void aggrava () throws MoltoGraveException {
        
        gravità ++;
        if (gravità > 10){
            MoltoGraveException e = new MoltoGraveException();
            throw e;
        }
    }

    public void attenua () throws GuaritaException {

        gravità --;
        if (gravità < 1) {
            GuaritaException e = new GuaritaException();
            throw e;
        }
    }

    public boolean equals (Patologie p) {
        // se nome patologia uguale -> true
        return nomePatologia == p.nomePatologia ? true : false;
    }

    public String toString () {
        return "Nome patologia: " + nomePatologia + "\nGravità: " + gravità + "\n";
    }
}
