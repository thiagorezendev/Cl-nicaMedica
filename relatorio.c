#include <stdio.h>
#include "relatorio.h"
#include "interface.h"

Relatorio DigitarRelatorio(){
    Relatorio R;

    gotoxy(29, 6);
    scanf(" %[^\n]", R.Estado);

    gotoxy(29, 9);
    scanf(" %[^\n]", R.Situacao);

    gotoxy(29, 12);
    scanf(" %[^\n]", R.Tempo);

    gotoxy(29, 15);
    scanf(" %[^\n]", R.Remarcacao);

    return R;
}

void TeclaRelatorio(){
    textcoloreback(LIGHT_CYAN, BLACK);
    Borda(14, 3, 52, 18, 1, 1);
    gotoxy(17, 6); printf("    ESTADO: ");
    gotoxy(17, 9); printf("  SITUACAO: ");
    gotoxy(17, 12); printf("     TEMPO: ");
    gotoxy(17, 15); printf("REMARCACAO: ");
    Borda(28, 5, 30, 2, 0, 0);
    Borda(28, 8, 30, 2, 0, 0);
    Borda(28, 11, 30, 2, 0, 0);
    Borda(28, 14, 30, 2, 0, 0);
}

void ImprimirRelatorio(Relatorio R){
    Borda(14, 3, 52, 18, 1, 1);
    Borda(28, 5, 30, 2, 0, 0);
    Borda(28, 8, 30, 2, 0, 0);
    Borda(28, 11, 30, 2, 0, 0);
    Borda(28, 14, 30, 2, 0, 0);
    gotoxy(18, 6);
    printf("   Estado:");
    gotoxy(29, 6);
    printf("%s\n", R.Estado);
    gotoxy(18, 9);
    printf(" Situacao:");
    gotoxy(29, 9);
    printf("%s\n", R.Situacao);
    gotoxy(18, 12);
    printf("    Tempo:");
    gotoxy(29, 12);
    printf("%s\n", R.Tempo);
    gotoxy(18, 15);
    printf(" Remarcar:");
    gotoxy(29, 15);
    printf("%s\n", R.Remarcacao);
}
