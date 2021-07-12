#include "funcoes.h"

//Se o tipo de representação escolhido for matriz de adjacências,
//esta função é executada
void tratarGrafoMatriz(string arquivo)
{
    bool dir;
    string linha, interm;
    vector<string> vet, vet2;
    int numVertices, numArestas;

    //verifica se o grafo é dirigido
    if(arquivo.at(0) == 'g')
        dir = false;
    else if(arquivo.at(0) == 'd')
        dir = true;
    ifstream readFile(arquivo);

    getline(readFile, linha);
    getline(readFile, linha);
    stringstream st(linha);
    while(getline(st, interm, ' '))
        vet.push_back(interm);
    numVertices = stoi(vet[0]);
    numArestas = stoi(vet[1]);

    GrafoMt g = criarGrafoM(numVertices, dir);
    while (getline(readFile, linha))
    {
        if(linha.at(0) == 'c')
            continue;
        stringstream st2(linha);
        while(getline(st2, interm, ' '))
            vet2.push_back(interm);
       
        int v1 = stoi(vet2[0]);
        int v2 = stoi(vet2[1]);
        int p = stoi(vet2[2]);
        
        if(p == 0)
            inserirArestaM(g, v1, v2);
        else 
            inserirArestaM(g, v1, v2, p);
        
        vet2.clear();
    }
    readFile.close();
    exportarSaidaM(g);
    excluirGrafoM(g);
}

//Se o tipo de representação escolhido for lista de adjacências,
//esta função é executada
void tratarGrafoLista(string arquivo)
{
    bool dir;
    string linha, interm;
    vector<string> vet, vet2;
    int numVertices, numArestas;

    //verifica se o grafo é dirigido
    if(arquivo.at(0) == 'g')
        dir = false;
    else if(arquivo.at(0) == 'd')
        dir = true;
    ifstream readFile(arquivo);

    getline(readFile, linha);
    getline(readFile, linha);
    stringstream st(linha);
    while(getline(st, interm, ' '))
        vet.push_back(interm);
    numVertices = stoi(vet[0]);
    numArestas = stoi(vet[1]);

    GrafoLst g = criarGrafoL(numVertices, dir);
    for(int i = 0; i < numVertices; i++)
    {
        Vertice vr = criarVerticeL(i);
        inserirVerticeL(g, vr);
    }
    
    while (getline(readFile, linha))
    {
        if(linha.at(0) == 'c')
            continue;
        cout << linha << endl;
        stringstream st2(linha);
        while(getline(st2, interm, ' '))
        {
            vet2.push_back(interm);
        }
        conectarVerticesL(g, stoi(vet2[0]), stoi(vet2[1]), stoi(vet2[2]));
        vet2.clear();
    }
    readFile.close();
    exportarSaidaL(g);
    excluirGrafoL(g);
}

string requisitarEntradaUsuario()
{
    string res;
    cout << "Qual o tipo de representação deseja usar?\nDigite 'matriz' para matriz de adjacências ou \n'lista' para lista de adjacências: ";
    getline(cin, res);
    return res;
}
