package SO.Java.CreazioneThread.Implements;

public class Main {
    public static void main(String[] args) {
        Thread ct;
        ct = new Thread(new EsempioRunnable());
        ct.start();

        try {
            ct.join();
        } catch(InterruptedException e) {
            e.printStackTrace();
        }
    }
}
