#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct aluno {
    int matricula;
	char nome[40];
    float A1,A2,A3,media;   
 }Aluno,*PAluno,**PPAluno;
/* Com o uso do typedef uma variável do tipo "struct aluno" pode ser declarada
 apenas como "Aluno" e um ponteiro para esta estrutura como "PAluno" e um ponteiro
 de ponteiro para a estrutura como "PPAluno"*/

int inicializa_vetor(int num_alunos, PPAluno ppa){
  int i;
  for(i=0;i<num_alunos;i++){
    ppa[i] = NULL;             
  }                     
}

PPAluno incluir_aluno(int num_alunos){
    int i;
    PPAluno ppa;
    //alocar o vetor de estruturas
    ppa = (PPAluno) malloc(num_alunos*sizeof(PAluno));   
    if (ppa == NULL){
         printf("\n\nMemoria insuficiente\n\n");
         exit(1);           
    }
    
    //este procedimento aponta todas as células do vetor para NULL
    inicializa_vetor(num_alunos, ppa);
                
    for(i=0;i<num_alunos;i++)
    {       
        ppa[i] = (PAluno) malloc(sizeof(Aluno));   
        if (ppa == NULL){
           printf("\n\nMemoria insuficiente\n\n");
           exit(1);           
        }
      
        printf("Informe a matricula do Aluno: "); 
        scanf("%d",&ppa[i]->matricula);
		printf("Informe o nome do Aluno: "); 
        scanf(" %[^\n]",ppa[i]->nome);
        printf("Informe a nota da A1: "); 
        scanf("%f",&ppa[i]->A1);  
        printf("Informe a nota da A2: ");   
        scanf("%f",&ppa[i]->A2);
        printf("Informe a nota do A3: ");     
        scanf("%f",&ppa[i]->A3);   
    }
                   
   return ppa;  
}

PPAluno mock_testes(){
    int i;
    PPAluno ppa;
    //alocar o vetor de estruturas
    ppa = (PPAluno) malloc(10*sizeof(PAluno));   
    if (ppa == NULL) exit(1);           
    //este procedimento aponta todas as células do vetor para NULL
    inicializa_vetor(10, ppa);
    ppa[0] = (PAluno) malloc(sizeof(Aluno));
	ppa[0]->matricula = 44;
    strcpy(ppa[0]->nome,"Andre Lucio");
	ppa[0]->A1 = 8.0;
    ppa[0]->A2 = 7.3;
    ppa[0]->A3 = 6.0;
    ppa[0]->media = 0.0;

	ppa[1] = (PAluno) malloc(sizeof(Aluno));
	ppa[1]->matricula = 10;
    strcpy(ppa[1]->nome,"Joao Pedro");
	ppa[1]->A1 = 5.0;
    ppa[1]->A2 = 7.0;
    ppa[1]->A3 = 6.2;
    ppa[1]->media = 0.0;

    ppa[2] = (PAluno) malloc(sizeof(Aluno));
	ppa[2]->matricula = 5;
    strcpy(ppa[2]->nome,"Joana Josefa");
	ppa[2]->A1 = 5.0;
    ppa[2]->A2 = 7.9;
    ppa[2]->A3 = 6.0;
    ppa[2]->media = 0.0;
    
    ppa[3] = (PAluno) malloc(sizeof(Aluno));
	ppa[3]->matricula = 22;
    strcpy(ppa[3]->nome,"Alana Souza");
	ppa[3]->A1 = 5.0;
    ppa[3]->A2 = 7.0;
    ppa[3]->A3 = 6.0;
    ppa[3]->media = 0.0;
    
    ppa[4] = (PAluno) malloc(sizeof(Aluno));
	ppa[4]->matricula = 23;
    strcpy(ppa[4]->nome,"Tamiris Vespucia");
	ppa[4]->A1 = 5.0;
    ppa[4]->A2 = 7.4;
    ppa[4]->A3 = 6.0;
    ppa[4]->media = 0.0;
    
    ppa[5] = (PAluno) malloc(sizeof(Aluno));
	ppa[5]->matricula = 9;
    strcpy(ppa[5]->nome,"Carol Villar");
	ppa[5]->A1 = 5.0;
    ppa[5]->A2 = 7.6;
    ppa[5]->A3 = 6.4;
    ppa[5]->media = 0.0;
    
    ppa[6] = (PAluno) malloc(sizeof(Aluno));
	ppa[6]->matricula = 111;
    strcpy(ppa[6]->nome,"Shirley Mendonca");
	ppa[6]->A1 = 5.6;
    ppa[6]->A2 = 7.2;
    ppa[6]->A3 = 6.0;
    ppa[6]->media = 0.0;
    
    ppa[7] = (PAluno) malloc(sizeof(Aluno));
	ppa[7]->matricula = 33;
    strcpy(ppa[7]->nome,"Carlos Souza");
	ppa[7]->A1 = 5.0;
    ppa[7]->A2 = 7.0;
    ppa[7]->A3 = 6.0;
    ppa[7]->media = 0.0;
    
    ppa[8] = (PAluno) malloc(sizeof(Aluno));
	ppa[8]->matricula = 123;
    strcpy(ppa[8]->nome,"Beatriz Maria");
	ppa[8]->A1 = 5.6;
    ppa[8]->A2 = 7.2;
    ppa[8]->A3 = 6.0;
    ppa[8]->media = 0.0;
    
    ppa[9] = (PAluno) malloc(sizeof(Aluno));
	ppa[9]->matricula = 2;
    strcpy(ppa[9]->nome,"Ana de Souza");
	ppa[9]->A1 = 5.0;
    ppa[9]->A2 = 7.0;
    ppa[9]->A3 = 6.2;
    ppa[9]->media = 0.0;
                   
   return ppa;  
}

