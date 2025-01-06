public class Sala {
    // ATRIBUTOS
    private String bloco, sala, andar;

    // METODOS ESPECIAIS
    public Sala(String bloco, String sala, String andar) {
        this.bloco = bloco;
        this.sala = sala;
        this.andar = andar;
    }
    public String getBloco() {
        return bloco;
    }
    public String getNome() {
        return sala;
    }
    public String getAndar() {
        return andar;
    }
}
