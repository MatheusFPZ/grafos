#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 18 // Número de vértices (cidades)

// Estrutura para representar um nó na lista de adjacência
struct Adjacente {
    int destino;
    int peso;
    struct Adjacente* proximo;
};

// Estrutura para representar um grafo como uma matriz de listas de adjacência
struct Grafo {
    struct Adjacente** listaAdjacente;
};

// Função para criar um novo nó na lista de adjacência
struct Adjacente* novoAdjacente(int destino, int peso) {
    struct Adjacente* novo = (struct Adjacente*)malloc(sizeof(struct Adjacente));
    novo->destino = destino;
    novo->peso = peso;
    novo->proximo = NULL;
    return novo;
}

// Função para criar um grafo com V vértices
struct Grafo* criarGrafo() {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->listaAdjacente = (struct Adjacente**)malloc(V * sizeof(struct Adjacente*));

    for (int i = 0; i < V; ++i)
        grafo->listaAdjacente[i] = NULL;

    return grafo;
}

// Função para adicionar uma aresta direcionada ao grafo
void adicionarAresta(struct Grafo* grafo, int origem, int destino, int peso) {
    struct Adjacente* novo = novoAdjacente(destino, peso);
    novo->proximo = grafo->listaAdjacente[origem];
    grafo->listaAdjacente[origem] = novo;
}

// Função para encontrar o vértice com a distância mínima
int encontrarMinimaDistancia(int distancias[], bool visitado[]) {
    int minimaDistancia = INT_MAX, minimoIndice;

    for (int v = 0; v < V; v++)
        if (visitado[v] == false && distancias[v] <= minimaDistancia)
            minimaDistancia = distancias[v], minimoIndice = v;

    return minimoIndice;
}

// Função para exibir o menor caminho entre todas as cidades
void mostrarMenorCaminho(int distancias[]) {
    printf("\nMenor caminho entre todas as cidades:\n");
    for (int i = 0; i < V; i++)
        printf("De 0 para %d: Distância = %d\n", i, distancias[i]);
}

// Função que implementa o algoritmo de Dijkstra
void dijkstra(struct Grafo* grafo) {
    int distancias[V];
    bool visitado[V];

    for (int i = 0; i < V; i++) {
        distancias[i] = INT_MAX;
        visitado[i] = false;
    }

    distancias[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = encontrarMinimaDistancia(distancias, visitado);
        visitado[u] = true;

        struct Adjacente* atual = grafo->listaAdjacente[u];
        while (atual != NULL) {
            int v = atual->destino;
            if (!visitado[v] && distancias[u] != INT_MAX && distancias[u] + atual->peso < distancias[v])
                distancias[v] = distancias[u] + atual->peso;
            atual = atual->proximo;
        }
    }

    mostrarMenorCaminho(distancias);
}

