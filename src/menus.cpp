
#include "menus.hpp"
#include "Sistema.hpp"

void menuInicial(unique_ptr<Sistema> sistema)
{
    while (true)
    {
        string entrada;

        getline(cin, entrada);

        string comando = entrada.substr(0, entrada.find(" "));

        if (comando == "quit")
        {
            cout << "Saindo do Concordo" << endl;
            break;
        }
        else if (comando == "login")
        {
        }
        else if (comando == "create-user")
        {
            string email = "", senha = "", nome = "";
            string dados = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

            int i = 0;

            for (; i <= dados.size(); i++)
            {
                if (dados[i] == ' ')
                {
                    email = dados.substr(0, i);
                    break;
                }
            }

            auto usuarios = sistema->getUsuarios();

            for (int j = 0; j <= usuarios->size(); j++)
            {
                if (usuarios->size() == 0)
                    break;

                auto usuario = move(usuarios->at(j));
                if (usuario->getEmail() == email)
                {
                    cout << "Usuário já existe" << endl;
                    break;
                }
            }

            for (i++; i <= dados.size(); i++)
            {
                if (dados[i] == ' ')
                    break;

                senha += dados[i];
            }

            nome = dados.substr(i + 1, entrada.size() - 1);

            if (email == "" || senha == "" || nome == "")
            {
                cout << "Dados inválidos" << endl;
            }
            else
            {
                sistema->adicionarUsuario(make_unique<Usuario>(email, senha, nome));
                cout << "Usuário criado" << endl;
            }
        }
    }
    cout << "Usuários: " << sistema->getUsuarios()->size() << endl;
}