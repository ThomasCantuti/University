package Ereditarietà.Dottore;

public class Paziente extends Persona {
    
    private String nome;
    private String id;

    public Paziente() {
        super();
        id = null;
    }

    public Paziente(String newNome, String newID) {
        nome = newNome;
        id = newID;
    }

    public void setID(String newID) {
        id = newID;
    }

    public String getID() {
        return id;
    }

    public void setNome(String newNome) {
        nome = newNome;
    }

    public String getNome() {
        return nome;
    }
}
