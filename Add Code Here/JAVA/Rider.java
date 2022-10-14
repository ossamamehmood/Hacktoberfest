package Abstraction;

interface Bike {
    public void start();
}

class Honda implements Bike {
    @Override
    public void start() {
        System.out.println("Honda Bike.");
    }
}

class Apache implements Bike {
    @Override
    public void start() {
        System.out.println("Apache Bike.");
    }
}


public class Rider {
    public static void main(String[] args) {
        Bike b1 = new Honda();
        Bike b2 = new Apache();
        b1.start();
        b2.start();
    }
}
