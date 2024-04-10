package SubtypingPolimorfismo;

public class Persona {
    protected String nome;
    protected int eta;

    public Persona(String n, int e){
        nome = n;
        eta = e;
    }

    public void saluta(){
        System.out.println("Ciao sono " + nome + " e ho " + eta + " anni");
    }
}
