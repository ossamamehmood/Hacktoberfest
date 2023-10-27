class YearsMonthsDaysFormatter {
    static convertDaysToYearsMonthsDays(days) {
        const years = Math.floor(days / 365);
        const months = Math.floor((days % 365) / 30);
        days = (days % 365) % 30;

        const result = `${years} years ${months} months ${days} days`;

        return result ? result : "0 years 0 months 0 days";
    }
}

// Example usage:
const days = 500; // Replace with your desired number of days
const formatted = YearsMonthsDaysFormatter.convertDaysToYearsMonthsDays(days);
console.log(formatted);
