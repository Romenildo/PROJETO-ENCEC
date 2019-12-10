#ifndef PALESTRANTE_H_INCLUDED
#define PALESTRANTE_H_INCLUDED

typedef struct palestrante{
    int MatriculapT;
    char nome[30];
    char cpf[15];
    char telefone[15];
    char email[30];
    int ocupado;
};//PALESTRANTES
typedef struct palestrante PALESTRANTE;

typedef struct capsulapT{
    PALESTRANTE dado;
    struct capsulapT *proximo;
};
typedef struct capsulapT CAPSpT;


typedef struct listapT{
    CAPSpT *inicio;
};

typedef struct listapT LISTApT;

LISTApT* CriarpT();
void liberarpT(LISTApT *li);
void mostrarTodospT(LISTApT *li);
int tamanhoListapT(LISTApT *li);
void inserirListapT(LISTApT *li, PALESTRANTE pT);
int mostrarEmRemoverpT(CAPSpT *aux);
int removerListapT(LISTApT *li, int num);
void pegarInfoPalestrante(PALESTRANTE *pT, LISTApT *lipT,int MatriculapT);
void editarPalesrante(LISTApT *li, int matriculaINFO);
char *MostrarPalestrantes(LISTApT* li,char *nome);
char *MostrarPalestrantesGRUPOS(LISTApT* li,int X);





#endif // PALESTRANTE_H_INCLUDED
