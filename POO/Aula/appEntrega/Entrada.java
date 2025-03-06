import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.NoSuchElementException;
/**
 * Classe com rotinas de entrada e saída
 * @author Hilario Seibel Junior
 */
public class Entrada {
/**
     * Classe com as rotinas de entrada e saída do projeto
     * @author Hilario Seibel Junior e <seu nome aqui>
     */

    public Scanner input;

    /**
     * Construtor da classe InputOutput
     * Se houver um arquivo input.txt, define que o Scanner vai ler deste arquivo.
     * Se o arquivo não existir, define que o Scanner vai ler da entrada padrão (teclado)
     */
    public Entrada() {
        try {
            // Se houver um arquivo input.txt na pasta corrente, o Scanner vai ler dele.
            this.input = new Scanner(new FileInputStream("entrada.txt")).useLocale(Locale.US);
            // NAO ALTERE A LOCALICAÇÃO DO ARQUIVO!!
        } catch (FileNotFoundException e) {
            // Caso contrário, vai ler do teclado.
            this.input = new Scanner(System.in).useLocale(Locale.US);
        }
    }

    /**
     * Faz a leitura de uma linha inteira
     * Ignora linhas começando com #, que vão indicar comentários no arquivo de entrada:
     * @param msg: Mensagem que será exibida ao usuário
     * @return Uma String contendo a linha que foi lida
     */
    private String lerLinha(String msg) {
        // Imprime uma mensagem ao usuário, lê uma e retorna esta linha
        System.out.print(msg);
        String linha = this.input.nextLine();

        // Ignora linhas começando com #, que vão indicar comentários no arquivo de entrada:
        while (linha.charAt(0) == '#') linha = this.input.nextLine();
        return linha;
    }
    
    /**
     * Faz a leitura de um número inteiro
     * @param msg: Mensagem que será exibida ao usuário
     * @return O número digitado pelo usuário convertido para int
     */
    public int lerInteiro(String msg) {
        while (true) {
            try {
                String linha = this.lerLinha(msg); // Usa lerLinha para ignorar comentários
                return Integer.parseInt(linha);
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida. Digite um número inteiro.");
            }
        }
    }
    /**
     * Faz a leitura de um ponto flutuante
     * @param msg: Mensagem que será exibida ao usuário
     * @return O número digitado pelo usuário convertido para double
     */

