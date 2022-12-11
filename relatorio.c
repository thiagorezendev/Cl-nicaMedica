#include <stdio.h>
#include "relatorio.h"
#include "interface.h"

FILE *fpRelatorio;

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

void TelaRelatorio(){
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

void AbrirArquivoRelatorio(){
    fpRelatorio = fopen("Relatorio.txt", "rb+");

    if(fpRelatorio == NULL){
        fpRelatorio = fopen("Relatorio.txt", "wb+");
        if(fpRelatorio == NULL){
            printf("Nao abriu Relatorio.txt\n");
            exit(1);
        }
    }
}

void FecharArquivoRelatorio(){
    fclose(fpRelatorio);
}

void SalvarNovoRelatorio(Relatorio R){
    fseek(fpRelatorio, 0, SEEK_END);//Posiciona no fim do arquivo
    fwrite(&R, sizeof(Relatorio), 1, fpRelatorio);//Grava
    fflush(fpRelatorio);
}

void AtivarRelatorio(){
    Relatorio R;
    int Escolha = 0;
    char opcoes[][51] = {"Novo","Pesquisar","Alterar","Sair"};
    int x[] = {20, 29, 42, 56};
    int y[] = {19, 19, 19, 19};

    char opcoesConfirma[][51] = {"Confirma", "Cancela"};
    int x1[] = {30, 42};
    int y1[] = {19, 19};

    AbrirArquivoRelatorio();
    do{
        TelaRelatorio();
        Borda(16, 18, 10, 2, 0, 0);
        Borda(28, 18, 10, 2, 0, 0);
        Borda(40, 18, 10, 2, 0, 0);
        Borda(52, 18, 10, 2, 0, 0);
        Escolha = menu(opcoes, x, y, Escolha, 4);
        if(Escolha == 0){
            TelaRelatorio();
            R = DigitarRelatorio();
            Borda(28, 18, 10, 2, 0, 0);
            Borda(40, 18, 10, 2, 0, 0);
            Escolha = menu(opcoesConfirma, x1, y1, Escolha, 2);
            if(Escolha == 0){
               SalvarNovoRelatorio(R);
            }else Escolha = 0;
        }
    }while(Escolha != 3);
    FecharArquivoRelatorio();
}
