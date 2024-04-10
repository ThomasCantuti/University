package JCF;

import java.util.*;

public class EsListIterator {
    public static void main(String[] args) {
        
        List l = new LinkedList();
        
        for (int i=0; i<args.length; i++) 
            l.add(args[i]);
        
        for( ListIterator i = l.listIterator(l.size()); i.hasPrevious(); )
            System.out.print(i.previous()+" ");
    }
}
