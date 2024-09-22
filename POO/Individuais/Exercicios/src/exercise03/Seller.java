package exercise03;
public class Seller {
    // ATRIBUTOS
    private double salary;
    private int id, cargo;
    private String name, nomeCargo;

    // MÉTODOS ESPECIAIS
    public Seller(int id, String name) {
        this.setId(id);
        this.setCargo(id);
        this.setName(name);
        this.setNomeCargo();
        this.setSalary();
    }
    public double getSalary() {
        return salary;
    }
    public void setSalary() {
        switch (this.getCargo()) 
        {
            case 1:
                this.salary = 1200; 
                break;
            case 2:
                this.salary = 2500;
                break;
            case 3:
                this.salary = 5000;
                break;
            case 4:
                this.salary = 10000;
                break;
            default:
                break;
        };
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getCargo() {
        return cargo;
    }
    public void setCargo(int cargo) {
        this.cargo = cargo;
    }
    public String getNomeCargo() {
        return nomeCargo;
    }
    public void setNomeCargo() {
        switch (this.getCargo()) 
        {
            case 1:
                this.nomeCargo = "Junior"; 
                break;
            case 2:
                this.nomeCargo = "Pleno";
                break;
            case 3:
                this.nomeCargo = "Senior";
                break;
            case 4:
                this.nomeCargo = "Master";
                break;
            default:
                break;
        };
    }
}
