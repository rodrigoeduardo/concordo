#include <iostream>
#include <string>

#include "Usuario.hpp"
#include "Mensagem.hpp"

using namespace std;

int main()
{
    Usuario rod("Rodrigo", "rod@blob.com", "oi123");
    Usuario vini("Vinicius", "vini@blob.com", "oi123");
    Mensagem m1(rod.getId(), "Oi, Vinicius!");

    cout << "Rodrigo: " << rod.getId() << endl;
    cout << "Vinicius: " << vini.getId() << endl;

    cout << "Mensagem: " << m1.getConteudo() << endl;
    cout << "Enviada por: " << m1.getEnviadaPor() << endl;
    cout << "Data e hora: " << m1.getDataHora() << endl;

    return 0;
}