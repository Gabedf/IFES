import java.util.Scanner;
public class ContaCorrente extends Conta {
    // ATRIBUTES
    public double limite;

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
    public double disponivel() {
        return this.saldo + this.limite;
    }
    public void alterarLimite() {
        if (this.gerente.validarAcesso()) {
            System.out.println("Digite o novo limite: ");
            Scanner s = new Scanner(System.in);
            this.limite = s.nextDouble();
            s.close();
        } else {System.out.println("Não possível alterar limite.");}
    }
    
    // SPECIAL METHODS
    public ContaCorrente(Gerente g) {
        super(g);
        this.limite = 200;
    }
}
