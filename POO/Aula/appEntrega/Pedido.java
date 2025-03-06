import java.util.ArrayList;
public class Pedido {
    // ATRIBUTOS
    private String cod;
    private Aluno cliente, entregador;
    private Sala s;
    private ArrayList<Item> carrinho;
    private boolean entregue;

    // METODOS ESPECIAIS
    public Pedido(String cod, Aluno cliente, Sala sala) {
        this.cod = cod;
        this.cliente = cliente;
        this.s = sala;
        this.carrinho = new ArrayList<Item>();
        this.entregue = false;
    }
    public void setCod(String c) {
        this.cod = c;
    }
    public String getCod() {
        return cod;
    }
    public Aluno getCliente() {
        return cliente;
    }
    public Aluno getEntregador() {
        return entregador;
    }
    public Sala getS() {
        return s;
    }
    public ArrayList<Item> getCarrinho() {
        return carrinho;
    }
    public boolean isEntregue() {
        return entregue;
    }
    public String getStatus() {
        if (this.entregue) {return "Entregue";}
        else {return "Em aberto";} 
    }

    // METODOS
    public String toString() {
        String resultado = "Código do Pedido: " + cod + "\n";
        resultado += "Cliente: " + cliente + "\n";
        resultado += "Sala: " + s + "\n";
        resultado += "Produtos:\n";
    
        for (Item item : carrinho) {
            resultado += " - " + item + "\n";
        }
    
        resultado += "Status: " + (entregue ? "Entregue" : "Em aberto") + "\n";
        resultado += String.format("Valor Total: R$%.2f\n", valorTotal());
    
        return resultado;
    }
    public String toString(boolean b) {
        String resultado = "Código do Pedido: " + cod + "\n";
        resultado += "Produtos:\n";
    
        for (Item item : carrinho) {
            resultado += item.getP().getCodigo() +": "+ item.getP().getNome() + " (QTD: " + item.getQtd() + ")\n";
        }
    
        resultado += "Status: " + (entregue ? "Entregue" : "Em aberto") + "\n";
        resultado += String.format("Valor Total: R$%.2f\n", valorTotal());
    
        return resultado;
    }
    public void atribuirEntregador(Aluno a) {
        if ((this.cliente != a) || (this.cliente == null)) {this.entregador = a;}
    }
    public boolean disponivel() {
        return !entregue && entregador == null;
    }
    public void adicionarItem(Produto produto, int qtd) {
        Item item = new Item(produto, qtd);
        this.carrinho.add(item);
    }
    public double valorTotal() {
        double total = 1.0; 
        for (Item item : this.carrinho) {
            total += item.valorTotal(); 
        }
        return total; 
    }
    public void marcarComoEntregue() {
        this.entregue = true;
    }
    public void confirmar() {
        for (Item item : this.carrinho) {
            item.getP().retirarDeEstoque(item.getQtd());;
        }
    }
    public int totalItens() {
        int total = 0;
        for (Item item : this.carrinho) {
            total += 1; 
        }
        return total;
    }
}
