import java.util.Scanner;
public class Gerente extends Pessoa {
    // ATRIBUTES
    private String matricula, senha;

    // METHODS
    public boolean validarAcesso(String s) {
        return s.equals(this.senha);
    }
    public boolean validarAcesso() {
        Scanner s = new Scanner(System.in);
        System.out.print("\nDigite sua senha: ");
        String senha = s.nextLine();

        return this.validarAcesso(senha);
    }

    // SPECIAL METHODS
    public Gerente() {
        super();
        Scanner s = new Scanner(System.in);

        System.out.print("Digite a matricula: ");
        this.setMatricula(s.nextLine());

        System.out.print("Digite a senha: ");
        this.setSenha(s.nextLine());

    }

    public Gerente(String nome, String cpf, Data dtNasc, char sexo, String m, String s) {
        super(nome, cpf, dtNasc, sexo);
        this.setMatricula(m);
        this.setSenha(s);
    }
    public String getMatricula() {
        return matricula;
    }
    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }
    public void setSenha(String senha) {
        this.senha = senha;
    }
}