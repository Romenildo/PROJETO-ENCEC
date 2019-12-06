#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "Visual.h"
    char horasTarde[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
    char GhorasS1[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
    char GhorasS2[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
    char GhorasS3[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};


#define C_BLACK      "\x1b[30m"
#define C_RED      "\x1b[31m"
#define C_GREEN      "\x1b[32m"
#define C_YELLOW      "\x1b[33m"
#define C_WATER      "\x1b[36m"
#define C_BLUE   "\x1b[34m"
#define C_WHITE      "\x1b[1m"
//CURSO
typedef struct{
    int n_cadastroG;
    int capacidade;
    char horario[5];
    int cargaHoraria;
    int local;//ou int local 1laboratorio 2
    char tema[30];
    int Qpalestrantes;
    char palestrantes[5][30];
    int EditG;
}EVENTOG;//evento palestras


//--------------------------------fila para eventos-----------
typedef struct capsulaG{
    EVENTOG dado;
    struct capsulaG *proximo;
}CAPSG;

typedef struct{
    CAPSG *inicio;
}LISTAG;

LISTAG* CriarG(){
    LISTAG* liG=(LISTAG*)malloc(sizeof(LISTAG));
    if(liG!=NULL){
        liG->inicio=NULL;
    }
    return liG;

}
void liberar(LISTAG *li){
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
    //mostrar todos os campeonados cadastrados
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPSG* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                printf("\nCadastro: %d                                       |",aux->dado.n_cadastroG);
                printf("\nHorario: %s",aux->dado.horario);
                printf("\nCarga horaria: %d",aux->dado.cargaHoraria);
                printf("\nlocal: Auditorio %d",aux->dado.local);
                printf("\nCapacidade: %d",aux->dado.capacidade);
                printf("\n\nTema: %s",aux->dado.tema);
                for(int i=0;i<aux->dado.Qpalestrantes;i++){
                    printf("\nPalestrantes: %s",aux->dado.palestrantes[i]);
                }
                printf("\n--------------------------------------------\n");

                aux=aux->proximo;
            }
        }
    }
}

int tamanhoLista(LISTAG *li){
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
    linhaH(50,7,20);linhaV(12,7,20);linhaH(50,7,31);linhaV(12,56,20);
    Pchar(7,20,218);Pchar(56,20,191);Pchar(7,31,192);Pchar(56,31,217);
    gotoxy(9,22);printf("CADASTRO: %d",aux->dado.n_cadastroG);
    gotoxy(9,23);printf("CAPACIDADE: %d",aux->dado.capacidade);
    gotoxy(9,24);printf("HORARIO: %s",aux->dado.horario);
    gotoxy(9,25);printf("CARGA HORARIA: %d",aux->dado.cargaHoraria);
    gotoxy(9,26);printf("LOCAL: Sala %d",aux->dado.local);
    gotoxy(9,27);printf("TEMA: %s",aux->dado.tema);
    for(int y=28,i=0;i<aux->dado.Qpalestrantes;i++,y++){
        gotoxy(9,y);printf("PALESTRANTEs: %s",aux->dado.palestrantes[i]);
    }
    VdesejaRemover();
    int op=getch();
    if(op==1){
        return 0;
    }else{
        return 1;
        }

}
void removerListaG(LISTAG *li,int num){//recebe numero da matricula

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
                    return;
                }
                free(aux);
            }else{
                CAPSG *ante;
                while((aux!=NULL)&&(aux->dado.n_cadastroG!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    AvisoNumeroNaoEcontrado();
                    return;
                }
                ante->proximo=aux->proximo;//
                if(mostrarEmRemoverG(aux)){//se deseja realmente remover
                        return;
                }
                free(aux);
            }
        }
    }

}

int PegarLocalGrupo(){
    //transforma a opcao local 1,2,3 em uma string
    int local;
    int on=1;
    while(on){
        gotoxy(42,17);printf("[Entre 1-3]");
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
            default:
                gotoxy(39,32);printf(C_RED"POR FAVOR ESCOLHA UMA ENTRE AS OPCOES!!!"C_WHITE);

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
                gotoxy(39,32);printf(C_RED"POR FAVOR ESCOLHA UMA ENTRE AS OPCOES!!!"C_WHITE);

        }

    }
    gotoxy(39,32);printf("                                                            ");
}

pegarInfoGrupo(EVENTOG *gD,LISTAG *liG,int n_cadastroG){

    n_cadastroG++;//1000
    gotoxy(27,32);printf("%d",n_cadastroG);
    gD->n_cadastroG=n_cadastroG;
//------------------------------capacidade
    gD->capacidade = 50;
    gotoxy(48,13);printf("%d",gD->capacidade);setbuf(stdin,NULL);
//-----------------------local
    AvisoEventoLimpar();
    AvisoEventoCursoLocais();
    gD->local=PegarLocalGrupo();//eP->local



    AvisoEventoLimpar();
//---------------------------------------carga horaria
    gotoxy(48,19);scanf("%d",&gD->cargaHoraria);setbuf(stdin,NULL);

//---------------------------horario

    int H;
    if(gD->local==1){
            AvisoEventoCursoHorario(GhorasS1);
            H =PegarHorarioCurso(GhorasS1);
            strcpy(gD->horario,GhorasS1[H]);
            strcpy(GhorasS1[H],"indis.");
        }
        if(gD->local==2){
            AvisoEventoCursoHorario(GhorasS2);
            H =PegarHorarioCurso(GhorasS2);
            strcpy(gD->horario,GhorasS2[H]);
            strcpy(GhorasS2[H],"indis.");
        }
        if(gD->local==3){
            AvisoEventoCursoHorario(GhorasS3);
            H =PegarHorarioCurso(GhorasS3);
            strcpy(gD->horario,GhorasS3[H]);
            strcpy(GhorasS3[H],"indis.");
        }
        gD->EditG=H;//guardar a posição no vetor para quando for editar



//--------------------------------tema
    AvisoEventoLimpar();
    gotoxy(40,25);gets(gD->tema);setbuf(stdin,NULL);

//------------------------quantidade palestrantes
    gotoxy(94,25);scanf("%d",&gD->Qpalestrantes);setbuf(stdin,NULL);
//-----------------------------palestrantes
    //verificar se est]ao cadastrados
    gotoxy(40,28);gets(gD->palestrantes[1]);setbuf(stdin,NULL);//fazer a parade ir escrevendo varios
        //verificarPalestrante(&eP,&p,palestrante[i]);//mostrar na frente do numero o erro em vermelho
}
//verificarPalestrante(PALESTRANTES *p, char palestrante){
                //verificar os palestrantes cadastrados com os digitados
                //se nao encontrar pedir pra digitar novamente e mostra mensagem de erro


