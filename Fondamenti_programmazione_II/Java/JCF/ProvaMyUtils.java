package JCF;
import java.util.*;

public class ProvaMyUtils {
    public static void main(String[] args) {
        List<Integer> l1 = new ArrayList<Integer>();
        List<Number> l2 = new ArrayList<Number>();
        l1.add(10);
        l1.add(20);
        l1.add(30);
        MyUtils.copy(l1, l2);
        System.out.println(l2);
    }
}
