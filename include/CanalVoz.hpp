#ifndef CANALVOZ_HPP
#define CANALVOZ_HPP

#include <string>

#include "Mensagem.hpp"
#include "Canal.hpp"

using namespace std;

class CanalVoz : public Canal
{
private:
    Mensagem ultimaMensagem;

public:
    CanalVoz(string nome);
    Mensagem getUltimaMensagem();
    void setUltimaMensagem(Mensagem mensagem);
};

#endif // CANALVOZ_HPP