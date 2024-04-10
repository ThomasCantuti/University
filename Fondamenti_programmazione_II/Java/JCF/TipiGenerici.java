package JCF;
import java.util.*;

public class TipiGenerici {
    public static void main(String[] args) {
        List<Number> list = new LinkedList<Number>();
        for(int i = 0; i < 12; i ++)
            list.add(i*i);
        list.add(3.14);
        System.out.println(list);
    }
}
