#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "Organizador.h"
#include "Visual.h"


typedef struct organizador ORGANIZADOR;
typedef struct capsulaO CAPSO;
typedef struct listaO LISTAO;


LISTAO* CriarO(){
    LISTAO* li=(LISTAO*)malloc(sizeof(LISTAO));
    if(li!=NULL){
        li->inicio=NULL;
    }
    return li;

}
void liberarO(LISTAO *li){
    if(li==NULL){
        //ERRO
    }else{
        CAPSO *aux;
        while(li->inicio!=NULL){
            aux=li->inicio;
            li->inicio=li->inicio->proximo;
            free(aux);
        }
        free(li);
    }
}
void mostrarTodosO(LISTAO* li){
    system("cls");
    //mostrar todos os campeonados cadastrados
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");//FAZER UMA RESTRICAO PARA NAO ENTRAR COM ELA VAZIA
        }else{
            CAPSO* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
                printf("  Matricula: %d   \n",aux->dado.MatriculaO);
                printf("  Nome: %s        \n",aux->dado.nome);
                printf("  CPF: %s         \n",aux->dado.cpf);
                printf("  telefone: %s    \n",aux->dado.telefone);
                printf("  Email: %s       \n",aux->dado.email);
                PlinhaH(50);PFchar(217);printf("\n");

                aux=aux->proximo;
            }
        }
    }
}

int tamanhoListaO(LISTAO *li){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //vazia
        }else{
            int cont=0;
            CAPSO *aux=li->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont++;
        }
    }
}

void inserirListaO(LISTAO *li,ORGANIZADOR eO){//insere na ordem de matricula
    if(li==NULL){
        //ERRO
    }else{
        CAPSO *novo= (CAPSO*)malloc(sizeof(CAPSO));
        if(novo!=NULL){
            novo->dado= eO;
            if(li->inicio==NULL){//insercao com lista vazia
                novo->proximo=NULL;
                li->inicio=novo;
            }else{//insercao no inicio quando ja tem alguem na lista
                CAPSO *aux=li->inicio;
                if(aux->dado.MatriculaO>novo->dado.MatriculaO){// se o dado que tiver la for maior do que o que esta inserindo ai ele entra na frente[b] = [a,b]
                    novo->proximo=aux;
                    li->inicio=novo;
                }else{//insercao no meio ou no fim
                    CAPSO *ante;
                    while((aux!=NULL)&&(aux->dado.MatriculaO<novo->dado.MatriculaO)){//enquanto o auxiliar for menor do que o dado inserido
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
int mostrarEmRemoverO(CAPSO *aux){
    linhaH(50,7,20);linhaV(12,7,20);linhaH(50,7,31);linhaV(12,56,20);
    Pchar(7,20,218);Pchar(56,20,191);Pchar(7,31,192);Pchar(56,31,217);
    gotoxy(9,22);printf("MATRICULA: %d",aux->dado.MatriculaO);
    gotoxy(9,24);printf("NOME: %s",aux->dado.nome);
    gotoxy(9,25);printf("CPF: %s",aux->dado.cpf);
    gotoxy(9,26);printf("TELEFONE: %s",aux->dado.telefone);
    gotoxy(9,27);printf("EMAIL: %s",aux->dado.email);
    VdesejaRemover();
    int op=getch();
    if(op==1){
        return 0;
    }else{
        return 1;
        }

}
int removerListaO(LISTAO *li,int num){//recebe numero da matricula

    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            CAPSO *aux=li->inicio;
            if(aux->dado.MatriculaO==num){//se for o 1 da lista
                li->inicio=aux->proximo;//inicio aponta pro proximo
                if(mostrarEmRemoverO(aux)){
                    return 1;
                }
                free(aux);
                return 0;
            }else{
                CAPSO *ante;
                while((aux!=NULL)&&(aux->dado.MatriculaO!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    AvisoNumeroNaoEncontrado();
                    return 1;
                }
                ante->proximo=aux->proximo;//
                if(mostrarEmRemoverO(aux)){//se deseja realmente remover
                        return 1;
                }
                free(aux);
                return 0;
            }
        }
    }

}


void pegarInfoOrganizador(ORGANIZADOR *eO,LISTAO *liO,int MatriculaO){

    gotoxy(21,29);printf("%d",MatriculaO);
    eO->MatriculaO=MatriculaO;

//-----------------------nome
    gotoxy(17,17);gets(eO->nome);
//---------------------------------cpf
    gotoxy(16,20);gets(eO->cpf);

//------------------------telefone
    gotoxy(21,23);gets(eO->telefone);

//-----------------------------email
    gotoxy(18,26);gets(eO->email);

}


void editarOrganizador(LISTAO* li, int matriculaINFO){

    if(li !=NULL){
        CAPSO* aux=li->inicio;
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.MatriculaO==matriculaINFO){
                VcadastrarOrganizador();
                gotoxy(21,29);printf("%d",aux->dado.MatriculaO);
                //------------------------------ANTIGO caixa de baixo
                linhaH(65,12,31);linhaV(3,12,31);linhaH(65,12,33);linhaV(3,77,31);
                Pchar(12,31,218);Pchar(77,31,191);Pchar(12,33,192);Pchar(77,33,217);
                //-----------------------nome
                gotoxy(15,32);printf("ANTIGO => %s",aux->dado.nome);
                gotoxy(17,17);gets(aux->dado.nome);
                gotoxy(15,32);printf("                                                      ");//limpa a parte do antigo para mostrar o proximo
                //------------------------------cpf
                gotoxy(15,32);printf("ANTIGO => %s",aux->dado.cpf);
                gotoxy(16,20);gets(aux->dado.cpf);
                gotoxy(15,32);printf("                                                      ");
                //---------------------telefone
                gotoxy(15,32);printf("ANTIGO => %s",aux->dado.telefone);
                gotoxy(21,23);gets(aux->dado.telefone);
                gotoxy(15,32);printf("                                                      ");
                //-------------------------email
                gotoxy(15,32);printf("ANTIGO => %s",aux->dado.email);
                gotoxy(18,26);gets(aux->dado.email);
                gotoxy(15,32);printf("                                                      ");
                //-----------------------------palestrantes
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

