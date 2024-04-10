package EserciziEsame.Es2;

public class Call {

    private String sender, recever;
    private int start, stop;

    public Call (String Sender, String Recever, int Start, int Stop) {
        sender = Sender;
        recever = Recever;
        start = Start;
        stop = Stop;
    }

    public int getDuration () {
        return stop - start;
    }
}
