/*===== Implementação - Daniel Barros Melo =====*/
#include <stdio.h>

// Função auxiliar apenas para exibir o vetor na tela
// Isso evita repetir código, mantendo a simplicidade
void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    // 1. Definição do vetor desordenado com números não repetidos
    // Estamos "hardcoded" (fixando) os valores para facilitar o teste inicial
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    
    // Calcula o tamanho do vetor automaticamente
    // sizeof(numeros) pega o tamanho total em bytes
    // sizeof(numeros[0]) pega o tamanho de um único inteiro (4 bytes)
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    printf("=== ATIVIDADE SUPERMAN - BUBBLESORT ===\n\n");
    
    // Exibe o estado inicial
    printf("Tamanho do vetor: %d\n", tamanho);
    printf("Vetor original (Desordenado): ");
    exibirVetor(numeros, tamanho);

    // AQUI ENTRARÁ A LÓGICA DE ORDENAÇÃO NA PRÓXIMA PARTE

    return 0;
}