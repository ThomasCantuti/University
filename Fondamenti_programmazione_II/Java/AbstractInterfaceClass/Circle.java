package AbstractInterfaceClass;

public class Circle extends Shape{

    protected double r;

    public Circle(double r){
        this.r = r;
    }
    
    public double area(){
        return Math.PI * r * r;
    }

    public double perimeter(){
        return 2 * Math.PI * r;
    }

    public double getRadius(){
        return r;
    }
}
