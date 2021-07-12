#include "grafoLst.h"
#include "grafoMt.h"
#include "funcoes.h"

int main(int argc, char const *argv[])
{
    if(argc == 1)
    {
        cerr << "Erro: digite o nome do arquivo de entrada.\n";
        exit(1);
    }

    string arqEntrada = argv[1];
    string tipo = requisitarEntradaUsuario();
    if(tipo.compare("matriz") == 0)
    {
        tratarGrafoMatriz(arqEntrada);
    }
    else if(tipo.compare("lista") == 0)
    {
        tratarGrafoLista(arqEntrada);
    }
    return 0;
}
