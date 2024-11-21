import java.util.Scanner;
public class Conta {
    // ATRIBUTES
    protected String numero;
    protected Pessoa titular;
    protected Gerente gerente;
    protected Data dCriacao;
    protected double saldo;

    // METHODS
    public void depositar(double valor) {
        this.saldo += valor;
    }
    public void depositar() {
        Scanner s = new Scanner(System.in);
        System.out.println("Digite o valor a ser depositado: ");
        double v = s.nextDouble();
        depositar(v);
    }
    protected double disponivel() {
        return this.saldo;
    }
    public void extrato() {
        System.out.println("\n*** EXTRATO DA CONTA *** ");
        System.out.println("Conta: " + this.numero);
        System.out.println("Titular: " + this.titular.cpf);
        System.out.println("Saldo disponivel para saque: " + this.disponivel());
    }
    public boolean sacar(double valor) {
        if (valor <= this.disponivel()) {
            this.saldo -= valor;
            System.out.println("Saque na conta " + this.numero + " realizado com sucesso. \nNovo saldo: " + this.saldo);
            return true;
        }
        else {
            System.out.println("ERRO: Saque na conta " + this.numero + " nao foi realizado. \nValor disponivel: " + this.disponivel());
            return false;
        }
    }
    public boolean sacar() {
        Scanner s = new Scanner(System.in);
        System.out.println("Digite o valor a ser sacado: ");
        double v = s.nextDouble();
        return sacar(v);
    }
    public boolean transferir(double valor, Conta destino) {
        if (this.sacar(valor)) {
            destino.depositar(valor);
            System.out.println("Transferencia de " + valor + " da conta " + this.numero + " para a conta " + destino.numero + " foi realizado com sucesso.");
            return true;
        }
        else {
            System.out.println("ERRO: Nao foi possivel transferir " + valor + " da conta " + this.numero + " para a conta " + destino.numero + "\nValor disponivel: " + this.disponivel());
            return false;
        }
    }
    public boolean transferir(Conta destino) {
        Scanner s = new Scanner(System.in);
        System.out.println("Digite o valor a ser transferido: ");
        double v = s.nextDouble();
        return transferir(v, destino);
    }
    // SPECIAL METHODS
    public Conta(Pessoa t, Gerente g) {
        Scanner s = new Scanner(System.in);
        System.out.print("\n# ---- CRIACAO NOVA CONTA  ---- #\n");
        System.out.print("Digite o numero da conta: ");
        this.numero = s.nextLine();

        this.titular = new Pessoa(); 

        System.out.print("\n# ---- Data criacao conta  ---- #\n");
        this.dCriacao = new Data();

        this.gerente = g;
        this.saldo = 0;
        System.out.println("Nova conta adicionada ao sistema.");
    }
}
