import java.util.Scanner;
public class Data {
    // ATRIBUTES
    public int dia, mes, ano;

    // METHODS
    public void imprimir() {
        System.out.println(this.dia + "/" + this.mes + "/" + this.ano);
    }
    public boolean maior(Data d2) {
        if (this.ano > d2.ano) {
            return true;
        } else if (this.ano == d2.ano) {
            if (this.mes > d2.mes) {
                return true;
            } else if (this.mes == d2.mes) {
                if (this.dia > d2.dia) {
                    return true;
                }
            }
        }
        return false;
    }
    // SPECIAL METHODS
    public Data() {
        Scanner s = new Scanner(System.in);

        System.out.println("Digite o dia: ");
        this.dia = s.nextInt();
        System.out.println("Digite o mes: ");
        this.mes = s.nextInt();
        System.out.println("Digite o ano: ");
        this.ano = s.nextInt();

        s.close();
    }   

    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }
}
