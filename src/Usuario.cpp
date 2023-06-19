#include "Usuario.hpp"

int Usuario::contador = 0;

Usuario::Usuario(string nome, string email, string senha)
{
    contador++;

    this->id = contador;
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

Usuario::~Usuario()
{
}

int Usuario::getId()
{
    return this->id;
}

void Usuario::setId(int id)
{
    this->id = id;
}

string Usuario::getNome()
{
    return this->nome;
}

void Usuario::setNome(string nome)
{
    this->nome = nome;
}

string Usuario::getEmail()
{
    return this->email;
}

void Usuario::setEmail(string email)
{
    this->email = email;
}

string Usuario::getSenha()
{
    return this->senha;
}

void Usuario::setSenha(string senha)
{
    this->senha = senha;
}
