#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct aluno {
    int matricula;
	char nome[40];
    float A1,A2,A3,media;   
 }Aluno,* PAluno;
/* Com o uso do typedef uma variável do tipo "struct aluno" pode ser declarada
 apenas como "Aluno" e um ponteiro para esta estrutura como "PAluno"*/

PAluno incluir_aluno(int* num_alunos){
    int i;
    PAluno pa;
    //num_alunos é uma variável que será lida para guardar o número de alunos inseridos 
    printf("Informe o numero de alunos a serem inseridos: ");
    scanf("%d",num_alunos);
    pa = (PAluno) malloc((*num_alunos)*sizeof(Aluno));
    if (pa == NULL){
       printf("FALTOU MEMORIA");
       exit(1);     
    }
        
    for(i=0;i<(*num_alunos);i++){     
      printf("Informe a matricula: "); 
      scanf("%d",&pa[i].matricula);  
	  printf("Informe o nome do Aluno: "); 
      scanf(" %[^\n]",pa[i].nome);
      printf("Informe a nota da A1: "); 
      scanf("%f",&pa[i].A1);  
      printf("Informe a nota da A2: ");   
      scanf("%f",&pa[i].A2);
      printf("Informe a nota do A3: ");     
      scanf("%f",&pa[i].A3);
    }

    /* Nesta versão podemos usar o "." para acessar as variáveis do struct, pois
       o vetor  contém estruturas estáticas e o uso dos colchetes [i] permite
       acessar diretamente o conteúdo da célula de um vetor */

   /*O & foi usado, pois a função "scanf" necessita saber o endereço da variável.
   No caso do nome não foi necessário, pois em C um String é tratado como um vetor
   de caracteres e o nome dado a um vetor sempre representa o endereço
   da sua primeira posição.*/
      
   return pa;  
}

void imprimir_alunos(int num_alunos, PAluno pa){
  int i;                       
  for(i=0;i<num_alunos;i++){     
    printf("Nome: %s Matricula: %d A1: %.2f  A2: %.2f  A3: %.2f Media: %.2f\n",pa[i].nome,pa[i].matricula,pa[i].A1,pa[i].A2,pa[i].A3,pa[i].media);
  }                                         
}

void media_alunos(int num_alunos, PAluno pa){
  int i;
  for(i=0;i<num_alunos;i++){     
        pa[i].media = (pa[i].A1 + pa[i].A2 + pa[i].A3)/3;       
  }                                         
}

/* Função de comparação: elemento é do tipo Aluno */
/*OBS: quando o vetor é ponteiro de ponteiro, 
esta função de comparação deve prever isso*/
int cmp_alunos_alfabetico(const void* a1,const void* a2){
        //converte ponteiros genéricos para ponteiros de Aluno
        //Aluno* aluno1 = (Aluno*) a1; //ERRADO
	//Aluno* aluno2 = (Aluno*) a2; //ERRADO
	Aluno* aluno1 = (Aluno*) a1;
	Aluno* aluno2 = (Aluno*) a2;
	// dados os ponteiros de Aluno, faz a comparação
    return strcmp(aluno1->nome,aluno2->nome);
}
	
/*Função de comparacao a ser usada pelo qsort*/
/*OBS: quando o vetor é ponteiro de ponteiro, 
esta função de comparação deve prever isso*/
int cmp_aluno_media_matricula(const void* a1,const void* a2){
	//Aluno* aluno1 = (Aluno*) a1; //ERRADO
	//Aluno* aluno2 = (Aluno*) a2; //ERRADO
	Aluno* aluno1 = (Aluno*) a1;
	Aluno* aluno2 = (Aluno*) a2;
	//primeiro criterio = media mais alta primeiro (decrescente)
	if(aluno1->media > aluno2->media) return -1;
	if(aluno1->media < aluno2->media) return 1;
	//segundo criterio = medias iguais - matricula (crescente)
	if(aluno1->matricula < aluno2->matricula) return -1;
	if(aluno1->matricula > aluno2->matricula) return 1;
}

