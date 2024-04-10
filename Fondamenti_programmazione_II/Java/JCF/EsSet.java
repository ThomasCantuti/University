package JCF;
import java.util.*;

public class EsSet {
    public static void main(String[] args){
        // analizzare insieme di parole da terminale
        // stampare parole duplicate
        // stampare numero di parole distinte
        // stampare lista di parole distinte
        Set s = new HashSet<>();
        for (int i = 0; i < args.length; i ++)
            if (!s.add(args[i]))
                System.out.println("Parola duplicata: " + args[i]);
        System.out.println(s.size() + " parole distinte: " + s);
    }
}
