package SO.Java.CreazioneThread.Ibrido;

public class EsempioIbrido implements Runnable {
    
    private Thread t = null;

    public void start () {
        t = new Thread(this);
        t.start();
    }

    public void run () {
        
    }

}
