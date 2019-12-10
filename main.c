#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Visual.h"
#include "Organizador.h"
#include "Palestrante.h"
#include "Congressista.h"
#include "Palestra.h"
#include "Grupos.h"
#include "Cursos.h"
#include "Oficinas.h"


//structss
EVENTOC eC;//congressistas
ORGANIZADOR eO;//organizadores
PALESTRANTE pT;//palestrantes
PALESTRA eP;//palestras
EVENTOG gD;//Grupos de discussoes
EVENTOK eK;//Cursos
EVENTOOf oF;//Oficinas

//MATRICULAS
int MatriculaO=1000;//ORGANIZADORES
int MatriculaC=2000;//CONGRESSISTAS
int MatriculapT=3000;//PALESTRANTES
int MatriculaP=6000;//PALESTRAS
int MatriculaG=7000;//GRUPOS DE DISCUSSAO
int MatriculaK=8000;//CURSO
int MatriculaOf=9000;//OFICINAS



void menuPrincipal(LISTAC *liC, LISTAO *liO,LISTApT *lipT,LISTA *liP,LISTAG *liG,LISTAK *liK,LISTAOf *liOf){


    int on=1,lim300=0;
    char op;
    TelaLoading();

    while(on){
        limparTela();
        VopcoesPrincipal();
        gotoxy(2,33);op=getch();setbuf(stdin,NULL);
        switch(op){
            case '1'://Eventos
                MENUEVENTOSop(liP,liG,liK,lipT,liOf);

                break;
            case '2'://congressistas
                CONGRESSISTAop(liC,lim300);

                break;
            case '3'://palestrantes
                PALESTRANTESop(lipT);

                break;
            case '4'://organizadores
                ORGANIZADORESop(liO);

                break;
            case '5'://gerenciar eventos
                GERENCIARop(liP,liC,liG,liK,liOf);
                break;
            case '0':
                on=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;


        }//fim do switch


    }//fim do while


}//fim da funçao

void MENUEVENTOSop(LISTA *liP, LISTAG *liG,LISTAK *liK,LISTApT *lipT,LISTAOf *liOf){
    int onE=1;
    char opE;

    while(onE){
        limparTela();
        VopcoesEventos();
        gotoxy(2,33);opE=getch();setbuf(stdin,NULL);
        switch(opE){
            case '1'://palestras
                MENUPALESTRAop(liP,lipT);

                break;
            case '2'://grupos de discussoes
                MENUGRUPOop(liG,lipT);

                break;
            case '3'://cursos
                MENUCURSOop(liK,lipT);

                break;
            case '4'://oficinas
                MENUOFICINAop(liOf,lipT,liK);

                break;
            case '5'://voltar
                onE=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;
        }//fim do switch


    }//fim do while


}//fim da funçao

void MENUPALESTRAop(LISTA *liP,LISTApT *lipT){
    int onP=1;
    char opP;

    while(onP){
        limparTela();
        VopcoesPalestras();
        gotoxy(2,33);opP=getch();setbuf(stdin,NULL);
        switch(opP){
            case '1'://adicionar
                if(tamanhoListapT(lipT)==0){//caso n tenha palestrantes cadastrados
                    AvisoVAZIOP();
                }else{
                    MatriculaP++;
                    VcadastrarPalestra();
                    pegarInfoPalestra(&eP,liP,MatriculaP,lipT);
                    inserirLista(liP,eP);
                    system("cls");

                    AvisoADDsucesso();
                }

                break;
            case '2'://listar
                 if(tamanhoLista(liP)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodosP(liP);
                    getchar();
                }

                break;
            case '3'://remover
                if(tamanhoLista(liP)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerP;
                    VremoverPalestra();
                    gotoxy(22,17);scanf("%d",&num_removerP);setbuf(stdin,NULL);
                    desocuparPalestrante(lipT,liP,num_removerP);
                    removerHorario(liP,num_removerP);
                    removerLista(liP,num_removerP);

                }

                break;
            case '4'://editar
                if(tamanhoLista(liP)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_editarP;
                    VeditarPalestra();
                    gotoxy(22,17);scanf("%d",&num_editarP);setbuf(stdin,NULL);
                    desocuparPalestrante(lipT,liP,num_editarP);
                    editarPalestra(liP,num_editarP,lipT);
                }

                break;
            case '5'://voltar
                onP=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;
        }//fim do switch


    }//fim do while

}

