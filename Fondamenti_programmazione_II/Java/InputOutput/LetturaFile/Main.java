package InputOutput.LetturaFile;

import java.io.*;
//import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main (String[] args) throws IOException {

        // se uso Scanner non uno StringTokenizer

        String line, name;
        int units, count = 0;
        float price;
        String file = "/home/thomas/Università/Linguaggi di programmazione/Java/InputOutput/LetturaFile/inventory.dat";

        InventoryItem[] items = new InventoryItem[100];
        StringTokenizer tokenizer;

        try {

            FileReader fr = new FileReader(file);
            BufferedReader inFile = new BufferedReader(fr);
            // Scanner file = new Scanner(new File("inventory.dat"));

            line = inFile.readLine(); // per leggere le righe del file

            while (line != null) {

                tokenizer = new StringTokenizer(line);
                name = tokenizer.nextToken();

                try {

                    units = Integer.parseInt(tokenizer.nextToken());
                    price = Float.parseFloat(tokenizer.nextToken());
                    items[count++] = new InventoryItem(name, units, price);

                } catch (NumberFormatException e) {
                    System.out.println("Error in input. Line: " + line);
                }

                line = inFile.readLine();
            }

            inFile.close();

            for (int i = 0; i < count; i++)
                System.out.println(items[i]);

        } catch (FileNotFoundException e) {
            System.out.println("File " + file + " not found.");

        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
