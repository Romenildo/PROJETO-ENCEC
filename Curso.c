#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "Visual.h"
    char horasTarde[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
    char horasS1[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
    char horasS2[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};
    char horasS3[7][10]={"0","13:00","14:00","15:00","16:00","17:00","18:00"};


#define C_BLACK      "\x1b[30m"
#define C_RED      "\x1b[31m"
#define C_GREEN      "\x1b[32m"
#define C_YELLOW      "\x1b[33m"
#define C_WATER      "\x1b[36m"
#define C_BLUE   "\x1b[34m"
#define C_WHITE      "\x1b[1m"
//CURSO
typedef struct{
    int n_cadastrocU;
    int capacidade;
    char horario[5];
    int cargaHoraria;
    int local;//ou int local 1laboratorio 2
    char tema[30];
    char palestrante[30];
    int EditcU;
}EVENTOcU;//evento palestras


//--------------------------------fila para eventos-----------
typedef struct capsulacU{
    EVENTOcU dado;
    struct capsulacU *proximo;
}CAPScU;

typedef struct{
    CAPScU *inicio;
}LISTAcU;

LISTAcU* CriarcU(){
    LISTAcU* licU=(LISTAcU*)malloc(sizeof(LISTAcU));
    if(licU!=NULL){
        licU->inicio=NULL;
    }
    return licU;

}
void liberar(LISTAcU *li){
    if(li==NULL){
        //ERRO
    }else{
        CAPScU *aux;
        while(li->inicio!=NULL){
            aux=li->inicio;
            li->inicio=li->inicio->proximo;
            free(aux);
        }
        free(li);
    }
}
void mostrarTodoscU(LISTAcU* li){
    //mostrar todos os campeonados cadastrados
    if(li==NULL){
        printf("ERRO DE ALOCACAO!!!\n");
    }else{
        if(li->inicio==NULL){
            printf("LISTA VAZIA\n");
        }else{
            CAPScU* aux = li->inicio;
            while(aux!=NULL){//talvez fze uma lihaH e colocar um caractere | antes de cada print
                printf("\nCadastro: %d                                       |",aux->dado.n_cadastrocU);
                printf("\nHorario: %s",aux->dado.horario);
                printf("\nCarga horaria: %d",aux->dado.cargaHoraria);
                printf("\nlocal: Auditorio %d",aux->dado.local);
                printf("\nCapacidade: %d",aux->dado.capacidade);
                printf("\n\nTema: %s",aux->dado.tema);
                printf("\nPalestrante: %s",aux->dado.palestrante);
                printf("\n--------------------------------------------\n");

                aux=aux->proximo;
            }
        }
    }
}

int tamanhoLista(LISTAcU *li){
    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //vazia
        }else{
            int cont=0;
            CAPScU *aux=li->inicio;
            while(aux!=NULL){
                cont++;
                aux=aux->proximo;
            }
            return cont++;
        }
    }
}

