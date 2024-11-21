public class Main {
    public static void main(String[] args) 
    {
        // CRIANDO EMPRESA 
        Empresa partnerSolutions = new Empresa();

        // 5 FUNCIONARIOS INICIAS E SEU GERENTE (sem senha)
        partnerSolutions.contratarGerente();
        for (int i = 0; i < 1; i++) {
            partnerSolutions.contratarFuncionario();
            partnerSolutions.atribuirFuncGer();
        } 
        
        // 5 FUNCIONARIOS (segunda vez) E SEU GERENTE (com senha) & ALTERANDO SENHA
        partnerSolutions.contratarGerente();
        for (int i = 0; i < 1; i++) {
            partnerSolutions.contratarFuncionario();
            partnerSolutions.atribuirFuncGer();
        }
        System.out.println("\n#---ALTERACAO DA SENHA---#");
        partnerSolutions.getGerentes().get(1).alterarSenha();

        // DADOS FUNCIONARIO MAIS ANTIGO
        System.out.print("\n#---DADOS FUNCIONARIO MAIS ANTIGO---#");
        Funcionario f = partnerSolutions.funcionarioMaisAntigo();
        f.listarDados();

        // DADOS FUNCIONARIO MAIS VELHO
        System.out.print("\n#---DADOS FUNCIONARIO MAIS VELHO---#");
        Funcionario f1 = partnerSolutions.funcionarioMaisVelho();
        f1.listarDados();

        // CUSTO MENSAL
        System.out.println("\n#---FOLHA PAGAMENTO FUNCIONARIOS---#");
        partnerSolutions.folhaDePagamento();
    }
}
