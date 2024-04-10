package Stringhe;

public class InversioneStringa {
    public static void main(String[] args){
        String s = "ciao a tutti";
        StringBuffer sb;
        sb = new StringBuffer(s);
        char ch;
        for(int i = 0; i < sb.length()/2; i ++){
            ch = sb.charAt(i);
            sb.setCharAt(i,sb.charAt(sb.length()-i-1));
            sb.setCharAt(sb.length()-i-1,ch);
        }
        s = sb.toString();
        System.out.println(s);
    }
}
