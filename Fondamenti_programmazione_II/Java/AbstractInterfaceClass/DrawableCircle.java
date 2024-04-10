package AbstractInterfaceClass;

public class DrawableCircle extends Circle implements Drawable{

    protected int c;
    protected double x, y;

    public DrawableCircle (double r){
        super(r);
    }

    public void setColor(int c){
        this.c = c;
    }

    public void setPosition(double x, double y){
        this.x = x;
        this.y = y;
    }

    public void draw(){
        System.out.println("Cerchio, posizione " + x 
        + " " + y + "colore " + c);
    }
}
