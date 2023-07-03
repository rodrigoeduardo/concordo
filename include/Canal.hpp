#ifndef CANAL_HPP
#define CANAL_HPP

#include <string>
#include <memory>
#include <vector>

#include "Mensagem.hpp"
#include "Usuario.hpp"

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
    virtual void listarMensagens(vector<shared_ptr<Usuario>> usuariosCadastrados) = 0;
};

#endif // CANAL_HPP