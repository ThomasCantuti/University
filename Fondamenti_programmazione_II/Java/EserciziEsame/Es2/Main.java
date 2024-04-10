package EserciziEsame.Es2;

import java.io.*;
import java.util.*;

public class Main {
    public static void main (String[] args) {

        String sender, recever;
        int start, stop;

        String file = "/home/thomas/Università/Linguaggi di programmazione/Java/EserciziEsame/Es2/data.txt";
        StringTokenizer tokenizer;

        List<Call> chiamate = new ArrayList<Call>();

        try {
            BufferedReader inFile = new BufferedReader(new FileReader(file));
            String line = inFile.readLine();

            while (line != null) {
                tokenizer = new StringTokenizer(line);

                try {

                    sender = tokenizer.nextToken(";");
                    recever = tokenizer.nextToken(";");
                    start = Integer.parseInt(tokenizer.nextToken(";"));
                    stop = Integer.parseInt(tokenizer.nextToken(";"));

                    Call call = new Call(sender, recever, start, stop);

                    if (call.getDuration() > 550000)
                        chiamate.add(call);

                } catch (NumberFormatException e) {
                    System.out.println("Error in input. Line: " + line);
                }

                line = inFile.readLine();
            }

            inFile.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("File " + file + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }

        System.out.println("Totale: " + chiamate.size() + " chiamate lunghe");
    }
}
