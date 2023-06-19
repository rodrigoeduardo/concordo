#include <iostream>
#include <string>

#include "Usuario.hpp"

using namespace std;

int main()
{
    Usuario rod("Rodrigo", "rod@blob.com", "oi123");
    Usuario vini("Vinicius", "vini@blob.com", "oi123");

    cout << "Rodrigo: " << rod.getId() << endl;
    cout << "Vinicius: " << vini.getId() << endl;

    return 0;
}