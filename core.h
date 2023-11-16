#ifndef CPP_CORE_CORE_H
#define CPP_CORE_CORE_H

#include <vector>
#include <fstream>
#include <ostream>

class core {
public:
    struct flag {
        const char *flagString = "";
        int index = 0;
        char *valueptr = nullptr;
    };

    struct flagToCheck {
        const char *flagString = "";
        const bool withValue = true;
    };

    static std::vector<flag> checkForFlags(int argc, char *argv[], const std::vector<flagToCheck> &flagsToCheck);

    static void toBinFile(char *path, char *data);
    static char* toBytes(const auto &data);
};


#endif //CPP_CORE_CORE_H