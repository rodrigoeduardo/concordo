#ifndef CANALTEXTO_HPP
#define CANALTEXTO_HPP

#include "Canal.hpp"
#include "Mensagem.hpp"

#include <string>
#include <vector>

using namespace std;

// essa classe herdará de Canal
class CanalTexto : public Canal
{
private:
    vector<Mensagem> mensagens;

public:
    CanalTexto(string nome);
    vector<Mensagem> getMensagens();
    void setMensagens(vector<Mensagem> mensagens);
    void enviarMensagem(Mensagem mensagem);
};

#endif // CANALTEXTO_HPP