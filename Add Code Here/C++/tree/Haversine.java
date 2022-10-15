package haversine;

public class Haversine {
    
    public static double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
        // distance between latitudes and longitudes
        double dLat = Math.toRadians(lat2 - lat1);
        double dLon = Math.toRadians(lon2 - lon1);

        // convert to radians
        lat1 = Math.toRadians(lat1);
        lat2 = Math.toRadians(lat2);

        // apply formulae
        double a = Math.pow(Math.sin(dLat / 2), 2) + Math.pow(Math.sin(dLon / 2), 2) * Math.cos(lat1) * Math.cos(lat2);
        double rad = 6371;
        double c = 2 * Math.asin(Math.sqrt(a));
        return rad * c;
    }
    
    public static void main(String[] args) {
        double lat1 = 7.257163;
        double lon1 = 80.587300;
        double lat2 = 7.296761;
        double lon2 = 80.635144;
        
        System.out.println(Haversine.calculateDistance(lat1, lon1, lat2, lon2));
    }
    
}
