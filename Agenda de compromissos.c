#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_COMPROMISSOS 100  // Máximo de compromissos que podem ser armazenados
#define MAX_NOME 50  // Tamanho máximo do nome do compromisso


// Função para adicionar um compromisso
void adicionarCompromisso(int dias[], int meses[], int anos[], char nomes[][MAX_NOME], int *quantidade) {
    // Verifica se o limite de compromissos foi atingido
    if (*quantidade >= MAX_COMPROMISSOS) {
        printf("Limite de compromissos atingido!\n");
        return;  // Sai da função se o limite foi atingido
    }

    // Pede ao usuário para digitar a data do compromisso
    printf("Digite a data do compromisso (dia mês ano): ");
    scanf("%d %d %d", &dias[*quantidade], &meses[*quantidade], &anos[*quantidade]);

    // Pede ao usuário para digitar o nome do compromisso
    printf("Digite o nome do compromisso: ");
    scanf(" %[^\n]", nomes[*quantidade]);  // Lê uma linha completa, permitindo espaços

    // Incrementa a quantidade total de compromissos
    (*quantidade)++;
    printf("Compromisso adicionado com sucesso!\n");
}

// Função para listar todos os compromissos
void listarCompromissos(int dias[], int meses[], int anos[], char nomes[][MAX_NOME], int quantidade) {
    // Verifica se há compromissos para listar
    if (quantidade == 0) {
        printf("Nenhum compromisso agendado.\n");
        return;  // Sai da função se não houver compromissos
    }

    // Loop para imprimir cada compromisso
    for (int i = 0; i < quantidade; i++) {
        printf("Compromisso %d: %s - %02d/%02d/%04d\n", i + 1, nomes[i], dias[i], meses[i], anos[i]);
    }
}

// Função para remover um compromisso
void removerCompromisso(int dias[], int meses[], int anos[], char nomes[][MAX_NOME], int *quantidade) {
    // Verifica se há compromissos para remover
    if (*quantidade == 0) {
        printf("Nenhum compromisso para remover.\n");
        return;  // Sai da função caso não tenha compromissos
    }

    // Lista os compromissos existentes para o usuário
    listarCompromissos(dias, meses, anos, nomes, *quantidade);
    int indice;
    printf("Digite o número do compromisso a ser removido: ");
    scanf("%d", &indice);  // Lê o índice do compromisso que vai ser removido

    // Verifica se o índice é válido
    if (indice < 1 || indice > *quantidade) {
        printf("Número inválido!\n");
        return;
    }

    // Move os compromissos para cima para preencher o espaço do compromisso removido
    for (int i = indice - 1; i < *quantidade - 1; i++) {
        dias[i] = dias[i + 1];
        meses[i] = meses[i + 1];
        anos[i] = anos[i + 1];
        strcpy(nomes[i], nomes[i + 1]);
    }

    // Diminuí a quantidade total de compromissos
    (*quantidade)--;
    printf("Compromisso removido com sucesso!\n");
}
// Função principal
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    // Declaração de arrays para armazenar compromissos
    int dias[MAX_COMPROMISSOS], meses[MAX_COMPROMISSOS], anos[MAX_COMPROMISSOS];  
    char nomes[MAX_COMPROMISSOS][MAX_NOME];  
    int quantidadeCompromissos = 0;
    
    int opcao;

    do {
        // Exibe o menu de opções
        printf("\n1. Adicionar compromisso\n2. Listar compromissos\n3. Remover compromisso\n0. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarCompromisso(dias, meses, anos, nomes, &quantidadeCompromissos);
                break;
            case 2:
                listarCompromissos(dias, meses, anos, nomes, quantidadeCompromissos);
                break;
            case 3:
                removerCompromisso(dias, meses, anos, nomes, &quantidadeCompromissos);
                break;
               default:
               printf("\nEscolha uma opção válida\n");
        }
    } while (opcao != 0); 

    printf("Saindo...\n");  
    
    return 0;  
}