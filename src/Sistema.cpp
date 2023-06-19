#include "Sistema.hpp"

Sistema::Sistema()
{
}

Sistema::~Sistema()
{
}

vector<Usuario *> Sistema::getUsuarios()
{
    return this->usuarios;
}

void Sistema::adicionarUsuario(Usuario *usuario)
{
    this->usuarios.push_back(usuario);
}

vector<Servidor *> Sistema::getServidores()
{
    return this->servidores;
}

void Sistema::adicionarServidor(Servidor *servidor)
{
    this->servidores.push_back(servidor);
}

Usuario *Sistema::getUsuarioLogado()
{
    return this->usuarioLogado;
}

void Sistema::setUsuarioLogado(Usuario *usuario)
{
    this->usuarioLogado = usuario;
}

Servidor *Sistema::getServidorAtual()
{
    return this->servidorAtual;
}

void Sistema::setServidorAtual(Servidor *servidor)
{
    this->servidorAtual = servidor;
}

Canal *Sistema::getCanalAtual()
{
    return this->canalAtual;
}

void Sistema::setCanalAtual(Canal *canal)
{
    this->canalAtual = canal;
}
