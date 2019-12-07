#include <stdio.h>
#include <stdlib.h>
#include "Visual.h"
#include "Organizador.h"
#include "Palestrante.h"
#include "Congressista.h"
#include "Palestra.h"
//structss
EVENTOC eC;//congressistas
ORGANIZADOR eO;//organizadores
PALESTRANTE pT;//palestrantes
PALESTRA eP;

//listas---


//matriculas
int MatriculaO=1000;//ORGANIZADORES
int MatriculaC=2000;//CONGRESSISTAS
int MatriculapT=3000;//PALESTRANTES
int MatriculaP=6000;//PALESTRAS



void menuPrincipal(){
    LISTAC *liC=CriarC();
    LISTAO *liO=CriarO();
    LISTApT *lipT=CriarpT();
    LISTA *liP=Criar();

    int on=1;
    char op;
    TelaLoading();

    while(on){
        limparTela();
        VopcoesPrincipal();
        gotoxy(2,33);op=getch();setbuf(stdin,NULL);
        switch(op){
            case '1'://Eventos
                MENUEVENTOSop(liP);

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

void MENUEVENTOSop(LISTA *liP){

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


                break;
            case '3'://cursos


                break;
            case '4'://oficinas


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
                 if(MatriculaC==6000){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodosP(liP);
                    getchar();
                }

                break;
            case '3'://remover
                if(MatriculaP==6000){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerP;
                    VremoverPalestra();
                    gotoxy(22,17);scanf("%d",&num_removerP);setbuf(stdin,NULL);
                    if(removerLista(liP,num_removerP)){
                        //caso nao remova
                    }else{
                        MatriculaP--;
                    }

                }

                break;
            case '4'://editar
                if(MatriculaP==6000){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_editarP;
                    VeditarPalestra();
                    gotoxy(22,17);scanf("%d",&num_editarP);setbuf(stdin,NULL);
                    editarCongressista(liP,num_editarP);
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
                if(MatriculaC==2000){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodosC(liC);
                    getchar();
                }
                break;
            case '3'://remover
                if(MatriculaC==2000){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerC;
                    VremoverCongressista();
                    gotoxy(22,17);scanf("%d",&num_removerC);setbuf(stdin,NULL);
                    if(removerListaC(liC,num_removerC)){
                        //caso nao remova
                    }else{
                        MatriculaC--;
                    }

                }
                break;
            case '4'://editar
                if(MatriculaC==2000){//Caso nenhum tenha sido cadastrado ainda
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
                if(MatriculapT==3000){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodospT(lipT);
                    getchar();
                }
                break;
            case '3'://remover
                if(MatriculapT==3000){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerpT;
                    VremoverPalestrante();
                    gotoxy(22,17);scanf("%d",&num_removerpT);setbuf(stdin,NULL);
                    if(removerListapT(lipT,num_removerpT)){
                        //caso nao remova
                    }else{
                        MatriculapT--;
                    }

                }
                break;
            case '4'://editar
                if(MatriculapT==3000){//Caso nenhum tenha sido cadastrado ainda
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
                if(MatriculaO==1000){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    mostrarTodosO(liO);
                    getchar();
                }
                break;
            case '3'://remover
                if(MatriculaO==1000){//Caso nenhum tenha sido cadastrado ainda
                    AvisoVAZIO();
                }else{
                    int num_removerO;
                    VremoverOrganizador();
                    gotoxy(22,17);scanf("%d",&num_removerO);setbuf(stdin,NULL);
                    if(removerListaO(liO,num_removerO)){
                        //caso nao remova
                    }else{
                        MatriculaO--;
                    }

                }
                break;
            case '4'://editar
                if(MatriculaO==1000){//Caso nenhum tenha sido cadastrado ainda
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
