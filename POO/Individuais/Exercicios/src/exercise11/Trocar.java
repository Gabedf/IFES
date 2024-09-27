package exercise11;
public class Trocar {
    // ATRIBUTES
    private int a, b;

    // METHODS
    public void swap() {
        int c;
        c = this.getA();
        this.setA(this.getB());
        this.setB(c);
    }

    public void infos() {
        System.out.println("\n# INFOS #");
        System.out.println("Valor de a: " + this.getA());
        System.out.println("Valor de b: " + this.getB());
    }

    // SPECIAL METHODS
    public Trocar(int a, int b) {
        this.setA(a);
        this.setB(b);
    }
    public int getA() {
        return a;
    }
    public void setA(int a) {
        this.a = a;
    }
    public int getB() {
        return b;
    }
    public void setB(int b) {
        this.b = b;
    }
}
