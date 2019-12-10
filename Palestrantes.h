#ifndef PALESTRA_H_INCLUDED
#define PALESTRA_H_INCLUDED

typedef struct palestra{
    int n_cadastroP;
    int capacidade;
    char horario[5];
    int cargaHoraria;
    int local;
    char tema[30];
    char palestrante[50];
    int EditH;
    int CongN[150];
    char CongNome[150][50]
};//evento palestras
typedef struct palestra PALESTRA;

typedef struct capsula{
    PALESTRA dado;
    struct capsula *proximo;
};
typedef struct capsula CAPS;

typedef struct lista{
    CAPS *inicio;
};
typedef struct lista LISTA;

typedef struct listapT LISTApT;

LISTA* Criar();
void liberar(LISTA *li);
void mostrarTodosP(LISTA *li);
int tamanhoLista(LISTA *li);
void inserirLista(LISTA *li, PALESTRA eP);
int mostrarEmRemover(CAPS *aux);
int removerLista(LISTA *li, int num);
int PegarLocalPalestra();
int PegarHorarioPalestra(char horas[7][10]);
void pegarInfoPalestra(PALESTRA *eP, LISTA *liP, int n_cadastroP, LISTApT *lipT);
void EditarLocalPalestra(CAPS *aux);
void EditarHorarioPalestra(CAPS *aux);
void editarPalestra(LISTA *li, int cadastroINFO,LISTApT *lipT);

void adicionarCongressista(LISTA *li,int Palestra,char *nome,int MAT);

void MostrarCongressistaPorPalestra(LISTA *li,int Palestra);

void RemoverCongressistaDaPalestra(LISTA *li,int Palestra,int Matricula);


void desocuparPalestrante(LISTApT *lipT,LISTA *liP,int Palestra);

void removerHorario(LISTA *liP, int Palestra);

#endif // PALESTRA_H_INCLUDED
