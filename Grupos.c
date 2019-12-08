#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Grupos.h"
#include "Visual.h"

char horasTarde[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char GhorasS1[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};//grupo sala 1
char GhorasS2[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char GhorasS3[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char GhorasL1[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char GhorasL2[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};

typedef struct eventoG EVENTOG;
typedef struct capsulaG CAPSG;
typedef struct listaG LISTAG;

LISTAG* CriarG(){
    LISTAG* li=(LISTAG*)malloc(sizeof(LISTAG));
    if(li!=NULL){
        li->inicio=NULL;
    }
    return li;

}
void liberarG(LISTAG *li){
    if(li==NULL){
        //ERRO
    }else{
        CAPSG *aux;
        while(li->inicio!=NULL){
            aux=li->inicio;
            li->inicio=li->inicio->proximo;
            free(aux);
        }
        free(li);
    }
}
void mostrarTodosG(LISTAG* li){
    system("cls");
    //mostrar todos os campeonados cadastrados
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPSG* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
                printf("  Cadastro: %d        \n",aux->dado.n_cadastroG);
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
                for(int i=0;i<aux->dado.Qpalestrantes;i++){
                    printf("  Palestrante %d: %s     \n",i+1,aux->dado.palestrante[i]);
                }

                PFchar(192);PlinhaH(50);PFchar(217);printf("\n");

                aux=aux->proximo;
            }
        }
    }
}
int tamanhoListaG(LISTAG *li){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //vazia
        }else{
            int cont=0;
            CAPSG *aux=li->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont++;
        }
    }
}
void inserirListaG(LISTAG *li,EVENTOG gD){//insere na ordem de matricula
    if(li==NULL){
        //ERRO
    }else{
        CAPSG *novo= (CAPSG*)malloc(sizeof(CAPSG));
        if(novo!=NULL){
            novo->dado= gD;
            if(li->inicio==NULL){//insercao com lista vazia
                novo->proximo=NULL;
                li->inicio=novo;
            }else{//insercao no inicio quando ja tem alguem na lista
                CAPSG *aux=li->inicio;
                if(aux->dado.n_cadastroG>novo->dado.n_cadastroG){// se o dado que tiver la for maior do que o que esta inserindo ai ele entra na frente[b] = [a,b]
                    novo->proximo=aux;
                    li->inicio=novo;
                }else{//insercao no meio ou no fim
                    CAPSG *ante;
                    while((aux!=NULL)&&(aux->dado.n_cadastroG<novo->dado.n_cadastroG)){//enquanto o auxiliar for menor do que o dado inserido
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
int mostrarEmRemoverG(CAPSG *aux){
    linhaH(50,7,20);linhaV(14,7,20);linhaH(50,7,33);linhaV(14,56,20);
    Pchar(7,20,218);Pchar(56,20,191);Pchar(7,33,192);Pchar(56,33,217);
    gotoxy(9,22);printf("CADASTRO: %d",aux->dado.n_cadastroG);
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
    for(int y=28,i=0;i<aux->dado.Qpalestrantes;i++){
        gotoxy(9,y);printf("PALESTRANTE %d: %s",i+1,aux->dado.palestrante[i]);
        y++;
    }

    VdesejaRemover();
    int op=getch();
    if(op==1){
        return 0;
    }else{
        return 1;
        }
}
int removerListaG(LISTAG *li,int num){//recebe numero da matricula

    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            CAPSG *aux=li->inicio;
            if(aux->dado.n_cadastroG==num){//se for o 1 da lista
                li->inicio=aux->proximo;//inicio aponta pro proximo
                if(mostrarEmRemoverG(aux)){
                    return 1;
                }
                free(aux);
                return 0;
            }else{
                CAPSG *ante;
                while((aux!=NULL)&&(aux->dado.n_cadastroG!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    AvisoNumeroNaoEncontrado();
                    return 1;
                }
                ante->proximo=aux->proximo;//
                if(mostrarEmRemoverG(aux)){//se deseja realmente remover
                        return 1;
                }
                free(aux);
                return 0;
            }
        }
    }
}
int PegarLocalGrupo(){
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
int PegarHorarioGrupo(char horas[7][10]){

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
void pegarInfoGrupo(EVENTOG *gD,LISTAG *liG,int n_cadastroG){

    gotoxy(27,32);printf("%d",n_cadastroG);
    gD->n_cadastroG=n_cadastroG;
//------------------------------capacidade
    gotoxy(48,13);printf("---");
//-----------------------local
    AvisoEventoLimpar();
    AvisoEventoLocais();
    gD->local=PegarLocalGrupo();//eP->local
    //capacidade dependendo do local
        if(gD->local==1){
            gD->capacidade =50;
        }
        if(gD->local==2){
            gD->capacidade =50;
        }
        if(gD->local==3){
            gD->capacidade =50;
        }
         if(gD->local==4){
            gD->capacidade =20;
        }
        if(gD->local==3){
            gD->capacidade =20;
        }
        gotoxy(48,13);printf("   ");
        gotoxy(48,13);printf("%d",gD->capacidade);setbuf(stdin,NULL);



    AvisoEventoLimpar();
//---------------------------------------carga horaria
    gotoxy(48,19);scanf("%d",&gD->cargaHoraria);setbuf(stdin,NULL);

//---------------------------horario

    int H;
    if(gD->local==1){
            AvisoEventoHorarios(GhorasS1);
            H =PegarHorarioGrupo(GhorasS1);
            strcpy(gD->horario,GhorasS1[H]);
            strcpy(GhorasS1[H],"indis.");
        }
        if(gD->local==2){
            AvisoEventoHorarios(GhorasS2);
            H =PegarHorarioGrupo(GhorasS2);
            strcpy(gD->horario,GhorasS2[H]);
            strcpy(GhorasS2[H],"indis.");
        }
        if(gD->local==3){
            AvisoEventoHorarios(GhorasS3);
            H =PegarHorarioGrupo(GhorasS3);
            strcpy(gD->horario,GhorasS3[H]);
            strcpy(GhorasS3[H],"indis.");
        }
        if(gD->local==4){
            AvisoEventoHorarios(GhorasL1);
            H =PegarHorarioGrupo(GhorasL1);
            strcpy(gD->horario,GhorasL1[H]);
            strcpy(GhorasL1[H],"indis.");
        }
        if(gD->local==5){
            AvisoEventoHorarios(GhorasL2);
            H =PegarHorarioGrupo(GhorasL2);
            strcpy(gD->horario,GhorasL2[H]);
            strcpy(GhorasL2[H],"indis.");
        }
        gD->EditH=H;//guardar a posição no vetor para quando for editar



//--------------------------------tema
    AvisoEventoLimpar();
    gotoxy(40,25);gets(gD->tema);setbuf(stdin,NULL);
    //uantidade palestrantes

    gotoxy(94,25);scanf("%d",&gD->Qpalestrantes);setbuf(stdin,NULL);
//-----------------------------palestrantes
    //verificar se est]ao cadastrados
    for(int y2=28,y=28,i=0;i<gD->Qpalestrantes;i++){
        if((i==3)||(i==4)){
            gotoxy(70,y2);gets(gD->palestrante[i]);setbuf(stdin,NULL);
            y2++;
        }else{
            gotoxy(40,y);gets(gD->palestrante[i]);setbuf(stdin,NULL);
            y++;
        }

    }

        //verificarPalestrante(&eP,&p,palestrante[i]);//mostrar na frente do numero o erro em vermelho
}
void EditarLocalGrupo(CAPSG *aux){
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
void EditarHorarioGrupo(CAPSG *aux){
    //transforma a opcao local 1,2,3 em uma string

    //Verificar qual a escolhida e diminuir um para alterar caso ele va do aud 1 para o 2; o 1 diminui 1 e o 2 aumenta-ra 1 dps
    gotoxy(46,23);printf("%s",aux->dado.horario);

        gotoxy(44,22);printf("=>");
        int H;
        if(aux->dado.local==1){
            strcpy(GhorasS1[aux->dado.EditH],horasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoHorarios(GhorasS1);//mostra os horarios disponiveis
            H =PegarHorarioGrupo(GhorasS1);//pega a posicao da hora
            strcpy(aux->dado.horario,GhorasS1[H]);//e guarda essa hora
            strcpy(GhorasS1[H],"indis.");//dps transforma ela em indispponivel
        }
        if(aux->dado.local==2){//cada palestra pode ocorrer em locais diferentes so que na mesma hora
            strcpy(GhorasS2[aux->dado.EditH],horasTarde[aux->dado.EditH]);
            AvisoEventoHorarios(GhorasS2);
            H =PegarHorarioGrupo(GhorasS2);
            strcpy(aux->dado.horario,GhorasS2[H]);
            strcpy(GhorasS2[H],"indis.");
        }
        if(aux->dado.local==3){
            strcpy(GhorasS3[aux->dado.EditH],horasTarde[aux->dado.EditH]);
            AvisoEventoHorarios(GhorasS3);
            H =PegarHorarioGrupo(GhorasS3);
            strcpy(aux->dado.horario,GhorasS3[H]);
            strcpy(GhorasS3[H],"indis.");
        }
        if(aux->dado.local==4){
            strcpy(GhorasL1[aux->dado.EditH],horasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoHorarios(GhorasL1);//mostra os horarios disponiveis
            H =PegarHorarioGrupo(GhorasL1);//pega a posicao da hora
            strcpy(aux->dado.horario,GhorasL1[H]);//e guarda essa hora
            strcpy(GhorasL1[H],"indis.");//dps transforma ela em indispponivel
        }
        if(aux->dado.local==5){
            strcpy(GhorasL2[aux->dado.EditH],horasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoHorarios(GhorasL2);//mostra os horarios disponiveis
            H =PegarHorarioGrupo(GhorasL2);//pega a posicao da hora
            strcpy(aux->dado.horario,GhorasL2[H]);//e guarda essa hora
            strcpy(GhorasL2[H],"indis.");//dps transforma ela em indispponivel
        }


    gotoxy(39,32);printf("                                                            ");
}
void editarGrupo(LISTAG* li, int cadastroINFO){
    if(li !=NULL){
        CAPSG* aux=li->inicio;
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.n_cadastroG==cadastroINFO){
                VcadastrarGrupos();
                gotoxy(27,32);printf("%d",aux->dado.n_cadastroG);
                //------------------------------capacidade
                gotoxy(48,13);printf("%d =>---",aux->dado.capacidade);setbuf(stdin,NULL);

                //-----------------------local
                AvisoEventoLimpar();
                AvisoEventoLocais();
                EditarLocalGrupo(aux);
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

                EditarHorarioGrupo(aux);


                //--------------------------------tema

                gotoxy(40,25);printf("%s",aux->dado.tema);
                gotoxy(38,26);printf("=>");
                gotoxy(40,26);gets(aux->dado.tema);setbuf(stdin,NULL);
                //-----------------------------palestrantes
                //quantidade
                gotoxy(94,25);printf("%d",aux->dado.Qpalestrantes);
                gotoxy(92,26);printf("=>");
                gotoxy(94,26);scanf("%d",&aux->dado.Qpalestrantes);setbuf(stdin,NULL);
                //verificar se est]ao cadastrados
                gotoxy(40,28);printf("%s",aux->dado.palestrante[0]);
                gotoxy(38,29);printf("=>");
                gotoxy(40,29);gets(aux->dado.palestrante[0]);

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


