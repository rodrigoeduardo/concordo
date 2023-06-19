#include "Sistema.hpp"

Sistema::Sistema()
{
    this->usuarios = make_unique<vector<unique_ptr<Usuario>>>();
    this->servidores = make_unique<vector<unique_ptr<Servidor>>>();
}

Sistema::~Sistema()
{
}

unique_ptr<vector<unique_ptr<Usuario>>> Sistema::getUsuarios()
{
    return move(this->usuarios);
}

void Sistema::adicionarUsuario(unique_ptr<Usuario> usuario)
{
    this->usuarios->push_back(move(usuario));
}

unique_ptr<vector<unique_ptr<Servidor>>> Sistema::getServidores()
{
    return move(this->servidores);
}

void Sistema::adicionarServidor(unique_ptr<Servidor> servidor)
{
    this->servidores->push_back(move(servidor));
}

unique_ptr<Usuario> Sistema::getUsuarioLogado()
{
    return move(this->usuarioLogado);
}

void Sistema::setUsuarioLogado(unique_ptr<Usuario> usuario)
{
    this->usuarioLogado = move(usuario);
}

unique_ptr<Servidor> Sistema::getServidorAtual()
{
    return move(this->servidorAtual);
}

void Sistema::setServidorAtual(unique_ptr<Servidor> servidor)
{
    this->servidorAtual = move(servidor);
}

unique_ptr<Canal> Sistema::getCanalAtual()
{
    return move(this->canalAtual);
}

void Sistema::setCanalAtual(unique_ptr<Canal> canal)
{
    this->canalAtual = move(canal);
}
