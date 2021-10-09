# PThread
1)Fibonacci ----> main(1).c

fib (n) = fib (n-1) + fib (n-2)

sendo que fib(0)=0 e fib(1)=1.

O que acontece se, de alguma forma, fossem calculados os termos dessa soma de forma paralela?

Para isso, construa a função fib() que receba o parâmetro n e utilize PThreads para realizar a soma dos termos em threads diferentes. Ao final, mostre o resultado dessa soma.

Como parte do experimento, faça a validação dos resultados calculando o valor de n de forma tradicional e comparando com o valor do n calculado com threads, medindo o tempo gasto com cada um desses cálculos. Use apenas o programa fibonacci.c para este experimento.

Entrega:
Submeta seu código aqui no GitHub e também um PDF com os prints da execução do seu código.

3)Números primos -----> main(2).c
Faça um programa usando PThreads que encontre todos os números primos até N; defina uma função no seu programa que receba 2 parâmetros J e K (individualmente ou por vetor), indicando o número de início e de fim dessa pequisa. O número de threads deve ser definido por argumento de linha de comando na chamada do programa ou por variável de ambiente (NTHREADS).

Entregas
Submeta seu código aqui no GitHub (vc vai criar um novo arquivo fonte) e também os prints (PDF) das evidências de execuções.
