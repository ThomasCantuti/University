package AbstractInterfaceClass;

public class DrawableRectangle extends Rectangle implements Drawable{

    protected int c;
    protected double x, y;
    
    public DrawableRectangle(double h, double w){
        super(h, w);
    }

    public void setColor(int c){
        this.c = c;
    }

    public void setPosition(double x, double y){
        this.x = x;
        this.y = y;
    }

    public void draw(){
        System.out.println("Rettangolo, posizione " + x + 
        " " + y + "colore " + c);
    }
}
