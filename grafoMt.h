//Arquivo de cabeçalho representando um grafo, valorado ou não,
//por matriz de adjacências
#ifndef GRAFO_MT_H
#define GRAFO_MT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct grafom
{
    vector<vector<int> > matriz;
    bool dirigido;
};
typedef struct grafom* GrafoMt;

GrafoMt criarGrafoM(int,bool);
void inserirArestaM(GrafoMt,int,int,int val=1);
void excluirGrafoM(GrafoMt);
bool verificaGrafoValoradoM(GrafoMt);
void exportarSaidaM(GrafoMt,int,int);

#endif