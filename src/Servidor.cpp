#include "Servidor.hpp"

Servidor::Servidor(int usuarioDonoId, string nome, string descricao)
{
    this->usuarioDonoId = usuarioDonoId;
    this->nome = nome;
    this->descricao = descricao;
}

int Servidor::getUsuarioDonoId()
{
    return this->usuarioDonoId;
}

void Servidor::setUsuarioDonoId(int id)
{
    this->usuarioDonoId = id;
}

string Servidor::getNome()
{
    return this->nome;
}

void Servidor::setNome(string nome)
{
    this->nome = nome;
}

string Servidor::getDescricao()
{
    return this->descricao;
}

void Servidor::setDescricao(string descricao)
{
    this->descricao = descricao;
}

string Servidor::getCodigoConvite()
{
    return this->codigoConvite;
}

void Servidor::setCodigoConvite(string codigoConvite)
{
    this->codigoConvite = codigoConvite;
}

vector<Canal *> Servidor::getCanais()
{
    return this->canais;
}

void Servidor::setCanais(vector<Canal *> canais)
{
    this->canais = canais;
}

vector<int> Servidor::getParticipantesIds()
{
    return this->participantesIds;
}

void Servidor::setParticipantesIds(vector<int> participantesIds)
{
    this->participantesIds = participantesIds;
}
