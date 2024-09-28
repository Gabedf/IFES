package exercise15;
import java.util.Scanner;

public class Escola {
    public static void main(String[] args) {
        // CRIAÇÃO ALUNO 
        Scanner scann = new Scanner(System.in);
        System.out.print("Digite o nome do aluno: ");
        String nome = scann.nextLine();
        Aluno a1 = new Aluno(nome);

        // NOTAS
        Notas matematica = new Notas("Matemática");
        Notas fisica = new Notas("Física");
        Notas quimica = new Notas("Quimica");
        Notas biologia = new Notas("Biologia");
        Notas estatistica = new Notas("Estatistica");


        matematica.addNotas(10, 20, 20, 12);
        fisica.addNotas(25, 10, 9, 15);
        quimica.addNotas(9, 4, 12, 20);
        biologia.addNotas(6, 12, 13, 24);
        estatistica.addNotas(25, 20, 24, 23);
    

        // NOTAS ALUNOS
        a1.addNota(matematica);
        a1.addNota(fisica);
        a1.addNota(quimica);
        a1.addNota(biologia);
        a1.addNota(estatistica);

        // BOLETIM
        Boletim boletimA1 = new Boletim(a1);

        // RESULTADO FINAL
        boletimA1.mostrarNotas();
        System.out.println("# -------------- # -------------- #\n");
        boletimA1.resultadoFinal();

        scann.close();
    }
}
