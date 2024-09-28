package exercise15;
import java.util.List;
import java.util.ArrayList;

public class Aluno {
    // ATRIBUTES
    private String nome, matricula;
    private int id;
    private List<Notas> notas;

    // METHODS
    public void addNota(Notas nota) {
        this.getNotas().add(nota);
    }
    // SPECIAL METHODS
    public Aluno(String nome) {
        this.setNome(nome);
        this.setNotas(new ArrayList<>());
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getMatricula() {
        return matricula;
    }
    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public List<Notas> getNotas() {
        return notas;
    }
    public void setNotas(List<Notas> notas) {
        this.notas = notas;
    }
}