#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // número máximo do vetor de alunos

 typedef struct aluno {
    char nome[40];
    float A1,A2,A3, media;   
 }Aluno,* PAluno;
/* Com o uso do typedef uma variável do tipo "struct aluno" pode ser declarada
 apenas como "Aluno" e um ponteiro para esta estrutura como "PAluno"*/

int incluir_aluno(PAluno pa)
{
    int num_alunos,i;
    //num_alunos é uma variável que será lida para guardar o número de alunos inseridos 
    printf("Informe o numero de alunos a serem inseridos: ");
    scanf("%d",&num_alunos);
        
    for(i=0;i<num_alunos;i++)
    {     
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
      
   return num_alunos;  
}

void imprimir_alunos(int num_alunos, PAluno a)
{
  int i;                       
  for(i=0;i<num_alunos;i++)
  {     
    printf("Nome: %s A1: %.2f  A2: %.2f  A3: %.2f Media: %.2f\n",a[i].nome,a[i].A1,a[i].A2,a[i].A3,a[i].media);
  }                                         
}

void media_alunos(int num_alunos, PAluno a)
{
  int i;

  for(i=0;i<num_alunos;i++)
  {     
        a[i].media = (a[i].A1 + a[i].A2 + a[i].A3)/3;       
  }                                         
}

int main(int argc, char *argv[])
{
   Aluno alunos[MAX]; // a variável "a" foi declarada já usando a redefinição de tipo
   int qtd_alunos;
   
   qtd_alunos = incluir_aluno(alunos); 
   media_alunos(qtd_alunos, alunos);
   imprimir_alunos(qtd_alunos, alunos);   
      
   system("PAUSE");	
   return 0;
}