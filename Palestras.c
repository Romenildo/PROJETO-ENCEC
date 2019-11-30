#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "Visual.h"

int limAud1=0;
int limAud2=0;
int limAud3=0;


#define C_RESET   "\x1b[0m"
#define C_BLACK      "\x1b[30m"
#define C_RED      "\x1b[31m"
#define C_GREEN      "\x1b[32m"
#define C_YELLOW      "\x1b[33m"
#define C_WATER      "\x1b[36m"
#define C_BLUE   "\x1b[34m"
#define C_WHITE      "\x1b[37m"

typedef struct{
    int n_cadastroP;
    int capacidade;
    char horario[5];
    int cargaHoraria;
    int local;//ou int local 1laboratorio 2
    char tema[30];
    char palestrante[30];
    int on;
}EVENTOP;//evento palestras


//--------------------------------fila para eventos-----------
typedef struct capsula{
    EVENTOP dado;
    struct capsula *proximo;
}CAPS;

typedef struct{
    CAPS *inicio;
}LISTA;

LISTA* Criar(){
    LISTA* li=(LISTA*)malloc(sizeof(LISTA));
    if(li!=NULL){
        li->inicio=NULL;
    }
    return li;

}
void liberar(LISTA *li){
    if(li==NULL){
        //ERRO
    }else{
        CAPS *aux;
        while(li->inicio!=NULL){
            aux=li->inicio;
            li->inicio=li->inicio->proximo;
            free(aux);
        }
        free(li);
    }
}
void mostrarTodosP(LISTA* li){
    //mostrar todos os campeonados cadastrados
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPS* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                printf("\nCadastro: %d                                       |",aux->dado.n_cadastroP);
                printf("\nHorario: %s",aux->dado.horario);
                printf("\nCarga horaria: %d",aux->dado.cargaHoraria);
                printf("\nlocal: Auditorio %d",aux->dado.local);
                printf("\nTema: %s",aux->dado.tema);
                printf("\nPalestrante: %s",aux->dado.palestrante);
                printf("\n--------------------------------------------\n");

                aux=aux->proximo;
            }
        }
    }
}

int tamanhoLista(LISTA *li){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //vazia
        }else{
            int cont=0;
            CAPS *aux=li->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont++;
        }
    }
}

