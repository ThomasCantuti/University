package JCF;
import java.util.*;

public class EsMapTipoGenerico {
    public static void main(String[] args) {
        // conta le occorenze delle parole della linea di comando 
        // e metterle in tabella
        Map<String, Integer> m = new HashMap<String, Integer>();
        for (int i = 0; i < args.length; i ++) {
            Integer freq = m.get(args[i]);
            m.put(args[i], (freq == null ? 1 : freq + 1));
        }
        System.out.println(m.size() + " parole distinte:");
        System.out.println(m);
    }
}
