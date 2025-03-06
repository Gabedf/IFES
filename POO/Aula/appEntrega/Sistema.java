import java.util.ArrayList;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Sistema {
    // ATRIBUTOS
    private ArrayList<Aluno> alunos;
    private ArrayList<Admin> admins;
    private ArrayList<Produto> prods;
    private ArrayList<Pedido> pedidos;
    private ArrayList<Sala> salas;

    // METODOS ESPECIAIS
    public Sistema() {
        this.alunos = new ArrayList<Aluno>();
        this.admins = new ArrayList<Admin>();
        this.prods = new ArrayList<Produto>();
        this.pedidos = new ArrayList<Pedido>();
        this.salas = new ArrayList<Sala>();
    }

    // METODOS
    public void addAluno(Aluno a) {this.alunos.add(a);} 
    public void addAdmin(Admin adm) {this.admins.add(adm);} 
    public void addProd(Produto p) {
        this.prods.add(p);
        p.setCodigo(this.gerarCodigoProduto());
        } 
    public void addPedido(Pedido p) {
        this.pedidos.add(p);
        p.setCod(gerarCodigoPedido());
        } 
    public void addSala(Sala s) {this.salas.add(s);}

    public Aluno getAluno(String cpf) {
        for (Aluno a : this.alunos) {
            if (a.getCpf().equals(cpf)) {return a;}
        }
        return null;
    }
    public Admin getAdmin(String cpf) {
        for (Admin a : this.admins) {
            if (a.getCpf().equals(cpf)) {return a;}
        }
        return null;
    }
    public Produto getProduto(String cod) {
        for (Produto p : this.prods) {
            if (p.getCodigo().equals(cod)) {return p;}
        }
        return null;
    }
    public Pedido getPedido(String cod) {
        for (Pedido p : this.pedidos) {
            if (p.getCod().equals(cod)) {return p;}
        }
        return null;
    }
    public Sala getSala(String nome) {
        for (Sala s : this.salas) {
            if (s.getNome().equals(nome)) {return s;}
        }
        return null;
    }

    public boolean sistemaVazio() {
        return this.admins.isEmpty();
    }
    public String gerarCodigoProduto() {
        return "PROD-" + (this.prods.size());
    }
    public String gerarCodigoPedido() {
        return "PEDIDO-" + (this.pedidos.size());
    }
    public void listarProdutos() {
        for (Produto p : this.prods) {
            System.out.println(p.toString());
        }
    }
    public void listarSalas() {
        for (Sala s : this.salas) {
            System.out.println(s.getBloco() + s.getNome() + s.getAndar());
        }
    }
    public ArrayList<Pedido> filtrarPedidos(boolean disponivel) {
        ArrayList<Pedido> filtrados = new ArrayList<Pedido>();
        for (Pedido p : this.pedidos) {
            if (p.disponivel()) {
                filtrados.add(p);
            }
        }
        return filtrados;
    }
    public ArrayList<Pedido> filtrarPedidos(Aluno a) {
        ArrayList<Pedido> filtrados = new ArrayList<Pedido>();
        for (Pedido p : this.pedidos) {
            if (p.getCliente().equals(a)) {
                filtrados.add(p);
            }
        }
        return filtrados;
    }
    public void carregarDados(String caminhoArquivo) {
        try (BufferedReader br = new BufferedReader(new FileReader(caminhoArquivo))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                if (linha.equals("ADM")) {
                    String cpf = br.readLine();
                    String nome = br.readLine();
                    String senha = br.readLine();
                    String email = br.readLine();
                    Admin admin = new Admin(cpf, nome, senha, email);
                    this.addAdmin(admin);
                } else if (linha.equals("ALU")) {
                    String cpf = br.readLine();
                    String nome = br.readLine();
                    String senha = br.readLine();
                    Aluno aluno = new Aluno(cpf, nome, senha);
                    this.addAluno(aluno);
                } else if (linha.equals("FIM")) {
                    break;
                }
            }
            System.out.println("Dados carregados com sucesso!");
        } catch (IOException e) {
            System.out.println("Erro ao carregar o arquivo: " + e.getMessage());
        }
    }

    public void salvarDados(String caminhoArquivo) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(caminhoArquivo))) {
            for (Admin admin : this.admins) {
                bw.write("ADM\n");
                bw.write(admin.getCpf() + "\n");
                bw.write(admin.getNome() + "\n");
                bw.write(admin.getSenha() + "\n");
                bw.write(admin.getEmail() + "\n");
            }

            for (Aluno aluno : this.alunos) {
                bw.write("ALU\n");
                bw.write(aluno.getCpf() + "\n");
                bw.write(aluno.getNome() + "\n");
                bw.write(aluno.getSenha() + "\n");
            }

            bw.write("FIM\n");
            System.out.println("Dados salvos com sucesso!");
        } catch (IOException e) {
            System.out.println("Erro ao salvar o arquivo: " + e.getMessage());
        }
    }
}
