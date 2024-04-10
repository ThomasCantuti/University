package AbstractInterfaceClass;

public class Rectangle extends Shape{

    protected double h, w;

    public Rectangle(double h, double w){
        this.h = h;
        this.w = w;
    }

    public double area(){
        return w * h;
    }

    public double perimeter(){
        return 2 * (h + w);
    }

    public double getWidth(){
        return w;
    }

    public double getHeight(){
        return h;
    }
}
