#include "CanalVoz.hpp"
#include "Mensagem.hpp"

CanalVoz::CanalVoz(string nome) : Canal(nome)
{
}

Mensagem CanalVoz::getUltimaMensagem()
{
    return this->ultimaMensagem;
}

void CanalVoz::setUltimaMensagem(Mensagem mensagem)
{
    this->ultimaMensagem = mensagem;
}