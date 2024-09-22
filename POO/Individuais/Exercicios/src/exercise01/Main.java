package exercise01;
public class Main {
    public static void main(String[] args) {
        Estoque estoque = new Estoque();
        estoque.setQuantidadeMin(10);
        estoque.setQuantidadeMax(5);
        System.out.println("QUANTIDADE MAX: " + estoque.getQuantidadeMax() + "\nQUANTIDADE MINIMA: " + estoque.getQuantidadeMin() + "\nMEDIA: " + estoque.estoqueMedio());
    }
}
