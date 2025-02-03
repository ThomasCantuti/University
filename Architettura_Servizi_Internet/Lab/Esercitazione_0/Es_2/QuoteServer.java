import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class QuoteServer {
    static final String[] quotations = {
        "Adoro i piani ben riusciti",
        "Quel tappeto dava veramente un tono all'ambiente",
        "Se ci riprovi ti stacco un braccio",
        "Questo è un colpo di genio, Leonard",
        "I fagioli comunque erano uno schifo"
    };

    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java QuoteServer porta");
            System.exit(1);
        }

        // indice quote corrente
        int index = 0;

        try {
            // creazione socket
            DatagramSocket ds = new DatagramSocket(Integer.parseInt(args[0]));
            
            while(true) {
                // creazione buffer e datagram packet
                byte[] reqBuf = new byte[2048];
                DatagramPacket reqPacket = new DatagramPacket(reqBuf, reqBuf.length);
                
                // lettura messaggio di richiesta
                ds.receive(reqPacket);

                // estrazione stringa richiesta
                String request = new String(reqPacket.getData(), 0, 
                                            reqPacket.getLength(), "UTF-8");
                
                // verifica richiesta valida
                if (request.equals("QUOTE\n")) {
                    // ottenimento prossima quote
                    String quote = quotations[ index % quotations.length ];
                    
                    // conversione quote da stringa a sequenza di byte
                    byte[] respBuf = quote.getBytes("UTF-8");

                    // preparazione datagram packet di risposta
                    DatagramPacket respPacket = new DatagramPacket(respBuf, respBuf.length,
                                                                    reqPacket.getAddress(),
                                                                    reqPacket.getPort());
                    
                    // e trasmissione al client
                    ds.send(respPacket);
                }
                // aggiornamento contatore
                index += 1;
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(1);
        }
        
    }
}
