import java.util.ArrayList;
import java.util.Scanner;
public class Banco {
    public static int menuInicial() {
        Scanner s = new Scanner(System.in);
        System.out.println("#--------ESCOLHA A OPCAO--------#");
        System.out.println("0 - Fechar opcoes\n1 - Cadastro\n2 - Movimentacoes financeiras");
        int v = s.nextInt();
        return v;
        }
    public static void menuCadastro(ArrayList<Pessoa> p, ArrayList<Gerente> g, ArrayList<Conta> c) {
        Scanner s = new Scanner(System.in);
        System.out.println("#--------ESCOLHA A OPCAO--------#");
        System.out.println("0 - Fechar opcoes\n1 - Adicionar pessoa\n2 - Adicionar gerente\n3 - Criar conta corrente\n4 - Criar poupança");
        int v = s.nextInt();
        
        if (v == 1) {p.add(new Pessoa());}
        if (v == 2) {g.add(new Gerente());}
        if (v == 3 || v == 4) {
            
        }
        {c.add(new ContaCorrente());}
        if () {c.add(new Poupanca());}

    }
    public static void menuMovimentacoes() {
        System.out.println("oi");
    }
    public static void main(String[] args) {
        ArrayList<Pessoa> p = new ArrayList<>();
        ArrayList<Gerente> g = new ArrayList<>();
        ArrayList<Conta> c = new ArrayList<>();

        int v = menuInicial();
        while (v != 0) {
            if (v == 1) {menuCadastro(null, null, null);}
            if (v == 2) {menuMovimentacoes();}

            v = menuInicial();
        }
    }
}