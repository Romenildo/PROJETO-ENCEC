#include <stdio.h>
#include <stdlib.h>
#include "Visual.h"
#include "Organizador.h"
#include "Palestrante.h"
#include "Congressista.h"
//structss
EVENTOC eC;
ORGANIZADOR eO;

//listas---


//matriculas
int MatriculaO=1000;//ORGANIZADORES
int MatriculaC=2000;//CONGRESSISTAS




void menuPrincipal(){
    LISTAC *liC=CriarC();
    LISTAO *liO=CriarO();

    int on=1;
    char op;
    TelaLoading();

    while(on){
        limparTela();
        VopcoesPrincipal();
        gotoxy(2,33);op=getch();setbuf(stdin,NULL);
        switch(op){
            case '1'://Eventos


            case '2'://congressistas
                CONGRESSISTAop(liC);

                break;
            case '3'://palestrantes


            case '4'://organizadores
                ORGANIZADORESop(liO);

            case '5'://gerenciar eventos

            default:
                AvisoOPinvalida();//caso tenha digitado um que n tenha nas opcoes
                break;


        }//fim do switch


    }//fim do while


}//fim da funçao

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
