#ifndef VISUAL_H_INCLUDED
#define VISUAL_H_INCLUDED

void limparTela();
gotoxy(int x,int y);
PFchar(int ch);
PMchar(int local1, int local2, int quant);
Pchar(int local1, int local2, int caractere);
PlinhaH(int tam);
PlinhaV(int tam);
linhaV(int tam, int local1, int local2);
linhaH(int tam, int local1, int local2);
VdesignOP();
TelaLoading();
Vcabecalho();
VopcoesPrincipal();
VopcoesPalestrantes();
VopcoesCongressistas();
VopcoesOrganizadores();
VopcoesEventos();
VopcoesEventosPalestras();
VopcoesEventosGrupos();
VopcoesEventosCursos();
VopcoesEventosOficinas();
Vcadastrar();
VcadastrarCongressista();
VcadastrarPalestra();
VcadastrarGrupos();
VcadastrarOficina();

AvisoX();
AvisoOP();
AvisoEventoPalestra();
AvisoEventPalestraLocais();
AvisoEventoCursoLocais();
AvisoEventoHorarios(char horas[7][10]);
AvisoEventoLimpar();
AvisoEventoGrupo();
AvisoEventoCurso();
AvisoEventoOficina();
VeditarCongressista();
VeditarPalestra();
VeditarCurso();
VremoverPalestra();
VremoverGrupo();
VremoverCurso();
VremoverCongressista();
VdesejaRemover();
VeditadoComSucesso();
AvisoNumeroNaoEncontrado();
AvisoOPinvalida();
AvisoVAZIO();
AvisoADDsucesso();
VcadastrarOrganizador();
VeditarOrganizador();//pensar em substituir esse por um só e mudar somente o prinf
VeditarGrupo();
VremoverOrganizador();
VcadastrarPalestrante();
VeditarPalestrante();
VremoverPalestrante();






#endif // VISUAL_H_INCLUDED