int main() {
    struct Grafo* grafo = criarGrafo();

    // Exemplo de adição de arestas (modifique conforme necessário)
     adicionarAresta(grafo, 0, 1, 20); // Cidade 1 (vértice 0) conectada à cidade 2 (vértice 1) com peso 20
    adicionarAresta(grafo, 0, 8, 29); // Cidade 1 (vértice 0) conectada à cidade 8 (vértice 7) com peso 29
    adicionarAresta(grafo, 0, 13, 37); // Cidade 1 (vértice 0) conectada à cidade 13 (vértice 12) com peso 37
    adicionarAresta(grafo, 0, 12, 29); // Cidade 1 (vértice 0) conectada à cidade 12 (vértice 11) com peso 29

    adicionarAresta(grafo, 1, 2, 25); 
    adicionarAresta(grafo, 1, 8, 28); 
    adicionarAresta(grafo, 1, 12, 39); 

    adicionarAresta(grafo, 2, 4, 25); 
    adicionarAresta(grafo, 2, 8, 30); 
    adicionarAresta(grafo, 2, 13, 54); 

    adicionarAresta(grafo, 3, 7, 42); 
    adicionarAresta(grafo, 3, 6, 32); 
    adicionarAresta(grafo, 3, 5, 39); 
    adicionarAresta(grafo, 3, 10, 33); 
    adicionarAresta(grafo, 3, 14, 56); 
    adicionarAresta(grafo, 3, 9, 23); 

    adicionarAresta(grafo, 4, 7, 26); 
    adicionarAresta(grafo, 4,6, 12); 
    adicionarAresta(grafo, 4, 4, 39); 
    adicionarAresta(grafo, 4, 10, 19); 
    
    adicionarAresta(grafo, 5, 7, 17); 
    adicionarAresta(grafo, 5,11, 30); 
    adicionarAresta(grafo, 5, 5, 12); 
    adicionarAresta(grafo, 5, 10, 35); 
    adicionarAresta(grafo, 5, 4, 32); 

       adicionarAresta(grafo, 6, 4, 42); 
    adicionarAresta(grafo, 6,6, 17); 
    adicionarAresta(grafo, 6, 5, 26); 
    adicionarAresta(grafo, 6, 11, 38); 

       adicionarAresta(grafo, 7, 3, 30); 
    adicionarAresta(grafo, 7,2, 28); 
    adicionarAresta(grafo, 7, 1, 29); 
    adicionarAresta(grafo, 7, 12, 25); 
       adicionarAresta(grafo, 7, 13, 22); 

           adicionarAresta(grafo, 8, 4, 23); 
    adicionarAresta(grafo, 8,10, 26); 
    adicionarAresta(grafo, 8, 14, ?);      //falta o valor
    adicionarAresta(grafo, 8, 16, 43); 
       adicionarAresta(grafo, 8, 13, 34); 
    
     adicionarAresta(grafo, 9, 14, 30); 
    adicionarAresta(grafo, 9,9, 26); 
    adicionarAresta(grafo, 9, 4, 33); 
    adicionarAresta(grafo, 9, 6, 35); 
    adicionarAresta(grafo, 9, 5, 19); 
    adicionarAresta(grafo, 9, 11, 24); 
    adicionarAresta(grafo, 9, 15, 19); 

      adicionarAresta(grafo, 10, 7, 38); 
    adicionarAresta(grafo, 10,6, 30); 
    adicionarAresta(grafo, 10, 10, 24); 
    adicionarAresta(grafo, 10, 15, 26); 
    adicionarAresta(grafo, 10, 18, 36); 

          adicionarAresta(grafo, 11, 1, 29); 
    adicionarAresta(grafo, 11,2, 39); 
    adicionarAresta(grafo, 11, 8, 25); 
    adicionarAresta(grafo, 11, 13, 27); 
    adicionarAresta(grafo, 11, 16, 43); 

    adicionarAresta(grafo, 12, 12, 27); 
    adicionarAresta(grafo, 12,1, 37); 
    adicionarAresta(grafo, 12, 8, 22); 
    adicionarAresta(grafo, 12, 3, 54); 
    adicionarAresta(grafo, 12, 9, 34); 
    adicionarAresta(grafo, 12, 14, 24); 
    adicionarAresta(grafo, 12,16, 19); 

        adicionarAresta(grafo, 13, 16, 19); 
    adicionarAresta(grafo, 13,13, 24); 
    adicionarAresta(grafo, 13, 9, ?); //falta o valor
    adicionarAresta(grafo, 13, 4, 56); 
    adicionarAresta(grafo, 13, 10, 30); 
    adicionarAresta(grafo, 13, 15, 20); 
    adicionarAresta(grafo, 13,17, 17); 
  

  adicionarAresta(grafo, 14, 17, 18); 
    adicionarAresta(grafo, 14,14, 20); 
    adicionarAresta(grafo, 14, 10, 19); 
    adicionarAresta(grafo, 14, 11, 26); 
    adicionarAresta(grafo, 14, 18, 21); 

      adicionarAresta(grafo, 15, 12, 43); 
    adicionarAresta(grafo, 15,13, 19); 
    adicionarAresta(grafo, 15, 9, 43); 
    adicionarAresta(grafo, 15, 14, 19); 
    adicionarAresta(grafo, 15, 17, 26); 

    adicionarAresta(grafo, 16, 16, 26); 
    adicionarAresta(grafo, 16,14, 17); 
    adicionarAresta(grafo, 16, 15, 18); 
    adicionarAresta(grafo, 16, 18, 15); 

    adicionarAresta(grafo, 17, 17, 15); 
    adicionarAresta(grafo, 17,15, 21); 
    adicionarAresta(grafo, 17, 11, 36); 
  
  
    
    dijkstra(grafo);

    return 0;
}
