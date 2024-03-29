#ifndef GRUPOS_H_INCLUDED
#define GRUPOS_H_INCLUDED

typedef struct eventoG{
    int n_cadastroG;
    int capacidade;
    char horario[5];
    int cargaHoraria;
    int local;
    char tema[30];
    int Qpalestrantes;
    char palestrante[5][30];
    int EditH;
    int CongN[50];
    char CongNome[50][50]
};//evento palestras
typedef struct eventoG EVENTOG;

typedef struct capsulaG{
    EVENTOG dado;
    struct capsulaG *proximo;
};
typedef struct capsulaG CAPSG;

typedef struct listaG{
    CAPSG *inicio;
};
typedef struct listaG LISTAG;

typedef struct listapT LISTApT;


LISTAG* CriarG();
void liberarG(LISTAG *li);
void mostrarTodosG(LISTAG *li);
int tamanhoListaG(LISTAG *li);
void inserirListaG(LISTAG *li, EVENTOG gD);
int mostrarEmRemoverG(CAPSG *aux);
int removerListaG(LISTAG *li, int num);
int PegarLocalGrupo();
int PegarHorarioGrupo(char horas[7][10]);
void pegarInfoGrupo(EVENTOG *gD, LISTAG *liG, int n_cadastroG,LISTApT *lipT);
void EditarLocalGrupo(CAPSG *aux);
void EditarHorarioGrupo(CAPSG *aux);
void editarGrupo(LISTAG *li, int cadastroINFO,LISTApT *lipT);

void adicionarCongressistaG(LISTAG *liG,int Grupo,char *nome,int MAT);

void MostrarCongressistaPorGrupo(LISTAG *li,int Grupo);
void RemoverCongressistaDoGrupo(LISTAG *li,int Grupo,int Matricula);


#endif // GRUPOS_H_INCLUDED
