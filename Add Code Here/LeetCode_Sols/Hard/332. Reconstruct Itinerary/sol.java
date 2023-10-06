import java.util.*;

public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public List<String> findItinerary(List<List<String>> tickets) {
            Map<String, PriorityQueue<String>> graph = new HashMap<>();

            for (List<String> ticket : tickets) {
                graph.putIfAbsent(ticket.get(0), new PriorityQueue<>());
                graph.get(ticket.get(0)).add(ticket.get(1));
            }

            LinkedList<String> itinerary = new LinkedList<>();

            dfs("JFK", graph, itinerary);

            return itinerary;
        }

        private void dfs(String airport, Map<String, PriorityQueue<String>> graph, LinkedList<String> itinerary) {
            PriorityQueue<String> nextAirports = graph.get(airport);
            while (nextAirports != null && !nextAirports.isEmpty()) {
                dfs(nextAirports.poll(), graph, itinerary);
            }
            itinerary.addFirst(airport);
        }
    }
}