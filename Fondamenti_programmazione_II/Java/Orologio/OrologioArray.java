package Orologio;

public class OrologioArray {
    public static void main(String[] args){
        Orologio ore, min;
        min = new Orologio();
        ore = new Orologio();

        min.reset();
        ore.reset();

        min.tic();
        min.tic();

        System.out.println(min.getMin());
        System.out.println(ore.getOre());
    }
}
