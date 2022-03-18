# Projetos de Supercomputação do 1o. Semestre/2022

# Parte 1 - Heurística de Alinhamento Local de Smith-Waterman

Um algoritmo ingênuo para fazer o alinhamento local de duas sequencias de DNA. Uma heurística sequencial bastante interessante para reduzir o tempo de obtenção dos alinhamentos foi proposta por Smith e Waterman (1981), utilizando programação dinâmica.

Os passos diagonal, deleção e inserção são chamados, respectivamente, de salto em diagonal, salto de cima para baixo e salto da esquerda para a direita, e representam movimentações para obtenção do alinhamento local ótimo.

Para obter o alinhamento local ótimo, começamos com o maior valor na matriz (i,j). Então, nós vamos para trás para uma das posições (i-1,j), (i,j-1) ou (i-1,j-1), dependendo da direção de movimento usado para construir a matriz. Mantemos o processo até chegar a um célula da matriz com valor zero, ou o valor na posição (0,0).

Uma vez que tenhamos terminado, reconstruimos o alinhamento da seguinte forma: Começando com o último valor, chegamos a (i,j) usando o caminho previamente calculado. Um salto na diagonal implica que há um alinhamento (ou uma correspondência ou uma não correspondência). Um salto de cima para baixo implica que há uma deleção. Um salto da esquerda para a direita implica que há uma inserção.

Abaixo pode-se ver a saida do programa com duas Sequencias de DNA diferentes:

Sequencias AGCACACA e ACACACTA
![image](print_working_on_terminal2.png)

Sequencias GAAACTATCA e CTAAT-AGAGG-AAGGTAAGTGATG-C--ATACG-TC-TA
![image](print_working_on_terminal1.png)
