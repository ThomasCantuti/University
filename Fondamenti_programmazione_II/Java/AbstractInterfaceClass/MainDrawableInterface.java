package AbstractInterfaceClass;

public class MainDrawableInterface {
    public static void main(String[] args){
        Drawable[] drawables = new Drawable[3];
        drawables[0] = new DrawableCircle(2.5);
        drawables[1] = new DrawableRectangle(1.5, 2.5);
        drawables[2] = new DrawableText("ciao");

        for( int i = 0; i < drawables.length; i ++){
            drawables[i].setColor(i);
            drawables[i].setPosition(i * 10, i * 20);
            drawables[i].draw();
        }
    }
}
