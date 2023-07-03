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

void CanalVoz::listarMensagens(vector<shared_ptr<Usuario>> usuariosCadastrados)
{
    cout << "Última Mensagem #" << this->getNome() << ":" << endl;
    if (this->ultimaMensagem == nullptr)
    {
        cout << "Nenhuma mensagem enviada" << endl;
        return;
    }

    string nomeUsuario = "";

    for (int i = 0; i < usuariosCadastrados.size(); i++)
    {
        if (usuariosCadastrados[i]->getId() == this->ultimaMensagem->getEnviadaPor())
        {
            nomeUsuario = usuariosCadastrados[i]->getNome();
            break;
        }
    }

    cout << nomeUsuario << "<" << this->ultimaMensagem->getDataHora() << ">: " << this->ultimaMensagem->getConteudo() << endl;
}