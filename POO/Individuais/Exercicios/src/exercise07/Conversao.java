package exercise07;
public class Conversao {
    // ARTRIBUTOS
    private double farenheit;

    // MÉTODOS
    public double convertFtoC() {
        return ((this.getFarenheit() - 32) * 5) / 9;
    }

    // MÉTODOS ESPECIAIS
    public Conversao(double farenheit) {
        this.setFarenheit(farenheit);
    }
    public double getFarenheit() {
        return farenheit;
    }
    public void setFarenheit(double farenheit) {
        this.farenheit = farenheit;
    }

}
