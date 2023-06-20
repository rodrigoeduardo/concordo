
#include "menus.hpp"
#include "Sistema.hpp"

void menuInicial(shared_ptr<Sistema> sistema)
{
    while (true)
    {
        string entrada;

        getline(cin, entrada);

        string comando = entrada.substr(0, entrada.find(" "));

        if (comando == "quit")
        {
            cout << "Saindo do Concordo" << endl;
            return;
        }
        else if (comando == "login")
        {
            if (sistema->getUsuarios().size() == 0)
            {
                cout << "Nenhum usuário cadastrado" << endl;
                continue;
            }

            string email = "", senha = "";
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

            senha = dados.substr(i + 1, entrada.size() - 1);

            if (email == "" || senha == "")
            {
                cout << "Dados inválidos" << endl;
            }
            else
            {
                auto usuarios = sistema->getUsuarios();

                for (int j = 0; j <= usuarios.size() - 1; j++)
                {
                    auto usuario = move(usuarios.at(j));
                    if (usuario->getEmail() == email && usuario->getSenha() == senha)
                    {
                        auto usuarioLogado = usuario;
                        sistema->setUsuarioLogado(usuarioLogado);
                        cout << "Logado como " << usuarioLogado->getEmail() << endl;
                        break;
                    }

                    if (j == usuarios.size() - 1)
                        cout << "Email e/ou senha incorretos" << endl;
                }
            }
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

            cout << email << endl;

            auto usuarios = sistema->getUsuarios();

            if (usuarios.size() > 0)
            {
                for (int j = 0; j <= usuarios.size(); j++)
                {
                    auto usuario = usuarios.at(j);
                    if (usuario->getEmail() == email)
                    {
                        cout << "Usuário já existe" << endl;
                        break;
                    }
                }
            }

            for (i++; i <= dados.size(); i++)
            {
                if (dados[i] == ' ')
                    break;

                senha += dados[i];
            }

            cout << senha << endl;

            nome = dados.substr(i + 1, entrada.size() - 1);

            cout << nome << endl;

            if (email == "" || senha == "" || nome == "")
            {
                cout << "Dados inválidos" << endl;
            }
            else
            {
                sistema->adicionarUsuario(make_shared<Usuario>(Usuario(nome, email, senha)));
                cout << "Usuário criado" << endl;
            }
        }

        if (sistema->getUsuarioLogado() != nullptr)
        {
            menuLogado(sistema);
            return;
        }
    }
}

void menuLogado(shared_ptr<Sistema> sistema)
{
    string entrada;

    getline(cin, entrada);

    string comando = entrada.substr(0, entrada.find(" "));

    if (comando == "quit")
    {
        cout << "Saindo do Concordo" << endl;
        return;
    }
}