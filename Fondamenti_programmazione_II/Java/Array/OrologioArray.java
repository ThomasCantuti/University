package Array;

public class OrologioArray {
    public static void main(String[] args){
        Orologio orologio;
        orologio = new Orologio();

        for( int i = 0; i < 71; i ++){
            orologio.tic();
        }

        System.out.println("Ore: " + orologio.getOre() + " Minuti: " + orologio.getMin());
    }
}
