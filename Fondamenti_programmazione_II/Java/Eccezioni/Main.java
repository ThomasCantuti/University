package Eccezioni;

public class Main {
    public static void main(String[] args){
        // getMessage() è metodo in classe derivata di Exception
        // e è un oggetto della classe Exception
        // blocchi catch gestiti in cascata

        // GESTIONE
        int n = 1;
        String s = "asdf";
        try {
            n = Integer.parseInt(s);

        } catch (NumberFormatException e){
            n = 0;

        } catch (Exception e) {
            System.out.println(e.getMessage());
            System.exit(1);
        } finally {
            
        }
        
        System.out.println(n);

        // se codice non rispetta "Catch or Specify Requirement" non compila
        // 3 tipi di eccezioni:
        // Checked exceptions -> cond. eccezionali che un'app deve prevedere e recuperare
        // errors -> cond. eccezionali esterne all'app e che l'app non può prevedere e recuperare
        // runtime exceptions -> cond. eccezionali interne all'app ma che l'app non può prev. e rec.
        // unchecked exceptions -> Errors e Runtime exceptions
    }
}
