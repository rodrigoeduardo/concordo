#ifndef CANALVOZ_HPP
#define CANALVOZ_HPP

#include <string>
#include <memory>
#include <iostream>

#include "Mensagem.hpp"
#include "Canal.hpp"

using namespace std;

class CanalVoz : public Canal
{
private:
    shared_ptr<Mensagem> ultimaMensagem;

public:
    CanalVoz(string nome);
    shared_ptr<Mensagem> getUltimaMensagem();
    void enviarMensagem(Mensagem mensagem);
    void listarMensagens();
};

#endif // CANALVOZ_HPP