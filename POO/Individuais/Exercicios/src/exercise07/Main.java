package exercise07;
public class Main {
    public static void main(String[] args) {
        Conversao temperature = new Conversao(58);
        System.out.println("A temperatura em Farenheit é: " + temperature.getFarenheit() + "\nA temperatura em Celcius é: " + temperature.convertFtoC());
    }
}