EditarLocalGrupo(CAPSG *aux){
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
            default:
                gotoxy(39,32);printf(C_RED"POR FAVOR ESCOLHA UMA ENTRE AS OPCOES!!!"C_WHITE);

        }

    }
    gotoxy(39,32);printf("                                                            ");
}

EditarHorarioGrupo(CAPSG *aux){
    //transforma a opcao local 1,2,3 em uma string

    //Verificar qual a escolhida e diminuir um para alterar caso ele va do aud 1 para o 2; o 1 diminui 1 e o 2 aumenta-ra 1 dps
    gotoxy(46,23);printf("%s",aux->dado.horario);

        gotoxy(44,22);printf("=>");
        int H;
    if(aux->dado.local==1){
            strcpy(GhorasS1[aux->dado.EditG],horasTarde[aux->dado.EditG]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoCursoHorario(GhorasS1);//mostra os horarios disponiveis
            H =PegarHorarioCurso(GhorasS1);//pega a posicao da hora
            strcpy(aux->dado.horario,GhorasS1[H]);//e guarda essa hora
            strcpy(GhorasS1[H],"indis.");//dps transforma ela em indispponivel
        }
        if(aux->dado.local==2){//cada palestra pode ocorrer em locais diferentes so que na mesma hora
            strcpy(GhorasS2[aux->dado.EditG],horasTarde[aux->dado.EditG]);
            AvisoEventoCursoHorario(GhorasS2);
            H =PegarHorarioCurso(GhorasS2);
            strcpy(aux->dado.horario,GhorasS2[H]);
            strcpy(GhorasS2[H],"indis.");
        }
        if(aux->dado.local==3){
            strcpy(GhorasS3[aux->dado.EditG],horasTarde[aux->dado.EditG]);
            AvisoEventoCursoHorario(GhorasS3);
            H =PegarHorarioCurso(GhorasS3);
            strcpy(aux->dado.horario,GhorasS3[H]);
            strcpy(GhorasS3[H],"indis.");
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
                gotoxy(48,13);printf("  %d",aux->dado.capacidade);setbuf(stdin,NULL);

                //-----------------------local
                AvisoEventoLimpar();
                AvisoEventoCursoLocais();
                EditarLocalGrupo(aux);
                AvisoEventoLimpar();


                //---------------------------------------carga horaria
                gotoxy(48,19);printf("%d =>",aux->dado.cargaHoraria);
                gotoxy(54,19);scanf("%d",&aux->dado.cargaHoraria);setbuf(stdin,NULL);

                //---------------------------horario

                EditarHorarioGrupo(aux);
                AvisoEventoLimpar();


                //--------------------------------tema

                gotoxy(40,25);printf("%s",aux->dado.tema);
                gotoxy(38,26);printf("=>");
                gotoxy(40,26);gets(aux->dado.tema);setbuf(stdin,NULL);
                //------------quant palestrantes
                gotoxy(94,25);printf("%d",aux->dado.Qpalestrantes);
                gotoxy(92,26);printf("=>");
                gotoxy(94,26);scanf("%d",&aux->dado.Qpalestrantes);setbuf(stdin,NULL);
                //-----------------------------palestrantes
                //verificar se est]ao cadastrados
                gotoxy(77,25);printf("%s",aux->dado.palestrantes[1]);
                gotoxy(38,29);printf("=>");
                gotoxy(40,29);gets(aux->dado.palestrantes[1]);

                VeditadoComSucesso();
                return;
            }
            aux=aux->proximo;
        }
        //caso nao tenha entrado no if e dado break;
        AvisoNumeroNaoEcontrado();
        return;
    }else{
        printf("ERRO DE ALOCACAO!!!\n");
    }
}


main(){


    VcadastrarGrupos();

    EVENTOG gD;
    LISTAG *liG=CriarG();
    int n_cadastroG=5000;

    pegarInfoGrupo(&gD,liG,n_cadastroG);
    inserirListaG(liG,gD);
    //mostrar todos
    //
    system("cls");
    int num_editarG;
    VeditarGrupo();
    gotoxy(22,17);scanf("%d",&num_editarG);
    system("cls");
    editarGrupo(liG,num_editarG);
    //
    system("cls");
    mostrarTodosG(liG);
    getchar();
    //remover
    system("cls");
    int num_removerG;
    VremoverGrupo();
    gotoxy(22,17);scanf("%d",&num_removerG);
    removerListaG(liG,num_removerG);
//editar


    liberar(liG);
}




//para rodar basta colocar no projeto com visual
