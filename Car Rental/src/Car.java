import java.io.Serializable;

public class Car implements Serializable {
    private static final long serialVersionUID = 1L;
    private String carNumber;
    private String carName;
    private String carModel;
    private String horsePower;
    private String color;
    private int seatingCapacity ;
    private double fuelEconomy;
    private double rentalCost;
    public Car(String carNumber, String carName, String carModel, String horsePower, int seatingCapacity, double fuelEconomy,
               double rentalCost,String color) {
        this.carNumber = carNumber;
        this.carName = carName;
        this.carModel = carModel;
        this.horsePower = horsePower;
        this.seatingCapacity = seatingCapacity;
        this.fuelEconomy = fuelEconomy;
        this.rentalCost = rentalCost;
        this.color = color;
    }
    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }
    public String getCarNumber() {
        return carNumber;
    }

    public void setCarNumber(String carNumber) {
        this.carNumber = carNumber;
    }

    public String getCarName() {
        return carName;
    }

    public void setCarName(String carName) {
        this.carName = carName;
    }

    public String getCarModel() {
        return carModel;
    }

    public void setCarModel(String carModel) {
        this.carModel = carModel;
    }

    public String getHorsePower() {
        return horsePower;
    }

    public void setHorsePower(String horsePower) {
        this.horsePower = horsePower;
    }

    public int getSeatingCapacity() {
        return seatingCapacity;
    }
    public void setSeatingCapacity(int seatingCapacity) {
        this.seatingCapacity = seatingCapacity;
    }
    public double getFuelEconomy() {
        return fuelEconomy;
    }
    public void setFuelEconomy(double fuelEconomy) {
        this.fuelEconomy = fuelEconomy;
    }
    public double getRentalCost() {
        return rentalCost;
    }
    public void setRentalCost(double rentalCost) {
        this.rentalCost = rentalCost;
    }
}