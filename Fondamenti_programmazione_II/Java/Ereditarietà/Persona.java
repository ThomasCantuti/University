package Ereditarietà;

public class Persona {
    protected String nome;
    protected int eta;
    private String codiceFiscale;

    // visibilità:
    // public int a -> in class, package, subclass, world
    // protected int a -> in class, package, subclass
    // int a -> in class, package
    // private int a -> in class

    // metodi accesso: get (o getter) -> tipo getAttributo()  (se attributo è variabile d'istanza e ha tipo)
    // metodi di modifica: set (o setter) -> void setAttributo(tipo valore) (se attributo è variabile d'istanza e ha tipo)

    public Persona(String n, int e){
        nome = n;
        eta = e;
    }

    public Persona(String n, int e, String cf){
        nome = n;
        eta = e;
        codiceFiscale = cf;
    }

    public String getCodiceFiscale(){
        return codiceFiscale;
    }

    public void setCodiceFiscale(String cf){
        codiceFiscale = cf;
    }

    public void saluta(){
        System.out.println("Ciao sono " + nome + " e ho " + eta + " anni");
    }
}
