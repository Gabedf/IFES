package exercise09;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scann = new Scanner(System.in);
        int days, month, year;
        System.out.print("Days: ");
        days = scann.nextInt();
        System.out.print("Months: ");
        month = scann.nextInt();
        System.out.print("Years: ");
        year = scann.nextInt();
        Age gabe = new Age(days, month, year);
        gabe.infos();
        scann.close();
    }
}