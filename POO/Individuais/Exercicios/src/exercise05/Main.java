package exercise05;
public class Main {
    public static void main(String[] args) {
        Gasto viagemBH = new Gasto(10, 100);
        System.out.println("Foram usados " + viagemBH.litros_usados() + " litros numa distância de " + viagemBH.getDistancia() + "Km");
    }
}
