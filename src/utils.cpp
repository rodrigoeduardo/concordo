#include "utils.hpp"
#include <string>
#include <time.h>

using namespace std;

const string obterDataAtual()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}