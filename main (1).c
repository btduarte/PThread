#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4
#define NUM_PRIMOS_MAX 50000

//Barbara Duarte - 4161519-0
//Matehus Morais - 4199569-4

void *thread_function(void *arg);
char message[] = "Numeros primos"; // variavel global
int numVerificado = 2;
int qtdPrimos = 0;
pthread_mutex_t mutex;

int testarPrimo(int x){

    int maxDiv = sqrt(x);
    for (int i = 2; i <= maxDiv; i++) {
        if (x % i == 0) { 
            return 0;
        }
    }
    return 1;
}

void *thread_function(void *arg) { 
    int numAux, qtdPrimosAux = 0;
    pthread_mutex_lock(&mutex);
    
    while(numVerificado <= NUM_PRIMOS_MAX){
        numAux = numVerificado;
        ++numVerificado;
        pthread_mutex_unlock(&mutex);
        qtdPrimosAux += testarPrimo(numAux);
        pthread_mutex_lock(&mutex);
    }
    qtdPrimos += qtdPrimosAux;
    pthread_mutex_unlock(&mutex);
}

int main() {
    int res;
    pthread_t a_thread[NUM_THREADS];
    void *thread_result;

    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i <= NUM_THREADS; i++){
        res = pthread_create(&a_thread[i], NULL, thread_function, (void *)message);
        if (res != 0) {
            perror("Erro na criação de Thread");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i <= NUM_THREADS; i++){
        res = pthread_join(a_thread[i], &thread_result);

        if (res != 0) {
            perror("Erro");
            exit(EXIT_FAILURE);
        }
    }   

    printf("Quantidade de primos eh: %d\n", qtdPrimos);

    exit(EXIT_SUCCESS);
}