     public double lerDouble(String msg) {
        while (true) {
            try {
                System.out.print(msg);
                return Double.parseDouble(input.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Entrada inválida. Digite um número decimal.");
            }
        }
    }
    private Sala lerSala(Sistema s) {
        s.listarSalas();
        String nomeSala = this.lerLinha("\nDigite o nome da sala: ");         
        Sala sala = s.getSala(nomeSala); 
        return sala;
    }
    public Item lerItem(Sistema s) {
        Produto produto = null;
        while (produto == null) {
            s.listarProdutos();
            String codProduto = this.lerLinha("\nDigite o código do produto: ");
            if (codProduto == null) { 
                System.out.println("Operação cancelada.");
                return null;
            }
    
            produto = s.getProduto(codProduto);
    
            if (produto == null) {
                System.out.println("Produto não encontrado. Tente novamente.");
            }
        }
    
        int quantidade = -1;
        while (quantidade <= 0 || quantidade > produto.getQtd()) {
            quantidade = this.lerInteiro("\nDigite a quantidade desejada (máximo " + produto.getQtd() + "): ");
            if (quantidade <= 0 || quantidade > produto.getQtd()) {
                System.out.println("Quantidade inválida. Tente novamente.");
            }
        }
    
        return new Item(produto, quantidade);
    }
    
    
    // MENU SISTEMA
    public void menu(Sistema s) {
        if (s.sistemaVazio()) {this.cadAdmin(s);}

        while (true) {
            String msg = "\n*********************\n" +
            "Escolha uma opção:\n" +
            "1) Login.\n" +
            "0) Sair.\n";
            int opcao = this.lerInteiro(msg);
            
            switch (opcao) {
                case 1:
                    this.login(s);
                    break;
                case 0:
                    System.out.println("Encerrando sistema.");
                    return;
                default:
                    System.out.println("Opção inválida.");
            }
        }
    }
    public void login (Sistema s) {
        while (true) {
            String cpf = this.lerLinha("\nDigite seu CPF: ");
            String senha = this.lerLinha("\nDigite sua senha: ");
    
            // ADM 
            Admin admin = s.getAdmin(cpf);
            if (admin != null && admin.validarAcesso(senha)) {
                this.menu(admin, s);
                return;
            }
    
            // ALUNO
            Aluno aluno = s.getAluno(cpf);
            if (aluno != null && aluno.validarAcesso(senha)) {
                this.menu(aluno, s);
                return;
            }

            System.out.println("CPF ou senha inválidos.");
           }
        }

        // MENU ADM
        public void menu(Admin a, Sistema s) {
            while (true) {
                String msg = "\n*********************\n" +
                "Escolha uma opção:\n" +
                "1) Cadastrar novo administrador.\n" +
                "2) Cadastrar aluno.\n" +
                "3) Cadastrar produto.\n" +
                "4) Cadastrar sala.\n" +
                "0) Logout.\n";
                int opcao = this.lerInteiro(msg);

                if (opcao == 1) {this.cadAdmin(s);}
                if (opcao == 2) {this.cadAluno(s);}
                if (opcao == 3) {this.cadProduto(s);} 
                if (opcao == 4) {this.cadSala(s);}
                if (opcao == 0) {break;}
            }
        }
        public void cadAdmin(Sistema s) {
            String cpf = this.lerLinha("\nDigite o CPF: ");
            String nome = this.lerLinha("\nDigite o nome: ");
            String senha = this.lerLinha("\nDigite a senha: ");
            String email = this.lerLinha("\nDigite o email: ");
            Admin admin = new Admin(cpf, nome, senha, email);
            s.addAdmin(admin);
            System.out.println("Usuário " + admin.toString() + " criado com sucesso.");
        }
        public void cadAluno(Sistema s) {
            String cpf = this.lerLinha("\nDigite o CPF: ");
            String nome = this.lerLinha("\nDigite o nome: ");
            String senha = this.lerLinha("\nDigite a senha: ");
            Aluno aluno = new Aluno(cpf, nome, senha);
            s.addAluno(aluno);
            System.out.println("Usuário " + aluno.toString() + " criado com sucesso.");
        }
        public void cadProduto(Sistema s) {
            String nome = this.lerLinha("\nInsira o nome do produto: ");
            int qtd = this.lerInteiro("\nInsira a quantidade: ");
            double vlaor = this.lerDouble("\nInsira o valor do produto: ");
            Produto p = new Produto(nome, qtd, vlaor);
            s.addProd(p);
            System.out.println("Produto adicionado ao sistema.");
        }
        public void cadSala(Sistema s) {
            String bloco = this.lerLinha("\nInsira o bloco: ");
            String sala = this.lerLinha("\nInsira a sala: ");
            String andar = this.lerLinha("\nInsira o andar: ");
            Sala room = new Sala(bloco, sala, andar);
            s.addSala(room);
            System.out.println("Sala adicionada ao sistema.");
        }

        // MENU ALUNO
        public void menu(Aluno a, Sistema s) {
            while (true) {
                String msg = "\n*********************\n" +
                "Escolha uma opção:\n" +
                "1) Fazer pedido.\n" +
                "2) Fazer entrega.\n" +
                "3) Meus pedidos.\n" +
                "4) Inserir crédito.\n" +
                "0) Logout.\n";

                int opcao = this.lerInteiro(msg);
    
                if (opcao == 1) {this.fazerPedido(a, s);}
                if (opcao == 2) {this.entregarPedido(a, s);}
                if (opcao == 3) {this.listarPedido(a, s);} 
                if (opcao == 4) {this.inserirCredito(a, s);}
                if (opcao == 0) {return;}
            }
        }
        public void fazerPedido(Aluno a, Sistema s) {
            Sala sala = this.lerSala(s);
            Pedido pedido = new Pedido(s.gerarCodigoPedido(), a, sala);
        
            while (true) {
                String msg = "\n*********************\n" +
                        "Escolha uma opção:\n" +
                        "1) Inserir produto no carrinho.\n" +
                        "2) Fechar pedido.\n";
                int escolha = this.lerInteiro(msg);
        
                if (escolha == 1) {
                    Item item = this.lerItem(s);
                    if (item == null) {  
                        System.out.println("Operação cancelada ao adicionar item.");
                        return;
                    }
        
                    if (item.getQtd() <= item.getP().getQtd()) {
                        pedido.adicionarItem(item.getP(), item.getQtd());
                        System.out.println("Produto adicionado ao carrinho com sucesso!");
                    } else {
                        System.out.println("Quantidade superior ao estoque. Operação cancelada.");
                    }
                } else if (escolha == 2) {
                    if (pedido.getCarrinho().isEmpty()) {
                        System.out.println("Carrinho vazio. Pedido cancelado.");
                        return;
                    }
        
                    if (a.retirarSaldo(pedido.valorTotal())) {
                        pedido.confirmar();
                        s.addPedido(pedido);
                        System.out.println("Pedido concluído!");
                        return;
                    } else {
                        System.out.println("Saldo insuficiente. Pedido cancelado.");
                        return;
                    }
                } else {
                    System.out.println("Opção inválida. Tente novamente.");
                }
            }
        }
        
        public void entregarPedido(Aluno a, Sistema s) {
            ArrayList<Pedido> pedidosDisponiveis = s.filtrarPedidos(true);
            System.out.println("\n#---LISTAGEM PEDIDOS DISPONIVEIS---#");
            for (Pedido pedido : pedidosDisponiveis) {
                System.out.println(pedido.toString());
            }
        
            String escolha = this.lerLinha("\nDigite o codigo do pedido: ");
            if (escolha == null) { // Verifica se houve cancelamento ou erro na leitura
                System.out.println("Operação cancelada.");
                return;
            }
        
            Pedido pedido = s.getPedido(escolha);
            if (pedido == null) { // Verifica se o pedido foi encontrado
                System.out.println("Pedido não encontrado. Operação cancelada.");
                return;
            }
        
            pedido.atribuirEntregador(a);
            pedido.marcarComoEntregue();
            System.out.println("Pedido " + pedido.getCod() + " entregue com sucesso!");
        }
        
        public void listarPedido(Aluno a, Sistema s) {
            ArrayList<Pedido> pedidosAluno = s.filtrarPedidos(a);
        
            if (pedidosAluno == null || pedidosAluno.isEmpty()) {
                System.out.println("Nenhum pedido encontrado.");
                return;
            }
        
            // Ordena os pedidos conforme a quantidade de produtos diferentes e valor total
            pedidosAluno.sort((p1, p2) -> {
                int qtdProdutosDiferentesP1 = p1.getCarrinho().size();
                int qtdProdutosDiferentesP2 = p2.getCarrinho().size();
        
                if (qtdProdutosDiferentesP1 != qtdProdutosDiferentesP2) {
                    return Integer.compare(qtdProdutosDiferentesP2, qtdProdutosDiferentesP1);
                }
        
                return Double.compare(p2.valorTotal(), p1.valorTotal());
            });
        
            System.out.println(a.toString());
            System.out.println("*");
        
            for (Pedido pedido : pedidosAluno) {
                System.out.println("Código do Pedido: " + pedido.getCod());
        
                List<Item> itensOrdenados = new ArrayList<>(pedido.getCarrinho());
                itensOrdenados.sort((i1, i2) -> Integer.compare(i2.getQtd(), i1.getQtd()));
        
                System.out.println("Produtos:");
                for (Item item : itensOrdenados) {
                    System.out.printf(item.toString(true) + "\n");
                }
        
                System.out.println("Status: " + pedido.getStatus());
                System.out.printf("Valor Total: R$%.2f\n", pedido.valorTotal());
                System.out.println("*");
            }
        }
        
        public void inserirCredito(Aluno a, Sistema s) {
            double valor = -1;
            while (valor <= 0) {
                valor = this.lerDouble("\nDigite o valor a ser inserido (valor positivo): ");
                if (valor <= 0) {
                    System.out.println("Valor inválido. Por favor, insira um valor maior que 0.");
                }
            }
            
            a.inserirSaldo(valor);
        } 
}
