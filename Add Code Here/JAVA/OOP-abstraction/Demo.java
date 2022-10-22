enum BasicSalary {
    SE(100000),
    SSE(200000),
    TechLead(300000),
    Archi(400000);

    public final int basic;

    private BasicSalary(int basic) {
        this.basic = basic;
    }
}

enum AllowanceRate {
    SE(500),
    SSE(1000),
    TechLead(1500),
    Archi(2000);

    public final int rate;

    private AllowanceRate(int rate) {
        this.rate = rate;
    }
}

public class Demo implements Abstraction {

    public int basicSalaryCalculator(String designation, int no_of_tasks) {

        int basicSalary;
        int allowance;
        int netSalary = 0;

        if (no_of_tasks > 10) {
            //allowance addded
            if (designation == "SE") {
                allowance = allowanceCalculator(designation, no_of_tasks);
                netSalary = BasicSalary.SE.basic + allowance;
            } else if (designation == "SSE") {
                allowance = allowanceCalculator(designation, no_of_tasks);
                netSalary = BasicSalary.SSE.basic + allowance;
            } else if (designation == "TechLead") {
                allowance = allowanceCalculator(designation, no_of_tasks);
                netSalary = BasicSalary.TechLead.basic + allowance;
            } else if (designation == "Archi") {
                allowance = allowanceCalculator(designation, no_of_tasks);
                netSalary = BasicSalary.Archi.basic + allowance;
            } else {
                netSalary = 0;
            }
            return netSalary;
        } else {
            //task<=10
            if (designation == "SE") {
                return BasicSalary.SE.basic;
            } else if (designation == "SSE") {
                return BasicSalary.SSE.basic;
            } else if (designation == "TechLead") {
                return BasicSalary.TechLead.basic;
            } else if (designation == "Archi") {
                return BasicSalary.Archi.basic;
            } else {
                return 0;
            }
        }
    }

    public int allowanceCalculator(String designation, int tasks) {

        if (designation == "SE") {
            return (tasks - 10) * AllowanceRate.SE.rate;
        } else if (designation == "SSE") {
            return (tasks - 10) * AllowanceRate.SSE.rate;
        } else if (designation == "TechLead") {
            return (tasks - 10) * AllowanceRate.TechLead.rate;
        } else if (designation == "Archi") {
            return (tasks - 10) * AllowanceRate.Archi.rate;
        } else {
            return 0;
        }

    }
}