PAluno mock_testes(){
    int i;
    PAluno pa;
    //alocar o vetor de estruturas
    pa = (PAluno) malloc(10*sizeof(Aluno));   
    if (pa == NULL) exit(1);           
    //este procedimento aponta todas as células do vetor para NULL
  	pa[0].matricula = 44;
    strcpy(pa[0].nome,"Andre Lucio");
	pa[0].A1 = 8.0;
    pa[0].A2 = 7.3;
    pa[0].A3 = 6.0;
    pa[0].media = 0.0;

	pa[1].matricula = 10;
    strcpy(pa[1].nome,"Joao Pedro");
	pa[1].A1 = 5.0;
    pa[1].A2 = 7.0;
    pa[1].A3 = 6.2;
    pa[1].media = 0.0;

	pa[2].matricula = 5;
    strcpy(pa[2].nome,"Joana Josefa");
	pa[2].A1 = 5.0;
    pa[2].A2 = 7.9;
    pa[2].A3 = 6.0;
    pa[2].media = 0.0;
    
	pa[3].matricula = 22;
    strcpy(pa[3].nome,"Alana Souza");
	pa[3].A1 = 5.0;
    pa[3].A2 = 7.0;
    pa[3].A3 = 6.0;
    pa[3].media = 0.0;
    
	pa[4].matricula = 23;
    strcpy(pa[4].nome,"Tamiris Vespucia");
	pa[4].A1 = 5.0;
    pa[4].A2 = 7.4;
    pa[4].A3 = 6.0;
    pa[4].media = 0.0;
    
	pa[5].matricula = 9;
    strcpy(pa[5].nome,"Carol Villar");
	pa[5].A1 = 5.0;
    pa[5].A2 = 7.6;
    pa[5].A3 = 6.4;
    pa[5].media = 0.0;
    
	pa[6].matricula = 111;
    strcpy(pa[6].nome,"Shirley Mendonca");
	pa[6].A1 = 5.6;
    pa[6].A2 = 7.2;
    pa[6].A3 = 6.0;
    pa[6].media = 0.0;
    
	pa[7].matricula = 33;
    strcpy(pa[7].nome,"Carlos Souza");
	pa[7].A1 = 5.0;
    pa[7].A2 = 7.0;
    pa[7].A3 = 6.0;
    pa[7].media = 0.0;
    
	pa[8].matricula = 123;
    strcpy(pa[8].nome,"Beatriz Maria");
	pa[8].A1 = 5.6;
    pa[8].A2 = 7.2;
    pa[8].A3 = 6.0;
    pa[8].media = 0.0;
    
	pa[9].matricula = 2;
    strcpy(pa[9].nome,"Ana de Souza");
	pa[9].A1 = 5.0;
    pa[9].A2 = 7.0;
    pa[9].A3 = 6.2;
    pa[9].media = 0.0;
                   
   return pa;  
}


int main(int argc, char *argv[])
{
   PAluno alunos; 
   int qtd_alunos;
   
    
   /*
     ATENÇÃO nesta versão a função incluir passou a retornar o ponteiro para o início do vetor , pois a alocação dinâmica do
    vetor foi feita dentro da função e o escopo global não iria visualizar este endereço, ocasionando erro de execução.
   */
   
   /*OBS: Comente uma das linhas a seguir para fazer inserção manual, ou usar o mock de inserção*/
   //alunos = incluir_aluno(&qtd_alunos);
   alunos = mock_testes(); //Este mock é só para evitar ter que digitar vários alunos para testar. Descomente a linha 191 para incluir via teclado
   
   
   media_alunos(10,alunos);
   imprimir_alunos(10,alunos);
   printf("\n\nVetor ordenado por media e matricula\n");
   qsort(alunos,10,sizeof(Aluno),cmp_aluno_media_matricula);
   imprimir_alunos(10,alunos);
   printf("\n\nVetor ordenado por nome\n"); 
   qsort(alunos,10,sizeof(Aluno),cmp_alunos_alfabetico);
   imprimir_alunos(10,alunos);
      
   system("PAUSE");	
   return 0;
}