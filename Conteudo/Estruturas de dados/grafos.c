#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define fase 0

typedef struct adjacencia{
    int adj;
    int peso;
    struct adjacencia *proximo;
}ADJACENCIA;

typedef struct vertice{
    ADJACENCIA *prim;
}VERTICE;

typedef struct grafo{
    int vertices;
    int arestas;
    VERTICE *adjacencia;
}GRAFO;

GRAFO *criar_grafo(int qtd_vertices){
    int i;

    GRAFO *grafo = malloc(sizeof(GRAFO));
    grafo->arestas = 0;
    grafo->vertices = qtd_vertices;
    grafo->adjacencia = malloc(sizeof(VERTICE)*qtd_vertices);

    for ( i = 0; i < qtd_vertices; i++){
        grafo->adjacencia[i].prim = NULL;
    }
    return grafo;
}

GRAFO *criaGrafo (int v) {
	int i;
	
	GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO)); //aloca espaço para estrtura grafo
	g->vertices = v; //atualizo o numero de vertice
	g->arestas = 0;  //atualizo o numero de vertice
	g->adj = (VERTICE *)malloc(v*sizeof(VERTICE)); //ler abaixo
	//Dentro da estrturua tem só o arranjo para o ponteiro de vertice, não o arranjo em si 	
	// então aloco o arranjo com (v) o numero de vertice desejado
	for (i=0; i<v; i++){ 
		g->adj[i].cab=NULL; //coloco NULL em todas arestas
	}
	return(g);
}

/**função para adicionar arestas no GRAFO**/

ADJACENCIA *criaAdj(int v, int peso){ 
	ADJACENCIA *temp = (ADJACENCIA *) malloc (sizeof(ADJACENCIA)); //aloca espaço para um nó
	temp->vertice =v; //vertice alvo da adjacencia
	temp->peso = peso; //peso da aresta
	temp->prox = NULL; 
	return(temp); //retorno endereço da adjacencia
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p) { //vai de vi a vf
	if(!gr) return (false);  //validações se o grafo existe 
	if((vf<0)||(vf >= gr->vertices)return(false); //validações se os valores não são neg
	if((vi<0)||(vf >= gr->vertices)return(false); //ou maiores que o numero de vértice do grafo
	
	ADJACENCIA *novo = criaAdj(vf,p); //crio adjacencia com o vértice final e o peso
	//coloco a adjacencia na lista do vértice inicial
	novo->prox = gr->adj[vi].cab; //o campo prox da adjacencia vai receber a cabeça da lista
	gr->adj[vi].cab=novo; // e a cabeça da lista passa a ser o novo elemento
	gr->arestas++; // atualizo o numero de aresta no grafo
	return (true);
}
int main(){


    return 0;
}    
