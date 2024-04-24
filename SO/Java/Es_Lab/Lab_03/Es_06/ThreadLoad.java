import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

public class ThreadLoad implements Serializable {
    private HashMap<Integer, Double> threadLoad = null;

    public ThreadLoad () {
        this.threadLoad = new HashMap<Integer, Double>(10);
    }

    public synchronized void setThreadLoad (int id, double load) {
        this.threadLoad.put(id, load);
    }

    public synchronized Integer getMaxId () {
        Map.Entry<Integer, Double> threadLoad_max = null;
        for (Map.Entry<Integer, Double> obj : threadLoad.entrySet()) {
            if (threadLoad_max == null || obj.getValue().compareTo(threadLoad_max.getValue()) > 0) {
                threadLoad_max = obj;
            }
        }
        if (threadLoad_max == null) return null;
        return threadLoad_max.getKey();
    }

    public synchronized Double getMaxLoad (int maxId) {
        if (threadLoad.get(maxId) == null) return null;
        return threadLoad.get(maxId);
    }

    public String toString () {
        String result = "";
        for (Map.Entry<Integer, Double> obj : threadLoad.entrySet()) {
            result += "id: " + obj.getKey() + " value: " + obj.getValue();
        }
        return result;
    }
}
