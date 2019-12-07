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
    int P;
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








#endif // CONGRESSISTA_H_INCLUDED

