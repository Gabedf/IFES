# Calculadora de Juros Compostos

Este repositório contém o código de uma **Calculadora de Juros Compostos**, com funcionalidades que permitem ao usuário calcular o montante final de um investimento, levando em consideração a taxa de juros, tempo de aplicação, e contribuições periódicas. O programa também pode exibir um gráfico de evolução do montante ao longo do tempo.

## Estrutura do Repositório

### **Calculator.py** - Classe principal da calculadora

O arquivo `calculator.py` contém a classe `Calculator`, que possui os métodos necessários para realizar o cálculo do montante final, simular contribuições periódicas e gerar o gráfico do crescimento do investimento.

- **Métodos:**
  - `tipoTempo`: Define a unidade de tempo (ano, mês ou dia) para o cálculo.
  - `calcularMontanteFinal`: Calcula o montante final do investimento sem contribuições periódicas.
  - `simularContribuicoes`: Calcula o montante final levando em consideração as contribuições periódicas.
  - `plotarGrafico`: Gera um gráfico mostrando a evolução do montante ao longo do tempo.

### **Graphics.py** - Função de Exibição de Gráfico

O arquivo `graphics.py` contém a função `plotar_grafico`, que é responsável por gerar e exibir um gráfico mostrando a evolução do montante ao longo do tempo.

### **Main.py** - Arquivo Principal

O arquivo `main.py` é o ponto de entrada do programa. Ele permite a interação com o usuário, oferecendo um menu de opções para:
1. Definir a unidade de tempo (ano, mês ou dia).
2. Calcular o montante final sem contribuições.
3. Simular o montante com contribuições periódicas.
4. Exibir o gráfico de evolução do investimento.
5. Encerrar o programa.

## Como Usar

1. Clone este repositório para sua máquina local.
2. Instale a biblioteca `matplotlib` para gerar gráficos:

```bash
pip install matplotlib
