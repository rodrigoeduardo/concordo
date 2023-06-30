#include "CanalTexto.hpp"

CanalTexto::CanalTexto(string nome) : Canal(nome)
{
}

vector<shared_ptr<Mensagem>> CanalTexto::getMensagens()
{
    return this->mensagens;
}

void CanalTexto::enviarMensagem(Mensagem mensagem)
{
    this->mensagens.push_back(make_shared<Mensagem>(mensagem));
}

void CanalTexto::listarMensagens()
{
    for (auto mensagem : this->mensagens)
    {
        auto usuario = mensagem->getEnviadaPor();
        cout << usuario << "<" << mensagem->getDataHora() << ">: " << mensagem->getConteudo() << endl;
    }
}