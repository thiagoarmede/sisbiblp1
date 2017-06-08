#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char class_cdd[8];
    char composicao[6];
    char ano[5];
    char vol[6];
    char exemp[5];
}NUMCHAMADA;

typedef struct{
    int DIA;
    int MES;
    int ANO;
}DATA;

typedef struct{
    NUMCHAMADA loc;
    char ISBN[14];
    char nome[51];
    char autor[4][31];
    char edicao[4];
    char ano[5];
    char editora[31];
    DATA DATA_CADAST;
    int forma_aquis;
    DATA DATA_BAIXA;
    int MOTIVO_BAIXA;
    int EXEMP_PRAT;
}LIVRO;

typedef struct{
    char identif[11];
    char ISSN[8];
    char nome[51];
    char editora[31];
    DATA DATA_CADAST;
    int forma_aquis;
    char secao[11];
    char estante[6];
    char prateleira[6];
    int copias;
    DATA DATA_BAIXA;
    int MOTIVO_BAIXA;
}PERIODICO;

typedef struct{
    char nome[100];
    char RG[10];
    char CPF[12];
    char email[50];
    DATA data_nasc, data_cadastro;
    char usuario[50], senha[50];
}BIBLIOTECARIO;

typedef struct{
    int TIPO;
    union{
        LIVRO L;
        PERIODICO P;
    };
}ACERVO;