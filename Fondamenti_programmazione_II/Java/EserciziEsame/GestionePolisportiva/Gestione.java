package EserciziEsame.GestionePolisportiva;

import java.util.*;
import java.io.*;

public class Gestione {

    static List<Squadra> squadre = new LinkedList<Squadra>();
    static List<Giocatore> giocatori = new LinkedList<Giocatore>();
    static Map<Integer, Squadra> codiceSquadra = new HashMap<Integer, Squadra>();
    static double vittorieHockey = 0, vittoriePallamano = 0;
    static double totPartiteH = 0, totPartiteP = 0;

    public static void main (String[] args) {

        String fileSquadre = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/GestionePolisportiva/squadre.txt";
        String fileGiocatori = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/GestionePolisportiva/giocatori.txt";

        StringTokenizer tok;

        // Punto 1: memorizzazione delle squadre
        try {

            BufferedReader inFile = new BufferedReader(new FileReader(fileSquadre));
            String line = inFile.readLine();

            while (line != null) {

                tok = new StringTokenizer(line);
                int codice = Integer.parseInt(tok.nextToken());
                String sport = tok.nextToken();

                line = inFile.readLine();
                String squadra = line;

                line = inFile.readLine();
                tok = new StringTokenizer(line);

                if (sport.equals("hockey")) {

                    int vinte = Integer.parseInt(tok.nextToken());
                    int perse = Integer.parseInt(tok.nextToken());
                    double mediaGoal = Double.parseDouble(tok.nextToken());
                    double falli = Double.parseDouble(tok.nextToken());

                    Squadra s = new Hockey(codice, squadra, vinte, perse, mediaGoal, mediaGoal, falli);
                    squadre.add(s);

                    codiceSquadra.put(codice, s);
                    
                    vittorieHockey += s.getVittorie();
                    totPartiteH ++;
                }

                if (sport.equals("pallamano")) {

                    int vinte = Integer.parseInt(tok.nextToken());
                    int perse = Integer.parseInt(tok.nextToken());
                    double mediaGoalFatti = Double.parseDouble(tok.nextToken());

                    Squadra s = new Pallamano(codice, squadra, vinte, perse, mediaGoalFatti, mediaGoalFatti);
                    squadre.add(s);

                    codiceSquadra.put(codice, s);

                    vittoriePallamano += s.getVittorie();
                    totPartiteP ++;

                }

                line = inFile.readLine();
                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileSquadre + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        // Punto 2: memorizzazione dei giocatori
        try {

            BufferedReader inFile = new BufferedReader(new FileReader(fileGiocatori));
            String line = inFile.readLine();

            while (line != null) {

                int codice = Integer.parseInt(line);

                String cognome = inFile.readLine();

                String nome = inFile.readLine();

                line = inFile.readLine();
                tok = new StringTokenizer(line);
                int eta = Integer.parseInt(tok.nextToken());
                int maglia = Integer.parseInt(tok.nextToken());
                String ruolo = tok.nextToken();
                boolean titolare = Boolean.parseBoolean(tok.nextToken());

                Giocatore g = new Giocatore(cognome, nome, eta, maglia, ruolo, titolare);
                giocatori.add(g);
                GiocatoreSquadra gs = new GiocatoreSquadra(codiceSquadra.get(codice), codice);
                g.addGiocatoreSquadra(gs);

                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + fileGiocatori + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        System.out.println("nome squadra, codice, vittorie, sconfitte, n. medio di goal" + 
        ",n. medio di falli, n. medio di reti, sport");

        for (Squadra v : squadre)
            System.out.println(v);

        System.out.println("nome, cognome, numero di maglia, ruolo, titolare, nome squadra");

        for (Giocatore g : giocatori)
            System.out.println(g);
        
        System.out.println("media partite vinte delle squadre di hockey: " + 
        vittorieHockey / totPartiteH);
        System.out.println("media partite vinte delle squadre di pallamano: " + 
        vittoriePallamano / totPartiteP);
    }
}
