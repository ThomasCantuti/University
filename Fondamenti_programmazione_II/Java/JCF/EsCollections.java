package JCF;
import java.util.*;

public class EsCollections {
    public static void main(String[] args) {
        // costruire array di elementi comparabili
        // ottenerne una lista
        // ordinare tale lista

        Persona elencoPersone[] = {
            new Persona("Eugenio", "Bennato"),
            new Persona("Roberto", "Benigni"),
            new Persona("Edoardo", "Bennato"),
            new Persona("Bruno", "Vespa")
        };

        List l = Arrays.asList(elencoPersone);
        Collections.sort(l);
        System.out.println(l);
    }
}
