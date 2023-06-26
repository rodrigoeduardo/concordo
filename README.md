# Concordo

Concordo é uma aplicação clone do Discord. Para implementá-la foi utilizada a linguagem C++. Este projeto foi criado a partir de uma atividade da disciplina Linguagem de Programação I no curso de Tecnologia da Informação da UFRN.

# Informações do Aluno

    - Nome: Rodrigo Eduardo Dantas Barbalho
    - Turma: 01
    - Matrícula: 20220050553

# Como rodar o projeto

Clone o projeto utilizando o git e entre no diretório:

```bash
git clone https://github.com/rodrigoeduardo/concordo.git
cd concordo
```

Agora, para compilar o Concordo, siga os seguintes passos:

```bash
mkdir build
cd build
cmake ..
make
```

Dessa forma, o Concordo está pronto para rodar:

```bash
./concordo
```

Para rodar o projeto utilizando o script que passa por todas as funcionalidades, utilize:

```bash
./concordo < ../script.txt
```

# Funcionalidades

O Concordo, atualmente, conta com todas as funcionalidades previstas pelo professor até a Parte I:

- Sair do sistema
- Criar usuário
- Fazer login
- Interações com Servidores
  - Desconectar
  - Criar servidor
  - Mudar a descrição do servidor
  - Setar código de convite do servidor
  - Listar servidores
  - Remover servidor
  - Entrar em um servidor
  - Sair de um servidor
  - Listar participantes do servidor
