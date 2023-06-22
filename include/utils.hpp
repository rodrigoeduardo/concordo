#include <string>
#include <time.h>
#include <memory>
#include "Sistema.hpp"

using namespace std;

const string obterDataAtual();

void executarComando(string entrada, shared_ptr<Sistema> sistema);