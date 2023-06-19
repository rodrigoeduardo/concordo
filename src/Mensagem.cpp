#include "Mensagem.hpp"
#include "utils.hpp"
#include <string>

using namespace std;

Mensagem::Mensagem(int enviadaPor, string conteudo)
{
    this->dataHora = obterDataAtual();
    this->enviadaPor = enviadaPor;
    this->conteudo = conteudo;
}

string Mensagem::getDataHora()
{
    return this->dataHora;
}

void Mensagem::setDataHora(string dataHora)
{
    this->dataHora = dataHora;
}

int Mensagem::getEnviadaPor()
{
    return this->enviadaPor;
}

void Mensagem::setEnviadaPor(int id)
{
    this->enviadaPor = id;
}

string Mensagem::getConteudo()
{
    return this->conteudo;
}

void Mensagem::setConteudo(string conteudo)
{
    this->conteudo = conteudo;
}
