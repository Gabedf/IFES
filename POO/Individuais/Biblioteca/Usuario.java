public class Usuario extends Pessoa {
    // ATRIBUTES
    private String email, cpf, senha;
    private boolean pendencias;
    private double saldo;
    // METHODS

    // SPECIAL METHODS
    public Usuario(String nome, String email, String cpf, String senha) {
        super(nome);
        setEmail(email);
        setCpf(cpf);
        setSenha(senha);
        this.pendencias = false;
        this.saldo = 0;
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
    private String getSenha() {
        return senha;
    }
    public void setSenha(String senha) {
        this.senha = senha;
    }
}