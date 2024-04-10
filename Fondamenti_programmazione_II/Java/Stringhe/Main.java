package Stringhe;

public class Main{
    public static void main(String[] args){
        // le stringhe sono oggetti della classe String
        String s = "ciao a tutti";
        String nome = "Thomas";

        // concatenazione
        String frase = s + nome;
        frase = frase + 20;

        // Stringhe sono immutabili -> nessuna cambia valore
        // si creano più istanze e quelle non usate vengono cancellate
        // dalla garbage collection

        // metodi:
        nome.length(); // restituisce lunghezza stringa
        nome.charAt(0); // restituisce carattere alla posizione prefissata
        nome.indexOf('c'); // restituisce l'indice appena trova 'c', -1 se non c'è
        nome.equals(frase); // se nome = frase
        s = nome.substring(0, 3); // restituisce sottostringa che va da 0 a 2 (3-1)
        s = nome.replace('T', 't'); // restituisce una stringa con tutte le 'T' sostituite con 't'

        // convertire numero in stringa:
        int n = 10;
        String s1 = "" + n;
        s1.length();
        
        // cambiare il valore di una stringa -> classe StringBuffer
        StringBuffer s2;
        s2 = new StringBuffer(s);
        s2.setCharAt(2, 'c'); // modificare il valore di un carattere della stringa
        s = s2.toString();

    }
}