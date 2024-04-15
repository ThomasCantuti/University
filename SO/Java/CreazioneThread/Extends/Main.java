package SO.Java.CreazioneThread.Extends;

public class Main {
    public static void main(String[] args) {

        EsempioExtends ct = new EsempioExtends();
        ct.start();

        try {
            ct.join();
        } catch(InterruptedException e) {
            e.printStackTrace();
        }
        
    }
}
