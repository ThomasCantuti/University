import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) throws Exception {
        PipedOutputStream pos = new PipedOutputStream();
        PipedInputStream pis = new PipedInputStream(pos);
    
        FromInpuPt fromInput = new FromInpuPt(pos);
        ToOutput toOutput = new ToOutput(pis);
    
        fromInput.start();
        toOutput.start();

        fromInput.join();
        toOutput.join();
    }
}