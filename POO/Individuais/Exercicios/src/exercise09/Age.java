package exercise09;
public class Age {
    // ATRIBUTES
    private int year, months, days, age;

    // METHODS
    public int monthToDay() {
        return this.getMonths() * 30;
    }
    public int yearToDay() {
        return this.getYear() * 365;
    }
    public void infos() {
        System.out.println("#-------------INFOS-------------#");
        System.out.println("Days: " + this.getDays());
        System.out.println("Months: " + this.getMonths());
        System.out.println("Years: " + this.getYear());
        System.out.println("Total in days: " + this.getAge());
        System.out.println("#-------------------------------#");
    }
    // SPECIAL METHODS2
    public Age(int days, int months, int year) {
        this.setDays(days);
        this.setMonths(months);
        this.setYear(year);
        this.setAge();
    }
    public int getYear() {
        return year;
    }
    public void setYear(int year) {
        this.year = year;
    }
    public int getMonths() {
        return months;
    }
    public void setMonths(int months) {
        this.months = months;
    }
    public int getDays() {
        return days;
    }
    public void setDays(int days) {
        this.days = days;
    }
    public int getAge() {
        return age;
    }
    public void setAge() {
        this.age = this.getDays() + (this.monthToDay()) + (this.yearToDay());
    }
}
