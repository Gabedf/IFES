public class Conta {
    public String numero;
    public Pessoa titular;
    public double saldo, limite;

    public double disponivel() {
        return this.saldo + this.limite;
    }

    public void depositar(double valor) {
        this.saldo += valor;
    }

    public void extrato() {
        System.out.println("*** EXTRATO DA CONTA *** ");
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

    public void chequeEspecial(double juro) {
        if (this.saldo < 0) {
            this.saldo *= (1+(juro/100));
        }
    }

}
