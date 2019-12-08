#ifndef OFICINAS_H_INCLUDED
#define OFICINAS_H_INCLUDED

typedef struct eventoOf{
    int n_cadastroOf;
    int capacidade;
    char horario[5];
    int cargaHoraria;
    int local;
    char tema[30];
    char palestrante[30];
    int EditH;
};
typedef struct eventoOf EVENTOOf;

typedef struct capsulaOf{
    EVENTOOf dado;
    struct capsulaOf *proximo;
};
typedef struct capsulaOf CAPSOf;

typedef struct listaOf{
    CAPSOf *inicio;
};
typedef struct listaOf LISTAOf;

typedef struct listapT LISTApT;

LISTAOf* CriarOf();
void liberarOf(LISTAOf *li);
void mostrarTodosOf(LISTAOf *li);
int tamanhoListaOf(LISTAOf *li);
void inserirListOf(LISTAOf *li, EVENTOOf oF);
int mostrarEmRemoverOf(CAPSOf *aux);
int removerListaOf(LISTAOf *li, int num);
int PegarLocalOficina();
int PegarHorarioOficina(char horas[7][10]);
void pegarInfoOficina(EVENTOOf *oF, LISTAOf *liOf, int n_cadastroOf,LISTApT *lipT);
void EditarLocalOficina(CAPSOf *aux);
void EditarHorarioOficina(CAPSOf *aux);
void editarOficina(LISTAOf *li, int cadastroINFO);






#endif // OFICINAS_H_INCLUDED
