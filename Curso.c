#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Cursos.h"
#include "Palestrante.h"
#include "Visual.h"

char KhorasTarde[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char KhorasS1[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};//grupo sala 1
char KhorasS2[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char KhorasS3[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char KhorasL1[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char KhorasL2[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};

typedef struct eventoK EVENTOK;
typedef struct capsulaK CAPSK;
typedef struct listaK LISTAK;

LISTAK* CriarK(){
    LISTAK* li=(LISTAK*)malloc(sizeof(LISTAK));
    if(li!=NULL){
        li->inicio=NULL;
    }
    return li;

}
void liberarK(LISTAK *li){
    if(li==NULL){
        //ERRO
    }else{
        CAPSK *aux;
        while(li->inicio!=NULL){
            aux=li->inicio;
            li->inicio=li->inicio->proximo;
            free(aux);
        }
        free(li);
    }
}
void mostrarTodosK(LISTAK* li){
    system("cls");
    //mostrar todos os campeonados cadastrados
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPSK* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
                printf("  Cadastro: %d        \n",aux->dado.n_cadastroK);
                printf("  Horario: %s         \n",aux->dado.horario);
                printf("  Carga horaria: %d   \n",aux->dado.cargaHoraria);
                if(aux->dado.local==4){
                    printf("  local: Lab 1 \n");
                }else{
                    if(aux->dado.local==5){
                        printf("  local: Lab 2 \n");
                    }else{
                        printf("  local: Sala %d \n",aux->dado.local);
                    }
                }
                printf("  Capacidade: %d      \n",aux->dado.capacidade);
                printf("  Tema: %s            \n",aux->dado.tema);
                printf("  Palestrante: %s     \n",aux->dado.palestrante);


                PFchar(192);PlinhaH(50);PFchar(217);printf("\n");

                aux=aux->proximo;
            }
        }
    }
}
int tamanhoListaK(LISTAK *li){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //vazia
        }else{
            int cont=0;
            CAPSK *aux=li->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont++;
        }
    }
}
void inserirListaK(LISTAK *li,EVENTOK eK){//insere na ordem de matricula
    if(li==NULL){
        //ERRO
    }else{
        CAPSK *novo= (CAPSK*)malloc(sizeof(CAPSK));
        if(novo!=NULL){
            novo->dado= eK;
            if(li->inicio==NULL){//insercao com lista vazia
                novo->proximo=NULL;
                li->inicio=novo;
            }else{//insercao no inicio quando ja tem alguem na lista
                CAPSK *aux=li->inicio;
                if(aux->dado.n_cadastroK>novo->dado.n_cadastroK){// se o dado que tiver la for maior do que o que esta inserindo ai ele entra na frente[b] = [a,b]
                    novo->proximo=aux;
                    li->inicio=novo;
                }else{//insercao no meio ou no fim
                    CAPSK *ante;
                    while((aux!=NULL)&&(aux->dado.n_cadastroK<novo->dado.n_cadastroK)){//enquanto o auxiliar for menor do que o dado inserido
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
int mostrarEmRemoverK(CAPSK *aux){
    linhaH(50,7,20);linhaV(12,7,20);linhaH(50,7,31);linhaV(12,56,20);
    Pchar(7,20,218);Pchar(56,20,191);Pchar(7,31,192);Pchar(56,31,217);
    gotoxy(9,22);printf("CADASTRO: %d",aux->dado.n_cadastroK);
    gotoxy(9,23);printf("CAPACIDADE: %d",aux->dado.capacidade);
    gotoxy(9,24);printf("HORARIO: %s",aux->dado.horario);
    gotoxy(9,25);printf("CARGA HORARIA: %d",aux->dado.cargaHoraria);
    if(aux->dado.local==4){
        gotoxy(9,26);printf("LOCAL: Lab 1");
    }else{
        if(aux->dado.local==5){
            gotoxy(9,26);printf("LOCAL: Lab 2 ");
        }else{
            gotoxy(9,26);printf("LOCAL: Sala %d",aux->dado.local);
        }
    }

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
int removerListaK(LISTAK *li,int num){//recebe numero da matricula

    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            CAPSK *aux=li->inicio;
            if(aux->dado.n_cadastroK==num){//se for o 1 da lista
                li->inicio=aux->proximo;//inicio aponta pro proximo
                if(mostrarEmRemoverK(aux)){
                    return 1;
                }
                free(aux);
                return 0;
            }else{
                CAPSK *ante;
                while((aux!=NULL)&&(aux->dado.n_cadastroK!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    AvisoNumeroNaoEncontrado();
                    return 1;
                }
                ante->proximo=aux->proximo;//
                if(mostrarEmRemoverK(aux)){//se deseja realmente remover
                        return 1;
                }
                free(aux);
                return 0;
            }
        }
    }
}
int PegarLocalCurso(){
    //transforma a opcao local 1,2,3 em uma string
    int local;
    int on=1;
    while(on){
        gotoxy(42,17);printf("[Entre 1-5]");
        gotoxy(46,16);scanf("%d",&local);setbuf(stdin,NULL);

        switch(local){
            case 1:
                gotoxy(42,16);printf("Sala 1");
                on=0;
                break;
            case 2:
                gotoxy(42,16);printf("Sala 2");
                on=0;
                break;
            case 3:
                gotoxy(42,16);printf("Sala 3");
                on=0;
                break;
            case 4:
                gotoxy(42,16);printf("Lab 1  ");
                on=0;
                break;
            case 5:
                gotoxy(42,16);printf("Lab 2  ");
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
int PegarHorarioCurso(char horas[7][10]){

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
void pegarInfoCurso(EVENTOK *eK,LISTAK *liK,int n_cadastroK, LISTApT *lipT){

    gotoxy(27,32);printf("%d",n_cadastroK);
    eK->n_cadastroK=n_cadastroK;
//------------------------------capacidade
    gotoxy(48,13);printf("---");
//-----------------------local
    AvisoEventoLimpar();
    AvisoEventoLocais();
    eK->local=PegarLocalCurso();//eP->local
    //capacidade dependendo do local
        if(eK->local==1){
            eK->capacidade =50;
        }
        if(eK->local==2){
            eK->capacidade =50;
        }
        if(eK->local==3){
            eK->capacidade =50;
        }
         if(eK->local==4){
            eK->capacidade =20;
        }
        if(eK->local==5){
            eK->capacidade =20;
        }
        gotoxy(48,13);printf("   ");
        gotoxy(48,13);printf("%d",eK->capacidade);setbuf(stdin,NULL);



    AvisoEventoLimpar();
//---------------------------------------carga horaria
    gotoxy(48,19);scanf("%d",&eK->cargaHoraria);setbuf(stdin,NULL);

//---------------------------horario

    int H;
    if(eK->local==1){
            AvisoEventoHorarios(KhorasS1);
            H =PegarHorarioCurso(KhorasS1);
            strcpy(eK->horario,KhorasS1[H]);
            strcpy(KhorasS1[H],"indis.");
        }
        if(eK->local==2){
            AvisoEventoHorarios(KhorasS2);
            H =PegarHorarioCurso(KhorasS2);
            strcpy(eK->horario,KhorasS2[H]);
            strcpy(KhorasS2[H],"indis.");
        }
        if(eK->local==3){
            AvisoEventoHorarios(KhorasS3);
            H =PegarHorarioCurso(KhorasS3);
            strcpy(eK->horario,KhorasS3[H]);
            strcpy(KhorasS3[H],"indis.");
        }
        if(eK->local==4){
            AvisoEventoHorarios(KhorasL1);
            H =PegarHorarioCurso(KhorasL1);
            strcpy(eK->horario,KhorasL1[H]);
            strcpy(KhorasL1[H],"indis.");
        }
        if(eK->local==5){
            AvisoEventoHorarios(KhorasL2);
            H =PegarHorarioCurso(KhorasL2);
            strcpy(eK->horario,KhorasL2[H]);
            strcpy(KhorasL2[H],"indis.");
        }
        eK->EditH=H;//guardar a posição no vetor para quando for editar



//--------------------------------tema
    AvisoEventoLimpar();
    gotoxy(40,25);gets(eK->tema);setbuf(stdin,NULL);
    //uantidade palestrantes

//-----------------------------palestrantes
    //verificar se est]ao cadastrados
    int palestranteC;
    AvisoP();
    gotoxy(40,28);scanf("%d",&palestranteC);setbuf(stdin,NULL);
    char *nome=(char*)malloc(50*sizeof(char));
    strcpy(eK->palestrante,MostrarPalestrantes(lipT,&nome));
    free(nome);


}


void EditarLocalCurso(CAPSK *aux){
    //transforma a opcao local 1,2,3 em uma string

    //Verificar qual a escolhida e diminuir um para alterar caso ele va do aud 1 para o 2; o 1 diminui 1 e o 2 aumenta-ra 1 dps
    if(aux->dado.local==1){
        gotoxy(42,16);printf("Sala 1");
    }
    if(aux->dado.local==2){
        gotoxy(42,16);printf("Sala 2");
    }
    if(aux->dado.local==3){
        gotoxy(42,16);printf("Sala 3");
    }
    if(aux->dado.local==4){
        gotoxy(42,16);printf("Lab 1 ");
    }
    if(aux->dado.local==5){
        gotoxy(42,16);printf("Lab 2 ");
    }
    int on=1;
    while(on){
        gotoxy(43,17);printf("       ");
        gotoxy(43,17);printf("=>");
        gotoxy(46,17);scanf("%d",&aux->dado.local);setbuf(stdin,NULL);
        switch(aux->dado.local){
            case 1:
                gotoxy(40,17);printf("=>Sala 1");
                on=0;
                break;
            case 2:
                gotoxy(40,17);printf("=>Sala 2");
                on=0;
                break;
            case 3:
                gotoxy(40,17);printf("=>Sala 3");
                on=0;
                break;
            case 4:
                gotoxy(40,17);printf("=>Lab 1");
                on=0;
                break;
            case 5:
                gotoxy(40,17);printf("=>Lab 2");
                on=0;
                break;
            default:
                gotoxy(39,32);printf("POR FAVOR ESCOLHA UMA ENTRE AS OPCOES!!!");

        }

    }
    gotoxy(39,32);printf("                                                            ");
}
void EditarHorarioCurso(CAPSK *aux){
    //transforma a opcao local 1,2,3 em uma string

    //Verificar qual a escolhida e diminuir um para alterar caso ele va do aud 1 para o 2; o 1 diminui 1 e o 2 aumenta-ra 1 dps
    gotoxy(46,23);printf("%s",aux->dado.horario);

        gotoxy(44,22);printf("=>");
        int H;
        if(aux->dado.local==1){
            strcpy(KhorasS1[aux->dado.EditH],KhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoHorarios(KhorasS1);//mostra os horarios disponiveis
            H =PegarHorarioCurso(KhorasS1);//pega a posicao da hora
            strcpy(aux->dado.horario,KhorasS1[H]);//e guarda essa hora
            strcpy(KhorasS1[H],"indis.");//dps transforma ela em indispponivel
        }
        if(aux->dado.local==2){//cada palestra pode ocorrer em locais diferentes so que na mesma hora
            strcpy(KhorasS2[aux->dado.EditH],KhorasTarde[aux->dado.EditH]);
            AvisoEventoHorarios(KhorasS2);
            H =PegarHorarioCurso(KhorasS2);
            strcpy(aux->dado.horario,KhorasS2[H]);
            strcpy(KhorasS2[H],"indis.");
        }
        if(aux->dado.local==3){
            strcpy(KhorasS3[aux->dado.EditH],KhorasTarde[aux->dado.EditH]);
            AvisoEventoHorarios(KhorasS3);
            H =PegarHorarioCurso(KhorasS3);
            strcpy(aux->dado.horario,KhorasS3[H]);
            strcpy(KhorasS3[H],"indis.");
        }
        if(aux->dado.local==4){
            strcpy(KhorasL1[aux->dado.EditH],KhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoHorarios(KhorasL1);//mostra os horarios disponiveis
            H =PegarHorarioCurso(KhorasL1);//pega a posicao da hora
            strcpy(aux->dado.horario,KhorasL1[H]);//e guarda essa hora
            strcpy(KhorasL1[H],"indis.");//dps transforma ela em indispponivel
        }
        if(aux->dado.local==5){
            strcpy(KhorasL2[aux->dado.EditH],KhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoHorarios(KhorasL2);//mostra os horarios disponiveis
            H =PegarHorarioCurso(KhorasL2);//pega a posicao da hora
            strcpy(aux->dado.horario,KhorasL2[H]);//e guarda essa hora
            strcpy(KhorasL2[H],"indis.");//dps transforma ela em indispponivel
        }


    gotoxy(39,32);printf("                                                            ");
}
void editarCurso(LISTAK* li, int cadastroINFO, LISTApT *lipT){
    if(li !=NULL){
        CAPSK* aux=li->inicio;
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.n_cadastroK==cadastroINFO){
                VcadastrarCurso();
                gotoxy(27,32);printf("%d",aux->dado.n_cadastroK);
                //------------------------------capacidade
                gotoxy(48,13);printf("%d =>---",aux->dado.capacidade);setbuf(stdin,NULL);

                //-----------------------local
                AvisoEventoLimpar();
                AvisoEventoLocais();
                EditarLocalCurso(aux);
                //capacidade
                if(aux->dado.local==1){
                    aux->dado.capacidade =50;
                }
                if(aux->dado.local==2){
                    aux->dado.capacidade =50;
                }
                if(aux->dado.local==3){
                    aux->dado.capacidade =50;
                }
                if(aux->dado.local==4){
                    aux->dado.capacidade =20;
                }
                if(aux->dado.local==5){
                    aux->dado.capacidade =20;
                }
                gotoxy(54,13);printf("   ");
                gotoxy(54,13);printf(" %d",aux->dado.capacidade);
                AvisoEventoLimpar();


                //---------------------------------------carga horaria
                gotoxy(48,19);printf("%d =>",aux->dado.cargaHoraria);
                gotoxy(54,19);scanf("%d",&aux->dado.cargaHoraria);setbuf(stdin,NULL);

                //---------------------------horario

                EditarHorarioCurso(aux);
                AvisoEventoLimpar();


                //--------------------------------tema

                gotoxy(40,25);printf("%s",aux->dado.tema);
                gotoxy(38,26);printf("=>");
                gotoxy(40,26);gets(aux->dado.tema);setbuf(stdin,NULL);
                //-----------------------------palestrantes
                //verificar se est]ao cadastrados
                int palestranteC;
                AvisoP();
                gotoxy(40,28);scanf("%d",&palestranteC);setbuf(stdin,NULL);
                char *nome=(char*)malloc(50*sizeof(char));
                strcpy(aux->dado.palestrante,MostrarPalestrantes(lipT,&nome));
                free(nome);

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

void adicionarCongressistaK(LISTAK *li,int Curso,char *nome,int MAT){
    //adiciona na palestra informada o nome, e matricula
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPSK* aux = li->inicio;
            while(aux!=NULL){
                if(aux->dado.n_cadastroK==Curso){//acha a palestra
                    for(int i=0;i<50;i++){
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
void MostrarCongressistaPorCurso(LISTAK *li,int Curso){
    system("cls");

    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPSK* aux = li->inicio;
            printf("CONGRESSISTAS CADASTRADOS NO CURSO %d\n",Curso);
            PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                if(aux->dado.n_cadastroK==Curso){
                    for(int i=0;i<50;i++){
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

void RemoverCongressistaDoCurso(LISTAK *li,int Curso,int Matricula){
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPSK* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                if(aux->dado.n_cadastroK==Curso){
                    for(int i=0;i<50;i++){
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

void desocuparPalestranteK(LISTApT *lipT,LISTAK *liK,int Curso){
    if(liK==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(liK->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPSK* aux = liK->inicio;
            CAPSpT* aux2=lipT->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                if(aux->dado.n_cadastroK==Curso){
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

void removerHorarioK(LISTAK *li, int Curso){
     if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPSK* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                if(aux->dado.local==1){
                strcpy(KhorasS1[aux->dado.EditH],KhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
                }
                if(aux->dado.local==2){
                strcpy(KhorasS2[aux->dado.EditH],KhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
                }
                if(aux->dado.local==3){
                strcpy(KhorasS3[aux->dado.EditH],KhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
                }
                if(aux->dado.local==4){
                strcpy(KhorasL1[aux->dado.EditH],KhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
                }
                if(aux->dado.local==4){
                strcpy(KhorasL2[aux->dado.EditH],KhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
                }


                aux=aux->proximo;
            }
        }
    }

}
