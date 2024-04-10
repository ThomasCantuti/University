package Object;

public class Object {
    // uso di final:
    // con metodi -> metodo non può essere ridefinito (no overriding)
    // con classi -> classe non può avere sottoclassi (no extends)

    // this -> parola che rappresenta l'istanza corrente

    private int val;
    public Object(int val){
        this.val = val;
    }

    public void print(){
        System.out.println(this);
        System.out.println(this.val);
    }
}
