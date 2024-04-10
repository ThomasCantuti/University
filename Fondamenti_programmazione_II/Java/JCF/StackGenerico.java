package JCF;

import java.util.*;

public class StackGenerico<T> {

    private List<T> storage;
    
    public StackGenerico(){ 
        storage = new ArrayList<T>(); 
    }
    
    public StackGenerico<T> push(T elem){
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

    public void moveFrom(StackGenerico<T> source) {
        while(!source.isEmpty())
            push(source.pop());
    }
}
