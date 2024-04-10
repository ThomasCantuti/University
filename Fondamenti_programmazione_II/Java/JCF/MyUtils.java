package JCF;
import java.util.*;

public class MyUtils {

    // copiare tutti gli elementi di una collezione in un'altra
    public static <T> void copy(Collection<? extends T> src,
                                Collection<? super T> dest) {
        // src "almeno" di elementi di tipo T
        // dest "al più / oltrepasso" di elementi di tipo T
        for (T elem : src)
            dest.add(elem);
    }

    public static void printCollection(Collection<?> c) {
        for (Object e : c)
            System.out.println(e);
    }
}
