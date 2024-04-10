package AbstractInterfaceClass;

public class MainShapeAbstract {
    public static void main(String[] args){
        Shape[] shapes = new Shape[3];
        shapes[0] = new Circle(2.5);
        shapes[1] = new Rectangle(2.5, 4);
        shapes[2] = new Rectangle(2.5, 4.5);
        //shapes[n] = new Shape(); -> non si puù fare
        double totalArea = 0;

        for(int i = 0; i < shapes.length; i ++){
            totalArea += shapes[i].area();
        }

        System.out.println("Total Area: " + totalArea);
    }
}
