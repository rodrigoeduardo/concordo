#include "Servidor.hpp"

#include <CanalTexto.hpp>
#include <CanalVoz.hpp>

Servidor::Servidor(int usuarioDonoId, string nome)
{
    this->usuarioDonoId = usuarioDonoId;
    this->nome = nome;
    this->descricao = "";
    this->canaisTexto = vector<shared_ptr<CanalTexto>>();
    this->canaisVoz = vector<shared_ptr<CanalVoz>>();
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

vector<shared_ptr<CanalTexto>> Servidor::getCanaisTexto()
{
    return this->canaisTexto;
}

void Servidor::adicionarCanalTexto(shared_ptr<CanalTexto> canalTexto)
{
    this->canaisTexto.push_back(move(canalTexto));
}

vector<shared_ptr<CanalVoz>> Servidor::getCanaisVoz()
{
    return this->canaisVoz;
}

void Servidor::adicionarCanalVoz(shared_ptr<CanalVoz> canalVoz)
{
    this->canaisVoz.push_back(move(canalVoz));
}

vector<int> Servidor::getParticipantesIds()
{
    return this->participantesIds;
}

void Servidor::adicionarParticipanteId(int id)
{
    this->participantesIds.push_back(id);
}
