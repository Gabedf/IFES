import java.util.Scanner;
public class Gerente extends Pessoa {
    // ATRIBUTES
    public String matricula, senha;

    // 
    public boolean validarAcesso(String s) {
        return s.equals(this.senha);
    }
    public boolean validarAcesso() {
        Scanner s = new Scanner(System.in);
        System.out.println("Digite sua senha: ");
        String senha = s.nextLine();
        s.close();

        return this.validarAcesso(senha);
    }

    // SPECIAL METHODS
    public Gerente() {
        super();
        Scanner s = new Scanner(System.in);

        System.out.println("Digite a matricula: ");
        this.matricula = s.nextLine();

        System.out.println("Digite a senha: ");
        this.senha = s.nextLine();

        s.close();
    }

    public Gerente(String nome, String cpf, Data dtNasc, char sexo, String m, String s) {
        super(nome, cpf, dtNasc, sexo);
        this.matricula = m;
        this.senha = s;
    }
}
