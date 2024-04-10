package EserciziEsame.Es1;

public class MoltoGraveException extends Exception{

    public MoltoGraveException () {
        super();
    }

    public String getMessage () {
        return "Malattia a gravità maggiore di 10";
    }
}
