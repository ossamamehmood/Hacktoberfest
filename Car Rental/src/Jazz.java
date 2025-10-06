public class Jazz {
    private String name;
    private String mobileNumber;
    private String cnic;
    private String mpin;
    public Jazz(String name, String mobileNumber, String cnic, String mpin) {
        this.name = name;
        this.mobileNumber = mobileNumber;
        this.cnic = cnic;
        this.mpin = mpin;
    }
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getMobileNumber() {
        return mobileNumber;
    }

    public void setMobileNumber(String mobileNumber) {
        this.mobileNumber = mobileNumber;
    }

    public String getCnic() {
        return cnic;
    }

    public void setCnic(String cnic) {
        this.cnic = cnic;
    }

    public String getMpin() {
        return mpin;
    }

    public void setMpin(String mpin) {
        this.mpin = mpin;
    }
}