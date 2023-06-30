#include "CanalVoz.hpp"
#include "Mensagem.hpp"

CanalVoz::CanalVoz(string nome) : Canal(nome)
{
    this->ultimaMensagem = make_shared<Mensagem>();
}

shared_ptr<Mensagem> CanalVoz::getUltimaMensagem()
{
    return this->ultimaMensagem;
}

void CanalVoz::enviarMensagem(Mensagem mensagem)
{
    this->ultimaMensagem = make_shared<Mensagem>(mensagem);
}

void CanalVoz::listarMensagens()
{
    if (this->ultimaMensagem == nullptr)
    {
        cout << "Nenhuma mensagem enviada" << endl;
        return;
    }
    auto usuario = this->ultimaMensagem->getEnviadaPor();
    cout << usuario << "<" << this->ultimaMensagem->getDataHora() << ">: " << this->ultimaMensagem->getConteudo() << endl;
}