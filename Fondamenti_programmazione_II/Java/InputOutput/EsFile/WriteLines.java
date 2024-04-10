package InputOutput.EsFile;
import java.io.*;

public class WriteLines {
    
    public WriteLines(String filename) throws IOException{

        // PrintWriter è uno stream di manipolazione per scrivere righe di testo
        // FileWriter è uno stream di dati che permette di collegarsi ad un file di testo in scrittura
        PrintWriter output = new PrintWriter(new FileWriter(filename));

        // BufferedReader è uno stream di manipolazione a caratteri che consente di leggere stringhe
        // InputStreamReader converte uno stream di byte in uno stream di caratteri
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.println("Inserisci il testo da salvare: ");
        String linea = input.readLine();
        while(!linea.equals("")){
            output.println(linea);
            linea = input.readLine();
        }

        input.close();
        output.close();
    }
}
