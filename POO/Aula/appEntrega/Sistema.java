import java.util.ArrayList;
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
}
