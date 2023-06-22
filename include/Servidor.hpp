#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include <string>
#include <vector>
#include <memory>

#include <Canal.hpp>

using namespace std;

class Servidor
{
private:
    int usuarioDonoId;
    string nome;
    string descricao;
    string codigoConvite;
    vector<shared_ptr<Canal>> canais;
    vector<int> participantesIds;

public:
    Servidor(int usuarioDonoId, string nome);
    int getUsuarioDonoId();
    void setUsuarioDonoId(int id);
    string getNome();
    void setNome(string nome);
    string getDescricao();
    void setDescricao(string descricao);
    string getCodigoConvite();
    void setCodigoConvite(string codigoConvite);
    vector<shared_ptr<Canal>> getCanais();
    void setCanais(vector<shared_ptr<Canal>> canais);
    vector<int> getParticipantesIds();
    void setParticipantesIds(vector<int> participantesIds);
};

#endif // SERVIDOR_HPP