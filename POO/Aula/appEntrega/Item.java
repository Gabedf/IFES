public class Item {
    // ATRIBUTOS
    private Produto p;
    private int qtd;
    private String obs;

    // METODOS ESPECIAIS
    public Item(Produto p, int qtd) {
        this.p = p;
        this.qtd = qtd;
    }
    public Produto getP() {
        return p;
    }
    public int getQtd() {
        return qtd;
    }
    public String getObs() {
        return obs;
    }
    
    // METODOS
    public String toString() {
        return String.format("%s (QTD: %d, Valor Total: R$%.2f)", 
            p.getNome(), qtd, valorTotal());
    }
    public double valorTotal() {
        return this.qtd * this.p.getValor();
    }
}
