#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class Usuario
{
private:
    int id;
    string nome;
    string email;
    string senha;

    static int contador;

public:
    Usuario(string nome, string email, string senha);
    ~Usuario();

    int getId();
    void setId(int id);
    string getNome();
    void setNome(string nome);
    string getEmail();
    void setEmail(string email);
    string getSenha();
    void setSenha(string senha);
};

#endif // USUARIO_H