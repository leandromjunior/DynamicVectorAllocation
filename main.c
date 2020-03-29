#include <stdio.h>
#include<stdlib.h>
//#define tam 3

int busca_binaria(int n, float k, float *v);

int main(void) {
  
  int i,achou, tam;
//	float vet[tam];
  float *vetor;
	float proc;

//Alocando Dinamicamente

printf("Insira o tamanho do seu vetor:");
scanf("%d", &tam);

vetor=(float*)malloc(tam*sizeof(float));

if(vetor == NULL){
  printf("Insuficiência de memória");
  exit(1);
}
	
	//leitura dos valores
	for(i=0;i<tam;i++)
	{
		printf("Entre com os valores[%d]: ",i);
		scanf("%f",&vetor[i]);
	}
	
	printf("\nEntre com o valor que deseja procurar: ");
	scanf("%f",&proc);

	achou = busca_binaria(tam,proc,vetor);
  
	if(achou == -1)
	{
    printf("\nO numero digitado nao existe no vetor!");
	}else
		printf("\nO numero esta na posicao: %d\n",achou);

  free(vetor);

  return 0;
}

int busca_binaria(int n, float k, float *v){
  int a=0, b=n-1, pos=0, j;

  while(a<=b && pos==0){
    j=(a+b)/2;

    if(v[j] == k){
      pos = j;
    }
    else if(k>v[j]){
      a = j + 1;
    }
    else{
      b= j - 1;
    }
  }
  return pos;
}