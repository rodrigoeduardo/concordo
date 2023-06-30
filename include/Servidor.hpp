#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include <string>
#include <vector>
#include <memory>

#include <Canal.hpp>
#include <CanalTexto.hpp>
#include <CanalVoz.hpp>

using namespace std;

class Servidor
{
private:
    int usuarioDonoId;
    string nome;
    string descricao;
    string codigoConvite;
    vector<shared_ptr<CanalTexto>> canaisTexto;
    vector<shared_ptr<CanalVoz>> canaisVoz;
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
    vector<shared_ptr<CanalTexto>> getCanaisTexto();
    void adicionarCanalTexto(shared_ptr<CanalTexto> canalTexto);
    vector<shared_ptr<CanalVoz>> getCanaisVoz();
    void adicionarCanalVoz(shared_ptr<CanalVoz> canalVoz);
    vector<int> getParticipantesIds();
    void adicionarParticipanteId(int id);
};

#endif // SERVIDOR_HPP