void imprimir_alunos(int num_alunos, PPAluno ppa){
  int i;                       
  for(i=0;i<num_alunos;i++)
  {     
    printf("Matricula: %d Nome: %s A1: %.2f  A2: %.2f  A3: %.2f Media: %.2f \n",
	ppa[i]->matricula,ppa[i]->nome,ppa[i]->A1,ppa[i]->A2,ppa[i]->A3,ppa[i]->media);
  }                                         
}

void media_alunos(int num_alunos, PPAluno ppa){
  int i;
  for(i=0;i<num_alunos;i++){     
        ppa[i]->media = (ppa[i]->A1 + ppa[i]->A2 + ppa[i]->A3)/3;       
  }                                         
}

/* Função de comparação: elemento é do tipo Aluno */
/*OBS: quando o vetor é ponteiro de ponteiro, 
esta função de comparação deve prever isso*/
int cmp_alunos_alfabetico(const void* a1,const void* a2){
        //converte ponteiros genéricos para ponteiros de Aluno
        //Aluno* aluno1 = (Aluno*) a1; //ERRADO
	//Aluno* aluno2 = (Aluno*) a2; //ERRADO
	Aluno** aluno1 = (Aluno**) a1;
	Aluno** aluno2 = (Aluno**) a2;
	// dados os ponteiros de Aluno, faz a comparação
    return strcmp((*aluno1)->nome,(*aluno2)->nome);
}
	


/*Função de comparacao a ser usada pelo qsort*/
/*OBS: quando o vetor é ponteiro de ponteiro, 
esta função de comparação deve prever isso*/
int cmp_aluno_media_matricula(const void* a1,const void* a2){
	//Aluno* aluno1 = (Aluno*) a1; //ERRADO
	//Aluno* aluno2 = (Aluno*) a2; //ERRADO
	Aluno** aluno1 = (Aluno**) a1;
	Aluno** aluno2 = (Aluno**) a2;
	//primeiro criterio = media mais alta primeiro (decrescente)
	if((*aluno1)->media > (*aluno2)->media) return -1;
	if((*aluno1)->media < (*aluno2)->media) return 1;
	//segundo criterio = medias iguais - matricula (crescente)
	if((*aluno1)->matricula < (*aluno2)->matricula) return -1;
	if((*aluno1)->matricula > (*aluno2)->matricula) return 1;
}


int main(int argc, char *argv[]){
   PPAluno alunos; // a variável "alunos" foi declarada já usando a redefinição de tipo
   int qtd_alunos;

   alunos = mock_testes();
   media_alunos(10,alunos);
   imprimir_alunos(10,alunos);
   printf("\n\nVetor ordenado por media e matricula\n");
   qsort(alunos,10,sizeof(Aluno*),cmp_aluno_media_matricula);
   imprimir_alunos(10,alunos);
   printf("\n\nVetor ordenado por nome\n"); 
   qsort(alunos,10,sizeof(Aluno*),cmp_alunos_alfabetico);
   imprimir_alunos(10,alunos);
         
   system("PAUSE");	
   return 0;
}