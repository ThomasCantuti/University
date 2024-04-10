package EserciziEsame.Autonoleggio;

import java.util.*;
import java.io.*;

public class Main {
    public static void main (String[] args) {

        String fileVeicoli = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/Autonoleggio/veicoli.txt";
        String fileClienti = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/Autonoleggio/clienti.txt";

        StringTokenizer tok;

        List<Veicolo> veicoli = new LinkedList<Veicolo>();
        List<Cliente> clienti = new LinkedList<Cliente>();
        Map<Integer, String> codiceTarga = new HashMap<Integer, String>();
        Map<Integer, Double> codiceCosto = new HashMap<Integer, Double>();
        Map<String, Integer> targaNoleggi = new HashMap<String, Integer>();

        try {

            BufferedReader inFile = new BufferedReader(new FileReader(fileVeicoli));
            String line = inFile.readLine();

            while (line != null) {

                tok = new StringTokenizer(line);
                int codice = Integer.parseInt(tok.nextToken());
                String tipo = tok.nextToken();
                String targa = tok.nextToken();

                line = inFile.readLine();
                String modello = line;

                line = inFile.readLine();
                String marca = line;

                line = inFile.readLine();
                tok = new StringTokenizer(line);

                if (tipo.equals("auto")) {

                    double capienza = Double.parseDouble(tok.nextToken());
                    int cilindrata = Integer.parseInt(tok.nextToken());

                    line = inFile.readLine();
                    String categoria = line;

                    line = inFile.readLine();
                    double costo = Double.parseDouble(line);

                    Veicolo v = new Auto(codice, targa, modello, marca, costo, capienza, cilindrata, categoria);
                    veicoli.add(v);

                    codiceTarga.put(codice, targa);
                    codiceCosto.put(codice, costo);
                    
                }

                if (tipo.equals("furgone")) {

                    boolean rimorchio = Boolean.parseBoolean(tok.nextToken());
                    int posti = Integer.parseInt(tok.nextToken());
                    boolean vanoCarico = Boolean.parseBoolean(tok.nextToken());

                    line = inFile.readLine();
                    double costo = Double.parseDouble(line);

                    Veicolo v = new Furgone(codice, targa, modello, marca, costo, rimorchio, vanoCarico, posti);
                    veicoli.add(v);

                    codiceTarga.put(codice, targa);
                    codiceCosto.put(codice, costo);
                }

                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileVeicoli + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        try {

            BufferedReader inFile = new BufferedReader(new FileReader(fileClienti));
            String line = inFile.readLine();

            while (line != null) {

                String nomeCognome = line;

                Cliente c = new Cliente(nomeCognome);
                clienti.add(c);

                line = inFile.readLine();
                
                while (line != null && !line.equals("")) {

                    tok = new StringTokenizer(line);
                    int codice = Integer.parseInt(tok.nextToken());
                    int giorni = Integer.parseInt(tok.nextToken());
                    
                    String targa = codiceTarga.get(codice);
                    double costo = codiceCosto.get(codice);
                    c.addNoleggio(targa, giorni, costo);
                    Integer noleggi = targaNoleggi.get(targa);
                    if (noleggi == null)
                        targaNoleggi.put(targa, 1);
                    else
                        targaNoleggi.put(targa, noleggi + 1);
                    
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

        System.out.println("tipo, targa, codice, modello, marca, costo giornaliero, " + 
        "bagagliaio, cilindrata, categoria, rimorchio, numero di posti, vano di carico");

        for (Veicolo v : veicoli)
            System.out.println(v);

        System.out.println("Nome Cognome, costo noleggio maggiore, numero noleggi");

        for (Cliente c : clienti)
            System.out.println(c);
        
        String targa = args[0];
        System.out.println("Numero noleggi di " + targa + ": " + targaNoleggi.get(targa));
    }
}
