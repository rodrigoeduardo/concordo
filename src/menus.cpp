
#include "menus.hpp"
#include "Sistema.hpp"
#include "utils.hpp"

void menu(shared_ptr<Sistema> sistema)
{
    while (true)
    {
        string entrada;

        getline(cin, entrada);

        executarComando(entrada, sistema);

        bool sair = *sistema->getSair();
        if (sair)
        {
            cout << "Saindo do Concordo" << endl;
            return;
        }
    }
}