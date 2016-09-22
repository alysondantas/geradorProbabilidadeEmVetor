#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetorEquilibrado(int,int, int v[]);
void exibeVetor(int, int v[]);
void gerarVetorDesequilibrado(int,int,int v[]);
int obterNumero(int, int v[]);
void insereProbabilidade(int, int, int v[]);
void mostrarProbabilidade(int, int, int v[]);


int main(){
    int probabilidades,num, i, x, en=0, opcao_menu = 0;
    
    int quit = 0;
    
	printf("Qual o tamanho do vetor?\n");
    scanf("%d",&x);
    int v[x];
    
    printf("A inicio o vetor é assim:\n");
    for(i=0 ; i <x ; i++){
    	v[i] = i+1;
	}
	exibeVetor(x,v);
	
    
    while(en==0){
		printf("diga a quantidade de probabilidades: ");
		scanf("%i",&probabilidades);
		printf("\n");
		if(probabilidades>x){
			printf("\nEntrada invalida deve ser menor que %d!\n", x);
		}else{
			en=1;
		}	
		
	}
	
	system("cls");//limpa a tela
    
    while(quit == 0){
    	
    	printf("============MENU DO GERADOR DE PROBABILIDADE============\n\n");
    	printf("1) Criar vetor aleatorio equilibrado\n2) Exibe vetor\n3) Criar vetor aleatorio desequilibrado\n4) Selecionar um numero\n5) Inserir probabilidade\n6) mostrar probabilidades\n7) Sair\n");
    	scanf("%d", &opcao_menu);
    	
    	switch(opcao_menu){
		case 1:
			gerarVetorEquilibrado(probabilidades, x, v);
			break;
		case 2:
			exibeVetor(x,v);
			break;
		case 3:
			gerarVetorDesequilibrado(probabilidades, x, v);
			break;
		case 4:
			num = -1;
			num = obterNumero(x, v);
			printf("\n-------Numero selecionado: %d------\n\n", num);
			break;
		case 5:
			insereProbabilidade(probabilidades, x, v);
			break;
		case 6:
			mostrarProbabilidade(probabilidades, x, v);
			break;
		case 7:
			quit = 1;
			break;
				
		default:
			
			printf("Opção invalida.");
			break;
		}
	}
    
    return 0;
}

void gerarVetorEquilibrado(int probabilidades, int x, int v[]){
	int en;
	int aux = 0;
	
	for(en = 0 ; en < x ; en++){
		if(aux > probabilidades){
			aux = 0;
		}
		v[en] = aux;	
		aux++;
	}
}

void exibeVetor(int x, int v[]){
	int i;
	
	for(i=0 ; i <x ; i++){
    	printf("Espaço do vetor é %d: e o numero %d\n",i, v[i]);
	}
}

void gerarVetorDesequilibrado(int probabilidades,int x,int v[]){
	gerarVetorEquilibrado(probabilidades, x, v);
	srand( (unsigned)time(NULL) );
	printf("A probabilidade vai de: 0 ate %d\n", RAND_MAX);
    
    int en,i;
	int aux = 0;
	
	for(en = 0 ; en < x ; en++){
		aux = rand() % x;
		i = rand() % probabilidades;
		if(i < probabilidades){
			v[aux] = i;
		}else{
			en--;
		}	
	}
}

int obterNumero(int x, int v[]){
	int aux = 0;
	
	srand( (unsigned)time(NULL) );
	aux = rand() % x;
	
	return v[aux];
}

void insereProbabilidade(int probabilidades, int x, int v[]){
	int num,aux;
	printf("Qual a probabilidade?");
	scanf("%d",&num);
	
	if(num>probabilidades || num<0){		
		printf("Probabilidade invalida! deve ser menor que %d e maior que 0\n", probabilidades);
	}else{
		srand( (unsigned)time(NULL) );
		aux = rand() % x;
		v[aux] = num;
	}
	
}

void mostrarProbabilidade(int probabilidades, int x, int v[]){
	int v1[probabilidades];
	int aux,i, valor;
	
	for(aux = 0 ; aux < probabilidades ; aux++){
		v1[aux] = 0;
	}
	
	for(aux = 0 ; aux < x ; aux++){
		i = v[aux];
		v1[i] = v1[i] + 1;
	}
	
	for(aux = 0 ; aux < probabilidades ; aux++){
		valor = (100 * v1[aux]) / x;
		printf("%d de %d s e a porcentagem é %d \n", v1[aux], aux, valor);
	}
}