void MENUGRUPOop(LISTA *liG,LISTApT *lipT){
    int onG=1;
    char opG;

    while(onG){
        limparTela();
        VopcoesGrupos();
        gotoxy(2,33);opG=getch();setbuf(stdin,NULL);
        switch(opG){
            case '1'://adicionar
                MatriculaG++;
                VcadastrarGrupos();
                pegarInfoGrupo(&gD,liG,MatriculaG,lipT);
                inserirListaG(liG,gD);

                AvisoADDsucesso();
                break;
            case '2'://listar
                if(tamanhoListaG(liG)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodosG(liG);
                    getchar();
                }

                break;
            case '3'://remover
                if(tamanhoListaG(liG)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerG;
                    VremoverGrupo();
                    gotoxy(22,17);scanf("%d",&num_removerG);setbuf(stdin,NULL);
                    removerListaG(liG,num_removerG);
                }

                break;
            case '4'://editar
                if(tamanhoListaG(liG)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_editarG;
                    VeditarGrupo();
                    gotoxy(22,17);scanf("%d",&num_editarG);setbuf(stdin,NULL);
                    editarGrupo(liG,num_editarG,lipT);
                }

                break;
            case '5'://voltar
                onG=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;
        }//fim do switch


    }//fim do while

}

void MENUCURSOop(LISTA *liK, LISTApT *lipT){
    int onK=1;
    char opK;

    while(onK){
        limparTela();
        VopcoesCursos();
        gotoxy(2,33);opK=getch();setbuf(stdin,NULL);
        switch(opK){
            case '1'://adicionar
                MatriculaK++;
                VcadastrarCurso();
                pegarInfoCurso(&eK,liK,MatriculaK,lipT);
                inserirListaK(liK,eK);

                AvisoADDsucesso();
                break;
            case '2'://listar
                    mostrarTodosK(liK);
                    getchar();



                break;
            case '3'://remover
                if(tamanhoListaK(liK)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerK;
                    VremoverCurso();
                    gotoxy(22,17);scanf("%d",&num_removerK);setbuf(stdin,NULL);
                    desocuparPalestranteK(lipT,liK,num_removerK);
                    removerHorarioK(liK,num_removerK);
                    removerListaK(liK,num_removerK);
                }

                break;
            case '4'://editar
                if(tamanhoListaK(liK)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_editarK;
                    VeditarCurso();
                    gotoxy(22,17);scanf("%d",&num_editarK);setbuf(stdin,NULL);
                    desocuparPalestranteK(lipT,liK,num_editarK);
                    editarCurso(liK,num_editarK,lipT);
                }

                break;
            case '5'://voltar
                onK=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;
        }//fim do switch


    }//fim do while
}

void MENUOFICINAop(EVENTOOf *liOf,LISTApT *lipT){
    int onOf=1;
    char opOf;

    while(onOf){
        limparTela();
        VopcoesOficinas();
        gotoxy(2,33);opOf=getch();setbuf(stdin,NULL);
        switch(opOf){
            case '1'://adicionar
                 MatriculaOf++;
                VcadastrarOficina();
                pegarInfoOficina(&oF,liOf,MatriculaOf,lipT);
                inserirListaOf(liOf,oF);

                AvisoADDsucesso();
                break;
            case '2'://listar
                 mostrarTodosOf(liOf);
                    getchar();



                break;
            case '3'://remover
                if(tamanhoListaOf(liOf)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerOf;
                    VremoverOficina();
                    gotoxy(22,17);scanf("%d",&num_removerOf);setbuf(stdin,NULL);
                    removerListaOf(liOf,num_removerOf);
                }

                break;
            case '4'://editar
                if(tamanhoListaOf(liOf)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_editarOf;
                    VeditarOficina();
                    gotoxy(22,17);scanf("%d",&num_editarOf);setbuf(stdin,NULL);
                    editarOficina(liOf,num_editarOf,lipT);
                }


                break;
            case '5'://voltar
                onOf=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;
        }//fim do switch


    }//fim do while

}

void CONGRESSISTAop(LISTAC *liC,int lim300){
    int onC=1;
    char opC;
    while(onC){
        limparTela();
        VopcoesCongressistas(lim300);
        gotoxy(2,33);opC=getch();setbuf(stdin,NULL);
        switch(opC){
            case '1'://cadastrar
                MatriculaC++;
                VcadastrarCongressista();
                pegarInfoCongressista(&eC,liC,MatriculaC);
                inserirListaC(liC,eC);

                AvisoADDsucesso();
                lim300++;
                break;
            case '2'://listar
                if(tamanhoListaC(liC)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodosC(liC);
                    getchar();
                }
                break;
            case '3'://remover
                if(tamanhoListaC(liC)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerC;
                    VremoverCongressista();
                    gotoxy(22,17);scanf("%d",&num_removerC);setbuf(stdin,NULL);
                    removerListaC(liC,num_removerC);
                    lim300--;

                }
                break;
            case '4'://editar
                if(tamanhoListaC(liC)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_editarC;
                    VeditarCongressista();
                    gotoxy(22,17);scanf("%d",&num_editarC);setbuf(stdin,NULL);
                    editarCongressista(liC,num_editarC);
                }
                break;

            case '5'://voltar
                onC=0;
                break;
            default:
                AvisoOPinvalida();
                break;

        }//fim do switch

    }//fim do while



}

