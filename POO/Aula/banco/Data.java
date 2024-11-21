import java.util.Scanner;
public class Data {
    // ATRIBUTES
    private int dia, mes, ano;

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

        System.out.print("Digite o dia: ");
        this.dia = s.nextInt();
        System.out.print("Digite o mes: ");
        this.mes = s.nextInt();
        System.out.print("Digite o ano: ");
        this.ano = s.nextInt();

    }   

    public Data(int dia, int mes, int ano) {
        this.setDia(dia);
        this.setMes(mes);
        this.setAno(ano);
    }
    public int getDia() {
        return dia;
    }
    public void setDia(int dia) {
        this.dia = dia;
    }
    public int getMes() {
        return mes;
    }
    public void setMes(int mes) {
        this.mes = mes;
    }
    public int getAno() {
        return ano;
    }
    public void setAno(int ano) {
        this.ano = ano;
    }
}
