import java.util.ArrayList;
import java.util.Scanner;
public class Gerente extends Funcionario {
    // ATRIBUTES
    private String senha;
    private ArrayList<Funcionario> equipe;
    private static Scanner s = new Scanner(System.in);

    // SPECIAL METHODS
    public Gerente() {
        super(); 
        System.out.print("Deseja criar uma senha?\n1 - Sim\n2 - Nao\nDigite: ");
        int r = s.nextInt();
        while (r != 1 && r != 2) {
            System.out.println("(Favor, inserir apenas '1' ou '2')");
            System.out.print("Deseja criar uma senha?\n1 - Sim\n2 - Nao\nDigite: ");
            r = s.nextInt();
        }
        if (r == 1) {
            s.nextLine();
            criarSenha();}
        this.equipe = new ArrayList<Funcionario>();
    }
    public void setSenha(String senha) {
        this.senha = senha;
    }
    protected String getSenha() {
        return this.senha;
    }
    public ArrayList<Funcionario> getEquipe() {
        return equipe;
    }

    // METHODS
    public void criarSenha() {
        if (this.getSenha() == null) {
            System.out.print("Digite sua senha: ");
            setSenha(s.nextLine());
        } else {System.out.println("Senha ja existente.");}
    }
    public boolean validarAcesso() {
        System.out.print("Digite sua senha: ");
        String psw = s.nextLine();

        if (psw.equals(this.getSenha())) {return true;}
        else {return false;}
    }
    public void alterarSenha() {
         if (validarAcesso()) {
            System.out.print("Digite sua senha: ");
            setSenha(s.nextLine());
         }
    }
    public double custoEquipe() {
        double custo = this.salario;
        for (int i = 0; i < this.equipe.size(); i++) {
            custo += equipe.get(i).salario;
        }
        return custo;
    }
    public void inserirFuncEquipe(Funcionario f) {
        this.equipe.add(f);
    }
    public void listarEquipe() {
        System.out.println("\n#---FUNCIONARIOS DA EQUIPE DO " + this.nome + "---#");
        System.out.println("0 - " + this.nome);
        for (int i = 0; i < this.equipe.size(); i++) {
            System.out.println((i+1) + " - " + equipe.get(i).nome);
        }
    }
}
