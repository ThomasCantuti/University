package AbstractInterfaceClass;

public class DrawableText implements Drawable{
    protected int c;
    protected double x, y;
    protected String s;
    
    public DrawableText(String s){
        this.s = s;
    }

    public void setColor(int c){
        this.c = c;
    }

    public void setPosition(double x, double y){
        this.x = x;
        this.y = y;
    }

    public void draw(){
        System.out.println("Testo, posizione " + x + 
        " " + y + "colore " + c);
    }
}
