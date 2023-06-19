#include <iostream>
#include <string>

#include "Usuario.hpp"
#include "Mensagem.hpp"
#include "CanalTexto.hpp"
#include "CanalVoz.hpp"

using namespace std;

int main()
{
    Usuario rod("Rodrigo", "rod@blob.com", "oi123");
    Usuario vini("Vinicius", "vini@blob.com", "oi123");
    Mensagem m1(rod.getId(), "Oi, Vinicius!");
    Mensagem m2(vini.getId(), "Oi, Rodrigo!");
    CanalTexto canal("Geral");
    CanalVoz voz("Geral");

    cout << "Rodrigo: " << rod.getId() << endl;
    cout << "Vinicius: " << vini.getId() << endl;

    canal.enviarMensagem(m1);
    voz.setUltimaMensagem(m2);

    cout << "Mensagem: " << canal.getMensagens()[0].getConteudo() << endl;
    cout << "Ultima mensagem: " << voz.getUltimaMensagem().getConteudo() << endl;

    return 0;
}