
#include "menus.hpp"
#include "Sistema.hpp"

void menuInicial(shared_ptr<Sistema> sistema)
{
    while (true)
    {
        sistema->setSair(make_shared<bool>(false));
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

            auto usuarios = sistema->getUsuarios();

            for (int j = 0; j <= usuarios.size(); j++)
            {
                if (j == usuarios.size())
                    break;

                auto usuario = usuarios.at(j);
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
                sistema->adicionarUsuario(make_shared<Usuario>(Usuario(nome, email, senha)));
                cout << "Usuário criado" << endl;
            }
        }

        if (sistema->getUsuarioLogado() != nullptr)
        {
            menuLogado(sistema);
            bool sair = *sistema->getSair();
            if (sair)
            {
                cout << "Saindo do Concordo" << endl;
                return;
            }
        }
    }
}

void menuLogado(shared_ptr<Sistema> sistema)
{
    while (true)
    {
        string entrada;

        getline(cin, entrada);

        string comando = entrada.substr(0, entrada.find(" "));

        if (comando == "quit")
        {
            sistema->setSair(make_shared<bool>(true));
            return;
        }
        else if (comando == "disconnect")
        {
            cout << "Desconectando usuário " << sistema->getUsuarioLogado()->getEmail() << endl;
            sistema->setUsuarioLogado(nullptr);
            return;
        }
        else if (comando == "create-server")
        {
            string nomeServidor = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

            auto servidores = sistema->getServidores();

            for (int j = 0; j <= servidores.size(); j++)
            {
                if (j == servidores.size())
                    break;

                auto servidor = servidores.at(j);
                if (servidor->getNome() == nomeServidor)
                {
                    cout << "Servidor com esse nome já existe" << endl;
                    break;
                }
            }

            if (nomeServidor == "")
            {
                cout << "Dados inválidos" << endl;
            }
            else
            {
                sistema->adicionarServidor(make_shared<Servidor>(Servidor(sistema->getUsuarioLogado()->getId(), nomeServidor)));
                cout << "Servidor criado" << endl;
            }
        }
        else if (comando == "set-server-desc")
        {
            string dados = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

            int i = 0;

            for (; i <= dados.size(); i++)
            {
                if (dados[i] == ' ')
                    break;
            }

            string nomeServidor = dados.substr(0, i);
            string descricaoNova = dados.substr(i + 1, entrada.size() - 1);

            if (descricaoNova == "" || nomeServidor == "")
            {
                cout << "Dados inválidos" << endl;
            }
            else
            {
                auto servidores = sistema->getServidores();

                for (int j = 0; j <= servidores.size(); j++)
                {
                    if (servidores.size() == 0)
                    {
                        cout << "Servidor " << nomeServidor << " não existe" << endl;
                        break;
                    }

                    auto servidor = servidores.at(j);

                    if (servidor->getNome() != nomeServidor)
                        continue;

                    if (servidor->getUsuarioDonoId() == sistema->getUsuarioLogado()->getId())
                    {
                        servidor->setDescricao(descricaoNova);
                        cout << "Descrição do servidor " << servidor->getNome() << " modificada!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << endl;
                        break;
                    }

                    if (j == servidores.size() - 1)
                        cout << "Servidor " << nomeServidor << " não existe" << endl;
                }
            }
        }
        else if (comando == "set-server-invite-code")
        {
            string dados = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

            int i = 0;

            for (; i <= dados.size(); i++)
            {
                if (dados[i] == ' ' || dados[i] == '\0')
                    break;
            }

            string nomeServidor;
            string codigoConvite;

            if (i == dados.size())
            {
                nomeServidor = dados.substr(0, i);
                codigoConvite = "";
            }
            else
            {
                nomeServidor = dados.substr(0, i - 1);
                codigoConvite = dados.substr(i + 1, entrada.size() - 1);
            }

            if (nomeServidor == "")
            {
                cout << "Dados inválidos" << endl;
            }
            else
            {
                auto servidores = sistema->getServidores();

                for (int j = 0; j <= servidores.size(); j++)
                {
                    if (servidores.size() == 0)
                    {
                        cout << "Servidor " << nomeServidor << " não existe" << endl;
                        break;
                    }

                    auto servidor = servidores.at(j);

                    if (servidor->getNome() != nomeServidor)
                        continue;

                    if (servidor->getUsuarioDonoId() == sistema->getUsuarioLogado()->getId())
                    {
                        servidor->setCodigoConvite(codigoConvite);
                        cout << "Código de convite do servidor " << servidor->getNome() << " modificado!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Você não pode alterar o código de convite de um servidor que não foi criado por você" << endl;
                        break;
                    }

                    if (j == servidores.size() - 1)
                        cout << "Servidor " << nomeServidor << " não existe" << endl;
                }
            }
        }
        else if (comando == "list-servers")
        {
            auto servidores = sistema->getServidores();

            if (servidores.size() == 0)
            {
                cout << "Nenhum servidor encontrado" << endl;
            }
            else
            {
                for (int i = 0; i < servidores.size(); i++)
                {
                    auto servidor = servidores.at(i);
                    cout << servidor->getNome() << endl;
                }
            }
        }
        else if (comando == "remove-server")
        {
        }
        else if (comando == "enter-server")
        {
        }
    }
}