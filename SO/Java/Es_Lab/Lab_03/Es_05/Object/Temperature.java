import java.io.Serializable;

public class Temperature implements Serializable {
    private double temp;

    public Temperature () {
        this.temp = temperatureGeneretor();
    }

    private double temperatureGeneretor () {
        return Math.random() * (21 - 18) + 18;
    }

    public double getValue () {
        return this.temp;
    }
}
