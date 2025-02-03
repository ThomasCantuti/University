import java.io.*;
import java.net.*;

public class QuoteClient {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Usage: java QuoteClient hostname porta");
            System.exit(1);
        }

        try {
            // crazione Socket
            DatagramSocket ds = new DatagramSocket();

            // preparazione richiesta
            byte[] reqBuf = new String("QUOTE\n").getBytes("UTF-8");
            DatagramPacket reqPacket = new DatagramPacket(reqBuf, reqBuf.length,
                        InetAddress.getByName(args[0]), Integer.parseInt(args[1]));

            // invio richiesta
            ds.send(reqPacket);

            // preparazione ricevuta risposta
            byte[] respBuf = new byte[2048];
            DatagramPacket respPacket = new DatagramPacket(respBuf, respBuf.length);

            // ricevuta risposta
            ds.receive(respPacket);

            // conversione della risposta in stringa
            String quote = new String(respPacket.getData(), 0,
                            respPacket.getLength(), "UTF-8");

            System.out.println(quote);

            ds.close();

        } catch (Exception e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(1);
        }
    }
}
