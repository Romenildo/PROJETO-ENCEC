#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "Palestrante.h"
#include "Visual.h"

typedef struct palestrante PALESTRANTE;
typedef struct capsulapT CAPSpT;
typedef struct listapT LISTApT;

LISTApT* CriarpT(){
    LISTApT* li=(LISTApT*)malloc(sizeof(LISTApT));
    if(li!=NULL){
        li->inicio=NULL;
    }
    return li;

}
void liberarpT(LISTApT *li){
    if(li==NULL){
        //ERRO
    }else{
        CAPSpT *aux;
        while(li->inicio!=NULL){
            aux=li->inicio;
            li->inicio=li->inicio->proximo;
            free(aux);
        }
        free(li);
    }
}
void mostrarTodospT(LISTApT* li){
    system("cls");
    //mostrar todos os campeonados cadastrados
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");//FAZER UMA RESTRICAO PARA NAO ENTRAR COM ELA VAZIA
        }else{
            CAPSpT* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
                printf("  Matricula: %d     \n",aux->dado.MatriculapT);
                printf("  Nome: %s          \n",aux->dado.nome);
                printf("  CPF: %s           \n",aux->dado.cpf);
                printf("  telefone: %s      \n",aux->dado.telefone);
                printf("  Email: %s         \n",aux->dado.email);
                PFchar(192);PlinhaH(50);PFchar(217);printf("\n");

                aux=aux->proximo;
            }
        }
    }
}

int tamanhoListapT(LISTApT *li){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //vazia
        }else{
            int cont=0;
            CAPSpT *aux=li->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont++;
        }
    }
}

void inserirListapT(LISTApT *li,PALESTRANTE pT){//insere na ordem de matricula
    if(li==NULL){
        //ERRO
    }else{
        CAPSpT *novo= (CAPSpT*)malloc(sizeof(CAPSpT));
        if(novo!=NULL){
            novo->dado= pT;
            if(li->inicio==NULL){//insercao com lista vazia
                novo->proximo=NULL;
                li->inicio=novo;
            }else{//insercao no inicio quando ja tem alguem na lista
                CAPSpT *aux=li->inicio;
                if(aux->dado.MatriculapT>novo->dado.MatriculapT){// se o dado que tiver la for maior do que o que esta inserindo ai ele entra na frente[b] = [a,b]
                    novo->proximo=aux;
                    li->inicio=novo;
                }else{//insercao no meio ou no fim
                    CAPSpT *ante;
                    while((aux!=NULL)&&(aux->dado.MatriculapT<novo->dado.MatriculapT)){//enquanto o auxiliar for menor do que o dado inserido
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
int mostrarEmRemoverpT(CAPSpT *aux){
    linhaH(50,7,20);linhaV(12,7,20);linhaH(50,7,31);linhaV(12,56,20);
    Pchar(7,20,218);Pchar(56,20,191);Pchar(7,31,192);Pchar(56,31,217);
    gotoxy(9,22);printf("MATRICULA: %d",aux->dado.MatriculapT);
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
int removerListapT(LISTApT *li,int num){//recebe numero da matricula

    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            CAPSpT *aux=li->inicio;
            if(aux->dado.MatriculapT==num){//se for o 1 da lista
                li->inicio=aux->proximo;//inicio aponta pro proximo
                if(mostrarEmRemoverpT(aux)==1){
                    return 1;
                }
                free(aux);
                return 0;
            }else{
                CAPSpT *ante;
                while((aux!=NULL)&&(aux->dado.MatriculapT!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    AvisoNumeroNaoEncontrado();
                    return 1;
                }
                ante->proximo=aux->proximo;//
                if(mostrarEmRemoverpT(aux)==1){//se deseja realmente remover
                        return 1;
                }
                free(aux);
                return 0;
            }
        }
    }

}


void pegarInfoPalestrante(PALESTRANTE *pT,LISTApT *lipT,int MatriculapT){

    gotoxy(21,29);printf("%d",MatriculapT);
    pT->MatriculapT=MatriculapT;

//-----------------------nome
    gotoxy(17,17);gets(pT->nome);
//---------------------------------cpf
    gotoxy(16,20);gets(pT->cpf);

//------------------------telefone
    gotoxy(21,23);gets(pT->telefone);

//-----------------------------email
    gotoxy(18,26);gets(pT->email);

}


void editarPalestrante(LISTApT* li, int matriculaINFO){

    if(li !=NULL){
        CAPSpT* aux=li->inicio;
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.MatriculapT==matriculaINFO){
                VcadastrarPalestrante();
                gotoxy(12,13);printf("                       ");
                gotoxy(12,13);printf("EDITAR PALESTRANTE");
                gotoxy(21,29);printf("%d",aux->dado.MatriculapT);
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

char *MostrarPalestrantes(LISTApT* li,char *nome){
    //mostra os palestrantes disponiveis dps pede qual quer escolher e adiciona ele
    system("cls");
    if(li!=NULL){
        CAPSpT* aux=li->inicio;
        int y=3;
        printf("             PALESTRANTES DISPONIVEIS\n");
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.ocupado==0){
                PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
                printf("   %d  :  %s  \n",aux->dado.MatriculapT,aux->dado.nome);
                PFchar(192);PlinhaH(50);PFchar(217);printf("\n");
            }

            aux=aux->proximo;
        }
        int Procurar;

        printf("DIGITE A MATRICULA: ");scanf("%d",&Procurar);setbuf(stdin,NULL);

        CAPSpT* aux0=li->inicio;
        while(aux0!=NULL){//varre todos da lista
            if(aux0->dado.MatriculapT==Procurar){
                strcpy(nome,aux0->dado.nome);
                aux0->dado.ocupado=1;
                break;
            }
            aux0=aux0->proximo;
        }
        return nome;
    }else{
        printf("ERRO DE ALOCACAO!!!\n");
    }
}
char *MostrarPalestrantesGRUPOS(LISTApT* li,int X){
    //mostra os palestrantes disponiveis dps pede qual quer escolher e adiciona ele
    system("cls");
    if(li!=NULL){
        CAPSpT* aux=li->inicio;
        printf("             PALESTRANTES DISPONIVEIS\n");
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.ocupado==0){
                PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
                printf("   %d  :  %s  \n",aux->dado.MatriculapT,aux->dado.nome);
                PFchar(192);PlinhaH(50);PFchar(217);printf("\n");
            }

            aux=aux->proximo;
        }
        int Procurar;

        printf("DIGITE A MATRICULA DO %d: ",X+1);scanf("%d",&Procurar);setbuf(stdin,NULL);

        CAPSpT* aux0=li->inicio;
        char *nome=(char*)malloc(50*sizeof(char));

        while(aux0!=NULL){//varre todos da lista
            if(aux0->dado.MatriculapT==Procurar){
                strcpy(nome,aux0->dado.nome);
                aux0->dado.ocupado=1;
                break;
            }
            aux0=aux0->proximo;
        }
        return nome;
    }else{
        printf("ERRO DE ALOCACAO!!!\n");
    }
}

