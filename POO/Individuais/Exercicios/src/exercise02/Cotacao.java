package exercise02;
public class Cotacao {
    // ATRIBUTOS
    private double dolar;

    // MÉTODOS
    public double converterPreco(double preco) {
        return (this.getDolar() * preco);
    }

    // MÉTODOS ESPECIAIS
    public double getDolar() {
        return dolar;
    }
    public void setDolar(double dolar) {
        this.dolar = dolar;
    }
}
