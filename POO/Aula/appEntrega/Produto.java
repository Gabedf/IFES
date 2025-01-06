public class Produto {
    // ATRIBUTOS
    private String codigo, nome, descricao;
    private int qtd;
    private double valor;

    // METODOS ESPECIAIS
    public Produto(String nome, int qtd, double valor) {
        this.nome = nome;
        this.qtd = qtd;
        this.valor = valor;
    }
    public String getCodigo() {
        return codigo;
    }
    public void setCodigo(String c) {
        this.codigo = c;
    }
    public String getNome() {
        return nome;
    }
    public String getDescricao() {
        return descricao;
    }
    public int getQtd() {
        return qtd;
    }
    public double getValor() {
        return valor;
    }
    public String toString() {
        return String.format("Produto: %s (Estoque: %d, Preço: R$%.2f)", nome, qtd, valor);
    }
    // METODOS
    public void retirarDeEstoque(int qtd) {
        this.qtd = this.qtd - qtd;
    }
}