void inserirListacU(LISTAcU *li,EVENTOcU cU){//insere na ordem de matricula
    if(li==NULL){
        //ERRO
    }else{
        CAPScU *novo= (CAPScU*)malloc(sizeof(CAPScU));
        if(novo!=NULL){
            novo->dado= cU;
            if(li->inicio==NULL){//insercao com lista vazia
                novo->proximo=NULL;
                li->inicio=novo;
            }else{//insercao no inicio quando ja tem alguem na lista
                CAPScU *aux=li->inicio;
                if(aux->dado.n_cadastrocU>novo->dado.n_cadastrocU){// se o dado que tiver la for maior do que o que esta inserindo ai ele entra na frente[b] = [a,b]
                    novo->proximo=aux;
                    li->inicio=novo;
                }else{//insercao no meio ou no fim
                    CAPScU *ante;
                    while((aux!=NULL)&&(aux->dado.n_cadastrocU<novo->dado.n_cadastrocU)){//enquanto o auxiliar for menor do que o dado inserido
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
int mostrarEmRemovercU(CAPScU *aux){
    linhaH(50,7,20);linhaV(12,7,20);linhaH(50,7,31);linhaV(12,56,20);
    Pchar(7,20,218);Pchar(56,20,191);Pchar(7,31,192);Pchar(56,31,217);
    gotoxy(9,22);printf("CADASTRO: %d",aux->dado.n_cadastrocU);
    gotoxy(9,23);printf("CAPACIDADE: %d",aux->dado.capacidade);
    gotoxy(9,24);printf("HORARIO: %s",aux->dado.horario);
    gotoxy(9,25);printf("CARGA HORARIA: %d",aux->dado.cargaHoraria);
    gotoxy(9,26);printf("LOCAL: Sala %d",aux->dado.local);
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
void removerListacU(LISTAcU *li,int num){//recebe numero da matricula

    if(li==NULL){
        //ERRO
    }else{
        if(li->inicio==NULL){
            //VAZIA
        }else{
            CAPScU *aux=li->inicio;
            if(aux->dado.n_cadastrocU==num){//se for o 1 da lista
                li->inicio=aux->proximo;//inicio aponta pro proximo
                if(mostrarEmRemovercU(aux)){
                    return;
                }
                free(aux);
            }else{
                CAPScU *ante;
                while((aux!=NULL)&&(aux->dado.n_cadastrocU!=num)){//varre a lista e enquando nao for igual ao que procura ele roda
                    ante=aux;
                    aux=aux->proximo;
                }
                if(aux==NULL){//caso nao tenha enconrado nada na lista
                    AvisoNumeroNaoEcontrado();
                    return;
                }
                ante->proximo=aux->proximo;//
                if(mostrarEmRemovercU(aux)){//se deseja realmente remover
                        return;
                }
                free(aux);
            }
        }
    }

}

int PegarLocalCurso(){
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

pegarInfoCurso(EVENTOcU *cU,LISTAcU *licU,int n_cadastrocU){

    n_cadastrocU++;//1000
    gotoxy(27,32);printf("%d",n_cadastrocU);
    cU->n_cadastrocU=n_cadastrocU;
//------------------------------capacidade
    cU->capacidade = 40;
    gotoxy(48,13);printf("%d",cU->capacidade);setbuf(stdin,NULL);
//-----------------------local
    AvisoEventoLimpar();
    AvisoEventoCursoLocais();
    cU->local=PegarLocalCurso();//eP->local



    AvisoEventoLimpar();
//---------------------------------------carga horaria
    gotoxy(48,19);scanf("%d",&cU->cargaHoraria);setbuf(stdin,NULL);

//---------------------------horario

    int H;
    if(cU->local==1){
            AvisoEventoCursoHorario(horasS1);
            H =PegarHorarioCurso(horasS1);
            strcpy(cU->horario,horasS1[H]);
            strcpy(horasS1[H],"indis.");
        }
        if(cU->local==2){
            AvisoEventoCursoHorario(horasS2);
            H =PegarHorarioCurso(horasS2);
            strcpy(cU->horario,horasS2[H]);
            strcpy(horasS2[H],"indis.");
        }
        if(cU->local==3){
            AvisoEventoCursoHorario(horasS3);
            H =PegarHorarioCurso(horasS3);
            strcpy(cU->horario,horasS3[H]);
            strcpy(horasS3[H],"indis.");
        }
        cU->EditcU=H;//guardar a posição no vetor para quando for editar



//--------------------------------tema
    AvisoEventoLimpar();
    gotoxy(40,25);gets(cU->tema);
//-----------------------------palestrantes
    //verificar se est]ao cadastrados
    gotoxy(40,28);gets(cU->palestrante);setbuf(stdin,NULL);
        //verificarPalestrante(&eP,&p,palestrante[i]);//mostrar na frente do numero o erro em vermelho
}
//verificarPalestrante(PALESTRANTES *p, char palestrante){
                //verificar os palestrantes cadastrados com os digitados
                //se nao encontrar pedir pra digitar novamente e mostra mensagem de erro


EditarLocalCurso(CAPScU *aux){
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

EditarHorarioCurso(CAPScU *aux){
    //transforma a opcao local 1,2,3 em uma string

    //Verificar qual a escolhida e diminuir um para alterar caso ele va do aud 1 para o 2; o 1 diminui 1 e o 2 aumenta-ra 1 dps
    gotoxy(46,23);printf("%s",aux->dado.horario);

        gotoxy(44,22);printf("=>");
        int H;
    if(aux->dado.local==1){
            strcpy(horasS1[aux->dado.EditcU],horasTarde[aux->dado.EditcU]);//tira o que ja tava como indisponivel e coloca o base
            AvisoEventoCursoHorario(horasS1);//mostra os horarios disponiveis
            H =PegarHorarioCurso(horasS1);//pega a posicao da hora
            strcpy(aux->dado.horario,horasS1[H]);//e guarda essa hora
            strcpy(horasS1[H],"indis.");//dps transforma ela em indispponivel
        }
        if(aux->dado.local==2){//cada palestra pode ocorrer em locais diferentes so que na mesma hora
            strcpy(horasS2[aux->dado.EditcU],horasTarde[aux->dado.EditcU]);
            AvisoEventoCursoHorario(horasS2);
            H =PegarHorarioCurso(horasS2);
            strcpy(aux->dado.horario,horasS2[H]);
            strcpy(horasS2[H],"indis.");
        }
        if(aux->dado.local==3){
            strcpy(horasS3[aux->dado.EditcU],horasTarde[aux->dado.EditcU]);
            AvisoEventoCursoHorario(horasS3);
            H =PegarHorarioCurso(horasS3);
            strcpy(aux->dado.horario,horasS3[H]);
            strcpy(horasS3[H],"indis.");
        }


    gotoxy(39,32);printf("                                                            ");
}


void editarCurso(LISTAcU* li, int cadastroINFO){

    if(li !=NULL){
        CAPScU* aux=li->inicio;
        while(aux!=NULL){//varre todos da lista
            if(aux->dado.n_cadastrocU==cadastroINFO){
                VcadastrarCurso();
                gotoxy(27,32);printf("%d",aux->dado.n_cadastrocU);
                //------------------------------capacidade
                gotoxy(48,13);printf("  %d",aux->dado.capacidade);setbuf(stdin,NULL);

                //-----------------------local
                AvisoEventoLimpar();
                AvisoEventoCursoLocais();
                EditarLocalCurso(aux);
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
        //caso nao tenha entrado no if e dado break;
        AvisoNumeroNaoEcontrado();
        return;
    }else{
        printf("ERRO DE ALOCACAO!!!\n");
    }
}


main(){


    VcadastrarCurso();

    EVENTOcU cU;
    LISTAcU *licU=CriarcU();
    int n_cadastrocU=3000;

    pegarInfoCurso(&cU,licU,n_cadastrocU);
    inserirListacU(licU,cU);
    //mostrar todos
    //
    system("cls");
    int num_editarcU;
    VeditarCurso();
    gotoxy(22,17);scanf("%d",&num_editarcU);
    system("cls");
    editarCurso(licU,num_editarcU);
    //
    system("cls");
    mostrarTodoscU(licU);
    getchar();
    //remover
    system("cls");
    int num_removercU;
    VremoverCurso();
    gotoxy(22,17);scanf("%d",&num_removercU);
    removerListacU(licU,num_removercU);
//editar


    liberar(licU);
}




//para rodar basta colocar no projeto com visual
