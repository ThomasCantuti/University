package EserciziEsame.GestioneNoleggioVeicoliRicreativi;

import java.util.*;
import java.io.*;

public class Gestione {

    static List<Veicolo> veicoli = new LinkedList<Veicolo>();
    static List<Cliente> clienti = new LinkedList<Cliente>();
    static Map<Integer, Veicolo> codiceVeicolo = new HashMap<Integer, Veicolo>(); //<key, value>

    public static void main (String[] args) {

        String fileVeicoli = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/GestioneNoleggioVeicoliRicreativi/veicoli.txt";
        String fileClienti = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/GestioneNoleggioVeicoliRicreativi/clienti.txt";

        StringTokenizer tok;

        // Punto 1: memorizzazione dei veicoli
        try {

            BufferedReader inFile = new BufferedReader(new FileReader(fileVeicoli));
            String line = inFile.readLine();

            while (line != null) {

                tok = new StringTokenizer(line);
                int codice = Integer.parseInt(tok.nextToken());
                String tipo = tok.nextToken();

                line = inFile.readLine();
                String marca = line;

                line = inFile.readLine();
                tok = new StringTokenizer(line);

                if (tipo.equals("roulotte")) {

                    int peso = Integer.parseInt(tok.nextToken());
                    float lunghezza = Float.parseFloat(tok.nextToken());
                    float larghezza = Float.parseFloat(tok.nextToken());
                    int postiLetto = Integer.parseInt(tok.nextToken());

                    line = inFile.readLine();
                    tok = new StringTokenizer(line);
                    String veranda = tok.nextToken();
                    float costo = Float.parseFloat(tok.nextToken());

                    Veicolo v = new Roulotte(codice, marca, larghezza, lunghezza, costo, postiLetto, peso, veranda);
                    veicoli.add(v);

                    codiceVeicolo.put(codice, v);
                    
                }

                if (tipo.equals("caravan")) {

                    float larghezza = Float.parseFloat(tok.nextToken());
                    float lunghezza = Float.parseFloat(tok.nextToken());
                    int potenza = Integer.parseInt(tok.nextToken());
                    int postiLetto = Integer.parseInt(tok.nextToken());
                    float costo = Float.parseFloat(tok.nextToken());

                    Veicolo v = new Caravan(codice, marca, larghezza, lunghezza, costo, postiLetto, potenza);
                    veicoli.add(v);

                    codiceVeicolo.put(codice, v);
                }

                line = inFile.readLine();
                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileVeicoli + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        // Punto 2: memorizzazione dei clienti
        try {

            BufferedReader inFile = new BufferedReader(new FileReader(fileClienti));
            String line = inFile.readLine();

            while (line != null) {

                int codiceC = Integer.parseInt(line);
                String nome = inFile.readLine();
                String cognome = inFile.readLine();
                String indirizzo = inFile.readLine();

                Cliente c = new Cliente(codiceC, nome, cognome, indirizzo);
                clienti.add(c);

                line = inFile.readLine();
                
                while (line != null && !line.equals("")) {

                    tok = new StringTokenizer(line);
                    int codiceV = Integer.parseInt(tok.nextToken());
                    int giorni = Integer.parseInt(tok.nextToken());
                    
                    Prenotazione n = new Prenotazione(codiceV, giorni);
                    c.addPrenotazione(n);
                    Veicolo v = codiceVeicolo.get(codiceV);
                    v.addPrenotazione(n);
                    
                    line = inFile.readLine();

                }

                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileClienti + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        System.out.println("tipo, codice, marca, larghezza, lunghezza " + 
        "posti letto, peso, veranda, potenza, costo");

        for (Veicolo v : veicoli)
            System.out.println(v);
        
        System.out.println();

        System.out.println("codice, cognome, nome, indirizzo, prenotazioni");

        for (Cliente c : clienti)
            System.out.println(c);
        
        System.out.println();

        System.out.println("codice, incasso");
        for (Veicolo v : veicoli)
            System.out.println(v.getCod() +"\t"+ v.incasso());
        
    }
}
