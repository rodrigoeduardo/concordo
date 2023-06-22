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
    vector<shared_ptr<Usuario>> usuarios;
    vector<shared_ptr<Servidor>> servidores;
    shared_ptr<Usuario> usuarioLogado;
    shared_ptr<Servidor> servidorAtual;
    shared_ptr<Canal> canalAtual;
    shared_ptr<bool> sair;

public:
    Sistema();
    ~Sistema();
    vector<shared_ptr<Usuario>> getUsuarios();
    shared_ptr<Usuario> getUsuarioPorId(int id);
    void adicionarUsuario(shared_ptr<Usuario> usuario);
    vector<shared_ptr<Servidor>> getServidores();
    void adicionarServidor(shared_ptr<Servidor> servidor);
    void removerServidor(shared_ptr<Servidor> servidor);
    shared_ptr<Usuario> getUsuarioLogado();
    void setUsuarioLogado(shared_ptr<Usuario> usuario);
    shared_ptr<Servidor> getServidorAtual();
    void setServidorAtual(shared_ptr<Servidor> servidor);
    shared_ptr<Canal> getCanalAtual();
    void setCanalAtual(shared_ptr<Canal> canal);
    shared_ptr<bool> getSair();
    void setSair(shared_ptr<bool> sair);
};

#endif // SISTEMA_HPP