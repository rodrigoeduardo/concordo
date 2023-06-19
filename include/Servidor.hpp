#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include <string>
#include <vector>

#include <Canal.hpp>

using namespace std;

class Servidor
{
private:
    int usuarioDonoId;
    string nome;
    string descricao;
    string codigoConvite;
    vector<Canal *> canais;
    vector<int> participantesIds;

public:
    Servidor(int usuarioDonoId, string nome, string descricao);
    int getUsuarioDonoId();
    void setUsuarioDonoId(int id);
    string getNome();
    void setNome(string nome);
    string getDescricao();
    void setDescricao(string descricao);
    string getCodigoConvite();
    void setCodigoConvite(string codigoConvite);
    vector<Canal *> getCanais();
    void setCanais(vector<Canal *> canais);
    vector<int> getParticipantesIds();
    void setParticipantesIds(vector<int> participantesIds);
};

#endif // SERVIDOR_HPP