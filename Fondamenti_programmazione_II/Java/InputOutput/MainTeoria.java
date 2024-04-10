package InputOutput;

public class MainTeoria {
    public static void main (String[] args) {
        /* stream = flusso -> canale di comunicazione dati monodirezionale
           stream -> insieme di classi nel package java.io
        
           2 misure di stream:
           - byte: per informazioni binarie
           - caratteri: per informazioni di testo

           3 criteri:
           - direzione: input/output
           - tipo di dati: byte/caratteri
           - scopo: collegamento con dispositivo/file o gestione di altro stream
           
           Stream di byte:
           - InputStream:
                * int read() -> lettura byte
                * int available() -> numero di byte disponibili
                * void close() -> chiusura canale
           - OutputStream:
                * void write(int b) -> scrittura di un byte
                * void flush() -> forza l'emissione di byte trasmessi
                * void close() -> chisura canale

           Stream di caratteri:
           - Reader:
                * int read() -> lettura di un carattere
                * boolean ready() -> dico se c'è qualcosa da leggere
                * void close() -> chiusura canale
           - Writer:
                * void write(int c) -> scrittura di carattere
                * void write(String str) -> scrittura di stringa
                * void flush() -> forza l'emissione di byte trasmessi
                * void close() -> chiusura canale
           
           Gestione input da tastiera:
           - BufferedReader kbd = new BufferedReader(new InputStreamReader(System.in));
           - Scanner tastiera = new Scanner(System.in); tastiera.close();

        */
    }
}
