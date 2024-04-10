package JCF;

import java.util.*;

public class StackWC<T> {

    private List<T> storage;
    
    public StackWC(){ 
        storage = new ArrayList<T>(); 
    }
    
    public StackWC<T> push(T elem){
        // CASCADING
        storage.add(elem); 
        return this;
    }
    
    public T pop(){ 
        return storage.remove(storage.size()-1);
    }
    
    public boolean isEmpty() { 
        return storage.isEmpty(); 
    }

    /*public <E extends T> void moveFrom(StackWC<E> source) {
        push(source.pop());
    }*/

    public void moveFrom(StackWC<? extends T>  source) {
        push(source.pop());
    }

    public static void emptyAndPrintStack(StackWC<?> stack) {
        while(!stack.isEmpty())
            System.out.println(stack.pop());
    }
}