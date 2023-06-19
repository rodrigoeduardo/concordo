#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

#include "utils.hpp"

using namespace std;

class Mensagem
{
private:
    string dataHora;
    int enviadaPor;
    string conteudo;

public:
    Mensagem(int enviadaPor, string conteudo);
    string getDataHora();
    void setDataHora(string dataHora);
    int getEnviadaPor();
    void setEnviadaPor(int id);
    string getConteudo();
    void setConteudo(string conteudo);
};

#endif // MENSAGEM_H