#include <stdio.h>
#include "consulta.h"
#include "interface.h"
#include "paciente.h"

FILE *fpConsulta;
char OpcoesPacientes[100][51];
int nPaciente, xPaciente[100], yPaciente[100];
char OpcoesMedicos[100][51];
int nMedico, xMedico[100], yMedico[100];

Consulta DigitarConsulta(){
    Consulta C;
    int Escolha = 0;

    gotoxy(27, 6);
    //scanf(" %[^\n]", C.CRMMedico);
    Borda(26, 5, 20, 7, 0, 0);
    Escolha = menu(OpcoesMedicos, xMedico, yMedico, Escolha, nMedico);
    TelaConsulta();
    strcpy(C.CRMMedico, OpcoesMedicos[Escolha]);
    ImprimirConsulta(C);

    gotoxy(27, 9);
    //scanf(" %[^\n]", C.CPFPaciente);
    Borda(26, 8, 20, 7, 0, 0);
    Escolha = menu(OpcoesPacientes, xPaciente, yPaciente, Escolha, nPaciente);
    TelaConsulta();
    strcpy(C.CPFPaciente, OpcoesPacientes[Escolha]);
    ImprimirConsulta(C);

    gotoxy(27, 12);
    scanf(" %[^\n]", C.DataConsulta);

    gotoxy(27, 15);
    scanf(" %[^\n]", C.HoraConsulta);

    return C;
}

void TelaConsulta(){
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

void AbrirArquivoConsulta(){
    fpConsulta = fopen("Consulta.txt", "rb+");

    if(fpConsulta == NULL){
        fpConsulta = fopen("Consulta.txt", "wb+");
        if(fpConsulta == NULL){
            printf("Nao abriu Consulta.txt\n");
            exit(1);
        }
    }
}

void FecharArquivoConsulta(){
    fclose(fpConsulta);
}

void SalvarNovoConsulta(Consulta P){
    fseek(fpConsulta, 0, SEEK_END);//Posiciona no fim do arquivo
    fwrite(&P, sizeof(Consulta), 1, fpConsulta);//Grava
    fflush(fpConsulta);
}

void AtivarConsulta(){
    Consulta C;
    int Escolha = 0;
    char opcoes[][51] = {"Novo","Pesquisar","Alterar","Sair"};
    int x[] = {20, 29, 42, 56};
    int y[] = {19, 19, 19, 19};

    char opcoesConfirma[][51] = {"Confirma", "Cancela"};
    int x1[] = {30, 42};
    int y1[] = {19, 19};

    AbrirArquivoPaciente();
    nPaciente = CarregarPaciente(OpcoesPacientes);
    FecharArquivoPaciente();

    for(int i = 0; i < nPaciente; i++){
        xPaciente[i] = 27;
        yPaciente[i] = 10+i;
    }

    AbrirArquivoMedico();
    nMedico = CarregarMedico(OpcoesMedicos);
    FecharArquivoMedico();

    for(int i = 0; i < nMedico; i++){
        xMedico[i] = 27;
        yMedico[i] = 7+i;
    }

    AbrirArquivoConsulta();
    do{
        TelaConsulta();
        Borda(16, 18, 10, 2, 0, 0);
        Borda(28, 18, 10, 2, 0, 0);
        Borda(40, 18, 10, 2, 0, 0);
        Borda(52, 18, 10, 2, 0, 0);
        Escolha = menu(opcoes, x, y, Escolha, 4);
        if(Escolha == 0){
            TelaConsulta();
            C = DigitarConsulta();
            Borda(28, 18, 10, 2, 0, 0);
            Borda(40, 18, 10, 2, 0, 0);
            Escolha = menu(opcoesConfirma, x1, y1, Escolha, 2);
            if(Escolha == 0){
               SalvarNovoConsulta(C);
            }else Escolha = 0;
        }
    }while(Escolha != 3);
    FecharArquivoConsulta();
}
