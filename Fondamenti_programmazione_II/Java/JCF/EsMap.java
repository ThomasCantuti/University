package JCF;
import java.util.*;

public class EsMap {
    public static void main(String[] args) {
        // conta le occorenze delle parole della linea di comando 
        // e metterle in tabella
        Map m = new HashMap();
        for (int i = 0; i < args.length; i ++) {
            Integer freq = (Integer) m.get(args[i]);
            m.put(args[i], (freq == null ? new Integer(1) : 
                            new Integer(freq.intValue()) + 1));
        }
        System.out.println(m.size() + " parole distinte:");
        System.out.println(m);
    }
}
