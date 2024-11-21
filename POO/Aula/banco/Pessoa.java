import java.util.Scanner;
public class Pessoa {
    // ATRIBUTES
    protected String nome, cpf;
    protected Data dtNasc;
    protected char sexo;

    // METHODS
    public int idade(Data hoje) {
        if (hoje.getMes() < this.dtNasc.getMes()) {
            return (hoje.getAno() - this.dtNasc.getAno()) - 1;
        } else {return (hoje.getAno() - this.dtNasc.getAno());}
    }

    // SPECIAL METHODS
    public Pessoa() {
        Scanner s = new Scanner(System.in);
        System.out.print("\n# ---- CRIACAO NOVA PESSOA  ---- #\n");

        System.out.print("Digite o nome da pessoa: ");
        this.nome = s.nextLine();

        System.out.print("Digite o CPF  da pessoa: ");
        this.cpf = s.nextLine();

        System.out.print("Digite o sexo: ");
        this.sexo = s.nextLine().charAt(0);

        this.dtNasc = new Data();

    }

    public Pessoa(String nome, String cpf, Data dtNasc, char sexo) {
        System.out.println("Nova pessoa criada no sistema.");
        this.nome = nome;
        this.dtNasc = dtNasc;
        this.cpf = cpf;
        this.sexo = sexo;
    }
}
