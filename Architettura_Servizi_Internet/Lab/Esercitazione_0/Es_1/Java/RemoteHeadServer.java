import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

// java remoteHeadServer hostname
//                       args[0]
public class RemoteHeadServer {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java RemoteHeadServer porta");
            System.exit(1);
        }

        try {
            ServerSocket ss = new ServerSocket(Integer.parseInt(args[0]));

            for(;;) {
                Socket s = ss.accept();

                BufferedReader netIn = new BufferedReader(new InputStreamReader(s.getInputStream(), "UTF-8"));
                BufferedWriter netOut = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));

                String filename = netIn.readLine();

                File file = new File(filename);
                if (file.exists()) {
                    String line;
                    int line_number = 1;
                    BufferedReader bfr = new BufferedReader(new FileReader(file));
                    while ((line = bfr.readLine()) != null && line_number <= 5) {
                        netOut.write(line);
                        netOut.newLine();
                        netOut.flush();
                        line_number += 1;
                    }
                }
                s.close();
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
            System.exit(1);
        }
    }
}
