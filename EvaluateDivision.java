import java.util.*;

public class EvaluateDivision {
    class Node {
        String key;
        double val;

        public Node(String k, double v) {
            key = k;
            val = v;
        }
    }

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, List<Node>> g = buildGraph(equations, values);
    }

    private Map<String, List<Node>> buildGraph(List<List<String>> eq, double[] values) {
        Map < String, List << Node>> g = new HashMap();
        for (int i = 0; i < values.length; i++) {
            String src = eq.get(i).get(0);
            String des = eq.get(i).get(1);
            g.putIfAbsent(src, new ArrayList());
            g.putIfAbsent(src, new ArrayList());
        }

    }
    public static void main (String[] args) {
    }
}