void inserirLista(LISTA *li,EVENTOP eP){//insere na ordem de matricula
    if(li==NULL){
        //ERRO
    }else{
        CAPS *novo= (CAPS*)malloc(sizeof(CAPS));
        if(novo!=NULL){
            novo->dado= eP;
            if(li->inicio==NULL){//insercao com lista vazia
                novo->proximo=NULL;
                li->inicio=novo;
            }else{//insercao no inicio quando ja tem alguem na lista
                CAPS *aux=li->inicio;
                if(aux->dado.n_cadastroP>novo->dado.n_cadastroP){// se o dado que tiver la for maior do que o que esta inserindo ai ele entra na frente[b] = [a,b]
                    novo->proximo=aux;
                    li->inicio=novo;
                }else{//insercao no meio ou no fim
                    CAPS *ante;
                    while((aux!=NULL)&&(aux->dado.n_cadastroP<novo->dado.n_cadastroP)){//enquanto o auxiliar for menor do que o dado inserido
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
int mostrarEmRemover(CAPS *aux){
    linhaH(50,7,20);linhaV(12,7,20);linhaH(50,7,31);linhaV(12,56,20);
    Pchar(7,20,218);Pchar(56,20,191);Pchar(7,31,192);Pchar(56,31,217);
    gotoxy(9,22);printf("CADASTRO: %d",aux->dado.n_cadastroP);
    gotoxy(9,23);printf("CAPACIDADE: %d",aux->dado.capacidade);
    gotoxy(9,24);printf("HORARIO: %s",aux->dado.horario);
    gotoxy(9,25);printf("CARGA HORARIA: %d",aux->dado.cargaHoraria);
    gotoxy(9,26);printf("LOCAL: Auditorio %d",aux->dado.local);
    gotoxy(9,27);printf("TEMA: %s",aux->dado.tema);
    gotoxy(9,28);printf("PALESTRANTE: %s",aux->dado.palestrante);
    VdesejaRemover();
    int op=getch();
    if(op==1){
        return 0;
    }else{
        return 1;
        }

}
void removerLista(LISTA *li,int num){//recebe numero da matricula

    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            CAPS *aux=li->inicio;
            if(aux->dado.n_cadastroP==num){//se for o 1 da lista
                li->inicio=aux->proximo;//inicio aponta pro proximo
                if(mostrarEmRemover(aux)){
                    return;
                }
                free(aux);
            }else{
                CAPS *ante;
                while((aux!=NULL)&&(aux->dado.n_cadastroP!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    AvisoNumeroNaoEcontrado();
                    return;
                }
                ante->proximo=aux->proximo;//
                if(mostrarEmRemover(aux)){//se deseja realmente remover
                        return;
                }
                free(aux);
            }
        }
    }

}

int PegarLocalPalestra(EVENTOP *eP){
    //transforma a opcao local 1,2,3 em uma string

    int on=1;
    while(on){
        gotoxy(42,23);printf("[Entre 1-3]");
        gotoxy(46,22);scanf("%d",&eP->local);setbuf(stdin,NULL);

        switch(eP->local){
            case 1:
                gotoxy(42,22);printf("Auditorio 1");

                limAud1++;

                on=0;
                break;
            case 2:
                gotoxy(42,22);printf("Auditorio 2");

                limAud2++;

                on=0;
                break;
            case 3:
                gotoxy(42,22);printf("Auditorio 3");
                limAud3++;
                on=0;
                break;
            default:
                gotoxy(39,32);printf(C_RED"POR FAVOR ESCOLHA UMA ENTRE AS OPCOES!!!"C_WHITE);

        }

    }
    gotoxy(39,32);printf("                                                            ");
    gotoxy(42,23);printf("             ");
    return eP->local;
}

pegarInfoPalestra(EVENTOP *eP,LISTA *liP,int n_cadastroP){

    n_cadastroP++;//1000
    gotoxy(27,32);printf("%d",n_cadastroP);
    eP->n_cadastroP=n_cadastroP;
//------------------------------capacidade
    gotoxy(48,13);scanf("%d",&eP->capacidade);setbuf(stdin,NULL);
    while((eP->capacidade<50) || (eP->capacidade>150)){
        gotoxy(48,13);printf("              ");
        gotoxy(42,14);printf(C_RED"ENTRE 50 a 150"C_WHITE);
        gotoxy(39,32);printf(C_RED"A CAPACIDADE DEVE ESTAR ENTRE OS LIMITES PERMITIDOS!!!"C_WHITE);
        gotoxy(48,13);scanf("%d",&eP->capacidade);setbuf(stdin,NULL);//horario
        gotoxy(42,14);printf("                    ");
        gotoxy(39,32);printf("                                                              ");
    }
//-----------------------horario
    gotoxy(46,16);gets(eP->horario);
    while(strlen(eP->horario)!=5){//meeh criar uma fucnao que verifica horario se formato for igual e tier disponivel e retunar 1 se sim
        gotoxy(43,17);printf(C_RED"FORMATO 00:00"C_WHITE);
        gotoxy(39,32);printf(C_RED"DEVE ESTAR NO FORMATO DE 00:00 E TER HORARIO DISPONIVEL!!!"C_WHITE);
        gotoxy(48,16);printf("      ");
        gotoxy(46,16);gets(eP->horario);
        gotoxy(43,17);printf("                 ");
        gotoxy(39,32);printf("                                                            ");
    }
    //deve estar no formato 00:00
//---------------------------------------carga horaria
    gotoxy(48,19);scanf("%d",&eP->cargaHoraria);setbuf(stdin,NULL);

//---------------------------local
    AvisoEventoLimpar();
    AvisoEventoPalestraLocais(limAud1,limAud2,limAud3);
    eP->local=PegarLocalPalestra(&eP);//eP->local


//--------------------------------tema
    AvisoEventoLimpar();
    gotoxy(40,25);gets(eP->tema);
//-----------------------------palestrantes
    //verificar se est]ao cadastrados
    gotoxy(40,28);gets(eP->palestrante);
        //verificarPalestrante(&eP,&p,palestrante[i]);//mostrar na frente do numero o erro em vermelho
}
//verificarPalestrante(PALESTRANTES *p, char palestrante){
                //verificar os palestrantes cadastrados com os digitados
                //se nao encontrar pedir pra digitar novamente e mostra mensagem de erro


EditarLocalPalestra(CAPS *aux){
    //transforma a opcao local 1,2,3 em uma string

    //Verificar qual a escolhida e diminuir um para alterar caso ele va do aud 1 para o 2; o 1 diminui 1 e o 2 aumenta-ra 1 dps
    if(aux->dado.local==1){
        limAud1--;
        gotoxy(42,22);printf("Auditorio 1");
    }
    if(aux->dado.local==2){
        limAud2--;
        gotoxy(42,22);printf("Auditorio 2");
    }
    if(aux->dado.local==3){
        limAud3--;
        gotoxy(42,22);printf("Auditorio 3");
    }
    //caso a pessoa escolha aud 1 e quando editar aud 1 novamente ele ira diminuir, mais adicionara 1 novamente depois
    int on=1;
    while(on){
        gotoxy(43,23);printf("=>");
        gotoxy(46,23);scanf("%d",&aux->dado.local);setbuf(stdin,NULL);
        switch(aux->dado.local){
            case 1:
                gotoxy(42,23);printf("Auditorio 1");

                limAud1++;

                on=0;
                break;
            case 2:
                gotoxy(42,23);printf("Auditorio 2");

                limAud2++;

                on=0;
                break;
            case 3:
                gotoxy(42,23);printf("Auditorio 3");
                limAud3++;
                on=0;
                break;
            default:
                gotoxy(39,32);printf(C_RED"POR FAVOR ESCOLHA UMA ENTRE AS OPCOES!!!"C_WHITE);

        }

    }
    gotoxy(39,32);printf("                                                            ");
}

void editarPalestra(LISTA* li, int cadastroINFO){

    if(li !=NULL){
        CAPS* aux=li->inicio;
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.n_cadastroP==cadastroINFO){
                VcadastrarPalestra();
                gotoxy(27,32);printf("%d",aux->dado.n_cadastroP);
                //------------------------------capacidade
                gotoxy(48,13);printf("%d =>",aux->dado.capacidade);
                gotoxy(54,13);scanf("%d",&aux->dado.capacidade);setbuf(stdin,NULL);
                while((aux->dado.capacidade<50) || (aux->dado.capacidade>150)){
                    gotoxy(48,13);printf("              ");
                    gotoxy(42,14);printf(C_RED"ENTRE 50 a 150"C_WHITE);
                    gotoxy(39,32);printf(C_RED"A CAPACIDADE DEVE ESTAR ENTRE OS LIMITES PERMITIDOS!!!"C_WHITE);
                    gotoxy(48,13);printf("%d =>",aux->dado.capacidade);
                    gotoxy(54,13);scanf("%d",&aux->dado.capacidade);setbuf(stdin,NULL);//horario
                    gotoxy(42,14);printf("                    ");
                    gotoxy(39,32);printf("                                                              ");
                }
                //-----------------------horario
                gotoxy(46,16);printf("%s =>",aux->dado.horario);
                gotoxy(55,16);gets(aux->dado.horario);
                while(strlen(aux->dado.horario)!=5){//meeh criar uma fucnao que verifica horario se formato for igual e tier disponivel e retunar 1 se sim
                gotoxy(43,17);printf(C_RED"FORMATO 00:00"C_WHITE);
                gotoxy(39,32);printf(C_RED"DEVE ESTAR NO FORMATO DE 00:00 E TER HORARIO DISPONIVEL!!!"C_RESET);
                gotoxy(48,16);printf("      ");
                gotoxy(55,16);gets(aux->dado.horario);
                gotoxy(43,17);printf("                 ");
                gotoxy(39,32);printf("                                                            ");
                }
                //---------------------------------------carga horaria
                gotoxy(48,19);printf("%d =>",aux->dado.cargaHoraria);
                gotoxy(54,19);scanf("%d",&aux->dado.cargaHoraria);setbuf(stdin,NULL);

                //---------------------------local
                AvisoEventoLimpar();
                AvisoEventoPalestraLocais(limAud1,limAud2,limAud3);
                EditarLocalPalestra(aux);
                AvisoEventoLimpar();

                //--------------------------------tema
                gotoxy(40,25);printf("%s",aux->dado.tema);
                gotoxy(38,26);printf("=>");
                gotoxy(40,26);gets(aux->dado.tema);
                //-----------------------------palestrantes
                //verificar se est]ao cadastrados
                gotoxy(40,28);printf("%s",aux->dado.palestrante);
                gotoxy(38,29);printf("=>");
                gotoxy(40,29);gets(aux->dado.palestrante);

                VeditadoComSucesso();
                return;
            }
            aux=aux->proximo;
        }
        //caso nao tenha enrado no if e dado break;
        AvisoNumeroNaoEcontrado();
        return;
    }else{
        printf("ERRO DE ALOCACAO!!!\n");
    }
}



main(){

    VcadastrarPalestra();
    EVENTOP eP;
    LISTA *liP=Criar();
    int n_cadastroP=1000;

    pegarInfoPalestra(&eP,liP,n_cadastroP);
    inserirLista(liP,eP);
    //mostrar todos
    //
    system("cls");
    int num_editar;
    VeditarPalestra();
    gotoxy(22,17);scanf("%d",&num_editar);
    system("cls");
    editarPalestra(liP,num_editar);
    //
    system("cls");
    mostrarTodosP(liP);
    getchar();
    getchar();
    //remover
    system("cls");
    int num_remover;
    VremoverPalestra();
    gotoxy(19,17);scanf("%d",&num_remover);
    removerLista(liP,num_remover);
//editar


    liberar(liP);
}
