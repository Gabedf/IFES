package exercise05;
public class Gasto {
    // ATRIBUTOS
    private int tempo, velocidade, distancia;

    // MÉTODOS
    public double litros_usados() {
        return (this.getDistancia() / 12);
    }

    // MÉTODOS ESPECIAIS
    public Gasto(int tempo, int velocidade) {
        this.setTempo(tempo);
        this.setVelocidade(velocidade);
    }
    public int getTempo() {
        return tempo;
    }
    public void setTempo(int tempo) {
        this.tempo = tempo;
    }
    public int getVelocidade() {
        return velocidade;
    }
    public void setVelocidade(int velocidade) {
        this.velocidade = velocidade;
        this.setDistancia();
    }
    public int getDistancia() {
        return distancia;
    }
    public void setDistancia() {
        this.distancia = this.getTempo() * this.getVelocidade();
    }
}
