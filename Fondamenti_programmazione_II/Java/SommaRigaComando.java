public class SommaRigaComando {
    public static void main(String[] args){
        int somma = 0;
        for(int i = 0; i < args.length; i ++){
            int arg = Integer.parseInt(args[i]);
            somma = somma + arg;
        }
        System.out.println("Somma = " + somma);
    }
}
