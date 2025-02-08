import java.io.*;
import java.net.*;

public class ClientTDConnreuseVini {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Errore! Uso: java ClientTDConnreuse hostname porta");
            System.exit(1);
        }
        
        try {
            Socket theSocket = new Socket(args[0], Integer.parseInt(args[1]));
            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader networkIn = new BufferedReader(
                    new InputStreamReader(theSocket.getInputStream(), "UTF-8"));
            BufferedWriter networkOut = new BufferedWriter(
                    new OutputStreamWriter(theSocket.getOutputStream(), "UTF-8"));
            
            while (true) {
                System.out.println("Inserisci nome_vino ('fine' per terminare):");
                String nome_vino = userIn.readLine();
                if (nome_vino.equals("fine"))
                    break;
                
                System.out.println("Inserisci nome progetto da ricercare ('fine' per terminare):");
                String anno = userIn.readLine();
                if (anno.equals("fine"))
                    break;
                
                networkOut.write(nome_vino);
                networkOut.newLine();
                networkOut.write(anno);
                networkOut.newLine();
                networkOut.flush();
                
                String theLine;
                while (true) {
                    theLine = networkIn.readLine();
                    if (theLine == null) {
                        System.err.println("Errore! Il server ha chiuso la connessione");
                        System.exit(2);
                    }
                    System.out.println(theLine);
                    if (theLine.equals("--- END REQUEST ---"))
                        break;
                }
            }
            
            theSocket.close();
        } catch (IOException e) {
            System.err.println("Errore: " + e.getMessage());
            e.printStackTrace();
            System.exit(3);
        }
    }
}