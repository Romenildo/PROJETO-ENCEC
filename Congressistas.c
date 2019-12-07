#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Congressista.h"
#include "Visual.h"


typedef struct eventoc EVENTOC;
typedef struct capsulaC CAPSC;
typedef struct listac LISTAC;

LISTAC* CriarC(){
    LISTAC* li=(LISTAC*)malloc(sizeof(LISTAC));
    if(li!=NULL){
        li->inicio=NULL;
    }
    return li;

}
void liberarC(LISTAC *li){
    if(li==NULL){
        //ERRO
    }else{
        CAPSC *aux;
        while(li->inicio!=NULL){
            aux=li->inicio;
            li->inicio=li->inicio->proximo;
            free(aux);
        }
        free(li);
    }
}
void mostrarTodosC(LISTAC* li){
    system("cls");
    //mostra dados de todos os congressistas
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPSC* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
                printf("  Matricula: %d   \n",aux->dado.MatriculaC);
                printf("  Idade: %d       \n",aux->dado.idade);
                printf("  Telefone: %s    \n",aux->dado.telefone);
                printf("  CPF: %s         \n",aux->dado.cpf);
                printf("  Curso: %s       \n",aux->dado.curso);
                printf("  Email: %s       \n",aux->dado.email);
                printf("  Nome: %s        \n",aux->dado.nome);
                PlinhaH(50);PFchar(217);printf("\n");

                aux=aux->proximo;
            }
        }
    }
}
int tamanhoListaC(LISTAC *li){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //vazia
        }else{
            int cont=0;
            CAPSC *aux=li->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont++;
        }
    }
}
void inserirListaC(LISTAC *li,EVENTOC eC){//insere na ordem de matricula
    if(li==NULL){
        //ERRO
    }else{
        CAPSC *novo= (CAPSC*)malloc(sizeof(CAPSC));
        if(novo!=NULL){
            novo->dado= eC;
            if(li->inicio==NULL){//insercao com lista vazia
                novo->proximo=NULL;
                li->inicio=novo;
            }else{//insercao no inicio quando ja tem alguem na lista
                CAPSC *aux=li->inicio;
                if(aux->dado.MatriculaC>novo->dado.MatriculaC){// se o dado que tiver la for maior do que o que esta inserindo ai ele entra na frente[b] = [a,b]
                    novo->proximo=aux;
                    li->inicio=novo;
                }else{//insercao no meio ou no fim
                    CAPSC *ante;
                    while((aux!=NULL)&&(aux->dado.MatriculaC<novo->dado.MatriculaC)){//enquanto o auxiliar for menor do que o dado inserido
                        ante = aux;//guarda qual capsula é menor do que o novo
                        aux = aux->proximo;//passa, e guar o proximo que ele ira apontar
                    }
                    ante->proximo=novo;//o numeros menor que o novo ira apontar para o novo
                    novo->proximo=aux;// aponta para o aux que era o proximo maior que ele
                }

            }

        }
    }

}
int mostrarEmRemoverC(CAPSC *aux){
    linhaH(50,7,20);linhaV(12,7,20);linhaH(50,7,31);linhaV(12,56,20);
    Pchar(7,20,218);Pchar(56,20,191);Pchar(7,31,192);Pchar(56,31,217);
    gotoxy(9,22);printf("MATRICULA: %d",aux->dado.MatriculaC);
    gotoxy(9,23);printf("IDADE: %d",aux->dado.idade);
    gotoxy(9,24);printf("TELEFONE: %s",aux->dado.telefone);
    gotoxy(9,25);printf("CPF: %s",aux->dado.cpf);
    gotoxy(9,26);printf("CURSO: %s",aux->dado.curso);
    gotoxy(9,27);printf("EMAIL: %s",aux->dado.email);
    gotoxy(9,28);printf("NOME: %s",aux->dado.nome);
    VdesejaRemover();
    char op=getch();
    if(op=='1'){
        return 0;
    }else{
        return 1;
        }

}
int removerListaC(LISTAC *li,int num){//recebe numero da matricula

    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            CAPSC *aux=li->inicio;
            if(aux->dado.MatriculaC==num){//se for o 1 da lista
                li->inicio=aux->proximo;//inicio aponta pro proximo
                if(mostrarEmRemoverC(aux)==1){
                    return 1;
                }
                free(aux);
                return 0;
            }else{
                CAPSC *ante;
                while((aux!=NULL)&&(aux->dado.MatriculaC!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    AvisoNumeroNaoEncontrado();
                    return 1;
                }
                ante->proximo=aux->proximo;//
                if(mostrarEmRemoverC(aux)==1){//se deseja realmente remover
                        return 1;
                }
                free(aux);
                return 0;
            }
        }
    }

}
void pegarInfoCongressista(EVENTOC *eC,LISTAC *liC,int MatriculaC){

    gotoxy(27,32);printf("%d",MatriculaC);
    eC->MatriculaC=MatriculaC;
//------------------------------capacidade
    gotoxy(48,13);scanf("%d",&eC->idade);setbuf(stdin,NULL);

//-----------------------horario
    gotoxy(40,16);gets(eC->telefone);
//---------------------------------------carga horaria
    gotoxy(40,19);gets(eC->cpf);

//---------------------------local
    gotoxy(40,22);gets(eC->curso);

//--------------------------------tema
    gotoxy(40,25);gets(eC->email);
//-----------------------------palestrantes
    //verificar se est]ao cadastrados
    gotoxy(40,28);gets(eC->nome);
}
void editarCongressista(LISTAC* li, int matriculaINFO){

    if(li !=NULL){
        CAPSC* aux=li->inicio;
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.MatriculaC==matriculaINFO){
                VcadastrarCongressista();
                gotoxy(27,32);printf("%d",aux->dado.MatriculaC);
                //------------------------------capacidade
                gotoxy(48,13);printf("%d =>",aux->dado.idade);
                gotoxy(54,13);scanf("%d",&aux->dado.idade);setbuf(stdin,NULL);
                //-----------------------horario
                gotoxy(42,16);printf("%s",aux->dado.telefone);
                gotoxy(40,17);printf("=>");
                gotoxy(42,17);gets(aux->dado.telefone);
                //---------------------------------------carga horaria
                gotoxy(40,19);printf("%s",aux->dado.cpf);
                gotoxy(38,20);printf("=>");
                gotoxy(40,20);gets(aux->dado.cpf);

                //---------------------------local
                gotoxy(40,22);printf("%s",aux->dado.curso);
                gotoxy(38,23);printf("=>");
                gotoxy(40,23);gets(aux->dado.curso);
                //--------------------------------tema
                gotoxy(40,25);printf("%s",aux->dado.email);
                gotoxy(38,26);printf("=>");
                gotoxy(40,26);gets(aux->dado.email);
                //-----------------------------palestrantes
                //verificar se est]ao cadastrados
                gotoxy(40,28);printf("%s",aux->dado.nome);
                gotoxy(38,29);printf("=>");
                gotoxy(40,29);gets(aux->dado.nome);

                VeditadoComSucesso();
                return;
            }
            aux=aux->proximo;
        }
        //caso nao tenha entrado no if e dado break;
        AvisoNumeroNaoEncontrado();
        return;
    }else{
        printf("ERRO DE ALOCACAO!!!\n");
    }
}

