package exercise15;

public class Boletim {
    // ATRIBUTES
    private Aluno aluno;

    // METHDOS
    public void resultadoFinal() {
        for (Notas nota : this.getAluno().getNotas()) {
            double result = nota.getAtv1() + nota.getAtv2() + nota.getP1() + nota.getP2();
            if (result >= 70) {
                System.out.println("Parabens, aluno aprovado!\nNota final em " + nota.getNome() + ": " + result + " pontos!\n");
            }
            else if(result > 50) {
                System.out.println("Aluno em recuperacao final.\nNota final em " + nota.getNome() + ": " + result + " pontos!\n");
            }
            else {
                System.out.println("Aluno reprovado automaticamente!.\nNota final em " + nota.getNome() + ": " + result + " pontos!\n");
            }
            
        }
    }
    public void mostrarNotas() {
        System.out.println("\nALUNO: " + this.getAluno().getNome());
        for (Notas nota : this.getAluno().getNotas()) {
            System.out.println(nota.getNome());
            System.out.println("Atividade 1: " + nota.getAtv1());
            System.out.println("Atividade 2: " + nota.getAtv2());
            System.out.println("Prova 1: " + nota.getP1());
            System.out.println("Prova 2: " + nota.getP2() + "\n");
        }
    }

    // SPECIAL METHODS
    public Boletim(Aluno aluno) {
        this.setAluno(aluno);
    }
    public Aluno getAluno() {
        return aluno;
    }
    public void setAluno(Aluno aluno) {
        this.aluno = aluno;
    }    
}
