#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<windows.h>
#include "Palestra.h"
#include "Palestrante.h"
#include "Visual.h"

char horasBASE[7][10]={"0","07:00","08:00","09:00","10:00","11:00","12:00"};
char horasL1[7][10]={"0","07:00","08:00","09:00","10:00","11:00","12:00"};
char horasL2[7][10]={"0","07:00","08:00","09:00","10:00","11:00","12:00"};
char horasL3[7][10]={"0","07:00","08:00","09:00","10:00","11:00","12:00"};

typedef struct palestra PALESTRA;
typedef struct capsula CAPS;
typedef struct lista LISTA;

typedef struct palestrante PALESTRANTE;
typedef struct capsulapT CAPSpT;
typedef struct listapT LISTApT;

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
    system("cls");
    //mostrar todos os campeonados cadastrados
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPS* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
                printf("  Cadastro: %d        \n",aux->dado.n_cadastroP);
                printf("  Horario: %s         \n",aux->dado.horario);
                printf("  Carga horaria: %d   \n",aux->dado.cargaHoraria);
                printf("  local: Auditorio %d \n",aux->dado.local);
                printf("  Capacidade: %d      \n",aux->dado.capacidade);
                printf("  Tema: %s            \n",aux->dado.tema);
                printf("  Palestrante: %s     \n",aux->dado.palestrante);
                PFchar(192);PlinhaH(50);PFchar(217);printf("\n");

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

void inserirLista(LISTA *li,PALESTRA eP){//insere na ordem de matricula
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
int removerLista(LISTA *li,int num){//recebe numero da matricula

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
                    return 1;
                }
                free(aux);
                return 0;
            }else{
                CAPS *ante;
                while((aux!=NULL)&&(aux->dado.n_cadastroP!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    AvisoNumeroNaoEncontrado();
                    return 1;
                }
                ante->proximo=aux->proximo;//
                if(mostrarEmRemover(aux)){//se deseja realmente remover
                        return 1;
                }
                free(aux);
                return 0;
            }
        }
    }

}

int PegarLocalPalestra(){
    //transforma a opcao local 1,2,3 em uma string
    int local;
    int on=1;
    while(on){
        gotoxy(42,17);printf("[Entre 1-3]");
        gotoxy(46,16);scanf("%d",&local);setbuf(stdin,NULL);

        switch(local){
            case 1:
                gotoxy(42,16);printf("Auditorio 1");
                on=0;
                break;
            case 2:
                gotoxy(42,16);printf("Auditorio 2");
                on=0;
                break;
            case 3:
                gotoxy(42,16);printf("Auditorio 3");

                on=0;
                break;
            default:
                gotoxy(39,32);printf("POR FAVOR ESCOLHA UMA ENTRE AS OPCOES!!!");

        }

    }
    gotoxy(39,32);printf("                                                            ");
    gotoxy(42,17);printf("             ");
    return local;
}

int PegarHorarioPalestra(char horas[7][10]){

    int hora;
    int on=1;
    while(on){
        gotoxy(48,22);scanf("%d",&hora);setbuf(stdin,NULL);

        switch(hora){
            case 1:
                gotoxy(46,22);printf("%s",horas[hora]);
                return hora;
            case 2:
                gotoxy(46,22);printf("%s",horas[hora]);
                return hora;
            case 3:
                gotoxy(46,22);printf("%s",horas[hora]);
                return hora;
            case 4:
                gotoxy(46,22);printf("%s",horas[hora]);
                return hora;
            case 5:
                gotoxy(46,22);printf("%s",horas[hora]);
                return hora;
            case 6:
                gotoxy(46,22);printf("%s",horas[hora]);
                return hora;
            default:
                gotoxy(39,32);printf("POR FAVOR ESCOLHA UMA ENTRE AS OPCOES!!!");

        }

    }
    gotoxy(39,32);printf("                                                            ");
}

