#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "Visual.h"
//fazer o system color com todas as cores Amarelo();
//-----------------------CORES----------
#define C_RESET   "\x1b[0m"
#define C_BLACK      "\x1b[30m"
#define C_RED      "\x1b[31m"
#define C_GREEN      "\x1b[32m"
#define C_YELLOW      "\x1b[33m"
#define C_WATER      "\x1b[36m"
#define C_BLUE   "\x1b[34m"
#define C_WHITE      "\x1b[1m"
//-------------------END CORES-------------------
//-------------------FUNCOES---------------------
void limparTela(){
    system("cls");
}
void gotoxy(int x, int y){
    //posiciona o cursor em determinado local da tela
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void PFchar(int ch){
    //printar caractere fixo
    printf("%c",ch);

}

void PMchar(int local1,int local2,int quant){
    //printar multiplos caracteres
    gotoxy(local1,local2);
    for(int i=0;i<quant;i++){
        printf("%c",219);
    }
}

void Pchar(int local1, int local2, int caractere){
    //printar caractere em local especifico

        gotoxy(local1,local2);printf("%c", caractere);
}
void linhaV(int tam,int local1,int local2){
    //printar linha no local desejado com o tamnho que quiser
    for(int i=0;i<tam;i++){
        gotoxy(local1,local2);printf("%c",179);
        local2+=1;

    }
}

void PlinhaV(int tam){
    //printar linha no local desejado com o tamnho que quiser
    for(int i=0;i<tam;i++){
        printf("%c",179);
    }
}
void PlinhaH(int tam){
    //printar linha do tamanho dito
    for(int i=0;i<tam;i++){
        printf("%c",196);
    }
}

void linhaH(int tam,int local1,int local2){
    //printar linha no local desejado com o tamnho que quiser
    for(int i=0;i<tam;i++){
        gotoxy(local1,local2);printf("%c",196);
        local1+=1;

    }
}

//-----------------END FUNCOES--------------------
//-----------------VISUAL---------------------------
void VdesignOP(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(35,38,12);linhaH(35,38,14);linhaV(3,38,12);linhaV(3,73,12);
    Pchar(38,12,218);Pchar(73,12,191);Pchar(38,14,192);Pchar(73,14,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    linhaH(35,9,16);linhaH(35,9,18);linhaV(3,9,16);linhaV(3,43,16);
    Pchar(9,16,218);Pchar(43,16,191);Pchar(9,18,192);Pchar(43,18,217);

    //------------------------------------------2 linha
    linhaH(35,9,19);linhaH(35,9,21);linhaV(3,9,19);linhaV(3,43,19);
    Pchar(9,19,218);Pchar(43,19,191);Pchar(9,21,192);Pchar(43,21,217);

    //--------------------------------------------3 lnha
    linhaH(35,9,22);linhaH(35,9,24);linhaV(3,9,22);linhaV(3,43,22);
    Pchar(9,22,218);Pchar(43,22,191);Pchar(9,24,192);Pchar(43,24,217);

    //-------------------------------4 linha
    linhaH(35,9,25);linhaH(35,9,27);linhaV(3,9,25);linhaV(3,43,25);
    Pchar(9,25,218);Pchar(43,25,191);Pchar(9,27,192);Pchar(43,27,217);
    //--------------------5linha
    linhaH(35,9,28);linhaH(35,9,30);linhaV(3,9,28);linhaV(3,43,28);
    Pchar(9,28,218);Pchar(43,28,191);Pchar(9,30,192);Pchar(43,30,217);
    //-------------------6linha

}


void TelaLoading(){
    system("color 0F");
    //mostrar tela de carregamento ENCEC
    PMchar(20,10,10);PMchar(34,10,3);PMchar(43,10,3);PMchar(49,10,9);PMchar(61,10,9);PMchar(73,10,9);
    PMchar(20,11,3);PMchar(34,11,5);PMchar(43,11,3);PMchar(49,11,3);PMchar(56,11,2);PMchar(61,11,3);PMchar(73,11,3);PMchar(80,11,2);
    PMchar(20,12,3);PMchar(34,12,7);PMchar(43,12,3);PMchar(49,12,3);PMchar(61,12,3);PMchar(73,12,3);
    PMchar(20,13,8);PMchar(34,13,3);PMchar(38,13,4);PMchar(43,13,3);PMchar(49,13,3);PMchar(61,13,8);PMchar(73,13,3);
    PMchar(20,14,3);PMchar(34,14,3);PMchar(40,14,6);PMchar(49,14,3);PMchar(61,14,3);PMchar(73,14,3);
    PMchar(20,15,3);PMchar(34,15,3);PMchar(41,15,5);PMchar(49,15,3);PMchar(56,15,2);PMchar(61,15,3);PMchar(73,15,3);PMchar(80,15,2);
    PMchar(20,16,10);PMchar(34,16,3);PMchar(43,16,3);PMchar(49,16,9);PMchar(61,16,9);PMchar(73,16,9);
    gotoxy(78,17);printf("UEPB");
    gotoxy(24,24);printf("CARREGANDO...");
    //  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(47,23,25);linhaH(47,23,27);linhaV(3,23,25);linhaV(3,70,25);
    Pchar(23,25,218);Pchar(70,25,191);Pchar(23,27,192);Pchar(70,27,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    gotoxy(24,26);
    for(int time=5,i=0;i<46;i++){
        PFchar(219);
        Sleep(time*i);
    }
 system("cls");
}

void Vcabecalho(){
    //BASE VISUAL DO SISTEMA
        //33 maxima baixo 106 maximo lado
    //quadrado de cima
    linhaV(6,5,5);linhaH(100,6,5);linhaV(5,106,5);linhaH(101,5,10);
    Pchar(5,5,218);Pchar(106,5,191);Pchar(5,10,192);Pchar(106,10,217);
    //----------------quadrado de baixo------------------------------------------------
    linhaH(100,6,11);linhaV(23,5,11);linhaH(100,6,34);linhaV(23,106,11);
    Pchar(5,11,218);Pchar(106,11,191);Pchar(5,34,192);Pchar(106,34,217);

    gotoxy(8,6);printf("UEPB - UNIVERSIDADE ESTADUAL DA PARAIBA");
    gotoxy(8,9);printf("GERENCIAMENTO - ENCEC");

    gotoxy(80,9);printf("%s  , %s\n",__DATE__,__TIME__);
}

void VopcoesPrincipal(){
    //primeira tela de opcoes
    system("color F0");
    Vcabecalho();
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   / linha baixo
    printf(C_WATER"");linhaH(27,9,12);linhaH(27,9,14);linhaV(10,9,12);linhaV(10,36,12);linhaH(27,9,22);
    Pchar(9,12,218);Pchar(36,12,191);Pchar(9,14,195);Pchar(36,14,180);Pchar(9,22,192);Pchar(36,22,217);
//  lados de cima   ----------------/lados 2 de cima----------------/ lados de baixo---------------
    gotoxy(11,13);printf("1-EVENTOS");
    gotoxy(11,15);PFchar(175);printf(" PALESTRAS");
    gotoxy(11,16);PFchar(175);printf(" GRUPOS DE DISCUSSOES");
    gotoxy(11,17);PFchar(175);printf(" CURSOS");
    gotoxy(11,18);PFchar(175);printf(" OFICINAS");
    gotoxy(11,19);PFchar(175);printf(" VOLTAR"C_BLACK);

    //-----------------------2H
    printf(C_BLUE"");linhaH(27,42,12);linhaH(27,42,14);linhaV(10,42,12);linhaV(10,69,12);linhaH(27,42,22);
    Pchar(42,12,218);Pchar(69,12,191);Pchar(42,14,195);Pchar(69,14,180);Pchar(42,22,192);Pchar(69,22,217);
    gotoxy(44,13);printf("2-CONGRESSISTAS");
    gotoxy(44,15);PFchar(175);printf(" CADASTRAR");
    gotoxy(44,16);PFchar(175);printf(" LISTAR");
    gotoxy(44,17);PFchar(175);printf(" EDITAR");
    gotoxy(44,18);PFchar(175);printf(" REMOVER");
    gotoxy(44,19);PFchar(175);printf(" VOLTAR"C_BLACK);
    //------------------------3H
    printf(C_YELLOW"");linhaH(27,74,12);linhaH(27,74,14);linhaV(10,74,12);linhaV(10,100,12);linhaH(27,74,22);
    Pchar(74,12,218);Pchar(100,12,191);Pchar(74,14,195);Pchar(100,14,180);Pchar(74,22,192);Pchar(100,22,217);
    gotoxy(76,13);printf("3-PALESTRANTES");
    gotoxy(76,15);PFchar(175);printf(" CADASTRAR");
    gotoxy(76,16);PFchar(175);printf(" LISTAR");
    gotoxy(76,17);PFchar(175);printf(" EDITAR");
    gotoxy(76,18);PFchar(175);printf(" REMOVER");
    gotoxy(76,19);PFchar(175);printf(" VOLTAR"C_BLACK);
    //----------------------1V altura 23
    linhaH(27,25,23);linhaH(27,25,25);linhaV(10,25,23);linhaV(10,51,23);linhaH(27,25,33);
    Pchar(25,23,218);Pchar(51,23,191);Pchar(25,25,195);Pchar(51,25,180);Pchar(51,33,192);Pchar(51,33,217);
    gotoxy(27,24);printf("4-ORGANIZADORES");
    gotoxy(27,26);PFchar(175);printf(" CADASTRAR");
    gotoxy(27,27);PFchar(175);printf(" LISTAR");
    gotoxy(27,28);PFchar(175);printf(" EDITAR");
    gotoxy(27,29);PFchar(175);printf(" REMOVER");
    gotoxy(27,30);PFchar(175);printf(" VOLTAR");
    //-----------------------2V
    linhaH(27,62,23);linhaH(27,62,25);linhaV(10,62,23);linhaV(10,89,23);linhaH(27,62,33);
    Pchar(62,23,218);Pchar(89,23,191);Pchar(62,25,195);Pchar(89,25,180);Pchar(62,33,192);Pchar(89,33,217);
    gotoxy(64,24);printf("5-GERENCIAR EVENTOS");
    gotoxy(64,26);PFchar(175);printf(" PALESTRAS");
    gotoxy(64,27);PFchar(175);printf(" CURSOS");
    gotoxy(64,28);PFchar(175);printf(" GRUPOS DE DISCUSSOES");
    gotoxy(64,29);PFchar(175);printf(" OFICINAS");
    gotoxy(64,30);PFchar(175);printf(" VOLTAR");
    gotoxy(100,33);printf("0-sair");

    //------------------------3V

    //------------------------3V

}
void VopcoesOficinas(){
    system("cls");
    system("color B0");
    Vcabecalho();
    VdesignOP();
    gotoxy(39,13);printf("            OFICINAS ");
    gotoxy(11,17);printf("1 - CADASTRAR");
    gotoxy(11,20);printf("2 - LISTAR");
    gotoxy(11,23);printf("3 - REMOVER");
    gotoxy(11,26);printf("4 - EDITAR");
    gotoxy(11,29);printf("5 - VOLTAR");
}

void VopcoesEventos(){
    system("cls");
    system("color B0");
    Vcabecalho();
    VdesignOP();
    gotoxy(39,13);printf("              EVENTOS");
    gotoxy(11,17);printf("1 - PALESTRAS");
    gotoxy(11,20);printf("2 - GRUPOS DE DISCUSSOES");
    gotoxy(11,23);printf("3 - CURSOS");
    gotoxy(11,26);printf("4 - OFICINAS");
    gotoxy(11,29);printf("5 - VOLTAR");
    AvisoOPeventos();
}
void AvisoOPeventos(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(32,60,16);linhaH(32,60,25);linhaV(10,60,16);linhaV(10,91,16);
    Pchar(60,16,218);Pchar(91,16,191);Pchar(60,25,192);Pchar(91,25,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,17);printf(" AVISO");
    gotoxy(62,19);printf("  Criacao dos eventos");
    gotoxy(62,20);printf("  devem ser criados");
    gotoxy(62,21);printf(" primeiros para poder");
    gotoxy(62,22);printf("ir para parte de gerenciar!");
}
void VopcoesGerenciar(){
    system("cls");
    system("color F0");
    Vcabecalho();
    VdesignOP();
    gotoxy(39,13);printf("              EVENTOS");
    gotoxy(11,17);printf("1 - PALESTRAS");
    gotoxy(11,20);printf("2 - GRUPOS DE DISCUSSOES");
    gotoxy(11,23);printf("3 - CURSOS");
    gotoxy(11,26);printf("4 - OFICINAS");
    gotoxy(11,29);printf("5 - VOLTAR");
    AvisoOPgerenciar();
}
void AvisoOPgerenciar(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(32,60,16);linhaH(32,60,25);linhaV(10,60,16);linhaV(10,91,16);
    Pchar(60,16,218);Pchar(91,16,191);Pchar(60,25,192);Pchar(91,25,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,17);printf(" AVISO");
    gotoxy(62,19);printf("  Gerenciar os eventos");
    gotoxy(62,20);printf(" Pode adicionar os");
    gotoxy(62,21);printf(" congressistas nos");
    gotoxy(62,22);printf(" devidos eventos ");
    gotoxy(62,23);printf("  cadastrados!");

}
void VopcoesCursos(){
    system("cls");
    system("color B0");
    Vcabecalho();
    VdesignOP();
    gotoxy(39,13);printf("             CURSOS");
    gotoxy(11,17);printf("1 - CADASTRAR");
    gotoxy(11,20);printf("2 - LISTAR");
    gotoxy(11,23);printf("3 - REMOVER");
    gotoxy(11,26);printf("4 - EDITAR");
    gotoxy(11,29);printf("5 - VOLTAR");
}


void VopcoesGrupos(){
    system("cls");
    system("color B0");
    Vcabecalho();
    VdesignOP();
    gotoxy(39,13);printf("      GRUPOS DE DISCUSSOES");
    gotoxy(11,17);printf("1 - CADASTRAR");
    gotoxy(11,20);printf("2 - LISTAR");
    gotoxy(11,23);printf("3 - REMOVER");
    gotoxy(11,26);printf("4 - EDITAR");
    gotoxy(11,29);printf("5 - VOLTAR");
    AvisoOPgrupos();
}
void AvisoOPgrupos(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(32,60,16);linhaH(32,60,25);linhaV(10,60,16);linhaV(10,91,16);
    Pchar(60,16,218);Pchar(91,16,191);Pchar(60,25,192);Pchar(91,25,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,17);printf(" AVISO");
    gotoxy(62,19);printf("  Os grupos sao organizados");
    gotoxy(62,20);printf(" entre 1 a 5 palestrantes");

}

void VopcoesPalestras(){
    system("cls");
    system("color B0");
    Vcabecalho();
    VdesignOP();
    gotoxy(39,13);printf("          PALESTRAS");
    gotoxy(11,17);printf("1 - CADASTRAR");
    gotoxy(11,20);printf("2 - LISTAR");
    gotoxy(11,23);printf("3 - REMOVER");
    gotoxy(11,26);printf("4 - EDITAR");
    gotoxy(11,29);printf("5 - VOLTAR");
    AvisoOPpalestras();
}
void AvisoOPpalestras(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(32,60,16);linhaH(32,60,25);linhaV(10,60,16);linhaV(10,91,16);
    Pchar(60,16,218);Pchar(91,16,191);Pchar(60,25,192);Pchar(91,25,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,17);printf(" AVISO");
    gotoxy(62,19);printf("  As palestras so poderao");
    gotoxy(62,20);printf(" ser cadastradas caso");
    gotoxy(62,21);printf(" haja palestrantes!!");
}


void VopcoesPalestrantes(){
    system("cls");
    system("color E0");
Vcabecalho();
VdesignOP();
    gotoxy(39,13);printf("          PALESTRANTES");
    gotoxy(11,17);printf("1 - CADASTRAR");
    gotoxy(11,20);printf("2 - LISTAR");
    gotoxy(11,23);printf("3 - REMOVER");
    gotoxy(11,26);printf("4 - EDITAR");
    gotoxy(11,29);printf("5 - VOLTAR");
    AvisoOPpalestrantes();
}
void AvisoOPpalestrantes(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(32,60,16);linhaH(32,60,25);linhaV(10,60,16);linhaV(10,91,16);
    Pchar(60,16,218);Pchar(91,16,191);Pchar(60,25,192);Pchar(91,25,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,17);printf(" AVISO");
    gotoxy(62,19);printf("  Os palestrantes sao");
    gotoxy(62,20);printf(" sao os principais para o");
    gotoxy(62,21);printf("evento devem ser cadastrados");
    gotoxy(62,22);printf("antes de adicionar os eventos!");
}

void VopcoesCongressistas(int lim300){
    system("cls");
    system("color 9F");
Vcabecalho();
VdesignOP();
    gotoxy(39,13);printf("          CONGRESSISTAS");
    gotoxy(11,17);printf("1 - CADASTRAR");
    gotoxy(11,20);printf("2 - LISTAR");
    gotoxy(11,23);printf("3 - REMOVER");
    gotoxy(11,26);printf("4 - EDITAR");
    gotoxy(11,29);printf("5 - VOLTAR");
    AvisoOPCongressistas(lim300);
}

void VopcoesOrganizadores(){
    system("cls");
    system("color 0F");
Vcabecalho();
VdesignOP();
    gotoxy(39,13);printf("          ORGANIZADORES");
    gotoxy(11,17);printf("1 - CADASTRAR");
    gotoxy(11,20);printf("2 - LISTAR");
    gotoxy(11,23);printf("3 - REMOVER");
    gotoxy(11,26);printf("4 - EDITAR");
    gotoxy(11,29);printf("5 - VOLTAR");
    AvisoOPorganizadores();
}
void AvisoOPorganizadores(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(32,60,16);linhaH(32,60,25);linhaV(10,60,16);linhaV(10,91,16);
    Pchar(60,16,218);Pchar(91,16,191);Pchar(60,25,192);Pchar(91,25,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,17);printf(" AVISO");
    gotoxy(62,19);printf("    Os organizadores");
    gotoxy(62,20);printf("     sao da parte do ");
    gotoxy(62,21);printf("  gerenciamento do evento");
}
//--------------------VISUAL EVENTO


//---------------END VISUAL EVENTO
//----------------VISUAL CADASTROS---------------
void Vcadastrar(){
system("color 0F");
Vcabecalho();
linhaH(99,6,12);linhaV(22,6,12);linhaH(99,6,33);linhaV(22,105,12);
Pchar(6,12,218);Pchar(105,12,191);Pchar(6,33,192);Pchar(105,33,217);
//-------------
linhaV(22,35,12);Pchar(35,12,194);Pchar(35,33,193);
linhaH(60,6,15);Pchar(6,15,195);Pchar(35,15,197);//capacidade
linhaH(60,6,18);Pchar(6,18,195);Pchar(35,18,197);//local
linhaH(60,6,21);Pchar(6,21,195);Pchar(35,21,197);//carga horaria
linhaH(99,6,24);Pchar(6,24,195);Pchar(35,24,197);Pchar(105,24,180);//horario
linhaH(99,6,27);Pchar(6,27,195);Pchar(35,27,197);Pchar(105,27,180);//tema
linhaH(99,6,31);Pchar(6,31,195);Pchar(35,31,197);Pchar(105,31,180);//palestrante
linhaV(13,65,12);Pchar(65,12,194);Pchar(65,15,180);Pchar(65,18,180);Pchar(65,21,180);
Pchar(65,24,193);

}
void VcadastrarCongressista(){
    system("cls");
    Vcadastrar();
    gotoxy(16,13);printf("IDADE ");
    gotoxy(16,16);printf("TELEFONE");
    gotoxy(16,19);printf("CPF");
    gotoxy(16,22);printf("CURSO");
    gotoxy(16,25);printf("EMAIL");
    gotoxy(16,28);printf("NOME");
    gotoxy(16,32);printf("MATRICULA");
    AvisoEventoLimpar();
}

void VcadastrarPalestra(){
    system("cls");
    Vcadastrar();
    gotoxy(16,13);printf("CAPACIDADE ");
    gotoxy(16,16);printf("LOCAL");
    gotoxy(16,19);printf("CARGA HORARIA");
    gotoxy(16,22);printf("HORARIO");
    gotoxy(16,25);printf("TEMA");
    gotoxy(16,28);printf("PALESTRANTE");
    gotoxy(16,32);printf("CADASTRO");

    AvisoEventoLimpar();
}
void VcadastrarGrupos(){
    system("cls");
    Vcadastrar();
    gotoxy(16,13);printf("CAPACIDADE ");//30 A 50
    gotoxy(16,16);printf("LOCAL");
    gotoxy(16,19);printf("CARGA HORARIA");//TARDE
    gotoxy(16,22);printf("HORARIO");
    gotoxy(16,25);printf("TEMA");
    gotoxy(16,28);printf("MEMBROS");
    gotoxy(16,32);printf("NUMERO");
    linhaV(4,75,24);Pchar(75,24,194);Pchar(75,27,193);
    gotoxy(77,25);printf("QUANT.");
    gotoxy(77,26);printf("MEMBROS");//MAX 5
    gotoxy(16,32);printf("CADASTRO");
    linhaV(4,90,24);Pchar(90,24,194);Pchar(90,27,193);//scanf quant fica aq
    AvisoEventoGrupo();
}
void VcadastrarCurso(){
    system("cls");
    Vcadastrar();
    gotoxy(16,13);printf("CAPACIDADE ");//MAX 40
    gotoxy(16,16);printf("LOCAL");
    gotoxy(16,19);printf("CARGA HORARIA");//TARDE
    gotoxy(16,22);printf("HORARIO");
    gotoxy(16,25);printf("TEMA");
    gotoxy(14,28);printf("PROF. PALESTRANTE");
    gotoxy(16,32);printf("CADASTRO");
    AvisoEventoCurso();
}
void VcadastrarOficina(){
    system("cls");
    Vcadastrar();
    gotoxy(16,13);printf("CAPACIDADE ");//MAX 20
    gotoxy(16,16);printf("LOCAL");
    gotoxy(16,19);printf("CARGA HORARIA");//TARDE
    gotoxy(16,22);printf("HORARIO");
    gotoxy(16,25);printf("TEMA");
    gotoxy(14,28);printf("PROF. PALESTRANTE");
    gotoxy(16,32);printf("CADASTRO");
    AvisoEventoOficina();
}
//0------------------END VISUAL CADASTROS-----------------
//------------------VISUAL REMOVER------------------


//mover todos os remover para ca depois


//---------------------END VISUAL REMOVER----------------

//-----------------END VISUAL---------------------


//--------------------AVISOS-------
void AvisoX(){
    system("cls");
    //avisos como num invalido , digitado errado
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(32,41,11);linhaH(32,41,20);linhaV(10,41,11);linhaV(10,72,11);
    Pchar(41,11,218);Pchar(72,11,191);Pchar(41,20,192);Pchar(72,20,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(50,12);printf(" AVISO");
    gotoxy(43,14);printf("Capacidade  39/50");
    gotoxy(43,15);printf("horarios disponiveis");
    gotoxy(43,16);printf("Avisos xxxxxxxxx");
    gotoxy(43,17);printf("Avisos xxxxxxxxx");
    gotoxy(43,18);printf("Avisos xxxxxxxxx");

}

void AvisoOP(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(32,60,16);linhaH(32,60,25);linhaV(10,60,16);linhaV(10,91,16);
    Pchar(60,16,218);Pchar(91,16,191);Pchar(60,25,192);Pchar(91,25,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,17);printf(" AVISO");
    gotoxy(62,19);printf("Capacidade  39/50");
    gotoxy(62,20);printf("horarios disponiveis");
    gotoxy(62,21);printf("Avisos xxxxxxxxx");
    gotoxy(62,22);printf("Avisos xxxxxxxxx");
    gotoxy(62,23);printf("Avisos xxxxxxxxx");

}
void AvisoOPCongressistas(int lim300){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(32,60,16);linhaH(32,60,25);linhaV(10,60,16);linhaV(10,91,16);
    Pchar(60,16,218);Pchar(91,16,191);Pchar(60,25,192);Pchar(91,25,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,17);printf(" AVISO");
    gotoxy(62,19);printf("   Capacidade  %d/300",lim300);
    gotoxy(62,20);printf("  Limite maximo de");
    gotoxy(62,21);printf(" congressistas no evento");
    gotoxy(62,22);printf(" sao de 300 pessoas!");

}

void AvisoEventoCurso(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(32,60,16);linhaH(32,60,25);linhaV(10,60,16);linhaV(10,91,16);
    Pchar(60,16,218);Pchar(91,16,191);Pchar(60,25,192);Pchar(91,25,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,17);printf(" AVISO");
    gotoxy(62,19);printf("");
    gotoxy(62,20);printf("");
    gotoxy(62,21);printf("");
    gotoxy(62,22);printf("");
    gotoxy(62,23);printf("");

}

void AvisoEventoPalestraLocais(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(38,66,13);linhaH(38,66,23);linhaV(11,66,13);linhaV(11,103,13);
    Pchar(66,13,218);Pchar(103,13,191);Pchar(66,23,192);Pchar(103,23,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,17);printf("  Locais disponiveis");
    gotoxy(80,18);printf("         Capacidade");

    gotoxy(72,19);printf("1-Auditorio 1       150");

    gotoxy(72,20);printf("2-Auditorio 2       100");

    gotoxy(72,21);printf("3-Auditorio 3        50");
}
void AvisoP(){
    //mostrar informaçoes sobre os palestrante cadastro
    gotoxy(72,18);printf("DIGITE 0(zero)");

    gotoxy(72,19);printf("PARA MOSTRAR A LISTA");

    gotoxy(72,20);printf("DE PALESTRANTES");
}
void AvisoEventoLocais(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(38,66,13);linhaH(38,66,23);linhaV(11,66,13);linhaV(11,103,13);
    Pchar(66,13,218);Pchar(103,13,191);Pchar(66,23,192);Pchar(103,23,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(72,16);printf("  Locais disponiveis");
    gotoxy(80,17);printf("         Capacidade");
    gotoxy(72,18);printf("         1-Sala 1      50");

    gotoxy(72,19);printf("         2-Sala 2      50");

    gotoxy(72,20);printf("         3-Sala 3      50");

    gotoxy(72,21);printf("         4-Lab 1       20");

    gotoxy(72,22);printf("         5-Lab 2       20");
}


void AvisoEventoHorarios(char horas[7][10]){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(38,66,13);linhaH(38,66,23);linhaV(11,66,13);linhaV(11,103,13);
    Pchar(66,13,218);Pchar(103,13,191);Pchar(66,23,192);Pchar(103,23,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida

    gotoxy(72,16);printf("  Horarios disponiveis");
    int X=81,Y=17;
    for(int i=1;i<7;i++){
        gotoxy(X,Y);printf("%d-%s",i,horas[i]);
        Y++;

    }

}

void AvisoEventoLimpar(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(38,66,13);linhaH(38,66,23);linhaV(11,66,13);linhaV(11,103,13);
    Pchar(66,13,218);Pchar(103,13,191);Pchar(66,23,192);Pchar(103,23,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(79,14);printf(" CADASTRAR");
    gotoxy(80,15);printf(" AVISOS");
    gotoxy(72,16);printf("                             ");
    gotoxy(72,17);printf("                             ");
    gotoxy(72,18);printf("                             ");
    gotoxy(72,19);printf("                             ");
    gotoxy(72,20);printf("                             ");
    gotoxy(72,21);printf("                             ");
    gotoxy(72,22);printf("                             ");

}

void AvisoEventoGrupo(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(38,66,13);linhaH(38,66,23);linhaV(11,66,13);linhaV(11,103,13);
    Pchar(66,13,218);Pchar(103,13,191);Pchar(66,23,192);Pchar(103,23,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(79,14);printf(" CADASTRAR");
    gotoxy(80,15);printf(" AVISOS");
    gotoxy(72,17);printf("Capacidade  39/50");
    gotoxy(72,18);printf("horarios disponiveis");
    gotoxy(72,19);printf("Avisos xxxxxxxxx");
    gotoxy(72,20);printf("Avisos xxxxxxxxx");
    gotoxy(72,21);printf("Avisos xxxxxxxxx");
    gotoxy(72,22);printf("Avisos xxxxxxxxx");

}

void AvisoEventoOficina(){
//  linha de cima, linha de baixo/ lado esquerdo/   lado direito   /Titulo
    linhaH(38,66,13);linhaH(38,66,23);linhaV(11,66,13);linhaV(11,103,13);
    Pchar(66,13,218);Pchar(103,13,191);Pchar(66,23,192);Pchar(103,23,217);
// cima/esquerda  /   direira     bqixo/ esquerda      /  direita/ 1linha
    //mensagens dos avisos irão mudar conforme a opcao escolhida
    gotoxy(79,14);printf(" CADASTRAR");
    gotoxy(80,15);printf(" AVISOS");
    gotoxy(72,17);printf("Capacidade  39/50");
    gotoxy(72,18);printf("horarios disponiveis");
    gotoxy(72,19);printf("Avisos xxxxxxxxx");
    gotoxy(72,20);printf("Avisos xxxxxxxxx");
    gotoxy(72,21);printf("Avisos xxxxxxxxx");
    gotoxy(72,22);printf("Avisos xxxxxxxxx");

}
//-------------------------------AJEIAR ESSE FINAL
void VeditarCongressista(){
system("cls");
Vcabecalho();
//------INFORMAÇOES
//VinformacoesRemover();//condicao para so aparecer depois que digitar a matricula
//-------------REMOVER PALESTRA
linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("EDITAR CONGRESSISTA");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("MATRICULA:");
//----------DESEJA REALMENTE REMOVER--
//VdesejaRemover();//condicao para aparecer somente depois que aparecer

//AVISOx REMOVIDO COM SUCESSO

}

void VeditarPalestra(){
system("cls");
Vcabecalho();
//------INFORMAÇOES
//VinformacoesRemover();//condicao para so aparecer depois que digitar a matricula
//-------------REMOVER PALESTRA
linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("EDITAR PALESTRA");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("CADASTRO:");
//----------DESEJA REALMENTE REMOVER--
//VdesejaRemover();//condicao para aparecer somente depois que aparecer

//AVISOx REMOVIDO COM SUCESSO

}
void VeditarCurso(){
system("cls");
Vcabecalho();
//------INFORMAÇOES
//VinformacoesRemover();//condicao para so aparecer depois que digitar a matricula
//-------------REMOVER PALESTRA
linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("EDITAR CURSO");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("CADASTRO:");
//----------DESEJA REALMENTE REMOVER--
//VdesejaRemover();//condicao para aparecer somente depois que aparecer

//AVISOx REMOVIDO COM SUCESSO

}
void VeditarOficina(){
system("cls");
Vcabecalho();

linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("EDITAR OFICINA");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("CADASTRO:");


}
void VremoverPalestra(){
system("cls");
Vcabecalho();

linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("REMOVER PALESTRA");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("CADASTRO:");

}
void VremoverOficina(){
system("cls");
Vcabecalho();

linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("REMOVER OFICINA");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("CADASTRO:");

}
void VremoverGrupo(){
system("cls");
Vcabecalho();

linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("REMOVER GRUPOS");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("CADASTRO:");

}
void VremoverCurso(){
system("cls");
Vcabecalho();
//------INFORMAÇOES
//VinformacoesRemover();//condicao para so aparecer depois que digitar a matricula
//-------------REMOVER PALESTRA
linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("REMOVER CURSO");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("CADASTRO:");

}

void VremoverCongressista(){
system("cls");
Vcabecalho();

linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("REMOVER CONGRESSISTA");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("CADASTRO:");
//----------DESEJA REALMENTE REMOVER--
//VdesejaRemover();//condicao para aparecer somente depois que aparecer

//AVISOx REMOVIDO COM SUCESSO

}

void VdesejaRemover(){
//nao esta centralizado no meio
linhaH(30,70,17);linhaV(8,70,17);linhaH(30,70,25);linhaV(8,100,17);
Pchar(70,17,218);Pchar(100,17,191);Pchar(70,25,192);Pchar(100,25,217);gotoxy(74,20);printf("DESEJA REALMENTE REMOVER");
                                                                     gotoxy(80,23);printf("1-SIM/2-NAO");
}


void VeditadoComSucesso(){
    //limpa toda a tela e aparece um quadrado no meio
    system("cls");
    system("color A0");
    linhaH(30,38,12);linhaV(8,38,12);linhaH(30,38,20);linhaV(8,68,12);
    Pchar(38,12,218);Pchar(68,12,191);Pchar(38,20,192);Pchar(68,20,217);

    gotoxy(44,15);printf("EDITADO COM SUCESSO!!!");
    gotoxy(50,18);printf("VOLTANDO");
    for(int x=58,sl=430,i=0;i<3;i++,x++){
        gotoxy(x,18);printf(".");
        Sleep(sl);
    }

}
void AvisoNumeroNaoEncontrado(){
    //limpa toda a tela e aparece um quadrado no meio
    system("cls");
    system("color CF");
    linhaH(30,38,12);linhaV(8,38,12);linhaH(30,38,20);linhaV(8,68,12);
    Pchar(38,12,218);Pchar(68,12,191);Pchar(38,20,192);Pchar(68,20,217);

    gotoxy(44,15);printf("NUMERO NAO ENCONTRADO!!!");
    gotoxy(50,18);printf("VOLTANDO");
    for(int x=58,sl=430,i=0;i<3;i++,x++){
        gotoxy(x,18);printf(".");
        Sleep(sl);
    }

}
void AvisoOPinvalida(){
    //limpa toda a tela e aparece um quadrado no meio
    system("cls");
    system("color CF");
    linhaH(30,38,12);linhaV(8,38,12);linhaH(30,38,20);linhaV(8,68,12);
    Pchar(38,12,218);Pchar(68,12,191);Pchar(38,20,192);Pchar(68,20,217);

    gotoxy(44,15);printf("OPCAO INVALIDA!!!");
    gotoxy(50,18);printf("VOLTANDO");
    for(int x=58,sl=430,i=0;i<3;i++,x++){
        gotoxy(x,18);printf(".");
        Sleep(sl);
    }


}
void AvisoVAZIO(){
    //limpa toda a tela e aparece um quadrado no meio
    system("cls");
    system("color CF");
    linhaH(30,38,12);linhaV(8,38,12);linhaH(30,38,20);linhaV(8,68,12);
    Pchar(38,12,218);Pchar(68,12,191);Pchar(38,20,192);Pchar(68,20,217);

    gotoxy(40,15);printf("AINDA NAO FORAM ADICIONADOS!");
    gotoxy(50,18);printf("VOLTANDO");
    for(int x=58,sl=430,i=0;i<3;i++,x++){
        gotoxy(x,18);printf(".");
        Sleep(sl);
    }
}
void AvisoVAZIOP(){
    //limpa toda a tela e aparece um quadrado no meio
    system("cls");
    system("color CF");
    linhaH(30,38,12);linhaV(8,38,12);linhaH(30,38,20);linhaV(8,68,12);
    Pchar(38,12,218);Pchar(68,12,191);Pchar(38,20,192);Pchar(68,20,217);

    gotoxy(40,15);printf("  NAO HA PALESTRANTES!!!");
    gotoxy(50,18);printf("VOLTANDO");
    for(int x=58,sl=430,i=0;i<3;i++,x++){
        gotoxy(x,18);printf(".");
        Sleep(sl);
    }
}
void AvisoADDsucesso(){
    //limpa toda a tela e aparece um quadrado no meio
    system("cls");
    system("color A0");
    linhaH(30,38,12);linhaV(8,38,12);linhaH(30,38,20);linhaV(8,68,12);
    Pchar(38,12,218);Pchar(68,12,191);Pchar(38,20,192);Pchar(68,20,217);

    gotoxy(41,15);printf("ADICIONADO COM SUCESSO!!!");
    gotoxy(50,18);printf("VOLTANDO");
    for(int x=58,sl=430,i=0;i<3;i++,x++){
        gotoxy(x,18);printf(".");
        Sleep(sl);
    }
}
void AvisoADDsucessoSpeed(){
    //limpa toda a tela e aparece um quadrado no meio
    system("cls");
    system("color A0");
    linhaH(30,38,12);linhaV(8,38,12);linhaH(30,38,20);linhaV(8,68,12);
    Pchar(38,12,218);Pchar(68,12,191);Pchar(38,20,192);Pchar(68,20,217);

    gotoxy(41,15);printf("ADICIONADO COM SUCESSO!!!");
    gotoxy(50,18);printf("VOLTANDO");
    for(int x=58,sl=100,i=0;i<3;i++,x++){
        gotoxy(x,18);printf(".");
        Sleep(sl);
    }
}



//-----------------------------------------Cadastrar organizador
void VcadastrarOrganizador(){
    system("cls");

Vcabecalho();

linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("CADASTRAR ORGANIZADOR");
//-------------NOME
linhaH(70,7,16);linhaV(3,7,16);linhaH(70,7,18);linhaV(3,77,16);
Pchar(7,16,218);Pchar(77,16,191);Pchar(7,18,192);Pchar(77,18,217);gotoxy(12,17);printf("NOME:");
//cpf
linhaH(43,7,19);linhaV(3,7,19);linhaH(43,7,21);linhaV(3,50,19);
Pchar(7,19,218);Pchar(50,19,191);Pchar(7,21,192);Pchar(50,21,217);gotoxy(12,20);printf("CPF:");
//telefeone
linhaH(43,7,22);linhaV(3,7,22);linhaH(43,7,24);linhaV(3,50,22);
Pchar(7,22,218);Pchar(50,22,191);Pchar(7,24,192);Pchar(50,24,217);gotoxy(12,23);printf("TELEFONE:");
//enail
linhaH(70,7,25);linhaV(3,7,25);linhaH(70,7,27);linhaV(3,77,25);
Pchar(7,25,218);Pchar(77,25,191);Pchar(7,27,192);Pchar(77,27,217);gotoxy(12,26);printf("EMAIL:");
//matricula
linhaH(30,7,28);linhaV(3,7,28);linhaH(30,7,30);linhaV(3,37,28);
Pchar(7,28,218);Pchar(37,28,191);Pchar(7,30,192);Pchar(37,30,217);gotoxy(11,29);printf("MATRICULA:");

//TALVEZ UM ADICIONAR NOVAMENTE AQUI
}

void VeditarOrganizador(){
system("cls");
Vcabecalho();
//------INFORMAÇOES
//-------------REMOVER PALESTRA
linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("EDITAR ORGANIZADOR");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("MATRICULA:");
//----------DESEJA REALMENTE REMOVER--

//AVISOx REMOVIDO COM SUCESSO

}
void VeditarGrupo(){
system("cls");
Vcabecalho();

linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("EDITAR GRUPOS");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("MATRICULA:");

}

void VremoverOrganizador(){
system("cls");
Vcabecalho();

linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("REMOVER ORGANIZADOR");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("MATRICULA:");
void VremoverPalestra(){
system("cls");
Vcabecalho();
//------INFORMAÇOES
//VinformacoesRemover();//condicao para so aparecer depois que digitar a matricula
//-------------REMOVER PALESTRA
linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("REMOVER PALESTRA");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("CADASTRO:");
//----------DESEJA REALMENTE REMOVER--
//VdesejaRemover();//condicao para aparecer somente depois que aparecer

//AVISOx REMOVIDO COM SUCESSO

}
}


//PALESTRANTE
void VcadastrarPalestrante(){
system("cls");
Vcabecalho();

linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("CADASTRAR PALESTRANTE");
//-------------NOME
linhaH(70,7,16);linhaV(3,7,16);linhaH(70,7,18);linhaV(3,77,16);
Pchar(7,16,218);Pchar(77,16,191);Pchar(7,18,192);Pchar(77,18,217);gotoxy(12,17);printf("NOME:");
//cpf
linhaH(43,7,19);linhaV(3,7,19);linhaH(43,7,21);linhaV(3,50,19);
Pchar(7,19,218);Pchar(50,19,191);Pchar(7,21,192);Pchar(50,21,217);gotoxy(12,20);printf("CPF:");
//telefeone
linhaH(43,7,22);linhaV(3,7,22);linhaH(43,7,24);linhaV(3,50,22);
Pchar(7,22,218);Pchar(50,22,191);Pchar(7,24,192);Pchar(50,24,217);gotoxy(12,23);printf("TELEFONE:");
//enail
linhaH(70,7,25);linhaV(3,7,25);linhaH(70,7,27);linhaV(3,77,25);
Pchar(7,25,218);Pchar(77,25,191);Pchar(7,27,192);Pchar(77,27,217);gotoxy(12,26);printf("EMAIL:");
//matricula
linhaH(30,7,28);linhaV(3,7,28);linhaH(30,7,30);linhaV(3,37,28);
Pchar(7,28,218);Pchar(37,28,191);Pchar(7,30,192);Pchar(37,30,217);gotoxy(11,29);printf("MATRICULA:");

//TALVEZ UM ADICIONAR NOVAMENTE AQUI
}

void VeditarPalestrante(){
system("cls");
Vcabecalho();
//------INFORMAÇOES
//-------------REMOVER PALESTRA
linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("EDITAR PALESTRANTE");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("MATRICULA:");
//----------DESEJA REALMENTE REMOVER--

//AVISOx REMOVIDO COM SUCESSO

}
void VremoverPalestrante(){
system("cls");
Vcabecalho();
//------INFORMAÇOES
//VinformacoesRemover();//condicao para so aparecer depois que digitar a matricula
//-------------REMOVER PALESTRA
linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);gotoxy(12,13);printf("REMOVER PALESTRANTE");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("MATRICULA:");
//----------DESEJA REALMENTE REMOVER--
//VdesejaRemover();//condicao para aparecer somente depois que aparecer

//AVISOx REMOVIDO COM SUCESSO

}

void VGerenciarPalestra(){
    system("color F0");
system("cls");
Vcabecalho();
//------INFORMAÇOES
//VinformacoesRemover();//condicao para so aparecer depois que digitar a matricula
//-------------REMOVER PALESTRA
linhaH(30,31,12);linhaV(3,31,12);linhaH(30,31,14);linhaV(3,61,12);
Pchar(31,12,218);Pchar(61,12,191);Pchar(31,14,192);Pchar(61,14,217);gotoxy(37,13);printf("GERENCIAR PALESTRA");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(9,17);printf("1-ADICIONAR CONGRESSISTA");
//-------------NUMERO

linhaH(30,45,16);linhaV(3,45,16);linhaH(30,45,18);linhaV(3,75,16);
Pchar(45,16,218);Pchar(75,16,191);Pchar(45,18,192);Pchar(75,18,217);gotoxy(47,17);printf("2-MOSTRAR POR PALESTRA");



linhaH(30,7,23);linhaV(3,7,21);linhaH(30,7,21);linhaV(3,37,21);
Pchar(7,21,218);Pchar(37,21,191);Pchar(7,23,192);Pchar(37,23,217);gotoxy(9,22);printf("3-REMOVER CONGRESSISTA");

linhaH(30,45,21);linhaV(3,45,21);linhaH(30,45,23);linhaV(3,75,21);
Pchar(45,21,218);Pchar(75,21,191);Pchar(45,23,192);Pchar(75,23,217);gotoxy(47,22);printf("4-VOLTAR");

}


void VGerenciarCurso(){
    system("color F0");
system("cls");
Vcabecalho();
//------INFORMAÇOES
//VinformacoesRemover();//condicao para so aparecer depois que digitar a matricula
//-------------REMOVER PALESTRA
linhaH(30,31,12);linhaV(3,31,12);linhaH(30,31,14);linhaV(3,61,12);
Pchar(31,12,218);Pchar(61,12,191);Pchar(31,14,192);Pchar(61,14,217);gotoxy(37,13);printf("GERENCIAR CURSO");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(9,17);printf("1-ADICIONAR CONGRESSISTA");
//-------------NUMERO

linhaH(30,45,16);linhaV(3,45,16);linhaH(30,45,18);linhaV(3,75,16);
Pchar(45,16,218);Pchar(75,16,191);Pchar(45,18,192);Pchar(75,18,217);gotoxy(47,17);printf("2-MOSTRAR POR CURSO");



linhaH(30,7,23);linhaV(3,7,21);linhaH(30,7,21);linhaV(3,37,21);
Pchar(7,21,218);Pchar(37,21,191);Pchar(7,23,192);Pchar(37,23,217);gotoxy(9,22);printf("3-REMOVER CONGRESSISTA");

linhaH(30,45,21);linhaV(3,45,21);linhaH(30,45,23);linhaV(3,75,21);
Pchar(45,21,218);Pchar(75,21,191);Pchar(45,23,192);Pchar(75,23,217);gotoxy(47,22);printf("4-VOLTAR");

}


void VGerenciarOficina(){
system("color F0");
system("cls");
Vcabecalho();
//------INFORMAÇOES
//VinformacoesRemover();//condicao para so aparecer depois que digitar a matricula
//-------------REMOVER PALESTRA
linhaH(30,31,12);linhaV(3,31,12);linhaH(30,31,14);linhaV(3,61,12);
Pchar(31,12,218);Pchar(61,12,191);Pchar(31,14,192);Pchar(61,14,217);gotoxy(37,13);printf("GERENCIAR OFICINA");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(9,17);printf("1-ADICIONAR CONGRESSISTA");
//-------------NUMERO

linhaH(30,45,16);linhaV(3,45,16);linhaH(30,45,18);linhaV(3,75,16);
Pchar(45,16,218);Pchar(75,16,191);Pchar(45,18,192);Pchar(75,18,217);gotoxy(47,17);printf("2-MOSTRAR POR OFICINA");



linhaH(30,7,23);linhaV(3,7,21);linhaH(30,7,21);linhaV(3,37,21);
Pchar(7,21,218);Pchar(37,21,191);Pchar(7,23,192);Pchar(37,23,217);gotoxy(9,22);printf("3-REMOVER CONGRESSISTA");

linhaH(30,45,21);linhaV(3,45,21);linhaH(30,45,23);linhaV(3,75,21);
Pchar(45,21,218);Pchar(75,21,191);Pchar(45,23,192);Pchar(75,23,217);gotoxy(47,22);printf("4-VOLTAR");

}
void VGerenciarGrupo(){
system("cls");
Vcabecalho();
//------INFORMAÇOES
//VinformacoesRemover();//condicao para so aparecer depois que digitar a matricula
//-------------REMOVER PALESTRA
linhaH(30,31,12);linhaV(3,31,12);linhaH(30,31,14);linhaV(3,61,12);
Pchar(31,12,218);Pchar(61,12,191);Pchar(31,14,192);Pchar(61,14,217);gotoxy(37,13);printf("GERENCIAR GRUPOS");
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(9,17);printf("1-ADICIONAR CONGRESSISTA");
//-------------NUMERO

linhaH(30,45,16);linhaV(3,45,16);linhaH(30,45,18);linhaV(3,75,16);
Pchar(45,16,218);Pchar(75,16,191);Pchar(45,18,192);Pchar(75,18,217);gotoxy(47,17);printf("2-MOSTRAR POR GRUPOS");



linhaH(30,7,23);linhaV(3,7,21);linhaH(30,7,21);linhaV(3,37,21);
Pchar(7,21,218);Pchar(37,21,191);Pchar(7,23,192);Pchar(37,23,217);gotoxy(9,22);printf("3-REMOVER CONGRESSISTA");

linhaH(30,45,21);linhaV(3,45,21);linhaH(30,45,23);linhaV(3,75,21);
Pchar(45,21,218);Pchar(75,21,191);Pchar(45,23,192);Pchar(75,23,217);gotoxy(47,22);printf("4-VOLTAR");

}

void VgerenciarMostrar(){
system("cls");
Vcabecalho();

linhaH(30,7,12);linhaV(3,7,12);linhaH(30,7,14);linhaV(3,37,12);
Pchar(7,12,218);Pchar(37,12,191);Pchar(7,14,192);Pchar(37,14,217);
//-------------NUMERO
linhaH(30,7,16);linhaV(3,7,16);linhaH(30,7,18);linhaV(3,37,16);
Pchar(7,16,218);Pchar(37,16,191);Pchar(7,18,192);Pchar(37,18,217);gotoxy(12,17);printf("CADASTRO:");
}







