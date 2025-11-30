#include <stdio.h>

// Variável Global para contar o esforço total (comparações + trocas)
long long int total_acoes = 0;

// Função auxiliar para exibir o vetor
void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para trocar dois elementos de lugar (Swap)
// Usa ponteiros para alterar os valores originais na memória
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    total_acoes++; // Contabiliza uma ação de troca
}

// Função que organiza os elementos em relação a um Pivô
// Esta é a alma do QuickSort
int particionar(int vetor[], int baixo, int alto) {
    // Escolhemos o último elemento como pivô
    int pivo = vetor[alto]; 
    
    // Índice do menor elemento
    int i = (baixo - 1); 

    // Percorre o vetor da posição 'baixo' até 'alto - 1'
    for (int j = baixo; j <= alto - 1; j++) {
        
        // Contabiliza a ação de comparação feita no if abaixo
        total_acoes++;
        
        // Se o elemento atual for menor que o pivô
        if (vetor[j] < pivo) {
            i++; // Incrementa o índice do menor elemento
            trocar(&vetor[i], &vetor[j]); // Coloca o menor à esquerda
        }
    }
    // Coloca o pivô na posição correta (entre os menores e os maiores)
    trocar(&vetor[i + 1], &vetor[alto]);
    
    return (i + 1); // Retorna a posição onde o pivô ficou
}

// A função principal do QuickSort (Recursiva)
void quickSort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        // Encontra a posição de partição (onde o pivô parou)
        // Nesse momento, o pivô já está no lugar certo ordenado
        int pi = particionar(vetor, baixo, alto);

        // Ordena os elementos ANTES da partição (Recursão à esquerda)
        quickSort(vetor, baixo, pi - 1);
        
        // Ordena os elementos DEPOIS da partição (Recursão à direita)
        quickSort(vetor, pi + 1, alto);
    }
}

int main() {
    // Vetor desordenado com números inteiros não repetidos
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    printf("=== ATIVIDADE SUPERMAN - QUICKSORT ===\n\n");
    
    printf("Tamanho do vetor: %d\n", tamanho);
    printf("Vetor original: ");
    exibirVetor(numeros, tamanho);

    // Chamada inicial do QuickSort
    // Passamos o índice 0 (início) e tamanho-1 (fim)
    quickSort(numeros, 0, tamanho - 1);

    printf("\n--- Relatorio da Missao ---\n");
    printf("Numero de acoes executadas: %lld\n", total_acoes);
    printf("Vetor ordenado: ");
    exibirVetor(numeros, tamanho);

    return 0;
}