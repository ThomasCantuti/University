package Ereditarietà.Dottore;

public class Dottore extends Persona {
    
    private String nome;
    private String specializzazione;
    private double parcella;

    public Dottore() {
        super();
        specializzazione = null;
        parcella = 0;
    }

    public Dottore(String newNome, String newSpec, double newParc) {

        nome = newNome;
        specializzazione = newSpec;
        parcella = newParc;
    }

    public void setSpecializzazione(String newSpec) {
        specializzazione = newSpec;
    }

    public String getSpecializzazione() {
        return specializzazione;
    }

    public void setParcella(double newParc) {
        parcella = newParc;
    }

    public double getParcella() {
        return parcella;
    }

    public void setNome(String newNome) {
        nome = newNome;
    }

    public String getNome() {
        return nome;
    }

    public boolean equals(Dottore altroDottore) {
        return false;
    }
}