void pegarInfoPalestra(PALESTRA *eP,LISTA *liP,int n_cadastroP, LISTApT *lipT){

    gotoxy(27,32);printf("%d",n_cadastroP);
    eP->n_cadastroP=n_cadastroP;
//------------------------------capacidade
    gotoxy(48,13);printf("---");
//-----------------------local
    AvisoEventoLimpar();
    AvisoEventoPalestraLocais();
    eP->local=PegarLocalPalestra();//eP->local
    //capacidade dependendo do local
        if(eP->local==1){
            eP->capacidade =150;
        }
        if(eP->local==2){
            eP->capacidade =100;
        }
        if(eP->local==3){
            eP->capacidade =50;
        }
        gotoxy(48,13);printf("   ");
        gotoxy(48,13);printf("%d",eP->capacidade);setbuf(stdin,NULL);



    AvisoEventoLimpar();
//---------------------------------------carga horaria
    gotoxy(48,19);scanf("%d",&eP->cargaHoraria);setbuf(stdin,NULL);

//---------------------------horario

    int H;
    if(eP->local==1){
            AvisoEventoHorarios(horasL1);
            H =PegarHorarioPalestra(horasL1);
            strcpy(eP->horario,horasL1[H]);
            strcpy(horasL1[H],"indis.");
        }
        if(eP->local==2){
            AvisoEventoHorarios(horasL2);
            H =PegarHorarioPalestra(horasL2);
            strcpy(eP->horario,horasL2[H]);
            strcpy(horasL2[H],"indis.");
        }
        if(eP->local==3){
            AvisoEventoHorarios(horasL3);
            H =PegarHorarioPalestra(horasL3);
            strcpy(eP->horario,horasL3[H]);
            strcpy(horasL3[H],"indis.");
        }
        eP->EditH=H;//guardar a posição no vetor para quando for editar



//--------------------------------tema
    AvisoEventoLimpar();
    gotoxy(40,25);gets(eP->tema);setbuf(stdin,NULL);
//-----------------------------palestrantes
    //verificar se est]ao cadastrados
    int palestranteP;
    AvisoP();
    gotoxy(40,28);scanf("%d",&palestranteP);setbuf(stdin,NULL);
    char *nome=(char*)malloc(50*sizeof(char));
    strcpy(eP->palestrante,MostrarPalestrantes(lipT,&nome));
    free(nome);

}

void EditarLocalPalestra(CAPS *aux){
    //transforma a opcao local 1,2,3 em uma string

    //Verificar qual a escolhida e diminuir um para alterar caso ele va do aud 1 para o 2; o 1 diminui 1 e o 2 aumenta-ra 1 dps
    if(aux->dado.local==1){
        gotoxy(42,16);printf("Auditorio 1");
    }
    if(aux->dado.local==2){
        gotoxy(42,16);printf("Auditorio 2");
    }
    if(aux->dado.local==3){
        gotoxy(42,16);printf("Auditorio 3");
    }
    int on=1;
    while(on){
        gotoxy(43,17);printf("       ");
        gotoxy(43,17);printf("=>");
        gotoxy(46,17);scanf("%d",&aux->dado.local);setbuf(stdin,NULL);
        switch(aux->dado.local){
            case 1:
                gotoxy(40,17);printf("=>Auditorio 1");
                on=0;
                break;
            case 2:
                gotoxy(40,17);printf("=>Auditorio 2");
                on=0;
                break;
            case 3:
                gotoxy(40,17);printf("=>Auditorio 3");
                on=0;
                break;
            default:
                gotoxy(39,32);printf("POR FAVOR ESCOLHA UMA ENTRE AS OPCOES!!!");

        }

    }
    gotoxy(39,32);printf("                                                            ");
}

