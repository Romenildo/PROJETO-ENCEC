#ifndef CURSOS_H_INCLUDED
#define CURSOS_H_INCLUDED

typedef struct eventoK{
    int n_cadastroK;
    int capacidade;
    char horario[5];
    int cargaHoraria;
    int local;
    char tema[30];
    char palestrante[30];
    int EditH;
    int CongN[50];
    char CongNome[50][50]
};//evento palestras
typedef struct eventoK EVENTOK;

typedef struct capsulaK{
    EVENTOK dado;
    struct capsulaK *proximo;
};
typedef struct capsulaK CAPSK;

typedef struct listaK{
    CAPSK *inicio;
};
typedef struct listaK LISTAK;

typedef struct listapT LISTApT;

LISTAK* CriarK();
void liberarK(LISTAK *li);
void mostrarTodosK(LISTAK *li);
int tamanhoListaK(LISTAK *li);
void inserirListaK(LISTAK *li, EVENTOK eK);
int mostrarEmRemoverK(CAPSK *aux);
int removerListaK(LISTAK *li, int num);
int PegarLocalCurso();
int PegarHorarioCurso(char horas[7][10]);
void pegarInfoCurso(EVENTOK *eK, LISTAK *liK, int n_cadastroK,LISTApT *lipT);
void EditarLocalCurso(CAPSK *aux);
void EditarHorarioCurso(CAPSK *aux);
void editarCurso(LISTAK *li, int cadastroINFO,LISTApT *lipT);

void adicionarCongressistaK(LISTAK *li,int Curso,char *nome,int MAT);
void MostrarCongressistaPorCurso(LISTAK *li,int Curso);
void RemoverCongressistaDoCurso(LISTAK *li,int Curso,int Matricula);

void desocuparPalestranteK(LISTApT *lipT,LISTAK *liK,int Curso);
void removerHorarioK(LISTAK *li, int Curso);
#endif // CURSOS_H_INCLUDED

