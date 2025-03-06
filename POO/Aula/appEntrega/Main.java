public class Main {
    public static void main(String[] args) {
        Sistema sistema = new Sistema();
        Entrada entrada = new Entrada();
    
        sistema.carregarDados("dados.txt");  
    
        entrada.menu(sistema);
    
        sistema.salvarDados("dados.txt"); 
    }
    
}