#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "interface.h"

FILE *fpPaciente;

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

void TelaPaciente(){
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

void AbrirArquivoPaciente(){
    fpPaciente = fopen("Paciente.txt", "rb+");

    if(fpPaciente == NULL){
        fpPaciente = fopen("Paciente.txt", "wb+");
        if(fpPaciente == NULL){
            printf("Nao abriu Paciente.txt\n");
            exit(1);
        }
    }
}

void FecharArquivoPaciente(){
    fclose(fpPaciente);
}

void SalvarNovoPaciente(Paciente P){
    fseek(fpPaciente, 0, SEEK_END);//Posiciona no fim do arquivo
    fwrite(&P, sizeof(Paciente), 1, fpPaciente);//Grava
    fflush(fpPaciente);
}

Paciente PesquisarPaciente(){
    char CPF[51]; Paciente P;
    gotoxy(27,6);
    scanf(" %[^\n]", CPF);
    fseek(fpPaciente, 0, SEEK_SET);
    while(fread(&P, sizeof(Paciente), 1, fpPaciente)){
        if(strcmp(P.CPF, CPF) == 0){
            return P;
        }
    }
    strcpy(P.CPF, "");
    return P;
}

int CarregarPaciente(char Dados[][51]){
    int n = 0;
    Paciente P;

    fseek(fpPaciente, 0, SEEK_SET);

    while(fread(&P, sizeof(Paciente), 1, fpPaciente)){
        strcpy(Dados[n], P.Nome);
        n++;
    }
    return n;
}

void AtivarPaciente(){
    Paciente P;
    int Escolha = 0;
    char opcoes[][51] = {"Novo","Pesquisar","Alterar","Sair"};
    int x[] = {20, 29, 42, 56};
    int y[] = {19, 19, 19, 19};

    char opcoesConfirma[][51] = {"Confirma", "Cancela"};
    int x1[] = {30, 42};
    int y1[] = {19, 19};

    AbrirArquivoPaciente();
    do{
        TelaPaciente();
        Borda(16, 18, 10, 2, 0, 0);
        Borda(28, 18, 10, 2, 0, 0);
        Borda(40, 18, 10, 2, 0, 0);
        Borda(52, 18, 10, 2, 0, 0);
        Escolha = menu(opcoes, x, y, Escolha, 4);
        if(Escolha == 0)
        {
            TelaPaciente();
            P = DigitarPaciente();
            Borda(28, 18, 10, 2, 0, 0);
            Borda(40, 18, 10, 2, 0, 0);
            Escolha = menu(opcoesConfirma, x1, y1, Escolha, 2);
            if(Escolha == 0)
            {
               SalvarNovoPaciente(P);
            }
        }
        if(Escolha == 1)
        {
                TelaPaciente();
                P = PesquisarPaciente();
                if(strlen(P.CPF) > 0)
                {
                    ImprimirPaciente(P);
                }
                else {
                        Borda(27, 18, 26, 2, 0, 0);
                        gotoxy(30, 19);
                        printf("PACIENTE NAO CADASTRO");
                }
                gotoxy(0, 25);
                system("Pause");
        }
    }while(Escolha != 3);
    FecharArquivoPaciente();
}
