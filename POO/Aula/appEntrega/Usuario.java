public class Usuario {
    // ATRIBUTOS
    protected String cpf, nome;
    private String senha;

    // METODOS ESPECIAIS
    public Usuario(String cpf, String nome, String senha) {
        this.cpf = cpf;
        this.nome = nome;
        this.senha = senha;
    }
    public String toString() {
        return nome + " - CPF: " + cpf;
    }
    public String getCpf() {
        return cpf;
    }
    public String getNome() {
        return nome;
    }
    public String getSenha() {
        return senha;
    }
    // METODOS
    public void criarSenha(String psw) {
        if (this.senha == null) {
            this.senha = psw;
        } else {System.out.println("Senha ja existente.");}
    }
    public boolean validarAcesso(String psw) {
        return psw.equals(this.senha);
    }
    public boolean alterarSenha(String newPsw, String psw) {
        if (validarAcesso(psw)) {
            this.senha = newPsw;
           return true;
        } else {return false;}
   }
}
