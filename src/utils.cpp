#include "utils.hpp"
#include <string>
#include <time.h>
#include <iostream>

using namespace std;

const string obterDataAtual()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%d/%m/%Y - %X", &tstruct);

    return buf;
}

void executarComando(string entrada, shared_ptr<Sistema> sistema)
{
    try
    {
        string comando = entrada.substr(0, entrada.find(" "));

        if (comando == "quit")
        {
            sistema->setSair(make_shared<bool>(true));
            return;
        }

        if (sistema->getUsuarioLogado() != nullptr)
        {
            if (comando == "disconnect")
            {
                cout << "Desconectando usuário " << sistema->getUsuarioLogado()->getEmail() << endl;
                sistema->setUsuarioLogado(nullptr);
                sistema->setServidorAtual(nullptr);
                sistema->setCanalAtual(nullptr);
                return;
            }
        }

        if (sistema->getUsuarioLogado() == nullptr)
        {
            if (comando == "login")
            {
                if (sistema->getUsuarios().size() == 0)
                {
                    cout << "Nenhum usuário cadastrado" << endl;
                    return;
                }

                string email = "", senha = "";
                string dados = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

                int i = 0;

                for (; i < dados.size(); i++)
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

                    for (int j = 0; j < usuarios.size(); j++)
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
                return;
            }
            else if (comando == "create-user")
            {
                string email = "", senha = "", nome = "";
                string dados = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

                int i = 0;

                for (; i < dados.size(); i++)
                {
                    if (dados[i] == ' ')
                    {
                        email = dados.substr(0, i);
                        break;
                    }
                }

                auto usuarios = sistema->getUsuarios();

                for (int j = 0; j < usuarios.size(); j++)
                {
                    auto usuario = usuarios.at(j);
                    if (usuario->getEmail() == email)
                    {
                        cout << "Usuário já existe" << endl;
                        break;
                    }
                }

                for (i++; i < dados.size(); i++)
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
                return;
            }
        }
        else if (sistema->getUsuarioLogado() != nullptr && sistema->getServidorAtual() == nullptr)
        {
            if (comando == "create-server")
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
                return;
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
                return;
            }
            else if (comando == "set-server-invite-code")
            {
                string dados = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

                string nomeServidor = "";
                string codigoConvite = "";

                int i = 0;

                for (; i <= dados.size(); i++)
                {
                    if (dados[i] == ' ')
                    {
                        nomeServidor = dados.substr(0, i);
                        codigoConvite = dados.substr(i + 1, entrada.size() - 1);
                        break;
                    }
                    else if (dados[i] == '\0')
                    {
                        nomeServidor = dados.substr(0, i);
                        codigoConvite = "";
                        break;
                    }
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
                return;
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
                return;
            }
            else if (comando == "remove-server")
            {
                string nomeServidor = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

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
                            sistema->removerServidor(servidor);
                            cout << "Servidor " << servidor->getNome() << " removido!" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Você não pode remover um servidor que não foi criado por você" << endl;
                            break;
                        }

                        if (j == servidores.size() - 1)
                            cout << "Servidor " << nomeServidor << " não existe" << endl;
                    }
                }
                return;
            }
            else if (comando == "enter-server")
            {
                string dados = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

                string nomeServidor = "";
                string codigoConvite = "";

                int i = 0;

                for (; i <= dados.size(); i++)
                {
                    if (dados[i] == ' ')
                    {
                        nomeServidor = dados.substr(0, i);
                        codigoConvite = dados.substr(i + 1, entrada.size() - 1);
                        break;
                    }
                    else if (dados[i] == '\0')
                    {
                        nomeServidor = dados.substr(0, i);
                        codigoConvite = "";
                        break;
                    }
                }

                if (nomeServidor == "")
                {
                    cout << "Dados inválidos" << endl;
                }
                else
                {
                    auto servidores = sistema->getServidores();

                    for (int j = 0; j < servidores.size(); j++)
                    {
                        if (servidores.size() == 0)
                        {
                            cout << "Servidor " << nomeServidor << " não existe" << endl;
                            break;
                        }

                        auto servidor = servidores.at(j);

                        if (servidor->getNome() != nomeServidor)
                            continue;

                        if (
                            servidor->getCodigoConvite() == codigoConvite ||
                            sistema->getUsuarioLogado()->getId() == servidor->getUsuarioDonoId())
                        {
                            sistema->setServidorAtual(servidor);
                            servidor->adicionarParticipanteId(sistema->getUsuarioLogado()->getId());
                            cout << "Entrou no servidor " << servidor->getNome() << endl;
                            break;
                        }
                        else
                        {
                            cout << "Código de convite inválido" << endl;
                            break;
                        }

                        if (j == servidores.size() - 1)
                            cout << "Servidor " << nomeServidor << " não existe" << endl;
                    }
                }
                return;
            }
        }
        else if (sistema->getUsuarioLogado() != nullptr && sistema->getServidorAtual() != nullptr && sistema->getCanalAtual() == nullptr)
        {
            if (comando == "leave-server")
            {
                cout << "Saindo do servidor " << sistema->getServidorAtual()->getNome() << endl;
                sistema->setServidorAtual(nullptr);
                return;
            }
            else if (comando == "list-participants")
            {
                auto servidorAtual = sistema->getServidorAtual();

                if (servidorAtual == nullptr)
                {
                    cout << "Nenhum servidor encontrado" << endl;
                }
                else
                {
                    auto participantesIds = servidorAtual->getParticipantesIds();

                    if (participantesIds.size() == 0)
                    {
                        cout << "Nenhum participante encontrado" << endl;
                    }
                    else
                    {
                        for (int i = 0; i < participantesIds.size(); i++)
                        {
                            auto participanteId = participantesIds.at(i);
                            auto participante = sistema->getUsuarioPorId(participanteId);
                            cout << participante->getNome() << endl;
                        }
                    }
                }
                return;
            }
            else if (comando == "list-channels")
            {
                auto servidorAtual = sistema->getServidorAtual();

                cout << "#canais de texto" << endl;

                auto canaisTexto = servidorAtual->getCanaisTexto();

                if (canaisTexto.size() == 0)
                {
                    cout << "Nenhum canal de texto encontrado" << endl;
                }
                else
                {
                    for (int i = 0; i < canaisTexto.size(); i++)
                    {
                        auto canalTexto = canaisTexto.at(i);
                        cout << canalTexto->getNome() << endl;
                    }
                }

                cout << "#canais de voz" << endl;

                auto canaisVoz = servidorAtual->getCanaisVoz();

                if (canaisVoz.size() == 0)
                {
                    cout << "Nenhum canal de voz encontrado" << endl;
                }
                else
                {
                    for (int i = 0; i < canaisVoz.size(); i++)
                    {
                        auto canalVoz = canaisVoz.at(i);
                        cout << canalVoz->getNome() << endl;
                    }
                }
                return;
            }
            else if (comando == "create-channel")
            {
                string dados = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

                int i = 0;

                for (; i <= dados.size(); i++)
                {
                    if (dados[i] == ' ')
                        break;
                }

                string nomeCanal = dados.substr(0, i);
                string tipo = dados.substr(i + 1, entrada.size() - 1);

                if (nomeCanal == "" || tipo == "")
                {
                    cout << "Dados inválidos" << endl;
                }
                else
                {
                    auto servidorAtual = sistema->getServidorAtual();

                    if (tipo == "texto")
                    {
                        for (int j = 0; j < servidorAtual->getCanaisTexto().size(); j++)
                        {
                            if (servidorAtual->getCanaisTexto().at(j)->getNome() == nomeCanal)
                            {
                                cout << "Canal de texto " << nomeCanal << " já existe" << endl;
                                return;
                            }
                        }

                        servidorAtual->adicionarCanalTexto(make_shared<CanalTexto>(CanalTexto(nomeCanal)));
                        cout << "Canal de texto " << nomeCanal << " criado!" << endl;
                    }
                    else if (tipo == "voz")
                    {
                        for (int j = 0; j < servidorAtual->getCanaisVoz().size(); j++)
                        {
                            if (servidorAtual->getCanaisVoz().at(j)->getNome() == nomeCanal)
                            {
                                cout << "Canal de voz " << nomeCanal << " já existe" << endl;
                                return;
                            }
                        }

                        servidorAtual->adicionarCanalVoz(make_shared<CanalVoz>(CanalVoz(nomeCanal)));
                        cout << "Canal de voz " << nomeCanal << " criado!" << endl;
                    }
                    else
                    {
                        cout << "Tipo de canal inválido" << endl;
                    }
                }
                return;
            }
            else if (comando == "enter-channel")
            {
                string nomeServidor = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

                if (nomeServidor == "")
                {
                    cout << "Dados inválidos" << endl;
                }
                else
                {
                    for (int i = 0; i < sistema->getServidorAtual()->getCanaisTexto().size(); i++)
                    {
                        if (sistema->getServidorAtual()->getCanaisTexto().at(i)->getNome() == nomeServidor)
                        {
                            sistema->setCanalAtual(sistema->getServidorAtual()->getCanaisTexto().at(i));
                            cout << "Entrou no canal " << nomeServidor << endl;
                            return;
                        }
                    }
                    for (int i = 0; i < sistema->getServidorAtual()->getCanaisVoz().size(); i++)
                    {
                        if (sistema->getServidorAtual()->getCanaisVoz().at(i)->getNome() == nomeServidor)
                        {
                            sistema->setCanalAtual(sistema->getServidorAtual()->getCanaisVoz().at(i));
                            cout << "Entrou no canal " << nomeServidor << endl;
                            return;
                        }
                    }
                    cout << "Canal " << nomeServidor << " não existe" << endl;
                }
                return;
            }
        }
        else
        {
            if (comando == "leave-channel")
            {
                cout << "Saindo do canal " << sistema->getCanalAtual()->getNome() << endl;
                sistema->setCanalAtual(nullptr);
                return;
            }
            else if (comando == "send-message")
            {
                string mensagem = entrada.substr(comando.length() + 1, entrada.size() - comando.length() - 1);

                if (mensagem == "")
                {
                    cout << "Dados inválidos" << endl;
                }
                else
                {
                    Mensagem novaMensagem = Mensagem(sistema->getUsuarioLogado()->getId(), mensagem);
                    sistema->getCanalAtual()->enviarMensagem(novaMensagem);
                }
                return;
            }
            else if (comando == "list-messages")
            {
                auto usuariosCadastrados = sistema->getUsuarios();
                sistema->getCanalAtual()->listarMensagens(usuariosCadastrados);
                return;
            }
        }
    }
    catch (...)
    {
        cout << "Dados inválidos. Por favor, tente novamente." << endl;
        return;
    }

    cout << "Comando inválido" << endl;
}