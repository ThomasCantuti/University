import java.io.*;
import java.net.*;

public class LeggiDatiSensori {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Uso: java LeggiDatiSensori hostname porta");
            System.exit(1);
        }

        try {
            Socket theSocket = new Socket(args[0], Integer.parseInt(args[1]));
            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader networkIn = new BufferedReader(new InputStreamReader(theSocket.getInputStream(), "UTF-8"));
            BufferedWriter networkOut = new BufferedWriter(new OutputStreamWriter(theSocket.getOutputStream(), "UTF-8"));

            while (true) {
                System.out.println("Inserire tipo di sensore ('fine' per terminare): ");
                String tipo_sensore = userIn.readLine();
                if (tipo_sensore.equals("fine"))
                    break;

                System.out.println("Inserire nome stanza ('fine' per terminare): ");
                String nome_stanza = userIn.readLine();
                if (nome_stanza.equals("fine"))
                    break;
                
                System.out.println("Inserire numero di letture ('fine' per terminare): ");
                String numero_letture = userIn.readLine();
                if (numero_letture.equals("fine"))
                    break;

                networkOut.write(tipo_sensore);
                networkOut.newLine();
                networkOut.write(nome_stanza);
                networkOut.newLine();
                networkOut.write(numero_letture);
                networkOut.newLine();
                networkOut.flush();

                String line;
                while (true) {
                    line = networkIn.readLine();
                    if (line == null) {
                        System.err.println("Errore: il Server ha chiuso la connessione");
                        System.exit(2);
                    }

                    System.out.println(line);
                    if (line.equals("--- END REQUEST ---"))
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
