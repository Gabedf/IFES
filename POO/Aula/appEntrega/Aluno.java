public class Aluno extends Usuario {
    // ATRIBUTOS
    private double saldo;

    // METODOS ESPECIAIS
    public Aluno(String cpf, String nome, String senha) {
        super(cpf, nome, senha);
        this.saldo = 0;
    }

    // METODOS
    public String toString() {
        return super.toString() + " (Saldo: R$" + String.format("%.2f", this.saldo) + ")";
    }
    public void inserirSaldo(double valor) {
        this.saldo = this.saldo + valor;
    }
    public boolean retirarSaldo(double valor) {
        if (valor <= this.saldo) {
            this.saldo = this.saldo - valor;
            return true;
        } else {return false;}
    }
}
