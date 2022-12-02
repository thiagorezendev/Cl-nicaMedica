#include <stdio.h>
#include "medico.h"
#include "interface.h"

Medico DigitarMedico(){
    Medico M;

    gotoxy(27, 6);
    scanf(" %[^\n]", M.CRM);

    gotoxy(27, 9);
    scanf(" %[^\n]", M.Nome);

    gotoxy(27, 12);
    scanf(" %[^\n]", M.Especialidade);

    gotoxy(27, 15);
    scanf(" %[^\n]", M.Telefone);

    return M;
}

void TeclaMedico(){
    textcoloreback(LIGHT_CYAN, BLACK);
    Borda(14, 3, 52, 18, 1, 1);
    gotoxy(17, 6); printf("     CRM: ");
    gotoxy(17, 9); printf("    NOME: ");
    gotoxy(17, 12); printf("  ESPECI: ");
    gotoxy(17, 15); printf("TELEFONE: ");
    Borda(26, 5, 30, 2, 0, 0);
    Borda(26, 8, 30, 2, 0, 0);
    Borda(26, 11, 30, 2, 0, 0);
    Borda(26, 14, 30, 2, 0, 0);
}

void ImprimirMedico(Medico M){
    Borda(14, 3, 52, 18, 1, 1);
    Borda(26, 5, 30, 2, 0, 0);
    Borda(26, 8, 30, 2, 0, 0);
    Borda(26, 11, 30, 2, 0, 0);
    Borda(26, 14, 30, 2, 0, 0);
    gotoxy(17, 6);
    printf("     CRM:");
    gotoxy(27, 6);
    printf("%s\n", M.CRM);
    gotoxy(17, 9);
    printf("    Nome:");
    gotoxy(27, 9);
    printf("%s\n", M.Nome);
    gotoxy(17, 12);
    printf("  Especi:");
    gotoxy(27, 12);
    printf("%s\n", M.Especialidade);
    gotoxy(17, 15);
    printf("Telefone:");
    gotoxy(27, 15);
    printf("%s\n", M.Telefone);
}
