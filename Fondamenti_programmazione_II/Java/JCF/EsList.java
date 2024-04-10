package JCF;

import java.util.*;

public class EsList {

    static void swap(List a, int i, int j) {
        Object tmp = a.get(i);
        a.set(i, a.get(j));
        a.set(j, tmp);
    }

    public static void main(String[] args) {
        // scambiare due elementi in una lista
        // aggiungo parola a lista con add
        // stampo prima dello scambio
        // effettuo scambio
        // stampo dopo lo scambio
        
        List list = new ArrayList() ;
        for (int i = 0; i < args.length; i ++) 
            list.add(args[i]);
        System.out.println(list);
        swap(list, 2, 3);
        System.out.println(list);
    }
}
