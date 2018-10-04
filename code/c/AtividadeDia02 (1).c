#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int chave;
    char nomeLivro[30];
    char idioma[10];
    int paginas;
} Registro;

typedef struct itemLivro{
    Registro reg;
    struct itemLivro *prox;
} itemLivro;

typedef struct{
    itemLivro *inicio;
} lista;

void inserirElemOrdenado(lista* a, Registro reg);
void insElem(lista* a,Registro r);

void iniciarLista (lista *a){
    a->inicio=NULL;
}

void reiniciarLista (lista *a){
    itemLivro *atual;
    atual = a->inicio;
    while (atual != NULL){
        itemLivro* liberar = atual;
        atual = atual->prox;
        free(liberar);
    }
    a->inicio = NULL;
}

void buscaLivroPorChave(lista* a, int ch){
	itemLivro *AuxLivro;
	AuxLivro = a->inicio;
	
	while (AuxLivro != NULL) {
		if (ch == AuxLivro->reg.chave) {
				printf("CHAVE: %d\nNOME: %s\nIDIOMA: %s\nPAGINAS: %d\n", AuxLivro->reg.chave, AuxLivro->reg.nomeLivro, AuxLivro->reg.idioma, AuxLivro->reg.paginas);
		}
		AuxLivro = AuxLivro->prox;
	}
}

void ImprimeLivSupPag(lista* a, int pag){
	itemLivro *AuxLivro;
	AuxLivro = a->inicio;
	
	while (AuxLivro != NULL) {
		if (AuxLivro->reg.paginas > pag) {
				printf(" CHAVE: %d \n NOME: %s \n IDIOMA: %s \n PAGINAS: %d \n", AuxLivro->reg.chave, AuxLivro->reg.nomeLivro, AuxLivro->reg.idioma, AuxLivro->reg.paginas);
		}
		AuxLivro = AuxLivro->prox;
	}
}

void AlteraIdioma(lista* a, int ch, char AuxIdioma[]){
	itemLivro *AuxLivro;
	AuxLivro = a->inicio;
	
	while (AuxLivro != NULL) {
		if (ch == AuxLivro->reg.chave) {
			strcpy(AuxLivro->reg.idioma, AuxIdioma);
			printf("idioma alterado com sucesso.");	
		}
		AuxLivro = AuxLivro->prox;
	}
}

void CopiaLista(lista *a, lista * b){
	itemLivro *AuxLivro;
	AuxLivro = a->inicio;
	while (AuxLivro != NULL) {
	printf("\nEntrou\n");
		insElem(b,AuxLivro->reg);
		printf("\npassei\n");
		AuxLivro = AuxLivro->prox;
	}
}


itemLivro* buscarSequencialMaisAnterior (lista* a, int ch, itemLivro **anterior){
    itemLivro* atual = a->inicio;
    *anterior=NULL;
    while ((atual != NULL)&&(atual->reg.chave < ch)){
		*anterior=atual;
        atual = atual->prox;
    }
 
    if ((atual != NULL)&&(atual->reg.chave==ch)){
		return atual;
	}
	return NULL;
}

void inserirElemOrdenado(lista* a, Registro reg){
    itemLivro *ponteiroNovoLivro;
    itemLivro *anterior = a->inicio;
    
    ponteiroNovoLivro = buscarSequencialMaisAnterior(a, reg.chave, &anterior);
    
    if (ponteiroNovoLivro != NULL) // elemento já existe com a chave buscada
        return;
    
    ponteiroNovoLivro = malloc(sizeof(itemLivro)); 
    ponteiroNovoLivro->reg=reg;
    
    if (anterior == NULL){ // Primeiro elemento a ser inserido na lista
        ponteiroNovoLivro->prox = a->inicio;
        a->inicio = ponteiroNovoLivro;
    }else{
        ponteiroNovoLivro->prox = anterior->prox;
        anterior->prox = ponteiroNovoLivro;
    }
}

void preenchimentoInicial (lista* a){
    Registro livro;
    
    
    printf("Digite a chave do livro: ");
	scanf("%d",&livro.chave);
	fflush(stdin);	
	printf("Digite o nome do livro: ");
	scanf("%[^\n]s",livro.nomeLivro);
	fflush(stdin);	
	printf("Digite o idioma do livro: ");
	scanf("%[^\n]s",livro.idioma);
		
	printf("Digite o numero de paginas do livro: ");
	scanf("%d",&livro.paginas);
	
    inserirElemOrdenado(a, livro);
}

void insElem(lista* a,Registro r){
	itemLivro* ant;
	itemLivro* novo;
	itemLivro* fim=a->inicio;
	while(fim!=NULL){
		ant=fim;
		fim=fim->prox;
	}
	novo=malloc(sizeof(itemLivro));
	novo->reg=r;
	novo->prox=NULL;
	if(a->inicio==NULL){
		a->inicio=novo;
	}
	else{
		ant->prox=novo;
	}
}


int main(){
	int escolha, ch1, ch2, pag1;
	char AuxIdioma [10];
	lista ListaLivros;
	lista copia;
	iniciarLista(&ListaLivros);
	do{
		printf("\n------MENU------\n");
		printf("1 - Inserir um livro na lista.\n");
		printf("2 - Buscar livro pela chave.\n");
		printf("3 - Imprimir todos os livros com numero de paginas superior a X.(informe X)\n");
		printf("4 - Alterar o idioma de um livro.(informe a chave e o novo idioma do livro\n");
		printf("5 - Apagar todos os livros da lista com chave superior a X.(informe x)\n");
		printf("6 - Reiniciar a lista de livros.\n");
		printf("7 - Fazer uma copia da lista.\n");
		printf("8 - Juntar as duas listas.\n\n");
		
		printf("Digite sua escolha: ");
		scanf("%d",&escolha);
		printf("\n\n");
		
		switch(escolha){
			case 1:
				preenchimentoInicial(&ListaLivros);
				break;
			case 2:	
				printf("Informe a chave: ");
				scanf("%d",&ch1);
				printf("\n\n");
				buscaLivroPorChave(&ListaLivros, ch1);
				break;
			case 3:
				printf("Informe o X: ");
				scanf("%d",&pag1);
				printf("\n\n");
				ImprimeLivSupPag(&ListaLivros, pag1);
				break;
			case 4:
				printf("Informe a chave: ");
				scanf("%d",&ch2);
				printf("Informe o idioma: ");
				fflush(stdin);
				fgets(AuxIdioma, 10, stdin);
				AlteraIdioma(&ListaLivros, ch2, AuxIdioma);
				break;
			case 5:
				break;
			case 6:
				reiniciarLista(&ListaLivros);	
				break;
			case 7 : 
				iniciarLista(&copia);
				CopiaLista(&ListaLivros, &copia);
				break;
				
		}
	}while(escolha != 0);
	
	
	
	
	return 0;
}
