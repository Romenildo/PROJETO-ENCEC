#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Oficinas.h"
#include "Palestrante.h"
#include "Visual.h"

char OhorasTarde[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char OhorasS1[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};//grupo sala 1
char OhorasS2[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char OhorasS3[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char OhorasL1[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
char OhorasL2[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};

typedef struct eventoOf EVENTOOf;
typedef struct capsulaOf CAPSOf;
typedef struct listaOf LISTAOf;


LISTAOf* CriarOf(){
    LISTAOf* li=(LISTAOf*)malloc(sizeof(LISTAOf));
    if(li!=NULL){
        li->inicio=NULL;
    }
    return li;

}
void liberarOf(LISTAOf *li){
    if(li==NULL){
        //ERRO
    }else{
        CAPSOf *aux;
        while(li->inicio!=NULL){
            aux=li->inicio;
            li->inicio=li->inicio->proximo;
            free(aux);
        }
        free(li);
    }
}
void mostrarTodosOf(LISTAOf* li){
    system("cls");
    //mostrar todos os campeonados cadastrados
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPSOf* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                PFchar(218);PlinhaH(50);PFchar(191);printf("\n");
                printf("  Cadastro: %d        \n",aux->dado.n_cadastroOf);
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

int tamanhoListaOf(LISTAOf *li){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //vazia
        }else{
            int cont=0;
            CAPSOf *aux=li->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont++;
        }
    }
}
void inserirListaOf(LISTAOf *li,EVENTOOf oF){//insere na ordem de matricula
    if(li==NULL){
        //ERRO
    }else{
        CAPSOf *novo= (CAPSOf*)malloc(sizeof(CAPSOf));
        if(novo!=NULL){
            novo->dado= oF;
            if(li->inicio==NULL){//insercao com lista vazia
                novo->proximo=NULL;
                li->inicio=novo;
            }else{//insercao no inicio quando ja tem alguem na lista
                CAPSOf *aux=li->inicio;
                if(aux->dado.n_cadastroOf>novo->dado.n_cadastroOf){// se o dado que tiver la for maior do que o que esta inserindo ai ele entra na frente[b] = [a,b]
                    novo->proximo=aux;
                    li->inicio=novo;
                }else{//insercao no meio ou no fim
                    CAPSOf *ante;
                    while((aux!=NULL)&&(aux->dado.n_cadastroOf<novo->dado.n_cadastroOf)){//enquanto o auxiliar for menor do que o dado inserido
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
//----
int mostrarEmRemoverOf(CAPSOf *aux){
    linhaH(50,7,20);linhaV(12,7,20);linhaH(50,7,31);linhaV(12,56,20);
    Pchar(7,20,218);Pchar(56,20,191);Pchar(7,31,192);Pchar(56,31,217);
    gotoxy(9,22);printf("CADASTRO: %d",aux->dado.n_cadastroOf);
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
int removerListaOf(LISTAOf *li,int num){//recebe numero da matricula

    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            CAPSOf *aux=li->inicio;
            if(aux->dado.n_cadastroOf==num){//se for o 1 da lista
                li->inicio=aux->proximo;//inicio aponta pro proximo
                if(mostrarEmRemoverOf(aux)){
                    return 1;
                }
                free(aux);
                return 0;
            }else{
                CAPSOf *ante;
                while((aux!=NULL)&&(aux->dado.n_cadastroOf!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    AvisoNumeroNaoEncontrado();
                    return 1;
                }
                ante->proximo=aux->proximo;//
                if(mostrarEmRemoverOf(aux)){//se deseja realmente remover
                        return 1;
                }
                free(aux);
                return 0;
            }
        }
    }
}
int PegarLocalOficina(){
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
int PegarHorarioOficina(char horas[7][10]){

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
void pegarInfoOficina(EVENTOOf *oF,LISTAOf *liOf,int n_cadastroOf, LISTApT *lipT){

    gotoxy(27,32);printf("%d",n_cadastroOf);
    oF->n_cadastroOf=n_cadastroOf;
//------------------------------capacidade
    gotoxy(48,13);printf("---");
//-----------------------local
    AvisoEventoLimpar();
    AvisoEventoLocais();
    oF->local=PegarLocalOficina();//eP->local
    //capacidade dependendo do local
        if(oF->local==1){
            oF->capacidade =50;
        }
        if(oF->local==2){
            oF->capacidade =50;
        }
        if(oF->local==3){
            oF->capacidade =50;
        }
         if(oF->local==4){
            oF->capacidade =20;
        }
        if(oF->local==5){
            oF->capacidade =20;
        }
        gotoxy(48,13);printf("   ");
        gotoxy(48,13);printf("%d",oF->capacidade);setbuf(stdin,NULL);



    AvisoEventoLimpar();
//---------------------------------------carga horaria
    gotoxy(48,19);scanf("%d",&oF->cargaHoraria);setbuf(stdin,NULL);

//---------------------------horario

    int H;
    if(oF->local==1){
            AvisoEventoHorarios(OhorasS1);
            H =PegarHorarioOficina(OhorasS1);
            strcpy(oF->horario,OhorasS1[H]);
            strcpy(OhorasS1[H],"indis.");
        }
        if(oF->local==2){
            AvisoEventoHorarios(OhorasS2);
            H =PegarHorarioOficina(OhorasS2);
            strcpy(oF->horario,OhorasS2[H]);
            strcpy(OhorasS2[H],"indis.");
        }
        if(oF->local==3){
            AvisoEventoHorarios(OhorasS3);
            H =PegarHorarioOficina(OhorasS3);
            strcpy(oF->horario,OhorasS3[H]);
            strcpy(OhorasS3[H],"indis.");
        }
        if(oF->local==4){
            AvisoEventoHorarios(OhorasL1);
            H =PegarHorarioOficina(OhorasL1);
            strcpy(oF->horario,OhorasL1[H]);
            strcpy(OhorasL1[H],"indis.");
        }
        if(oF->local==5){
            AvisoEventoHorarios(OhorasL2);
            H =PegarHorarioOficina(OhorasL2);
            strcpy(oF->horario,OhorasL2[H]);
            strcpy(OhorasL2[H],"indis.");
        }
        oF->EditH=H;//guardar a posição no vetor para quando for editar



//--------------------------------tema
    AvisoEventoLimpar();
    gotoxy(40,25);gets(oF->tema);setbuf(stdin,NULL);
    //uantidade palestrantes

//-----------------------------palestrantes
    //verificar se est]ao cadastrados
    int palestranteOf;
    AvisoP();
    gotoxy(40,28);scanf("%d",&palestranteOf);setbuf(stdin,NULL);
    strcpy(oF->palestrante,MostrarPalestrantes(lipT));

        //verificarPalestrante(&eP,&p,palestrante[i]);//mostrar na frente do numero o erro em vermelho
}


void EditarLocalOficina(CAPSOf *aux){
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
void EditarHorarioOficina(CAPSOf *aux){
    //transforma a opcao local 1,2,3 em uma string

    //Verificar qual a escolhida e diminuir um para alterar caso ele va do aud 1 para o 2; o 1 diminui 1 e o 2 aumenta-ra 1 dps
    gotoxy(46,23);printf("%s",aux->dado.horario);

        gotoxy(44,22);printf("=>");
        int H;
        if(aux->dado.local==1){
            strcpy(OhorasS1[aux->dado.EditH],OhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoHorarios(OhorasS1);//mostra os horarios disponiveis
            H =PegarHorarioOficina(OhorasS1);//pega a posicao da hora
            strcpy(aux->dado.horario,OhorasS1[H]);//e guarda essa hora
            strcpy(OhorasS1[H],"indis.");//dps transforma ela em indispponivel
        }
        if(aux->dado.local==2){//cada palestra pode ocorrer em locais diferentes so que na mesma hora
            strcpy(OhorasS2[aux->dado.EditH],OhorasTarde[aux->dado.EditH]);
            AvisoEventoHorarios(OhorasS2);
            H =PegarHorarioOficina(OhorasS2);
            strcpy(aux->dado.horario,OhorasS2[H]);
            strcpy(OhorasS2[H],"indis.");
        }
        if(aux->dado.local==3){
            strcpy(OhorasS3[aux->dado.EditH],OhorasTarde[aux->dado.EditH]);
            AvisoEventoHorarios(OhorasS3);
            H =PegarHorarioOficina(OhorasS3);
            strcpy(aux->dado.horario,OhorasS3[H]);
            strcpy(OhorasS3[H],"indis.");
        }
        if(aux->dado.local==4){
            strcpy(OhorasL1[aux->dado.EditH],OhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoHorarios(OhorasL1);//mostra os horarios disponiveis
            H =PegarHorarioOficina(OhorasL1);//pega a posicao da hora
            strcpy(aux->dado.horario,OhorasL1[H]);//e guarda essa hora
            strcpy(OhorasL1[H],"indis.");//dps transforma ela em indispponivel
        }
        if(aux->dado.local==5){
            strcpy(OhorasL2[aux->dado.EditH],OhorasTarde[aux->dado.EditH]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoHorarios(OhorasL2);//mostra os horarios disponiveis
            H =PegarHorarioOficina(OhorasL2);//pega a posicao da hora
            strcpy(aux->dado.horario,OhorasL2[H]);//e guarda essa hora
            strcpy(OhorasL2[H],"indis.");//dps transforma ela em indispponivel
        }


    gotoxy(39,32);printf("                                                            ");
}
void editarOficina(LISTAOf* li, int cadastroINFO){
    if(li !=NULL){
        CAPSOf* aux=li->inicio;
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.n_cadastroOf==cadastroINFO){
                VcadastrarOficina();
                gotoxy(27,32);printf("%d",aux->dado.n_cadastroOf);
                //------------------------------capacidade
                gotoxy(48,13);printf("%d =>---",aux->dado.capacidade);setbuf(stdin,NULL);

                //-----------------------local
                AvisoEventoLimpar();
                AvisoEventoLocais();
                EditarLocalOficina(aux);
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

                EditarHorarioOficina(aux);


                //--------------------------------tema

                gotoxy(40,25);printf("%s",aux->dado.tema);
                gotoxy(38,26);printf("=>");
                gotoxy(40,26);gets(aux->dado.tema);setbuf(stdin,NULL);
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
        //caso nao tenha entrado no if e dado break;
        AvisoNumeroNaoEncontrado();
        return;
    }else{
        printf("ERRO DE ALOCACAO!!!\n");
    }
}


