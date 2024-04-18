import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) throws Exception {
        PipedOutputStream pos = new PipedOutputStream();
        PipedInputStream pis = new PipedInputStream(pos);
    
        FromInpuPipedOutputStream fromInput = new FromInpuPipedOutputStream(pos);
        ToOutpu toOutput = new ToOutpu(pis);
    
        fromInput.start();
        toOutput.start();

        fromInput.join();
        toOutput.join();
    }
}