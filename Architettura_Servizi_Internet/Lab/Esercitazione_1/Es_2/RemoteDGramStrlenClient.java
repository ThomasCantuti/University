import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class RemoteDGramStrlenClient {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Usage: java RemoteSquareClient hostname porta");
            System.exit(1);
        }

        try {
            Socket s = new Socket(args[0], Integer.parseInt(args[1]));

            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader netIn = new BufferedReader(new InputStreamReader(s.getInputStream(), "UTF-8"));
            BufferedWriter netOut = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));

            System.out.println("Connesso al server RemoteSquare");

            while (true) {
                System.out.println("Parola: ");
                String line = userIn.readLine();

                if (line.equals("fine")) break;

                netOut.write(line);
                netOut.newLine();
                netOut.flush();
                System.out.println("'" + line + "' ha " + netIn.readLine() + " caratteri");
            }

            s.close();
        } catch (Exception e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(1);
        }
    }
}
