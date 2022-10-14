public class Wagon {
        private String id;
        public Wagon nextWagon;

    public Wagon() {
            char random = (char) (Math.random() * 100);
            String id = String.valueOf(random);
            Wagon nextWagon = null;
        }
        public String getId() {
            return id;
        }

}