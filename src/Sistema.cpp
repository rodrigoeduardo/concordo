#include "Sistema.hpp"

Sistema::Sistema()
{
    this->usuarios = vector<shared_ptr<Usuario>>();
    this->servidores = vector<shared_ptr<Servidor>>();
    this->sair = shared_ptr<bool>(new bool(false));
}

Sistema::~Sistema()
{
}

vector<shared_ptr<Usuario>> Sistema::getUsuarios()
{
    return this->usuarios;
}

shared_ptr<Usuario> Sistema::getUsuarioPorId(int id)
{
    for (int i = 0; i < this->usuarios.size(); i++)
    {
        if (this->usuarios[i]->getId() == id)
        {
            return this->usuarios[i];
        }
    }
    return nullptr;
}

void Sistema::adicionarUsuario(shared_ptr<Usuario> usuario)
{
    this->usuarios.push_back(move(usuario));
}

vector<shared_ptr<Servidor>> Sistema::getServidores()
{
    return this->servidores;
}

void Sistema::adicionarServidor(shared_ptr<Servidor> servidor)
{
    this->servidores.push_back(move(servidor));
}

void Sistema::removerServidor(shared_ptr<Servidor> servidor)
{
    for (int i = 0; i < this->servidores.size(); i++)
    {
        if (this->servidores[i] == servidor)
        {
            this->servidores.erase(this->servidores.begin() + i);
            break;
        }
    }
}

shared_ptr<Usuario> Sistema::getUsuarioLogado()
{
    return this->usuarioLogado;
}

void Sistema::setUsuarioLogado(shared_ptr<Usuario> usuario)
{
    this->usuarioLogado = usuario;
}

shared_ptr<Servidor> Sistema::getServidorAtual()
{
    return this->servidorAtual;
}

void Sistema::setServidorAtual(shared_ptr<Servidor> servidor)
{
    this->servidorAtual = move(servidor);
}

shared_ptr<Canal> Sistema::getCanalAtual()
{
    return this->canalAtual;
}

void Sistema::setCanalAtual(shared_ptr<Canal> canal)
{
    this->canalAtual = move(canal);
}

shared_ptr<bool> Sistema::getSair()
{
    return this->sair;
}

void Sistema::setSair(shared_ptr<bool> sair)
{
    this->sair = move(sair);
}
