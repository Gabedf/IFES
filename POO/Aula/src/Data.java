public class Data {
    // ATRIBUTES
    public int dia, mes, ano;

    // METHODS
    public void imprimir() {
        System.out.println(this.dia + "/" + this.mes + "/" + this.ano);
    }

    // SPECIAL METHODS
    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }
}
