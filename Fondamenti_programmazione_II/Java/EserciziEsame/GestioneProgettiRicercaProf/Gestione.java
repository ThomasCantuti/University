package EserciziEsame.GestioneProgettiRicercaProf;

import java.io.*;
import java.util.*;

public class Gestione {

    static List<Progetto> progetti=new LinkedList<Progetto>();
    static List<Ricercatore> ricercatori=new LinkedList<Ricercatore>();
    static Map<Integer,Progetto> codProg=new HashMap<Integer,Progetto>();   

    public static void main(String[] args){

        // Punto 1: memorizzazione dei progetti
        try{

            BufferedReader br=new BufferedReader(new FileReader("progetti.txt"));
            String line=br.readLine();

            while(line!=null){

                StringTokenizer tok=new StringTokenizer(line);
                int codice=Integer.parseInt(tok.nextToken());
                String tipo=tok.nextToken();

                String titolo=br.readLine();

                String coordinatore=br.readLine();

                String organizzazione=br.readLine();

                line=br.readLine();

                if(tipo.equals("ricerca")){

                    tok=new StringTokenizer(line);
                    String argomento=tok.nextToken();
                    int partner=Integer.parseInt(tok.nextToken());

                    double importo=Double.parseDouble(br.readLine());

                    Ricerca r=new Ricerca(codice,titolo,coordinatore,organizzazione,argomento,partner,importo);
                    progetti.add(r);
                    codProg.put(codice,r);
                }
                else{

                    tok=new StringTokenizer(line);
                    int aziende=Integer.parseInt(tok.nextToken());
                    double importo=Double.parseDouble(tok.nextToken());

                    Innovazione i=new Innovazione(codice,titolo,coordinatore,organizzazione,aziende,importo);
                    progetti.add(i);
                    codProg.put(codice,i);
                }

                line=br.readLine();
            }
            br.close();
        }
        catch(IOException e){
            System.err.println(e);
        }
        catch(Exception e){
            System.err.println(e);
        }

        // Punto 2: memorizzazione dei ricercatori
        try{

            BufferedReader br=new BufferedReader(new FileReader("riceratori.txt"));
            String line=br.readLine();

            while(line!=null){

                String nome=line;

                String cognome=br.readLine();

                Ricercatore r=new Ricercatore(nome,cognome);

                ricercatori.add(r);
                line=br.readLine();

                while(line!=null && !line.equals("")){

                    StringTokenizer tok=new StringTokenizer(line);
                    int codice=Integer.parseInt(tok.nextToken());
                    double impegno=Double.parseDouble(tok.nextToken());

                    r.addProgetto(codProg.get(codice), impegno);
                    line=br.readLine();
                }
                line=br.readLine();
            }
            br.close();
        }
        catch(IOException e){
            System.err.println(e);
        }
        catch(Exception e){
            System.err.println(e);
        }

        // Punto 3: visualizzazione di tutti i progetti
        System.out.println("tipo, titolo, codice, coordinatore, organizzazione, argomento, partner, aziende, importo totale in migliaia di euro");

        for(Progetto p:progetti)
            System.out.println(p);

        System.out.println();

        // Punto 4: visualizzazione di tutti i ricercatori
        for(Ricercatore r:ricercatori)
            System.out.println(r);
            
        System.out.println();

        // Punto 5: visualizzazione del progetto con l'impegno orario più alto dato il cognome
        String cognome=args[0];
        for(Ricercatore r:ricercatori){
            if(r.getCognome().equals(cognome)){
                Impegno i=r.getMax();
                System.out.println(r.getNome()+" "+r.getCognome()+" "+i.getOre()+" "+i.getProgetto().getTitolo());
            }
        }
    }
}
