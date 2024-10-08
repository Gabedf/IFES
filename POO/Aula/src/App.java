public class App {
    public static void main(String[] args) {
        Data hoje = new Data(07, 10, 2024);
        Data np1 = new Data(12, 11, 2001);
        Data np2 = new Data(04, 03, 2004);

        Pessoa p1 = new Pessoa("Gabriel", "123.456.789-00", np1, 'F');
        Pessoa p2 = new Pessoa("Joao", "234.567.890-00", np2, 'M');
        
        Conta c1 = new Conta("1234-5", p1);
        Conta c2 = new Conta("2345-6", p2);
        
        c1.extrato();
        c2.extrato();
        
        c1.sacar(150);
        c1.transferir(100, c2);
        c1.sacar(100);
        c1.depositar(100);
        c1.transferir(200, c2);
        
        for (int i = 1; i <= 120; i += 1) {
            c1.chequeEspecial(0.5);
        
            if (i % 30 == 0) {
                System.out.println(
                    "Saldo apos " + i + " dias: " + c1.saldo
                );
            }
        }   
        System.out.println(p1.idade(hoje));
    }
}
