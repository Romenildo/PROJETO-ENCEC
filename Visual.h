#ifndef VISUAL_H_INCLUDED
#define VISUAL_H_INCLUDED

void limparTela();
void gotoxy(int x,int y);
void PFchar(int ch);
void PMchar(int local1, int local2, int quant);
void Pchar(int local1, int local2, int caractere);
void PlinhaH(int tam);
void PlinhaV(int tam);
void linhaV(int tam, int local1, int local2);
void linhaH(int tam, int local1, int local2);
void VdesignOP();
void TelaLoading();
void Vcabecalho();
void VopcoesGrupos();
void VopcoesPalestras();
void VopcoesPrincipal();
void VopcoesPalestrantes();
void VopcoesCongressistas();
void VopcoesOrganizadores();
void VopcoesEventos();
void VopcoesCursos();
void VopcoesOficinas();
void Vcadastrar();
void VcadastrarCongressista();
void VcadastrarPalestra();
void VcadastrarGrupos();
void VcadastrarOficina();
void VopcoesGerenciar();

void AvisoX();
void AvisoOP();
void AvisoP();
void AvisoEventoPalestra();
void AvisoEventPalestraLocais();
void AvisoEventoLocais();
void AvisoEventoHorarios(char horas[7][10]);
void AvisoEventoLimpar();
void AvisoEventoGrupo();
void AvisoEventoCurso();
void AvisoEventoOficina();
void VeditarCongressista();
void VeditarPalestra();
void VeditarCurso();
void VeditarOficina();
void VremoverPalestra();
void VremoverGrupo();
void VremoverCurso();
void VremoverOficina();
void VremoverCongressista();
void VdesejaRemover();
void VeditadoComSucesso();
void AvisoNumeroNaoEncontrado();
void AvisoOPinvalida();
void AvisoVAZIO();
void AvisoVAZIOP();
void AvisoADDsucesso();
void VcadastrarOrganizador();
void VeditarOrganizador();
void VeditarGrupo();
void VremoverOrganizador();
void VcadastrarPalestrante();
void VeditarPalestrante();
void VremoverPalestrante();
void AvisoADDsucessoSpeed();
void VGerenciarPalestra();
void VGerenciarCurso();
void VGerenciarOficina();
void VGerenciarGrupo();
void VgerenciarMostrar();


void AvisoOPgerenciar();
void AvisoOPeventos();
void AvisoOPgrupos();
void AvisoOPpalestrantes();
void AvisoOPorganizadores();
void AvisoOPpalestras();


void AvisoOPCongressistas(int lim300);






#endif // VISUAL_H_INCLUDED
