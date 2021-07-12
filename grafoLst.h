//Arquivo de cabeçalho representando um grafo
//por lista de adjacências

#ifndef GRAFO_LST_H
#define GRAFO_LST_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

struct vizinho
{
    int labelVizinho;
    int peso;
};
typedef struct vizinho Vizinho;

struct vertice
{
    int label;
    list<Vizinho> vizinhos;
    map<int,int> vizinhanca;
};
typedef struct vertice* Vertice;

struct grafol
{
    vector<Vertice> vertices;
    bool dirigido;
};
typedef struct grafol* GrafoLst;


GrafoLst criarGrafoL(int,bool);
Vertice criarVerticeL(int);
void inserirVerticeL(GrafoLst,Vertice);
void conectarVerticesL(GrafoLst,int,int,int peso=0);
void excluirGrafoL(GrafoLst);
bool verificaGrafoValorado(GrafoLst);
void exportarSaidaL(GrafoLst);

#endif