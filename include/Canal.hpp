#ifndef CANAL_HPP
#define CANAL_HPP

#include <string>

using namespace std;

class Canal
{
private:
    string nome;

public:
    Canal(string nome);
    string getNome();
    void setNome(string nome);
};

#endif // CANAL_HPP