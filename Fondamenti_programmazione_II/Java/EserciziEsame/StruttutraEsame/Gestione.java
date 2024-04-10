package EserciziEsame.StruttutraEsame;

import java.util.*;
import java.io.*;

public class Gestione {

    static List<File1> nome1 = new LinkedList<File1>();
    static List<File2> nome2 = new LinkedList<File2>();
    static Map<Integer, String> codiceTarga = new HashMap<Integer, String>(); //<key, value>
    static Map<Integer, Double> codiceCosto = new HashMap<Integer, Double>();
    static Map<String, Integer> targaNoleggi = new HashMap<String, Integer>();
    public static void main (String[] args) {

        String file1 = "";
        String file2 = "";

        StringTokenizer tok;

        // Punto 1: memorizzazione dei ...
        try {

            BufferedReader inFile = new BufferedReader(new FileReader(file1));
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

                    File1 v = new Tipo1(codice, targa, modello, marca, costo, capienza, cilindrata, categoria);
                    nome1.add(v);

                    codiceTarga.put(codice, targa);
                    codiceCosto.put(codice, costo);
                    
                }

                if (tipo.equals("furgone")) {

                    boolean rimorchio = Boolean.parseBoolean(tok.nextToken());
                    int posti = Integer.parseInt(tok.nextToken());
                    boolean vanoCarico = Boolean.parseBoolean(tok.nextToken());

                    line = inFile.readLine();
                    double costo = Double.parseDouble(line);

                    File1 v = new Tipo2(codice, targa, modello, marca, costo, rimorchio, vanoCarico, posti);
                    nome1.add(v);

                    codiceTarga.put(codice, targa);
                    codiceCosto.put(codice, costo);
                }

                line = inFile.readLine();
                // un altro se c'è da andare a capo
                //line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + file1 + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        // Punto 2: memorizzazione dei ...
        try {

            BufferedReader inFile = new BufferedReader(new FileReader(file2));
            String line = inFile.readLine();

            while (line != null) {

                String nomeCognome = line;

                File2 c = new File2(nomeCognome);
                nome2.add(c);

                // se prendo più valori che vanno a capo senza sapere quanti
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

                // fine 1

                // se prendo più valori sulla stessa riga senza sapere quanti
                line = inFile.readLine();
                tok = new StringTokenizer(line);

                while (tok.hasMoreTokens()) {
                    int codCampo = Integer.parseInt(tok.nextToken());
                    int oraInizio = Integer.parseInt(tok.nextToken());
                    Prenotazione p = new Prenotazione(codCampo, oraInizio);
                    s.addPrenotazione(p);
                    codiceCampo.get(codCampo).addPrenotazione();
                }

                // fine 2

                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + file2 + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        System.out.println("tipo, targa, codice, modello, marca, costo giornaliero, " + 
        "bagagliaio, cilindrata, categoria, rimorchio, numero di posti, vano di carico");

        for (File1 v : nome1)
            System.out.println(v);

        System.out.println("Nome Cognome, costo noleggio maggiore, numero noleggi");

        for (File2 c : nome2)
            System.out.println(c);
        
        String targa = args[0];
        System.out.println("Numero noleggi di " + targa + ": " + targaNoleggi.get(targa));
    }
}
