package EserciziEsame.GestioneProgettiRicerca;

import java.util.*;
import java.io.*;

public class Main {
    public static void main (String[] args) {

        String fileProgetti = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/GestioneProgettiRicerca/progetti.txt";
        String fileRicercatori = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/GestioneProgettiRicerca/ricercatori.txt";

        StringTokenizer tokenizer;
        List<Progetto> progetti = new LinkedList<Progetto>();
        List<Ricercatore> ricercatori = new LinkedList<Ricercatore>();
        List<Persona> persone = new LinkedList<Persona>();
        Map<Integer, Double> elencoProgetti = new HashMap<Integer, Double>();
        Map<Integer, String> codiceTitolo = new HashMap<Integer, String>();

        // lettura progetti.txt
        try {

            BufferedReader inFile = new BufferedReader(new FileReader(fileProgetti));
            String line = inFile.readLine();

            while (line != null) {

                tokenizer = new StringTokenizer(line);
                int cod = Integer.parseInt(tokenizer.nextToken());
                String tipo = tokenizer.nextToken();
                
                line = inFile.readLine();
                String titoloProgetto = line;
                
                line = inFile.readLine();
                String nomeCognome = line;

                line = inFile.readLine();
                String orgCoordinatore = line;

                line = inFile.readLine();
                tokenizer = new StringTokenizer(line);

                if (tipo.equals("ricerca")) {
                    String codiceArg = tokenizer.nextToken();
                    int partner = Integer.parseInt(tokenizer.nextToken());

                    line = inFile.readLine();
                    double importo = Double.parseDouble(line);
                    Progetto p = new Ricerca(cod, titoloProgetto, nomeCognome, orgCoordinatore, codiceArg, partner, importo);
                    progetti.add(p);
                    // titolo e codice
                    codiceTitolo.put(cod, titoloProgetto);
                }

                if (tipo.equals("innovazione")) {
                    int aziende = Integer.parseInt(tokenizer.nextToken());
                    double importo = Double.parseDouble(tokenizer.nextToken());
                    Progetto p = new Innovazione(cod, titoloProgetto, nomeCognome, orgCoordinatore, aziende, importo);
                    progetti.add(p);
                    // titolo e codice
                    codiceTitolo.put(cod, titoloProgetto);
                }

                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileProgetti + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        // lettura ricercatori.txt
        try {
            BufferedReader inFile = new BufferedReader(new FileReader(fileRicercatori));
            String line = inFile.readLine();

            while (line != null) {

                String nome = line;

                line = inFile.readLine();
                String cognome = line;
                
                Ricercatore r = new Ricercatore(nome, cognome);
                ricercatori.add(r);

                line = inFile.readLine();

                while (line != null && !line.equals("")) {
                    
                    tokenizer = new StringTokenizer(line);
                    int codice = Integer.parseInt(tokenizer.nextToken());
                    double impegnoOrario = Double.parseDouble(tokenizer.nextToken());

                    r.addElencoProgetti(codice, impegnoOrario);
                    elencoProgetti.put(codice, impegnoOrario);
                    double impegnoMax = r.impegnoMax();
                    Persona persona = new Persona(nome, cognome, impegnoMax, codiceTitolo.get(codice));
                    persone.add(persona);
                    
                    line = inFile.readLine();
                }

                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileRicercatori + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        // stampa
        System.out.println("tipo\ttitolo\tcodice\tcoordinatore\t" + 
        "organizzatore\targomento\tpartner\taziende\timporto totale");

        for (Progetto p : progetti)
            System.out.println(p);

        System.out.println("\nnome e cognome\timpegno orario tatoale\tnumero di progetti\telenco progetti\t");

        for (Ricercatore r : ricercatori)
            System.out.println(r);
        
        System.out.println("\n");

        String cognome = args[0];
        for (Persona p : persone) 
            if (p.cognome.equals(cognome))
                System.out.println(p);
    }
}

