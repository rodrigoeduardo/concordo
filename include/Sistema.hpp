#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <string>
#include <vector>

#include "Usuario.hpp"
#include "Servidor.hpp"
#include "Canal.hpp"

using namespace std;

class Sistema
{
private:
    vector<Usuario *> usuarios;
    vector<Servidor *> servidores;
    Usuario *usuarioLogado;
    Servidor *servidorAtual;
    Canal *canalAtual;

public:
    Sistema();
    ~Sistema();
    vector<Usuario *> getUsuarios();
    void adicionarUsuario(Usuario *usuario);
    vector<Servidor *> getServidores();
    void adicionarServidor(Servidor *servidor);
    Usuario *getUsuarioLogado();
    void setUsuarioLogado(Usuario *usuario);
    Servidor *getServidorAtual();
    void setServidorAtual(Servidor *servidor);
    Canal *getCanalAtual();
    void setCanalAtual(Canal *canal);
};

#endif // SISTEMA_HPP