package exercise15;

public class Notas {
    // ATRIBUTES
    private double p1, p2, atv1, atv2;
    private String nome;

    // METHODS
    public void addNotas(double p1, double p2, double atv1, double atv2) {
        this.setAtv1(atv1);
        this.setAtv2(atv2);
        this.setP1(p1);
        this.setP2(p2);
    }
    
    // SPECIAL METHODS
    public Notas(String nome) {
        this.setNome(nome);
    }
    public double getP1() {
        return p1;
    }
    public void setP1(double p1) {
        this.p1 = p1;
    }
    public double getP2() {
        return p2;
    }
    public void setP2(double p2) {
        this.p2 = p2;
    }
    public double getAtv1() {
        return atv1;
    }
    public void setAtv1(double atv1) {
        this.atv1 = atv1;
    }
    public double getAtv2() {
        return atv2;
    }
    public void setAtv2(double atv2) {
        this.atv2 = atv2;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
}
