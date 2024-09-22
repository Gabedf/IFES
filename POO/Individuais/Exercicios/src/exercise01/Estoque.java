package exercise01;
public class Estoque {
    // ATRIBUTOS
    private int quantidadeMin, quantidadeMax;

    // MÉTODOS
    public double estoqueMedio() {
        return ((this.getQuantidadeMax() + this.getQuantidadeMin())/2);
    }

    // MÉTODOS ESPECIAIS
    public int getQuantidadeMin() {
        return quantidadeMin;
    }
    public void setQuantidadeMin(int quantidadeMin) {
        this.quantidadeMin = quantidadeMin;
    }
    public int getQuantidadeMax() {
        return quantidadeMax;
    }
    public void setQuantidadeMax(int quantidadeMax) {
        this.quantidadeMax = quantidadeMax;
    }
}
