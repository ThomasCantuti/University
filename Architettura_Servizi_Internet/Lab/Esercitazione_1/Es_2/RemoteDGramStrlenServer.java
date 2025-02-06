import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class RemoteDGramStrlenServer {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java RemoteSquareServer porta");
            System.exit(1);
        }

        try {
            ServerSocket ss = new ServerSocket(Integer.parseInt(args[0]));

            while (true) {
                Socket s = ss.accept();
                System.out.println("Connesso al client");

                BufferedReader netIn = new BufferedReader(new InputStreamReader(s.getInputStream(), "UTF-8"));
                BufferedWriter netOut = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));

                String line = null;
                while ((line = netIn.readLine()) != null) {
                    System.out.println("Ricevuto: " + line);
                    int num = line.length();
                    netOut.write(Integer.toString(num));
                    netOut.newLine();
                    netOut.flush();
                }

                s.close();
            }

        } catch (Exception e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(1);
        }
    }    
}
