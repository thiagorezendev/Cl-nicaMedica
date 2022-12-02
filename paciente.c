#include <stdio.h>
#include "paciente.h"
#include "interface.h"

Paciente DigitarPaciente(){
    Paciente P;

    gotoxy(27,6);
    scanf(" %[^\n]", P.CPF);

    gotoxy(27, 9);
    scanf(" %[^\n]", P.Nome);

    gotoxy(27, 12);
    scanf(" %[^\n]", P.Endereco);

    gotoxy(27, 15);
    scanf(" %[^\n]", P.Telefone);

    return P;
}

void TeclaPaciente(){
    textcoloreback(LIGHT_CYAN, BLACK);
    Borda(14, 3, 52, 18, 1, 1);
    gotoxy(17, 6); printf("     CPF: ");
    gotoxy(17, 9); printf("    NOME: ");
    gotoxy(17, 12); printf("ENDERECO: ");
    gotoxy(17, 15); printf("TELEFONE: ");
    Borda(26, 5, 30, 2, 0, 0);
    Borda(26, 8, 30, 2, 0, 0);
    Borda(26, 11, 30, 2, 0, 0);
    Borda(26, 14, 30, 2, 0, 0);
}

void ImprimirPaciente(Paciente P){
    Borda(14, 3, 52, 18, 1, 1);
    Borda(26, 5, 30, 2, 0, 0);
    Borda(26, 8, 30, 2, 0, 0);
    Borda(26, 11, 30, 2, 0, 0);
    Borda(26, 14, 30, 2, 0, 0);
    gotoxy(17, 6);
    printf("     CPF:");
    gotoxy(27, 6);
    printf("%s\n", P.CPF);
    gotoxy(17, 9);
    printf("    Nome:");
    gotoxy(27, 9);
    printf("%s\n", P.Nome);
    gotoxy(17, 12);
    printf("Endereco:");
    gotoxy(27, 12);
    printf("%s\n", P.Endereco);
    gotoxy(17, 15);
    printf("Telefone:");
    gotoxy(27, 15);
    printf("%s\n", P.Telefone);
}