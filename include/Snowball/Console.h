#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>

namespace Snowball::console {
struct flag {
    const char *flagString = "";
    int index = 0;
    char *valueptr = nullptr;
};

struct flagToCheck {
    const char *flagString = "";
    const bool withValue = true;
};

bool checkArgs(int argc, char** argv);
std::vector<Snowball::console::flag> checkForFlags(int argc, char *argv[], const std::vector<flagToCheck>& flagsToCheck);
}

#endif //CONSOLE_H
