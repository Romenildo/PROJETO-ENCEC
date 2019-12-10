#ifndef CONGRESSISTA_H_INCLUDED
#define CONGRESSISTA_H_INCLUDED

typedef struct eventoc{
    int MatriculaC;
    int idade;
    char telefone[15];
    char cpf[20];
    char curso[30];
    char email[30];
    char nome[30];
    int P[6];//palestras
    int G[6];//grupos de discursoes
    int C;//so poderá participar de um curso
    int O;//so podera participar de uma oficina

};//CONGRESSISTAS
typedef struct eventoc EVENTOC;

typedef struct capsulaC{
    EVENTOC dado;
    struct capsulaC *proximo;
};
typedef struct capsulaC CAPSC;


typedef struct listac{
    CAPSC *inicio;
};
typedef struct listac LISTAC;


LISTAC* CriarC();
void liberarC(LISTAC* li);
void mostrarTodosC(LISTAC* li);
int tamanhoListaC(LISTAC *li);
void inserirListaC(LISTAC* li,EVENTOC eC);
int mostrarEmRemoverC(CAPSC* aux);
int removerListaC(LISTAC* li, int num);
void pegarInfoCongressista(EVENTOC* eC, LISTAC* liC, int MatriculaC);
void editarCongressista(LISTAC* li, int matriculaINFO);

void mostrarMeNdosCPalestra(LISTAC* li);
void mostrarMeNdosCGrupo(LISTAC* li);
void mostrarMeNdosCCurso(LISTAC* li);
void mostrarMeNdosCOficina(LISTAC* li);

char *TransformarMemN(LISTAC *li,int Matricula);

void mudarPdoC(LISTAC *li,int Matricula,int PAL);
void REMOVERmudarPdoC(LISTAC *li,int Matricula,int PAL);


void mudarGdoC(LISTAC *li,int Matricula,int PAL);
void REMOVERmudarGdoC(LISTAC *li,int Matricula,int PAL);

void mudarCdoC(LISTAC *li,int Matricula,int PAL);
void REMOVERmudarCdoC(LISTAC *li,int Matricula,int PAL);

void mudarOdoC(LISTAC *li,int Matricula,int PAL);
void REMOVERmudarOdoC(LISTAC *li,int Matricula,int PAL);



#endif // CONGRESSISTA_H_INCLUDED

