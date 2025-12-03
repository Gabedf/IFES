import java.util.Scanner;

public class Teste {
    public static void main(String[] args) {
        String user01, user02, user03;
        Scanner scann = new Scanner(System.in);
        System.out.print("Digite aqui seu nome: ");
        user01 = scann.nextLine();

        System.out.print("Olá " + user01 + "! Seja bem vindo.");
        scann.close();
    }
}