#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para criar o diretor
typedef struct {
    char nome[50];
    int filmografia;
    int influencia;
    int inovacao;
    int premios;
    int bilheteria;
    int direcao;
} Diretor;

// Função auxiliar para limpar o buffer de entrada
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Cadastro de diretores
void cadastrarDiretor(Diretor *d) {
    printf("\nNome do diretor: ");
    // Lê o nome do diretor com fgets()
    if (fgets(d->nome, sizeof(d->nome), stdin) != NULL) {
        d->nome[strcspn(d->nome, "\n")] = '\0';
    }

    printf("Filmografia (número de filmes): ");
    scanf("%d", &d->filmografia);
    limparBuffer();

    printf("Influência (1 a 10): ");
    scanf("%d", &d->influencia);
    limparBuffer();

    printf("Inovação (1 a 10): ");
    scanf("%d", &d->inovacao);
    limparBuffer();

    printf("Prêmios (quantidade): ");
    scanf("%d", &d->premios);
    limparBuffer();

    printf("Bilheteria (em milhões de R$): ");
    scanf("%d", &d->bilheteria);
    limparBuffer();

    printf("Direção (1 a 10): ");
    scanf("%d", &d->direcao);
    limparBuffer();

    printf("\n✅ Diretor cadastrado com sucesso!\n");
}

// Desafio 1: Comparar um único atributo

void compararAtributoUnico(Diretor d1, Diretor d2, int atributo) {
    int valor1 = 0, valor2 = 0;
    char *nomeAtributo = "";

    if (atributo == 1) {
        valor1 = d1.filmografia;
        valor2 = d2.filmografia;
        nomeAtributo = "Filmografia";
    } else if (atributo == 2) {
        valor1 = d1.influencia;
        valor2 = d2.influencia;
        nomeAtributo = "Influência";
    } else if (atributo == 3) {
        valor1 = d1.inovacao;
        valor2 = d2.inovacao;
        nomeAtributo = "Inovação";
    } else if (atributo == 4) {
        valor1 = d1.premios;
        valor2 = d2.premios;
        nomeAtributo = "Prêmios";
    } else if (atributo == 5) {
        valor1 = d1.bilheteria;
        valor2 = d2.bilheteria;
        nomeAtributo = "Bilheteria";
    } else if (atributo == 6) {
        valor1 = d1.direcao;
        valor2 = d2.direcao;
        nomeAtributo = "Direção";
    } else {
        printf("\n⚠️ Atributo inválido!\n");
        return;
    }

    printf("\n🔍 Comparando %s:\n", nomeAtributo);
    printf("%s: %d\n", d1.nome, valor1);
    printf("%s: %d\n", d2.nome, valor2);

    if (valor1 > valor2)
        printf("Vencedor: %s\n", d1.nome);
    else if (valor2 > valor1)
        printf("Vencedor: %s\n", d2.nome);
    else
        printf("Empate!\n");
}

// Desafio 2: Comparar múltiplos atributos com switch

void compararMultiplosAtributos(Diretor d1, Diretor d2) {
    int pontos1 = 0, pontos2 = 0;

    for (int i = 1; i <= 6; i++) {
        int valor1 = 0, valor2 = 0;

        switch (i) {
            case 1: valor1 = d1.filmografia; valor2 = d2.filmografia; break;
            case 2: valor1 = d1.influencia;   valor2 = d2.influencia; break;
            case 3: valor1 = d1.inovacao;     valor2 = d2.inovacao; break;
            case 4: valor1 = d1.premios;      valor2 = d2.premios; break;
            case 5: valor1 = d1.bilheteria;   valor2 = d2.bilheteria; break;
            case 6: valor1 = d1.direcao;      valor2 = d2.direcao; break;
        }

        if (valor1 > valor2) pontos1++;
        else if (valor2 > valor1) pontos2++;
    }

    printf("\n🔢 Resultado múltiplos critérios:\n");
    printf("%s: %d pontos\n", d1.nome, pontos1);
    printf("%s: %d pontos\n", d2.nome, pontos2);

    if (pontos1 > pontos2)
        printf("Vencedor: %s\n", d1.nome);
    else if (pontos2 > pontos1)
        printf("Vencedor: %s\n", d2.nome);
    else
        printf("Empate!\n");
}

