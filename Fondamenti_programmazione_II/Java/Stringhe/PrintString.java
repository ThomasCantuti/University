package Stringhe;

class provaPrint{
    int val;

    public provaPrint(int n){
        val = n;
    }

    public String toString(){
        return "Nuovo valore: " + val;
    }
}

public class PrintString {
    public static void main(String[] args){
        Counter c = new Counter(10);
        System.out.println(c);

        provaPrint prova = new provaPrint(9);
        System.out.println(prova);
    }
}
