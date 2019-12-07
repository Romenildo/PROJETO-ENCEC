#ifndef ORGANIZADOR_H_INCLUDED
#define ORGANIZADOR_H_INCLUDED

typedef struct organizador{
    int MatriculaO;
    char nome[30];
    char cpf[15];
    char telefone[15];
    char email[30];
};//ORGANIZADORES
typedef struct organizador ORGANIZADOR;


typedef struct capsulaO{
    ORGANIZADOR dado;
    struct capsulaO *proximo;
};
typedef struct capsulaO CAPSO;


typedef struct listaO{
    CAPSO *inicio;
};
typedef struct listaO LISTAO;

LISTAO* CriarO();
void liberarO(LISTAO* li);
void mostrarTodosO(LISTAO* li);
int tamanhoListaO(LISTAO *li);
void inserirListaO(LISTAO *li,ORGANIZADOR eO);
int mostrarEmRemoverO(CAPSO *aux);
int removerListaO(LISTAO *li, int num);
void pegarInfoOrganizador(ORGANIZADOR *eO, LISTAO *liO, int MatriculaO);
void editarOrganizador(LISTAO *li, int matriculaINFO);


#endif // ORGANIZADOR_H_INCLUDED

