#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <string>
#include <vector>
#include <memory>

#include "Usuario.hpp"
#include "Servidor.hpp"
#include "Canal.hpp"

using namespace std;

class Sistema
{
private:
    unique_ptr<vector<unique_ptr<Usuario>>> usuarios;
    unique_ptr<vector<unique_ptr<Servidor>>> servidores;
    unique_ptr<Usuario> usuarioLogado;
    unique_ptr<Servidor> servidorAtual;
    unique_ptr<Canal> canalAtual;

public:
    Sistema();
    ~Sistema();
    unique_ptr<vector<unique_ptr<Usuario>>> getUsuarios();
    void adicionarUsuario(unique_ptr<Usuario> usuario);
    unique_ptr<vector<unique_ptr<Servidor>>> getServidores();
    void adicionarServidor(unique_ptr<Servidor> servidor);
    unique_ptr<Usuario> getUsuarioLogado();
    void setUsuarioLogado(unique_ptr<Usuario> usuario);
    unique_ptr<Servidor> getServidorAtual();
    void setServidorAtual(unique_ptr<Servidor> servidor);
    unique_ptr<Canal> getCanalAtual();
    void setCanalAtual(unique_ptr<Canal> canal);
};

#endif // SISTEMA_HPP