package pessoa;
import Data;

public class Usuario {
    // ATRIBUTES
    private String email, cpf;
    private int senha;

    // METHODS
    

    // SPECIAL METHODS
    public Usuario(String email, String cpf, int senha) {
        setEmail(email);
        setCpf(cpf);
        setSenha(senha);
    }
    public String getEmail() {
        return email;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public String getCpf() {
        return cpf;
    }
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    public int getSenha() {
        return senha;
    }
    public void setSenha(int senha) {
        this.senha = senha;
    }
}