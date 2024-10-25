import java.util.Scanner;
public class ContaCorrente extends Conta {
    // ATRIBUTES
    private double limite;

    // METHODS
    public void extrato() {
        System.out.println("*** EXTRATO DA CONTA - CONTA CORRENTE *** ");
        super.extrato();
    }
    public void chequeEspecial(double juro) {
        if (this.saldo < 0) {
            this.saldo *= (1+(juro/100));
        }
    }
    protected double disponivel() {
        return this.saldo + this.limite;
    }
    public void alterarLimite() {
        if (this.gerente.validarAcesso()) {
            System.out.print("Digite o novo limite: ");
            Scanner s = new Scanner(System.in);
            this.limite = s.nextDouble();
        } else {System.out.println("Nao possível alterar limite.");}
    }
    
    // SPECIAL METHODS
    public ContaCorrente(Gerente g) {
        super(g);
        this.setLimite(limite);
    }
    public double getLimite() {
        return limite;
    }
    public void setLimite(double limite) {
        this.limite = limite;
    }
}
