package exercise03;
public class Main {
    public static void main(String[] args) {
        Seller gabe = new Seller(4, "Gabriel");
        Store homeGoods = new Store();
        homeGoods.setSeller(gabe);

        System.out.println("*** ---------- *** ------------- ***");
        System.out.println("Nome vendedor: " + homeGoods.getSeller().getName());
        System.out.println("Cargo: " + homeGoods.getSeller().getNomeCargo());
        System.out.println("Salário: " + homeGoods.getSeller().getSalary());
        System.out.println("Salário pós vendas: " + homeGoods.comissao(3, 100, gabe));
    }
}
