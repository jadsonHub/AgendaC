#include <stdio.h>

#include <locale.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#define MAX 100

typedef struct Contato {
  char nome[250];
  int telefone;
  char email[200];
}
Contato;

int i, opcao, cont = 0; // coloquei um contatdor pra faciltar o cadastro 
Contato contato[MAX];

// ######   F U N C O E S   D A   A G E N D A ######

void menu();
void cadastrar();
void consultar();
void excluir();
void listar();
void inicializar();
void editar();

void menu() {

  printf("\n\n========================================= Agenda Telefônica ===================================================\n\n\n");

  printf("\n\nSelecione uma Opção\n\n 1-Adicionar\n\n 2-Buscar\n\n 3-Excluir\n\n 4-Listar todos \n\n 5-Editar\n\n 0-Sair\n\nOpção: ");
  scanf("%d", & opcao);
  system("cls");
  switch (opcao) {

  case 0:
    exit(0);
    break;
  case 1:
    cadastrar();
    menu();
    break;
  case 2:
    consultar();
    menu();
  case 3:
    excluir();
    menu();
  case 4:
    listar();
    menu();
    break;
  case 5:
    editar();
    break;
  default:
    printf("\n\nOpção invalida! \n\n");
    printf("Precione ENTER para voltar ao Menu inicial....\n\n");
    getchar();
    printf("=============================================================================================================");
    getchar();
    system("cls");
    menu();
    break;
  }
}
void cadastrar() { // eliminei o for porque como ele vai ficar meio que um ciclo vou usar o contador para armazenar os contatos na pose 0
  if (cont < MAX) {
    printf("\n=========================================== Cadastrar contato ============================================\n\n");
    printf("\nDigite o nome do contato , para contato com sobrenonome utiizar o '-':\nNome:");
    scanf(" %s", contato[cont].nome);
    printf("\nDigite o telefone do contato\nNumero:");
    scanf("%d", & contato[cont].telefone);
    printf("\nDigite o email do contato:\nE-mail: ");
    scanf(" %s", contato[cont].email);
    cont++;
    printf("\n\nContato cadastrado  com sucesso !\n\n");
    printf("Precione ENTER para voltar ao Menu inicial....\n\n");
    getchar();
    printf("=============================================================================================================");
    getchar();
    system("cls");
    menu();
  } else {
    printf("\n\nAgenda lotatda !\n\n");
    printf("Precione ENTER para voltar ao Menu inicial....\n\n");
    getchar();
    printf("=============================================================================================================");
    getchar();
    system("cls");
    menu();
  }

}
void consultar() {
  char buscaNome[200];
  int cont2 = 0, i;
  printf("\n============================================ Buscar contato ===================================================\n");
  printf("\n\nBuscar contato\n");
  printf("\n\nDigite o nome do contato\nNome :");
  scanf("%s", buscaNome);
  for (i = 0; i < cont; i++) {
    if (strcmp(buscaNome, contato[i].nome) == 0) { //coloquei o for para varrer o vetor e checar se o nome consultado
      printf("\n\nO contato de %s . \n\nCom o Numero: %d \n\nE Email: %s \n\nEstá na posição: %d\n\n\n", contato[i].nome, contato[i].telefone, contato[i].email, i);
      cont2 = 1;
      printf("\n\n=========================================================================================================\n\n");
    }
  }
  if (cont2 == 0) {
    printf("\nContato não cadastrado !\n\n");
    printf("\n\n=========================================================================================================\n\n");
  }
  getchar();
  printf("Precione ENTER para voltar ao Menu inicial....");
  getchar();
  system("cls");
  menu();
}
void excluir() {

  int cont2 = 0, i;
  printf("\n\n=================================================== Excluir contato ===========================================\n\n");

  for (i = 0; i < MAX && (strcmp(contato[i].nome, "\0") != 0); i++) {
    printf("\n\nNome: %s\n\n Telefone: %d\n\n Email: %s\n\n Codigo: %d\n\n", contato[i].nome, contato[i].telefone, contato[i].email, i);
    cont2++;
  }
  printf("Digite o codigo do contato que deseja excluir\n");
  scanf("%d", & i);

  strcpy(contato[i].nome, "\0");
  contato[i].telefone = 0;
  strcpy(contato[i].email, "\0");
  cont2--;

  printf("\n\nContato excluido com sucesso!\n\n");
  printf("\n\nPrecione ENTER para voltar ao Menu inicial....\n\n");
  getchar();
  printf("=============================================================================================================");
  getchar();
  system("cls");
  menu();
}
void listar() {
  int cont2 = i;
  printf("\n\n=========================================== Lista de contatos ============================================\n\n");
  printf("\n\nSe a lista estiver vazia não tem nem um contato salvo !\n\n");
  for (i = 0; i < MAX && (strcmp(contato[i].nome, "\0") != 0); i++) {
    printf("\n\nNome: %s\n\n Telefone: %d\n\n Email: %s\n\n Codigo: %d\n\n", contato[i].nome, contato[i].telefone, contato[i].email, i);
    cont2++;
  }
  getchar();
  printf("Precione ENTER para voltar ao Menu inicial....\n\n");
  printf("=============================================================================================================");
  getchar();
  system("cls");
  menu();
}
void editar() {

  char novoNome[200], novoEmail[200], buscaNome[200];
  int novoTLF = 0, cont2 = 0, i;

  printf("\n\n=================================================== Editar contato ===========================================\n\n");
  printf("\n\nBuscar contato\n");
  printf("\n\nDigite o nome do contato\nNome :");
  scanf("%s", buscaNome);

  for (i = 0; i < cont; i++) {
    if (strcmp(buscaNome, contato[i].nome) == 0) { //coloquei o for para varrer o vetor e checar se o nome consultado
      printf("\n\nO contato de %s . \n\nCom o Numero: %d \n\nE Email: %s \n\nEst� na posição: %d\n\n\n", contato[i].nome, contato[i].telefone, contato[i].email, i);
      cont2 = 1;
      printf("\n\n=========================================================================================================\n\n");
      printf("Digite o código do contato que deseja editar:\nCódigo: ");
      scanf("%d", & i);
      printf("\n\nDigite o novo nome se tiver sobrenome utilize '-' para separar  :\nNome : ");
      scanf("%s", novoNome);
      printf("\n\nDIgite o novo email :\nEmail: ");
      scanf("%s", novoEmail);
      printf("\n\nDIgite o novo telefone: \nTelefone: ");
      scanf("%d", & novoTLF);
      strcpy(contato[i].nome, novoNome);
      contato[i].telefone = novoTLF;
      strcpy(contato[i].email, novoEmail);

      printf("\n\nContato editado com sucesso!\n\n");
      printf("\n\nPrecione ENTER para voltar ao Menu inicial....\n\n");
      getchar();
      printf("=============================================================================================================");
      getchar();
      system("cls");
      menu();
    }
  }
  if (cont2 == 0) {

    printf("\nContato não cadastrado !\n\n");
    printf("\n\n=========================================================================================================\n\n");
    getchar();
    printf("Precione ENTER para voltar ao Menu inicial....");
    getchar();
    system("cls");
    menu();

  }
}

