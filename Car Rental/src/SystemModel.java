import java.io.Serializable;
public class SystemModel implements Serializable {
    private Car car;
    private Customer customer;
    public SystemModel() {}
    public SystemModel(Car car, Customer customer) {
        this.car = car;
        this.customer = customer;
    }
    public Car getCar() {
        return car;
    }
    public void setCar(Car car) {
        this.car = car;
    }
    public Customer getCustomer() {
        return customer;
    }
    public void setCustomer(Customer customer) {
        this.customer = customer;
    }
}