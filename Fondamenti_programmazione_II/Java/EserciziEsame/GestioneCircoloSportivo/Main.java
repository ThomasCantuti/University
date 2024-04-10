package EserciziEsame.GestioneCircoloSportivo;

import java.util.*;
import java.io.*;

public class Main {
    public static void main (String[] args) {

        String fileCampi = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/GestioneCircoloSportivo/campi.txt";
        String fileSoci = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/GestioneCircoloSportivo/soci.txt";

        StringTokenizer tokenizer;
        List<Campo> campi = new LinkedList<Campo>();
        List<Socio> soci = new LinkedList<Socio>();
        Map<Integer, Campo> codiceCampo = new HashMap<Integer, Campo>(); 


        // lettura campi.txt
        try {

            BufferedReader inFile = new BufferedReader(new FileReader(fileCampi));
            String line = inFile.readLine();

            while (line != null) {

                tokenizer = new StringTokenizer(line);
                int cod = Integer.parseInt(tokenizer.nextToken());
                String sport = tokenizer.nextToken();
                
                line = inFile.readLine();
                String nomeCampo = line;
                
                line = inFile.readLine();
                tokenizer = new StringTokenizer(line);
                float larghezza = Float.parseFloat(tokenizer.nextToken());
                float lunghezza = Float.parseFloat(tokenizer.nextToken());

                if (sport.equals("tennis")) {
                    float temp = Float.parseFloat(tokenizer.nextToken());
                    line = inFile.readLine();
                    tokenizer = new StringTokenizer(line);
                    String terreno = tokenizer.nextToken();
                    line = inFile.readLine();
                    tokenizer = new StringTokenizer(line);
                    float costo = Float.parseFloat(tokenizer.nextToken());
                    Campo c = new CampoTennis(cod, nomeCampo, larghezza, lunghezza, costo, temp, terreno);
                    campi.add(c);
                    codiceCampo.put(cod, c);
                }

                if (sport.equals("squash")) {
                    float altezza = Float.parseFloat(tokenizer.nextToken());
                    int piano = Integer.parseInt(tokenizer.nextToken());
                    float costo = Float.parseFloat(tokenizer.nextToken());
                    Campo c = new CampoSquash(cod, nomeCampo, larghezza, lunghezza, altezza, piano, costo);
                    campi.add(c);
                    codiceCampo.put(cod, c);
                }

                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileCampi + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        // lettura soci.txt
        try {
            BufferedReader inFile = new BufferedReader(new FileReader(fileSoci));
            String line = inFile.readLine();

            while (line != null) {

                tokenizer = new StringTokenizer(line);
                int codice = Integer.parseInt(tokenizer.nextToken());

                line = inFile.readLine();
                String nomeCognome = line;

                line = inFile.readLine();
                tokenizer = new StringTokenizer(line);
                int eta = Integer.parseInt(tokenizer.nextToken());
                int categoria = Integer.parseInt(tokenizer.nextToken());
                
                Socio s = new Socio(codice, nomeCognome, eta, categoria);
                soci.add(s);

                line = inFile.readLine();
                tokenizer = new StringTokenizer(line);

                while (tokenizer.hasMoreTokens()) {
                    int codCampo = Integer.parseInt(tokenizer.nextToken());
                    int oraInizio = Integer.parseInt(tokenizer.nextToken());
                    Prenotazione p = new Prenotazione(codCampo, oraInizio);
                    s.addPrenotazione(p);
                    codiceCampo.get(codCampo).addPrenotazione();
                }

                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileSoci + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        // stampa
        System.out.println("sport\tnome del campo\tcodice\tlarghezza\t" + 
        "lunghezza\ttemperatura\tterreno\taltezza\tpiano\tcosto\t");

        for (Campo c : campi)
            System.out.println(c);

        System.out.println("\ncodice\tnome e cognome\tetà\tcategoria\tprenotazioni\t");

        for (Socio s : soci)
            System.out.println(s);

        // leggere codice campo da terminale e stampare incasso tot da quel campo
        System.out.println("\n" + codiceCampo.get(Integer.parseInt(args[0])).incasso());
    }
}
