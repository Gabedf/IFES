package exercise11;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scann = new Scanner(System.in);
        System.out.print("Digite o valor de a: ");
        int a = scann.nextInt();
        System.out.print("Digite o valor de b: ");
        int b = scann.nextInt();
        scann.close();

        Trocar swap = new Trocar(a, b);
        swap.infos();
        swap.swap();
        swap.infos();
    }
}
