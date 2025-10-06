import java.io.Serializable;
public class Admin implements Serializable {
    String name;
    String cnic;

    public Admin(String name, String cnic) {
        this.name = name;
        this.cnic = cnic;
    }
    public Admin() {
        this.name = "";
        this.cnic = "";
    }
    public String getName() {
        return name;
    }
    public String getCnic() {
        return cnic;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setCnic(String cnic) {
        this.cnic = cnic;
    }
}
