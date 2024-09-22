package exercise02;
public class Main {
    public static void main(String[] args) {
        Cotacao blusa = new Cotacao();
        blusa.setDolar(5);
        System.out.println("O preço da blusa é: " + blusa.converterPreco(100) + " reais.");
    }
}