EditarHorarioPalestra(CAPS *aux){
    //transforma a opcao local 1,2,3 em uma string

    //Verificar qual a escolhida e diminuir um para alterar caso ele va do aud 1 para o 2; o 1 diminui 1 e o 2 aumenta-ra 1 dps
    gotoxy(46,23);printf("%s",aux->dado.horario);

        gotoxy(44,22);printf("=>");
        int H;
    if(aux->dado.local==1){
            strcpy(horasL1[aux->dado.EditH],horasBASE[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoHorarios(horasL1);//mostra os horarios disponiveis
            H =PegarHorarioPalestra(horasL1);//pega a posicao da hora
            strcpy(aux->dado.horario,horasL1[H]);//e guarda essa hora
            strcpy(horasL1[H],"indis.");//dps transforma ela em indispponivel
        }
        if(aux->dado.local==2){//cada palestra pode ocorrer em locais diferentes so que na mesma hora
            strcpy(horasL2[aux->dado.EditH],horasBASE[aux->dado.EditH]);
            AvisoEventoHorarios(horasL2);
            H =PegarHorarioPalestra(horasL2);
            strcpy(aux->dado.horario,horasL2[H]);
            strcpy(horasL2[H],"indis.");
        }
        if(aux->dado.local==3){
            strcpy(horasL3[aux->dado.EditH],horasBASE[aux->dado.EditH]);
            AvisoEventoHorarios(horasL3);
            H =PegarHorarioPalestra(horasL3);
            strcpy(aux->dado.horario,horasL3[H]);
            strcpy(horasL3[H],"indis.");
        }


    gotoxy(39,32);printf("                                                            ");
}

void editarPalestra(LISTA* li, int cadastroINFO,LISTApT *lipT){
    if(li !=NULL){
        CAPS* aux=li->inicio;
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.n_cadastroP==cadastroINFO){
                VcadastrarPalestra();
                gotoxy(27,32);printf("%d",aux->dado.n_cadastroP);
                //------------------------------capacidade
                gotoxy(48,13);printf("%d =>---",aux->dado.capacidade);setbuf(stdin,NULL);

                //-----------------------local
                AvisoEventoLimpar();
                AvisoEventoPalestraLocais();
                EditarLocalPalestra(aux);
                //capacidade
                if(aux->dado.local==1){
                    aux->dado.capacidade =150;
                }
                if(aux->dado.local==2){
                    aux->dado.capacidade =100;
                }
                if(aux->dado.local==3){
                    aux->dado.capacidade =50;
                }
                gotoxy(54,13);printf("   ");
                gotoxy(54,13);printf("%d",aux->dado.capacidade);
                AvisoEventoLimpar();


                //---------------------------------------carga horaria
                gotoxy(48,19);printf("%d =>",aux->dado.cargaHoraria);
                gotoxy(54,19);scanf("%d",&aux->dado.cargaHoraria);setbuf(stdin,NULL);

                //---------------------------horario

                EditarHorarioPalestra(aux);
                AvisoEventoLimpar();


                //--------------------------------tema

                gotoxy(40,25);printf("%s",aux->dado.tema);
                gotoxy(38,26);printf("=>");
                gotoxy(40,26);gets(aux->dado.tema);setbuf(stdin,NULL);
                //-----------------------------palestrantes
                //verificar se est]ao cadastrados
                int palestranteP;
                AvisoP();
                gotoxy(40,28);scanf("%d",&palestranteP);setbuf(stdin,NULL);
                strcpy(aux->dado.palestrante,MostrarPalestrantesGRUPOS(lipT,-1));
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

void adicionarCongressista(LISTA *li,int Palestra,char *nome,int MAT){
    //adiciona na palestra informada o nome, e matricula
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPS* aux = li->inicio;
            while(aux!=NULL){
                if(aux->dado.n_cadastroP==Palestra){//acha a palestra
                    for(int i=0;i<150;i++){
                        if(aux->dado.CongN[i]==0){//adiciona o nome onde tiver vago
                           aux->dado.CongN[i]=MAT;
                           strcpy(aux->dado.CongNome[i],nome);


                            return;
                        }
                    }
                }

                aux=aux->proximo;
            }
        }
    }



}

//mostrar todos os congressistas em determinada palestra
void MostrarCongressistaPorPalestra(LISTA *li,int Palestra){
    system("cls");

    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPS* aux = li->inicio;
            printf("CONGRESSISTAS CADASTRADOS NA PALESTRA %d\n",Palestra);
            PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                if(aux->dado.n_cadastroP==Palestra){
                    for(int i=0;i<150;i++){
                        if((aux->dado.CongN[i]!=0)&&(aux->dado.CongN[i])){
                            printf("     %d   -   %s\n",aux->dado.CongN[i],aux->dado.CongNome[i]);
                        }else{
                            break;
                        }
                    }

                }

                aux=aux->proximo;
            }
            PFchar(192);PlinhaH(50);PFchar(217);printf("\n");
        }
    }

}

void RemoverCongressistaDaPalestra(LISTA *li,int Palestra,int Matricula){

    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPS* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                if(aux->dado.n_cadastroP==Palestra){
                    for(int i=0;i<150;i++){
                        if(aux->dado.CongN[i]==Matricula){
                            aux->dado.CongN[i]=0;
                            strcpy(aux->dado.CongNome[i],"---");
                        }
                    }
                }
                aux=aux->proximo;
            }
        }
    }

}


void desocuparPalestrante(LISTApT *lipT,LISTA *liP,int Palestra){
    if(liP==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(liP->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPS* aux = liP->inicio;
            CAPSpT* aux2=lipT->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                if(aux->dado.n_cadastroP==Palestra){
                    if(strcmp(aux->dado.palestrante,aux2->dado.nome)==0){
                    aux2->dado.ocupado=0;
                }

                }
                aux2=aux2->proximo;
                aux=aux->proximo;
            }
        }
    }

}

void removerHorario(LISTA *li, int Palestra){
     if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPS* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                if(aux->dado.local==1){
                strcpy(horasL1[aux->dado.EditH],horasBASE[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
                }
                if(aux->dado.local==2){
                strcpy(horasL2[aux->dado.EditH],horasBASE[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
                }
                if(aux->dado.local==3){
                strcpy(horasL2[aux->dado.EditH],horasBASE[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
                }


                aux=aux->proximo;
            }
        }
    }

}

