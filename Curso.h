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

LISTAK* CriarK();
void liberarK(LISTAK *li);
void mostrarTodosK(LISTAK *li);
int tamanhoListaK(LISTAK *li);
void inserirListaK(LISTAK *li, EVENTOK eK);
int mostrarEmRemoverK(CAPSK *aux);
int removerListaK(LISTAK *li, int num);
int PegarLocalCurso();
int PegarHorarioCurso(char horas[7][10]);
void pegarInfoCurso(EVENTOK *eK, LISTAK *liK, int n_cadastroK);
void EditarLocalCurso(CAPSK *aux);
void EditarHorarioCurso(CAPSK *aux);
void editarCurso(LISTAK *li, int cadastroINFO);



#endif // CURSOS_H_INCLUDED

