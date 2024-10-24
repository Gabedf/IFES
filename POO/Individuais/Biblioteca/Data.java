public class Data {
    // ATRIBUTES
    private int dia, mes, ano;

    // METHODS
    public void imprimir() {
        System.out.println(this.dia + "/" + this.mes + "/" + this.ano);
    }

    // SPECIAL METHODS
    public Data(int dia, int mes, int ano) {
        setDia(dia);
        setMes(mes);
        setAno(ano);
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
