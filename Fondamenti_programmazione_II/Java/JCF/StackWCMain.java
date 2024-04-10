package JCF;

public class StackWCMain {
    public static void main(String[] args) {
        StackWC<Integer> src = new StackWC<Integer>();
        StackWC<Number> dest = new StackWC<Number>();
        src.push(10).push(29).push(34);
        dest.moveFrom(src);
        System.out.println(dest);
        StackWC.emptyAndPrintStack(dest); // static way
    }
}
