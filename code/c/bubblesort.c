#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int vetor[], int TAMANHO_VETOR) {
	int i, j;
	int aux;
	
	for(i = 0; i < TAMANHO_VETOR; i++){
		for(j = TAMANHO_VETOR - 1; j > i; j--){
			if(vetor[j] < vetor[j - 1]){
				aux = vetor[j];
				vetor[j] = vetor[j - 1];
				vetor[j - 1] = aux;
			}
		}
	}
}

int main(){
	srand(time(NULL));
	int TAMANHO_VETOR = 10;
	int i;
	
	int vetor[TAMANHO_VETOR];
	
	for (i = 0; i < TAMANHO_VETOR; i++) {
		vetor[i] = rand() % 100;
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
	
	bubblesort(vetor, TAMANHO_VETOR);
	
	for(i = 0; i < TAMANHO_VETOR; i++){
		printf("%d ",vetor[i]);
	}

	return 0;
}