#include "grafoLst.h"

//Inicializa a estrutura de dados Grafo
GrafoLst criarGrafoL(int tam, bool dir)
{
    GrafoLst g = new grafol;
    g->dirigido = dir;
    return g;
}

//Inicializa um vértice
Vertice criarVerticeL(int label)
{
    Vertice v = new vertice;
    v->label = label;
    return v;
}

//Adiciona o vértice à lista de vértices do Grafo
void inserirVerticeL(GrafoLst g, Vertice v)
{
    for(Vertice vr : g->vertices)
        if(vr->label == v->label)
            return;
    g->vertices.push_back(v);
}

//Insere uma aresta entre dois vértices
//Pré-condição: ambos os vértices já existem no grafo G
void conectarVerticesL(GrafoLst g, int v1, int v2, int peso)
{
    Vizinho vz1, vz2;
    vz1.labelVizinho = v1;
    vz1.peso = peso;
    vz2.labelVizinho = v2;
    vz2.peso = peso;
    for(int i = 0; i < g->vertices.size(); i++)
    {
        if(g->vertices[i]->label == v1)
        {
            g->vertices[i]->vizinhos.push_back(vz2);
        }
    }
}

void excluirGrafoL(GrafoLst g)
{
    for(int i = 0; i < g->vertices.size(); i++)
        delete g->vertices[i];
    delete g;
}

//Função auxiliar; verifica se um grafo é valorado ou não
bool verificaGrafoValorado(GrafoLst g)
{
    for(int i = 0; i < g->vertices.size(); i++)
    {
        for(Vizinho element : g->vertices[i]->vizinhos)
        {
            if(element.peso != 0)
                return true;
        }
    }
    return false;
}

//Exporta saída no formato exigido
void exportarSaidaL(GrafoLst g, int n, int m)
{
    string s = "graph G\n{";
    string pref = "di";
    string arqu;
    string fim = "_" + to_string(n) + "_" + to_string(m) + ".dot";
    if(verificaGrafoValorado(g))
    {        
        if(g->dirigido)
        {
            pref += s;
            s = pref;
            for(Vertice i : g->vertices)
            {
                for(Vizinho element : i->vizinhos)
                {
                    s += "\n\t";
                    s += to_string(i->label) + " -> " + to_string(element.labelVizinho);
                    s += " [label = " + to_string(element.peso);
                    s += "];";
                }
            }
            arqu = "digrafov";
        }
        else
        {
            for(Vertice i : g->vertices)
            {
                for(Vizinho element : i->vizinhos)
                {
                    s += "\n\t";
                    s += to_string(i->label) + " -- " + to_string(element.labelVizinho);
                    s += " [label = " + to_string(element.peso);
                    s += "];";
                }
            }
            arqu = "grafov";
        }
    }
    else
    {
        if(g->dirigido)
        {
            pref += s;
            s = pref;
            for(Vertice i : g->vertices)
            {
                for(Vizinho element : i->vizinhos)
                {
                    s += "\n\t";
                    s += to_string(i->label) + " -> " + to_string(element.labelVizinho);
                    s += ";";
                }
            }
            arqu = "digrafo";
            }
        else 
        {
            for(Vertice i : g->vertices)
            {
                for(Vizinho element : i->vizinhos)
                {
                    s += "\n\t";
                    s += to_string(i->label) + " -- " + to_string(element.labelVizinho);
                    s += ";";
                }
            }
            arqu = "grafo";
        }
    }
    arqu += fim;
    s += "\n}";
    ofstream file(arqu);
    file << s;
    file.close();
}