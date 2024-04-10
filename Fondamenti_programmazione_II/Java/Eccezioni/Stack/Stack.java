package Eccezioni.Stack;

public class Stack {

    private int count;
    private String[] items;

    public Stack (int max){
        count = 0;
        items = new String[max];
    }

    public void push (String value) 
        throws StackOverflowException {

        try {
            items[count] = value;
            count ++;
        } catch (ArrayIndexOutOfBoundsException ae) {
            StackOverflowException oe = new StackOverflowException();
            throw oe;
        }
    }

    public String pop () 
        throws StackUnderflowException {

        String value;
        
        try {
            count --; // se 0 diventa -1 -> exception
            value = items[count];
            return value;
        } catch (ArrayIndexOutOfBoundsException ae) {
            count = 0;
            StackUnderflowException ue = new StackUnderflowException();
            throw ue;
        }
        
    }

    public boolean isEmpty () {
        return count == 0;
    }
}
