package Eccezioni.Stack;

public class Main {
    public static void main (String[] args) {

        Stack stack = new Stack(100);

        try {
            stack.push("pippo");
            stack.push("pluto");
            System.out.println(stack.pop());
            System.out.println(stack.pop());
            System.out.println(stack.pop());
        } catch (StackOverflowException e) {
            System.out.println("Overflow");
        } catch (StackUnderflowException e) {
            System.out.println("Underflow");
        } catch (Exception e) {
            System.out.println("Errore strano: " + e.getMessage());
        }
    }
}
