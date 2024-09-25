package exercise08;
public class Volume {
    private double v, r, a;

    public Volume(double r, double a) {
        this.setR(r);
        this.setA(a);
        this.setV();
    }
    public double getV() {
        return v;
    }
    public void setV() {
        this.v = (3.14195 * this.getR() * this.getR() * this.getA());
    }
    public double getR() {
        return r;
    }
    public void setR(double r) {
        this.r = r;
    }
    public double getA() {
        return a;
    }
    public void setA(double a) {
        this.a = a;
    }
}
