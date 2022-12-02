#include <stdio.h>
#include "consulta.h"
#include "interface.h"

Consulta DigitarConsulta(){
    Consulta C;

    gotoxy(27, 6);
    scanf(" %[^\n]", C.CRMMedico);

    gotoxy(27, 9);
    scanf(" %[^\n]", C.CPFPaciente);

    gotoxy(27, 12);
    scanf(" %[^\n]", C.DataConsulta);

    gotoxy(27, 15);
    scanf(" %[^\n]", C.HoraConsulta);

    return C;
}

void TeclaConsulta(){
    textcoloreback(LIGHT_CYAN, BLACK);
    Borda(14, 3, 52, 18, 1, 1);
    gotoxy(17, 6); printf("  MEDICO: ");
    gotoxy(17, 9); printf("PACIENTE: ");
    gotoxy(17, 12); printf("    DATA: ");
    gotoxy(17, 15); printf("    HORA: ");
    Borda(26, 5, 30, 2, 0, 0);
    Borda(26, 8, 30, 2, 0, 0);
    Borda(26, 11, 30, 2, 0, 0);
    Borda(26, 14, 30, 2, 0, 0);
}

void ImprimirConsulta(Consulta C){
    Borda(14, 3, 52, 18, 1, 1);
    Borda(26, 5, 30, 2, 0, 0);
    Borda(26, 8, 30, 2, 0, 0);
    Borda(26, 11, 30, 2, 0, 0);
    Borda(26, 14, 30, 2, 0, 0);
    gotoxy(17, 6);
    printf("CRM-Med:");
    gotoxy(27, 6);
    printf("%s\n", C.CRMMedico);
    gotoxy(17, 9);
    printf("CPF-Pac:");
    gotoxy(27, 9);
    printf("%s\n", C.CPFPaciente);
    gotoxy(17, 12);
    printf("   Data:");
    gotoxy(27, 12);
    printf("%s\n", C.DataConsulta);
    gotoxy(17, 15);
    printf("   Hora:");
    gotoxy(27, 15);
    printf("%s\n", C.HoraConsulta);
}