void PALESTRANTESop(LISTApT *lipT){

    int onpT=1;
    char oppT;
    while(onpT){
        limparTela();
        VopcoesPalestrantes();
        gotoxy(2,33);oppT=getch();setbuf(stdin,NULL);
        switch(oppT){
            case '1'://cadastrar
                MatriculapT++;
                VcadastrarPalestrante();
                pegarInfoPalestrante(&pT,lipT,MatriculapT);
                inserirListapT(lipT,pT);

                AvisoADDsucesso();
                break;
            case '2'://listar
                if(tamanhoListapT(lipT)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodospT(lipT);
                    getchar();
                }
                break;
            case '3'://remover
                if(tamanhoListapT(lipT)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerpT;
                    VremoverPalestrante();
                    gotoxy(22,17);scanf("%d",&num_removerpT);setbuf(stdin,NULL);
                    removerListapT(lipT,num_removerpT);
                }
                break;
            case '4'://editar
                if(tamanhoListapT(lipT)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_editarpT;
                    VeditarPalestrante();
                    gotoxy(22,17);scanf("%d",&num_editarpT);setbuf(stdin,NULL);
                    editarPalestrante(lipT,num_editarpT);
                }
                break;

            case '5'://voltar
                onpT=0;
                break;
            default:
                AvisoOPinvalida();
                break;

        }//fim do switch

    }//fim do while



}

void ORGANIZADORESop(LISTAO *liO){
    int onO=1;
    char opO;
    while(onO){
        limparTela();
        VopcoesOrganizadores();
        gotoxy(2,33);opO=getch();setbuf(stdin,NULL);
        switch(opO){
            case '1'://cadastrar
                MatriculaO++;
                VcadastrarOrganizador();
                pegarInfoOrganizador(&eO,liO,MatriculaO);
                inserirListaO(liO,eO);

                AvisoADDsucesso();
                break;
            case '2'://listar
                if(tamanhoListaO(liO)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodosO(liO);
                    getchar();
                }
                break;
            case '3'://remover
                if(tamanhoListaO(liO)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerO;
                    VremoverOrganizador();
                    gotoxy(22,17);scanf("%d",&num_removerO);setbuf(stdin,NULL);
                    removerListaO(liO,num_removerO);

                }
                break;
            case '4'://editar
                if(tamanhoListaO(liO)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_editarO;
                    VeditarOrganizador();
                    gotoxy(22,17);scanf("%d",&num_editarO);setbuf(stdin,NULL);
                    editarOrganizador(liO,num_editarO);
                }
                break;

            case '5'://voltar
                onO=0;
                break;
            default:
                AvisoOPinvalida();
                break;

        }//fim do switch

    }//fim do while
}

void GERENCIARop(LISTA *liP,LISTAC *liC, LISTAG *liG,LISTAK *liK,LISTAOf liOf){
 int onGr=1;
 char opGr;

    while(onGr){
        limparTela();
        VopcoesGerenciar();
        gotoxy(2,33);opGr=getch();setbuf(stdin,NULL);
        switch(opGr){
            case '1'://palestras
                GERENCIARpalestra(liP,liC);


                break;
            case '2'://grupos de discussoes
                GERENCIARgrupo(liG,liC);

                break;
            case '3'://cursos
                GERENCIARcurso(liK,liC);

                break;
            case '4'://oficinas
                GERENCIARoficina(liOf,liC);

                break;
            case '5'://voltar
                onGr=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;
        }//fim do switch


    }//fim do while


}


