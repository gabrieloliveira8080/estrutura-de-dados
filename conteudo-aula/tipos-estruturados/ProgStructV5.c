#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // número máximo do vetor de alunos

 typedef struct aluno {
    char nome[40];
    float A1,A2,A3,media;   
 }Aluno,* PAluno, **PPAluno;
/* Com o uso do typedef uma variável do tipo "struct aluno" pode ser declarada
 apenas como "Aluno" e um ponteiro para esta estrutura como "PAluno"*/

int incluir_aluno(PPAluno ppa)
{
    int num_alunos,i;
    //num_alunos é uma variável que será lida para guardar o número de alunos inseridos 
    printf("Informe o numero de alunos a serem inseridos: ");
    scanf("%d",&num_alunos);
        
    for(i=0;i<num_alunos;i++)
    {     
      // No comando a seguir está sendo alocado um espaço de memória para 
      // armazenar os dados do aluno "i".
      ppa[i] = (PAluno) malloc(sizeof(Aluno));
      
      if (ppa[i] == NULL)
      {
         printf("\n\nMemoria insuficiente\n\n");
         exit(1);           
      }
      printf("Informe o nome do Aluno: "); 
      scanf(" %[^\n]",ppa[i]->nome);
      printf("Informe a nota da A1: "); 
      scanf("%f",&ppa[i]->A1);  
      printf("Informe a nota da A2: ");   
      scanf("%f",&ppa[i]->A2);
      printf("Informe a nota do A3: ");     
      scanf("%f",&ppa[i]->A3);
    }
    /* Nesta versão podemos temos que usar -> para acessar as variáveis do struct,
     pois o vetor  contém ponteiros para estruturas e não as estruturas de fato */
                   
   return num_alunos;  
}

void imprimir_alunos(int num_alunos, PPAluno ppa)
{
  int i;                       
  for(i=0;i<num_alunos;i++)
  {     
    printf("Nome: %s A1: %.2f  A2: %.2f  A3: %.2f Media: %.2f\n",ppa[i]->nome,ppa[i]->A1,ppa[i]->A2,ppa[i]->A3,ppa[i]->media);
  }                                         
}

void media_alunos(int num_alunos, PPAluno ppa)
{
  int i;

  for(i=0;i<num_alunos;i++)
  {     
        ppa[i]->media = (ppa[i]->A1 + ppa[i]->A2 + ppa[i]->A3)/3;       
  }                                         
}

/*Procedimento para inicializar todas as posições do vetor com NULL*/
void inicializa_vetor(PPAluno ppa)
{
  int i;
  
  for(i=0;i<MAX;i++)
  {     
    ppa[i] = NULL; 
  }   
}

int main(int argc, char *argv[])
{
   Aluno* alunos[MAX]; // a variável "a" foi declarada já usando a redefinição de tipo
   int qtd_alunos;

   inicializa_vetor(alunos);   
   qtd_alunos = incluir_aluno(alunos); 
   media_alunos(qtd_alunos,alunos);
   imprimir_alunos(qtd_alunos, alunos);   
      
   system("PAUSE");	
   return 0;
}