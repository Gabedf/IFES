package exercise03;
public class Store {
    // ATRIBUTOS
    private int qtd, codigo;
    private double price;
    private Seller seller;

    // MÉTODOS
    public double comissao(int codigo, int qtd, Seller seller) {
        this.setCodigo(codigo);
        return (seller.getSalary() + ((qtd * this.getPrice()) * 0.05));
    }

    public void infos(int codigo, int qtd, Seller seller) {
        System.out.println("*** ---------- *** ------------- ***");
        System.out.println("Nome vendedor: " + this.getSeller().getName());
        System.out.println("Cargo: " + this.getSeller().getNomeCargo());
        System.out.println("Salário: " + this.getSeller().getSalary());
        System.out.println("Salário pós vendas: " + this.comissao(codigo, qtd, seller));
    }
    
    // MÉTODOS ESPECIAS
    public int getQtd() {
        return qtd;
    }
    public void setQtd(int qtd) {
        this.qtd = qtd;
    }
    public int getCodigo() {
        return codigo;
    }
    public void setCodigo(int codigo) {
        this.codigo = codigo;
        this.setPrice();
    }
    public Seller getSeller() {
        return seller;
    }
    public void setSeller(Seller seller) {
        this.seller = seller;
    }
    public double getPrice() {
        return price;
    }
    public void setPrice() {
        switch (this.getCodigo()) {
            case 0:
                this.price = 10;
                break;
            case 1:
                this.price = 50;
                break;
            case 2: 
                this.price = 100;
                break;
            case 3:
                this.price = 150;
                break;
            case 4:
                this.price = 300;
                break;
            case 5:
                this.price = 100;
                break;
            default:
                break;
        }
    }
}
