package InputOutput;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class MainPratica {
    public static void main (String[] args) {

        // INPUT

        // per l'input da tastiera usare InputStreamReader e BufferedReader
        
        // leggere singoli caratteri da tastiera:
        InputStreamReader isr = new InputStreamReader(System.in);

        // leggere stringhe da tastiera:
        BufferedReader kdb = new BufferedReader(isr);

        // gestione input tastiera con InputStreamReader e BufferedReader:
        BufferedReader kbd = new BufferedReader(new InputStreamReader(System.in));

        // gestione input tastiera con Scanner:
        Scanner tastiera = new Scanner(System.in);
        tastiera.nextInt(); // -> legge prossimo intero inserito dall'utente
        tastiera.nextLine(); // -> legge una riga
        tastiera.next(); // -> legge stringa fino al prossimo delimitatore
        // cambiare delimitatore (esempio con ##, di default " "): 
        tastiera.useDelimiter("##");
        tastiera.close();

        // OUTPUT

        PrintWriter video = new PrintWriter(System.out);
        video.println(12);
        video.print("ciao");
    }    
}
