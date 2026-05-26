#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct Bairros {
    char cidade[20];
    char bairro[30];
};

int main() {
    struct Bairros bai[MAX];
    FILE *arquivoBai;
    char linha[100];
    char cidadeEscolhida[100];
    int i = 0;

    // Abre o arquivo CSV em modo leitura
    arquivoBai = fopen("bairros_cid.csv", "r");

    if (arquivoBai == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivoBai) != NULL && i < MAX) {
        // Remove o ENTER da linha
        linha[strcspn(linha, "\n")] = '\0';
        // Divide cidade e bairro e salva na struct
        sscanf(
            linha,
            "%19[^;];%29[^\n]",
            bai[i].cidade,
            bai[i].bairro
        );
        i++;
    }

    fclose(arquivoBai);

    printf("Cidades disponíveis:\n");
    for(int j=0; j<i; j++){
        printf("%s\n", bai[j].cidade);
    }

    // Usuário escolhe uma cidade
    printf("\nDigite a cidade: ");

    fgets( cidadeEscolhida, sizeof(cidadeEscolhida), stdin);
    cidadeEscolhida[ strcspn(cidadeEscolhida,"\n")] = '\0';
    printf("\nBairros encontrados:\n");

    // Procura bairros da cidade escolhida
    for(int j=0; j<i; j++){

        if(strcmp(bai[j].cidade, cidadeEscolhida) == 0){
             printf( "%s\n",bai[j].bairro);
        }
    }

    return 0;
}