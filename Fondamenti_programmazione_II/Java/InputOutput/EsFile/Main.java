package InputOutput.EsFile;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        
        String file = "/home/thomas/Università/Linguaggi di programmazione/Java/InputOutput/EsFile/testo.txt";
        
        try {
            FileWriter writer = new FileWriter(file);

            for (int i = 0; i < args.length; i ++)
                writer.append(args[i]);
            
            writer.close();

            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            
            while (reader.readLine() == null) {
                System.out.println(reader.readLine());
            }
            
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        

        
    }
}
