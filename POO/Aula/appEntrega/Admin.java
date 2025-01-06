public class Admin extends Usuario {
    // ATRIBUTOS
    private String email;

    // METODOS ESPECIAIS
    public Admin(String cpf, String nome, String senha, String email) {
        super(cpf, nome, senha);
        this.email = email;
    }

    // METODOS
    public String toString() {
        return super.toString() + "(ADMIN)";
    }
}