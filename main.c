#include <stdio.h>
#include <stdlib.h>
#include "Visual.h"
#include "Organizador.h"
#include "Palestrante.h"
#include "Congressista.h"
#include "Palestra.h"
#include "Grupos.h"
#include "Cursos.h"


//structss
EVENTOC eC;//congressistas
ORGANIZADOR eO;//organizadores
PALESTRANTE pT;//palestrantes
PALESTRA eP;
EVENTOG gD;
EVENTOK eK;


int MatriculaO=1000;//ORGANIZADORES
int MatriculaC=2000;//CONGRESSISTAS
int MatriculapT=3000;//PALESTRANTES
int MatriculaP=6000;//PALESTRAS
int MatriculaG=7000;//GRUPOS DE DISCUSSAO

int MatriculaK=8000;//CURSO
int MatriculaOf=9000;//OFICINAS



void menuPrincipal(){
    LISTAC *liC=CriarC();
    LISTAO *liO=CriarO();
    LISTApT *lipT=CriarpT();
    LISTA *liP=Criar();//palestras
    LISTAG *liG=CriarG();
    LISTAK *liK=CriarK();

    int on=1;
    char op;
    TelaLoading();

    while(on){
        limparTela();
        VopcoesPrincipal();
        gotoxy(2,33);op=getch();setbuf(stdin,NULL);
        switch(op){
            case '1'://Eventos
                MENUEVENTOSop(liP,liG,liK);

                break;
            case '2'://congressistas
                CONGRESSISTAop(liC);

                break;
            case '3'://palestrantes
                PALESTRANTESop(lipT);

                break;
            case '4'://organizadores
                ORGANIZADORESop(liO);

                break;
            case '5'://gerenciar eventos

            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;


        }//fim do switch


    }//fim do while


}//fim da funçao

void MENUEVENTOSop(LISTA *liP, LISTAG *liG,LISTAK *liK){
    int onE=1;
    char opE;

    while(onE){
        limparTela();
        VopcoesEventos();
        gotoxy(2,33);opE=getch();setbuf(stdin,NULL);
        switch(opE){
            case '1'://palestras
                MENUPALESTRAop(liP);

                break;
            case '2'://grupos de discussoes
                MENUGRUPOop(liG);

                break;
            case '3'://cursos
                MENUCURSOop(liK);

                break;
            case '4'://oficinas
                MENUOFICINAop();

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

void MENUPALESTRAop(LISTA *liP){
    int onP=1;
    char opP;

    while(onP){
        limparTela();
        VopcoesPalestras();
        gotoxy(2,33);opP=getch();setbuf(stdin,NULL);
        switch(opP){
            case '1'://adicionar
                MatriculaP++;
                VcadastrarPalestra();
                pegarInfoPalestra(&eP,liP,MatriculaP);
                inserirLista(liP,eP);

                AvisoADDsucesso();
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
                    editarPalestra(liP,num_editarP);
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

void MENUGRUPOop(LISTA *liG){
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
                pegarInfoGrupo(&gD,liG,MatriculaG);
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
                    editarGrupo(liG,num_editarG);
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

void MENUCURSOop(LISTA *liK){
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
                pegarInfoCurso(&eK,liK,MatriculaK);
                inserirListaK(liK,eK);

                AvisoADDsucesso();
                break;
            case '2'://listar
                if(tamanhoListaK(liK)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodosK(liK);
                    getchar();
                }


                break;
            case '3'://remover
                if(tamanhoListaK(liK)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerK;
                    VremoverCurso();
                    gotoxy(22,17);scanf("%d",&num_removerK);setbuf(stdin,NULL);
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
                    editarCurso(liK,num_editarK);
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

void MENUOFICINAop(){
    int onOf=1;
    char opOf;

    while(onOf){
        limparTela();
        VopcoesOficinas();
        gotoxy(2,33);opOf=getch();setbuf(stdin,NULL);
        switch(opOf){
            case '1'://adicionar

                break;
            case '2'://listar


                break;
            case '3'://remover

                break;
            case '4'://editar


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

void CONGRESSISTAop(LISTAC *liC){

    int onC=1;
    char opC;
    while(onC){
        limparTela();
        VopcoesCongressistas();
        gotoxy(2,33);opC=getch();setbuf(stdin,NULL);
        switch(opC){
            case '1'://cadastrar
                MatriculaC++;
                VcadastrarCongressista();
                pegarInfoCongressista(&eC,liC,MatriculaC);
                inserirListaC(liC,eC);

                AvisoADDsucesso();
                break;
            case '2'://listar
                if(tamanhoLista(liC)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodosC(liC);
                    getchar();
                }
                break;
            case '3'://remover
                if(tamanhoLista(liC)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerC;
                    VremoverCongressista();
                    gotoxy(22,17);scanf("%d",&num_removerC);setbuf(stdin,NULL);
                    removerListaC(liC,num_removerC);

                }
                break;
            case '4'://editar
                if(tamanhoLista(liC)==0){//Caso nenhum tenha sido cadastrado ainda
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
                if(tamanhoLista(lipT)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodospT(lipT);
                    getchar();
                }
                break;
            case '3'://remover
                if(tamanhoLista(lipT)==0){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerpT;
                    VremoverPalestrante();
                    gotoxy(22,17);scanf("%d",&num_removerpT);setbuf(stdin,NULL);
                    removerListapT(lipT,num_removerpT);
                }
                break;
            case '4'://editar
                if(tamanhoLista(lipT)==0){//Caso nenhum tenha sido cadastrado ainda
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

main(){



    menuPrincipal();


}
