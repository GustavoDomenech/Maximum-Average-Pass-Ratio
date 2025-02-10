# Gustavo Donenech de Souza - Turma M1

# Maximum Average Pass Ratio
Você tem uma escola com turmas de alunos, onde cada turma possui um número mínimo de alunos que devem ser aprovados. A tarefa é distribuir um número de extraStudents (que sempre serão aprovados) para essas turmas de modo que a taxa média de aprovação seja maximizada.

A taxa de aprovação de uma turma é dada pela fórmula: taxa de aprovação = alunos aprovados / total de alunos
 
A taxa média de aprovação é a soma das taxas de aprovação de todas as turmas, dividida pelo número de turmas.
Você precisa calcular a maior taxa média de aprovação possível após distribuir os alunos extraStudents entre as turmas.

# Casos Testados:
classes = [[1,2],[3,5],[2,2]], extraStudents = 2
classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
classes = [[3,5],[1,9],[4,10],[2,8],[11,12],[26,30]], extraStudents =  7

# Problemas em Aula
Meu código em aula excedia o tempo limite para os testes, parava mais exatamente no teste 59, o fato de eu estar usando a função qsort a cada iteração do loop principal fazia com que o qsort, que tem custo O(n log n) fosse chanada toda vez que eu incrementava a quantidade de estudantes aprovados, o que transformava o custo em (extraStudents * n log n), um número muito grande de extraStudents resultava em um código mais custoso e que excedia o tempo limite.
