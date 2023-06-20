#include <iostream>
#include <string>
#include <memory>

#include "Sistema.hpp"
#include "Usuario.hpp"
#include "menus.hpp"

using namespace std;

int main()
{
    shared_ptr<Sistema> sistema(new Sistema());

    menuInicial(move(sistema));

    return 0;
}
