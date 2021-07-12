#include "grafoMt.h"

//Inicializa a estrutura de dados;
//O tamanho da matriz criada será equivalente ao
//número de vértices
GrafoMt criarGrafoM(int tam, bool dir)
{
    GrafoMt g = new grafom;
    vector<vector<int> > vcol(tam);
    for(int i = 0; i < tam; i++)
        vcol[i] = vector<int>(tam);
    g->matriz = vcol;
    g->dirigido = dir;
    return g;
}

//Insere uma aresta entre dois vértices
void inserirArestaM(GrafoMt g, int v1, int v2, int val)
{
    if(g->dirigido)
    {
        g->matriz[v1-1][v2-1] = val;
    }
    else
    {
        g->matriz[v1-1][v2-1] = val;
        g->matriz[v2-1][v1-1] = val;
    }
}

void excluirGrafoM(GrafoMt g)
{
    delete g;
}

//Função auxiliar; verifica se o grafo é ou não valorado
bool verificaGrafoValoradoM(GrafoMt g)
{
    for(vector<int> v : g->matriz)
    {
        for(int i : v)
        {
            if(i != 0 && i != 1)
                return true;
        }
    }
    return false;
}

//Exporta saída no formato exigidos
void exportarSaidaM(GrafoMt g)
{
    string s = "graph G\n{";
    string arqu;
    if(verificaGrafoValoradoM(g))
    {
        if(g->dirigido)
        {
            for(int i = 0; i < g->matriz.size(); i++)
            {
                for(int j = 0; j < g->matriz[0].size(); j++)
                {
                    if(g->matriz[i][j] != 0)
                    {
                        s += "\n\t";
                        s += to_string(i+1) + " -> " + to_string(j+1);
                        s += " [label = " + to_string(g->matriz[i][j]);
                        s += "];";
                    }
                }
            }
            arqu = "digrafov_n_m.dot";
        }
        else 
        {
            for(int i = 0; i < g->matriz.size(); i++)
            {
                if(i == g->matriz.size()-1)
                    break;
                for(int j = i + 1; j < g->matriz[0].size(); j++)
                {
                    if(g->matriz[i][j] != 0)
                    {
                        s += "\n\t";
                        s += to_string(i+1) + " -- " + to_string(j+1);
                        s += " [label = " + to_string(g->matriz[i][j]);
                        s += "];";
                    }
                }
            }
            arqu = "grafov_n_m.dot";
        }
    }
    else
    {
        if(g->dirigido)
        {
            for(int i = 0; i < g->matriz.size(); i++)
            {
                for(int j = 0; j < g->matriz[0].size(); j++)
                {
                    if(g->matriz[i][j] != 0)
                    {
                        s += "\n\t";
                        s += to_string(i+1) + " -> " + to_string(j+1);
                        s += ";";
                    }
                }
            }
            arqu = "digrafo_n_m.dot";
        }
        else 
        {
            for(int i = 0; i < g->matriz.size(); i++)
            {
                if(i == g->matriz.size()-1)
                    break;
                for(int j = i + 1; j < g->matriz[0].size(); j++)
                {
                    if(g->matriz[i][j] != 0)
                    {
                        s += "\n\t";
                        s += to_string(i+1) + " -- " + to_string(j+1);
                        s += ";";
                    }
                }
            }       
            arqu = "grafo_n_m.dot";
        }
        
    }
    s += "\n}";
    ofstream file(arqu);
    file << s;
    file.close();
}