import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

// java RemoteHeadClient hostname  porta    nomefile
//                       args[0]   args[1]  args[2]
public class RemoteHeadClient {
    public static void main(String[] args) {
        Socket s = null;
        BufferedReader netIn = null;
        BufferedWriter netOut = null;
        String line = null;

        if (args.length != 3) {
            System.err.println("Usage: java RemoteHeadClient hostname porta nomefile");
            System.exit(1);
        }

        try {
            s = new Socket(args[0], Integer.parseInt(args[1]));

            netIn = new BufferedReader(new InputStreamReader(s.getInputStream(), "UTF-8"));
            netOut = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));

            netOut.write(args[2]);
            netOut.newLine();
            netOut.flush();

            int line_number = 1;
            while ((line = netIn.readLine()) != null && line_number <= 5) {
                System.out.println(line);
                line_number += 1;
            }
    
            s.close();
        } catch (IOException e) {
            System.err.println(e.getMessage());
            System.exit(1);
        }
    }
}
