public class Pessoa {
    // ATRIBUTES
    public String nome, cpf;
    public Data dtNasc;
    public char sexo;

    // METHODS
    public int idade(Data hoje) {
        if (hoje.mes < this.dtNasc.mes) {
            return (hoje.ano - this.dtNasc.ano) - 1;
        } else {return (hoje.ano - this.dtNasc.ano);}
    }

    // SPECIAL METHODS
    public Pessoa(String nome, String cpf, Data dtNasc, char sexo) {
        System.out.println("Nova pessoa criada no sistema.");
        this.nome = nome;
        this.dtNasc = dtNasc;
        this.cpf = cpf;
        this.sexo = sexo;
    }
}