void GERENCIARpalestra(LISTA *liP,LISTAC *liC){
    int MAT,PAL;//matricula, palestra
    int onGP=1;
    char opGP;
    int ProcurarPorM;//procurar palestra por matricula
    int REMOVERp,REMOVERc;//matricula de remover a palestra, matricula do congressista da palestra


    while(onGP){
        limparTela();
        VGerenciarPalestra();
        gotoxy(2,33);opGP=getch();setbuf(stdin,NULL);
        switch(opGP){
            case '1'://ADICIONAR
                if(tamanhoListaC(liC)==0){
                    AvisoVAZIO();
                }else{
                mostrarMeNdosCPalestra(liC);
                printf("ADICIONAR: ");scanf("%d",&MAT);setbuf(stdin,NULL);
                char NOME[50];
                strcpy(NOME,TransformarMemN(liC,MAT));
                system("cls");
                mostrarTodosP(liP);
                printf("NA PALESTRA: ");scanf("%d",&PAL);setbuf(stdin,NULL);
                adicionarCongressista(liP,PAL,&NOME,MAT);
                mudarPdoC(liC,MAT,PAL);
                AvisoADDsucessoSpeed();
                }
                break;
            case '2'://MOSTRAR POR PALESTRA
                mostrarTodosP(liP);
                printf("MOSTRAR TODOS DA PALESTRA: ");scanf("%d",&ProcurarPorM);setbuf(stdin,NULL);
                MostrarCongressistaPorPalestra(liP,ProcurarPorM);//palestras.c
                getchar();

                break;
            case '3'://REMOVER
                mostrarTodosP(liP);
                printf("REMOVER DA PALESTRA:");scanf("%d",&REMOVERp);
                system("cls");
                MostrarCongressistaPorPalestra(liP,REMOVERp);
                printf("O CONGRESSISTA: ");scanf("%d",&REMOVERc);
                RemoverCongressistaDaPalestra(liP,REMOVERp,REMOVERc);
                REMOVERmudarPdoC(liC,REMOVERc,0);//transforma de volta em zero
                break;
            case '4'://SAIR
                onGP=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;
        }//fim do switch
    }//fim do while
}

void GERENCIARgrupo(LISTAG *liG,LISTAC *liC){
    int MAT,PAL;//matricula, palestra
    int onG=1;
    char opG;
    int ProcurarPorM;//procurar palestra por matricula
    int REMOVERp,REMOVERc;//matricula de remover a palestra, matricula do congressista da palestra


    while(onG){
        limparTela();
        VGerenciarGrupo();
        gotoxy(2,33);opG=getch();setbuf(stdin,NULL);
        switch(opG){
            case '1'://ADICIONAR
                if(tamanhoListaC(liC)==0){
                    AvisoVAZIO();
                }else{
                mostrarMeNdosCPalestra(liC);
                printf("ADICIONAR: ");scanf("%d",&MAT);setbuf(stdin,NULL);
                char NOME[50];
                strcpy(NOME,TransformarMemN(liC,MAT));
                system("cls");
                mostrarTodosG(liG);
                printf("NO GRUPO: ");scanf("%d",&PAL);setbuf(stdin,NULL);
                adicionarCongressistaG(liG,PAL,&NOME,MAT);
                mudarGdoC(liC,MAT,PAL);
                AvisoADDsucessoSpeed();
                }
                break;
            case '2'://MOSTRAR POR PALESTRA
                mostrarTodosG(liG);
                printf("MOSTRAR TODOS DO GRUPO: ");scanf("%d",&ProcurarPorM);setbuf(stdin,NULL);
                MostrarCongressistaPorGrupo(liG,ProcurarPorM);//palestras.c
                getchar();

                break;
            case '3'://REMOVER
                mostrarTodosG(liG);
                printf("REMOVER DO GRUPO:");scanf("%d",&REMOVERp);
                system("cls");
                MostrarCongressistaPorGrupo(liG,REMOVERp);
                printf("O CONGRESSISTA: ");scanf("%d",&REMOVERc);
                RemoverCongressistaDoGrupo(liG,REMOVERp,REMOVERc);
                REMOVERmudarGdoC(liC,REMOVERc,0);//transforma de volta em zero
                break;
            case '4'://SAIR
                onG=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;
        }//fim do switch
    }//fim do while
}

