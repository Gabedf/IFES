<!DOCTYPE html>
<html lang="pt-br">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Simulação de Gerenciamento de Exames Médicos</title>
</head>
<body>

<h1>Simulação de Gerenciamento de Exames Médicos</h1>

<p>Este projeto implementa uma simulação de gerenciamento de exames médicos em um hospital. Ele utiliza filas de prioridade para gerenciar pacientes e alocar máquinas de exame disponíveis. A simulação é contínua e opera em um ambiente 24/7, alocando pacientes e gerando relatórios de condição.</p>

<h2>Estrutura do Projeto</h2>

<h3>1. Include (Headers)</h3>
<ul>
  <li><strong>condition.h:</strong> Define funções relacionadas à determinação da condição dos pacientes.</li>
  <li><strong>examNode.h:</strong> Define a estrutura de dados para os nós de exames.</li>
  <li><strong>examPriority.h:</strong> Define a estrutura e as funções para a fila de prioridade de exames.</li>
  <li><strong>machineManager.h:</strong> Define a estrutura e as funções para gerenciar as máquinas de exames.</li>
  <li><strong>oftenReport.h:</strong> Define funções para a geração frequente de relatórios.</li>
  <li><strong>patient.h:</strong> Define a estrutura de dados para os pacientes.</li>
  <li><strong>report.h:</strong> Define funções relacionadas à geração de relatórios.</li>
</ul>

<h3>2. Src (Source Files)</h3>
<ul>
  <li><strong>condition.c:</strong> Implementa funções para determinar a condição dos pacientes após os exames.</li>
  <li><strong>examPriority.c:</strong> Implementa a fila de prioridade de exames.</li>
  <li><strong>machine_manager.c:</strong> Implementa o gerenciamento das máquinas de exames, incluindo a alocação de pacientes.</li>
  <li><strong>patientQueue.c:</strong> Implementa a fila de pacientes e funções para gerenciar a inserção e remoção de pacientes.</li>
  <li><strong>report.c:</strong> Implementa a geração de relatórios e o armazenamento dos resultados.</li>
</ul>

<h3>3. Arquivos de Dados</h3>
<ul>
  <li><strong>db_exam.txt:</strong> Armazena informações sobre os exames realizados.</li>
  <li><strong>db_patient.txt:</strong> Armazena informações sobre os pacientes.</li>
  <li><strong>db_report.txt:</strong> Armazena os relatórios gerados após a conclusão dos exames.</li>
</ul>

<h3>4. Outros Arquivos</h3>
<ul>
  <li><strong>main.c:</strong> Contém a função principal que executa a simulação.</li>
  <li><strong>Makefile:</strong> Arquivo de automação para compilar o projeto.</li>
</ul>

<h2>Escolha das Estruturas de Dados</h2>
<p>Foi escolhida a utilização de filas ao longo do programa por uma questão de simplicidade e familiaridade com esse tipo de estrutura. As filas permitem gerenciar de forma eficiente a ordem de atendimento dos pacientes, a alocação de máquinas e a prioridade dos exames, o que é essencial para a simulação realista de um ambiente hospitalar.</p>

<h2>Como Executar o Projeto</h2>

<h3>Compilação</h3>
<p>Para compilar o projeto, execute o seguinte comando no terminal:</p>
<pre><code>make</code></pre>

<h3>Execução</h3>
<p>Após a compilação, para executar o programa, utilize:</p>
<pre><code>make run</code></pre>

<h2>Funcionamento do Programa</h2>
<p>O programa simula a operação de um hospital onde pacientes chegam aleatoriamente e são alocados em máquinas para realizar exames. A cada unidade de tempo, há uma chance de chegada de novos pacientes. As condições dos pacientes são determinadas com base nos exames realizados e os resultados são armazenados em arquivos de texto para análise posterior.</p>

<p><em>By Gabriel Leite Fonseca</em></p>

</body>
</html>
