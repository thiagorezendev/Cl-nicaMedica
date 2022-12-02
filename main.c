#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "medico.h"
#include "paciente.h"
#include "consulta.h"
#include "relatorio.h"

void TelaPrincipal(){
    Borda(0, 0, 79, 23, 1, 0);
    gotoxy(32, 1);printf("CLINICA MEDICA");
}

char opcoes[][51] = {"Paciente", "Medico", "Consulta", "Relatorios", "Fechar"};
int x[] = {1, 1, 1, 1, 1};
int y[] = {3, 4, 5, 6, 7};

int main()
{
    int escolha = 0;
    TelaPrincipal();
    Medico M; Paciente P; Relatorio R;
    escolha = menu(opcoes, x, y, escolha, 5);
    if(escolha == 0){
        TeclaPaciente();
        P = DigitarPaciente();
        ImprimirPaciente(P);
    }
    if(escolha == 1){
        TeclaMedico();
        M = DigitarMedico();
        ImprimirMedico(M);
    }
    /*if(escolha == 2){
        TeclaConsulta();
        C = DigitarConsulta();
        ImprimirConsulta(C);
    }*/
    if(escolha == 3){
        TeclaRelatorio();
        R = DigitarRelatorio();
        ImprimirRelatorio(R);
    }
    if(escolha == 4){
        textcoloreback(LIGHT_CYAN, BLACK);
        Borda(28, 10, 21, 2, 0, 0);
        gotoxy(29, 11);
        printf("Obrigado pelo acesso!");
    }
    getchar();

    gotoxy(1, 24);
    return 0;
}