void GERENCIARcurso(LISTAK *liK,LISTAC *liC){
    int MAT,PAL;//matricula, palestra
    int onG=1;
    char opG;
    int ProcurarPorM;//procurar palestra por matricula
    int REMOVERp,REMOVERc;//matricula de remover a palestra, matricula do congressista da palestra


    while(onG){
        limparTela();
        VGerenciarCurso();
        gotoxy(2,33);opG=getch();setbuf(stdin,NULL);
        switch(opG){
            case '1'://ADICIONAR
                if(tamanhoListaC(liC)==0){
                    AvisoVAZIO();
                }else{
                mostrarMeNdosCGrupo(liC);
                printf("ADICIONAR: ");scanf("%d",&MAT);setbuf(stdin,NULL);
                char NOME[50];
                strcpy(NOME,TransformarMemN(liC,MAT));
                system("cls");
                mostrarTodosK(liK);
                printf("NO CURSO: ");scanf("%d",&PAL);setbuf(stdin,NULL);
                adicionarCongressistaK(liK,PAL,&NOME,MAT);
                mudarCdoC(liC,MAT,PAL);
                AvisoADDsucessoSpeed();
                }
                break;
            case '2'://MOSTRAR POR PALESTRA
                mostrarTodosK(liK);
                printf("MOSTRAR TODOS DO CURSO: ");scanf("%d",&ProcurarPorM);setbuf(stdin,NULL);
                MostrarCongressistaPorCurso(liK,ProcurarPorM);//palestras.c
                getchar();

                break;
            case '3'://REMOVER
                mostrarTodosK(liK);
                printf("REMOVER DO CURSO:");scanf("%d",&REMOVERp);
                system("cls");
                MostrarCongressistaPorCurso(liK,REMOVERp);
                printf("O CONGRESSISTA: ");scanf("%d",&REMOVERc);
                RemoverCongressistaDoCurso(liK,REMOVERp,REMOVERc);
                REMOVERmudarCdoC(liC,REMOVERc,0);//transforma de volta em zero
                break;
            case '4'://SAIR
                onG=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;
        }//fim do switch
    }//fim do while
}

void GERENCIARoficina(LISTAOf *liOf,LISTAC *liC){
    int MAT,PAL;//matricula, palestra
    int onG=1;
    char opG;
    int ProcurarPorM;//procurar palestra por matricula
    int REMOVERp,REMOVERc;//matricula de remover a palestra, matricula do congressista da palestra


    while(onG){
        limparTela();
        VGerenciarOficina();
        gotoxy(2,33);opG=getch();setbuf(stdin,NULL);
        switch(opG){
            case '1'://ADICIONAR
                if(tamanhoListaC(liC)==0){
                    AvisoVAZIO();
                }else{
                mostrarMeNdosCOficina(liC);
                printf("ADICIONAR: ");scanf("%d",&MAT);setbuf(stdin,NULL);
                char NOME[50];
                strcpy(NOME,TransformarMemN(liC,MAT));
                system("cls");
                mostrarTodosOf(liOf);
                printf("NA OFICINA: ");scanf("%d",&PAL);setbuf(stdin,NULL);
                adicionarCongressistaOf(liOf,PAL,&NOME,MAT);
                mudarOdoC(liC,MAT,PAL);
                AvisoADDsucessoSpeed();
                }
                break;
            case '2'://MOSTRAR POR PALESTRA
                mostrarTodosOf(liOf);
                printf("MOSTRAR TODOS DA OFICINA: ");scanf("%d",&ProcurarPorM);setbuf(stdin,NULL);
                MostrarCongressistaPorOficina(liOf,ProcurarPorM);//palestras.c
                getchar();

                break;
            case '3'://REMOVER
                mostrarTodosOf(liOf);
                printf("REMOVER DA OFICINA:");scanf("%d",&REMOVERp);
                system("cls");
                MostrarCongressistaPorOficina(liOf,REMOVERp);
                printf("O CONGRESSISTA: ");scanf("%d",&REMOVERc);
                RemoverCongressistaDaOficina(liOf,REMOVERp,REMOVERc);
                REMOVERmudarOdoC(liC,REMOVERc,0);//transforma de volta em zero
                break;
            case '4'://SAIR
                onG=0;
                break;
            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;
        }//fim do switch
    }//fim do while
}
//fazer com que quando for editar coloca o palestrante desocupado


main(){
    LISTAC *liC=CriarC();
    LISTAO *liO=CriarO();
    LISTApT *lipT=CriarpT();
    LISTA *liP=Criar();//palestras
    LISTAG *liG=CriarG();
    LISTAK *liK=CriarK();
    LISTAOf *liOf=CriarOf();

    //caso diferente que zero vai mostrar lixo da memoria
    for(int i=0;i<6;i++){
        eC.P[i]=0;
        eC.G[i]=0;
    }


    menuPrincipal(liC,liO,lipT,liP,liG,liK,liOf);
    system("cls");
    printf("\t\t>>>FINALIZADO<<<");

    liberarC(liC);
    liberarO(liO);
    liberarpT(lipT);
    liberar(liP);
    liberarG(liG);
    liberarK(liK);
    liberarOf(liOf);
}
