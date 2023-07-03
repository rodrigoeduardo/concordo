#ifndef CANALTEXTO_HPP
#define CANALTEXTO_HPP

#include "Canal.hpp"
#include "Mensagem.hpp"

#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class CanalTexto : public Canal
{
private:
    vector<shared_ptr<Mensagem>> mensagens;

public:
    CanalTexto(string nome);
    vector<shared_ptr<Mensagem>> getMensagens();
    void enviarMensagem(Mensagem mensagem);
    void listarMensagens(vector<shared_ptr<Usuario>> usuariosCadastrados);
};

#endif // CANALTEXTO_HPP