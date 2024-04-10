package AbstractInterfaceClass;

public interface Drawable {
    // nelle interfacce si scrivono i metodi senza implementazione
    // le classi che usano l'interfaccia DEVONO IMPLEMENTARE 
    // TUTTI I METODI DELL'INTERFACCIA
    // consente subtyping anche per le interfacce
    // dopo implements si possono scrivere quante interfacce si vuole
    // dopo extends si può scrivere solo una classe
    public void setColor(int c);
    public void setPosition(double x, double y);
    public void draw();
}
