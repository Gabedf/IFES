public class Banco {
    public static void main(String[] args) {
        Gerente g1 = new Gerente();
        ContaCorrente c1 = new ContaCorrente(g1);
        c1.extrato();

        c1.alterarLimite();
        c1.extrato();
    }
}
