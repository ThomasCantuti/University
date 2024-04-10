package StaticClass;
public class CounterStatic {
    private static int val;
    public static void reset(){
        val = 0;
    }
    public static void inc(){
        val++;
    }
    public static int getValue(){
        return val;
    }
}
