import java.util.Scanner;
public class Funcionario {
    // ATRIBUTES
    protected String nome, cpf;
    protected double salario;
    protected Data dtNasc, dtContr;
    private static Scanner s = new Scanner(System.in);

    // SPECIAL METHODS
    public Funcionario() {
        if (this instanceof Gerente) {System.out.print("\n#---CRIACAO NOVO GERENTE---#\n");}
        else {System.out.print("\n#---CRIACAO NOVO FUNCIONARIO---#\n");}

        System.out.print("Digite o nome: ");
        this.nome = s.nextLine();
        
        System.out.print("Digite o CPF: ");
        this.cpf = s.nextLine();
        
        System.out.print("Digite o salario: ");
        this.salario = s.nextDouble();
        s.nextLine();
        System.out.println("Insira os dados da data de nascimento abaixo:");
        this.dtNasc = new Data();
        
        System.out.println("Insira os dados da data de contratacao abaixo:");
        this.dtContr = new Data();
    }
    public String getCpf() {
        return cpf;
    }

    // METHODS
    public void listarDados() {
        System.out.println("\n#---DADOS DO " + this.nome.toUpperCase() + "---#");
        System.out.println("Nome: " + this.nome);
        System.out.println("CPF: " + this.cpf);
        System.out.println("Salario: " + this.salario);
        System.out.print("Data nascimento: "); this.dtNasc.imprimir();
        System.out.print("Data contratacao: "); this.dtContr.imprimir();
    }
}
