import java.util.ArrayList;
import java.util.Scanner;

public class Empresa {
    // ATRIBUTES
    private ArrayList<Funcionario> funcionarios;
    private ArrayList<Gerente> gerentes;
    public static Scanner s = new Scanner(System.in);

    // SPECIAL METHODS
    public Empresa() {
        this.funcionarios = new ArrayList<Funcionario>();
        this.gerentes = new ArrayList<Gerente>();
    }
    public ArrayList<Gerente> getGerentes() {
        return this.gerentes;
    }
    public ArrayList<Funcionario> getFuncionarios() {
        return this.funcionarios;
    }
    // METHODS
    public void folhaDePagamento() {
        double custoTotal = 0;
        for (int i = 0; i < this.funcionarios.size(); i++) {
            custoTotal += funcionarios.get(i).salario;
            System.out.println("Salario funcionario " + funcionarios.get(i).nome + ": " + funcionarios.get(i).salario);
        }
        for (int i = 0; i < this.gerentes.size(); i++) {
            custoTotal += gerentes.get(i).salario;
            System.out.println("Salario gerente " + gerentes.get(i).nome + ": " + gerentes.get(i).salario);
            System.out.println("Custo equipe: " + gerentes.get(i).custoEquipe() + "\n");
        }
        System.out.println("Custo mensal salarios empresa: " + custoTotal); 
    }
    public void contratarFuncionario() {
        Funcionario f = new Funcionario();
        this.funcionarios.add(f);
    }
    public void contratarGerente() {
        Gerente g = new Gerente();
        this.gerentes.add(g);
    }
    public Funcionario funcionarioMaisAntigo() {
        Funcionario f = funcionarios.get(0);
        for (int i = 0; i < funcionarios.size(); i++) {
            int r = f.dtContr.comparar(funcionarios.get(i).dtContr);
            if (r == 1) {f = funcionarios.get(i);}
        }
        return f;
    }
    public Funcionario funcionarioMaisVelho() {
        Funcionario f = funcionarios.get(0);
        for (int i = 0; i < funcionarios.size(); i++) {
            int r = f.dtNasc.comparar(funcionarios.get(i).dtNasc);
            if (r == 1) {f = funcionarios.get(i);}
        }
        return f;
    }
    private Funcionario localizarFuncionarioPorCPF(String cpf) {
        for (Funcionario f : funcionarios) { 
            if (f.getCpf().equals(cpf)) { 
                return f; 
            }}
        return null;
    }
    private Gerente localizarGerentePorCPF(String cpf) {
        for (Gerente g : gerentes) { 
            if (g.getCpf().equals(cpf)) { 
                return g; 
            }}
        return null;
    }
    public void atribuirFuncGer() {
        System.out.println("\n#---ATRIBUICAO FUNCIONARIO A EQUIPE DO GERENTE---#");
        System.out.print("Digite o CPF do funcionario: "); 
        Funcionario f = localizarFuncionarioPorCPF(s.nextLine());

        System.out.print("Digite o CPF do gerente: "); 
        Gerente g = localizarGerentePorCPF(s.nextLine());

        if (f != null && g != null) {g.inserirFuncEquipe(f);}
    }
}
