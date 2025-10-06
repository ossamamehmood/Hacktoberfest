import java.io.Serializable;
public class Customer extends Person implements Serializable {
    private static final long serialVersionUID = 1L;
    private String issueNumber;
    private String licenceNum;
    public Customer(String issueNumber, String customerName, String age, String licenceNum) {
        super(customerName,age);
        this.issueNumber = issueNumber;
        this.licenceNum = licenceNum;
    }

    public String getIssueNumber() {
        return issueNumber;
    }

    public void setIssueNumber(String issueNumber) {
        this.issueNumber = issueNumber;
    }

    public String getCustomerName() {
        return super.getName();
    }
    public void setCustomerName(String customerName) {
        super.setName(customerName);
    }
    public String getAge() {
        return super.getAge();
    }
    public void setAge(String age) {
        super.setAge(age);
    }
    public String getLicenceNum() {
        return licenceNum;
    }
    public void setLicenceNum(String licenceNum) {
        this.licenceNum = licenceNum;
    }
}