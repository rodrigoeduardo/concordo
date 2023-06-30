#ifndef CANAL_HPP
#define CANAL_HPP

#include <string>

#include "Mensagem.hpp"

using namespace std;

class Canal
{
private:
    string nome;

public:
    Canal(string nome);
    string getNome();
    void setNome(string nome);
    virtual void enviarMensagem(Mensagem mensagem) = 0;
    virtual void listarMensagens() = 0;
};

#endif // CANAL_HPP