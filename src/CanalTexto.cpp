#include "CanalTexto.hpp"

CanalTexto::CanalTexto(string nome) : Canal(nome)
{
}

vector<Mensagem> CanalTexto::getMensagens()
{
    return this->mensagens;
}

void CanalTexto::setMensagens(vector<Mensagem> mensagens)
{
    this->mensagens = mensagens;
}

void CanalTexto::enviarMensagem(Mensagem mensagem)
{
    this->mensagens.push_back(mensagem);
}
