package InputOutput.LetturaFile;

public class InventoryItem {

    private String name;
    private int units;
    private float price;

    public InventoryItem (String nm, int num, float pr) {
        name = nm; units = num; price = pr;
    }

    public String toString () {
        return name + ": " + units + " a euro " + price;
    }
}
