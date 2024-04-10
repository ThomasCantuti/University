package EserciziEsame.StruttutraEsame;

public class Aggiunta {
    protected File1 file1;
    protected double impegno;
    
    public Aggiunta(File1 file1, double impegno){
        this.file1=file1;
        this.impegno=impegno;
    }

    public double getOre(){
        return impegno;
    }

    public File1 getFile1(){
        return file1;
    }

    public String toString(){
        return "(" + file1.getQualcosa() + "," + impegno + ")";
    }
}
