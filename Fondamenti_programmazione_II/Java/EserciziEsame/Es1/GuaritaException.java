package EserciziEsame.Es1;

public class GuaritaException extends Exception {

    public GuaritaException () {
        super();
    }

    public String getMessage () {
        return "Malattia a gravità minore di 1";
    }
}
