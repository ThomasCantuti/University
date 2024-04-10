package Eccezioni.Stack;

public class StackUnderflowException extends Exception {
    
    public StackUnderflowException () {
        super();
    }

    public StackUnderflowException (String s) {
        super(s);
    }
}
