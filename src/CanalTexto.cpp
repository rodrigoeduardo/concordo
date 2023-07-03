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

void CanalTexto::listarMensagens(vector<shared_ptr<Usuario>> usuariosCadastrados)
{
    cout << "Mensagens #" << this->getNome() << ":" << endl;
    if (this->mensagens.size() == 0)
    {
        cout << "Nenhuma mensagem enviada" << endl;
        return;
    }

    for (auto mensagem : this->mensagens)
    {
        string nomeUsuario = "";

        for (int i = 0; i < usuariosCadastrados.size(); i++)
        {
            if (usuariosCadastrados[i]->getId() == mensagem->getEnviadaPor())
            {
                nomeUsuario = usuariosCadastrados[i]->getNome();
                break;
            }
        }

        cout << nomeUsuario << "<" << mensagem->getDataHora() << ">: " << mensagem->getConteudo() << endl;
    }
}