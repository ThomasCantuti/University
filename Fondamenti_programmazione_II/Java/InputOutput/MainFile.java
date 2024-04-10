package InputOutput;

import java.io.*;

public class MainFile {
    public static void main(String[] args) {
        
        File file = new File("/home/thomas/Università/Linguaggi di programmazione/Java/InputOutput/prova.txt");
        
        
        if (file.exists()) {
            System.out.println("Il file esiste");
            System.out.println(file.getPath());
            System.out.println(file.getAbsolutePath());
            System.out.println(file.isFile());
        } else {
            System.out.println("Il file non esiste");
        }

        try {
            FileWriter writer = new FileWriter(file);
            writer.write("ciao");
            writer.append("\nseconda riga");
            writer.close();
            
            FileReader reader = new FileReader(file);
            int data = reader.read();
            System.out.println(data);
            reader.close();

            BufferedReader tastiera = new BufferedReader(new InputStreamReader(System.in));
            tastiera.readLine();
            System.out.println(tastiera);
            tastiera.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