// Desafio 3: Comparar dois atributos com operador ternário

void compararDoisAtributos(Diretor d1, Diretor d2, int a1, int a2) {
    int v1_d1 = 0, v1_d2 = 0;
    int v2_d1 = 0, v2_d2 = 0;

    v1_d1 = (a1 == 1) ? d1.filmografia :
            (a1 == 2) ? d1.influencia :
            (a1 == 3) ? d1.inovacao :
            (a1 == 4) ? d1.premios :
            (a1 == 5) ? d1.bilheteria :
            (a1 == 6) ? d1.direcao : -1;

    v1_d2 = (a1 == 1) ? d2.filmografia :
            (a1 == 2) ? d2.influencia :
            (a1 == 3) ? d2.inovacao :
            (a1 == 4) ? d2.premios :
            (a1 == 5) ? d2.bilheteria :
            (a1 == 6) ? d2.direcao : -1;

    v2_d1 = (a2 == 1) ? d1.filmografia :
            (a2 == 2) ? d1.influencia :
            (a2 == 3) ? d1.inovacao :
            (a2 == 4) ? d1.premios :
            (a2 == 5) ? d1.bilheteria :
            (a2 == 6) ? d1.direcao : -1;

    v2_d2 = (a2 == 1) ? d2.filmografia :
            (a2 == 2) ? d2.influencia :
            (a2 == 3) ? d2.inovacao :
            (a2 == 4) ? d2.premios :
            (a2 == 5) ? d2.bilheteria :
            (a2 == 6) ? d2.direcao : -1;

    int pontos1 = 0, pontos2 = 0;
    pontos1 += (v1_d1 > v1_d2) ? 1 : 0;
    pontos2 += (v1_d2 > v1_d1) ? 1 : 0;
    pontos1 += (v2_d1 > v2_d2) ? 1 : 0;
    pontos2 += (v2_d2 > v2_d1) ? 1 : 0;

    printf("\nResultado:\n");
    printf("%s: %d pontos\n", d1.nome, pontos1);
    printf("%s: %d pontos\n", d2.nome, pontos2);

    (pontos1 > pontos2) ? printf("Vencedor: %s\n", d1.nome) :
    (pontos2 > pontos1) ? printf("Vencedor: %s\n", d2.nome) :
                          printf("Empate!\n");
}

int main() {
    Diretor d1, d2;
    int opcao;

    printf("\n=========== 🎬 SUPER TRUNFO: DIRETORES ===========\n");
    printf("Cadastro do primeiro diretor:\n");
    cadastrarDiretor(&d1);

    printf("\nCadastro do segundo diretor:\n");
    cadastrarDiretor(&d2);

    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Comparar por um único atributo (Desafio 1)\n");
        printf("2 - Comparar por todos os atributos (Desafio 2)\n");
        printf("3 - Comparar por dois atributos (Desafio 3)\n");
        printf("4 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1: {
                int atributo;
                printf("\nAtributos:\n1 - Filmografia\n2 - Influência\n3 - Inovação\n4 - Prêmios\n5 - Bilheteria\n6 - Direção\n");
                printf("Escolha um atributo: ");
                scanf("%d", &atributo);
                limparBuffer();
                compararAtributoUnico(d1, d2, atributo);
                break;
            }
            case 2:
                compararMultiplosAtributos(d1, d2);
                break;
            case 3: {
                int a1, a2;
                printf("\nEscolha o primeiro atributo (1-6): ");
                scanf("%d", &a1);
                limparBuffer();
                printf("Escolha o segundo atributo (1-6): ");
                scanf("%d", &a2);
                limparBuffer();
                compararDoisAtributos(d1, d2, a1, a2);
                break;
            }
            case 4:
                printf("\n👋 Encerrando o programa.\n");
                break;
            default:
                printf("\n❌ Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}