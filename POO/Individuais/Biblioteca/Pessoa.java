public class Pessoa {
    // ATRIBUTES
    private String nome;
    private Data dt_nascimento;

    // METHODS

    // SPECIAL METHODS
    public Pessoa(String nome) {
        setNome(nome);
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
}
