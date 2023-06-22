#include "Servidor.hpp"

Servidor::Servidor(int usuarioDonoId, string nome)
{
    this->usuarioDonoId = usuarioDonoId;
    this->nome = nome;
    this->descricao = "";
    this->canais = vector<shared_ptr<Canal>>();
    this->participantesIds = vector<int>();
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

vector<shared_ptr<Canal>> Servidor::getCanais()
{
    return this->canais;
}

void Servidor::setCanais(vector<shared_ptr<Canal>> canais)
{
    this->canais = move(canais);
}

vector<int> Servidor::getParticipantesIds()
{
    return this->participantesIds;
}

void Servidor::adicionarParticipanteId(int id)
{
    this->participantesIds.push_back(id);
}
