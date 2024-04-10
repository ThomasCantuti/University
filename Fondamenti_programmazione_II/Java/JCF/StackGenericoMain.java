package JCF;

public class StackGenericoMain {
    public static void main(String[] args) {

        StackGenerico<Integer> stack = new StackGenerico<Integer>();

        stack.push(25).push(18).push(35);

        while (!stack.isEmpty()) {
            System.out.println(stack.pop());
        }
    }
}
