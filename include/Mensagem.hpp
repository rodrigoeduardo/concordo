#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

using namespace std;

class Mensagem
{
private:
    string dataHora;
    int enviadaPor;
    string conteudo;

public:
    string getDataHora();
    void setDataHora(string dataHora);
    int getEnviadaPor();
    void setEnviadaPor(int id);
    string getConteudo();
    void setConteudo(string conteudo);
};

#endif // MENSAGEM_H