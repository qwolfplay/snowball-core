#include "Snowball/Console.h"

namespace Snowball::console
{
bool checkArgs(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        if (!argv[i]) {
            return false;
        }
    }
    return true;
}

std::vector<Snowball::console::flag> checkForFlags(int argc, char *argv[], const std::vector<flagToCheck>& flagsToCheck) {
    std::vector<flag> flags = {};

    for (auto &i: flagsToCheck) {
        for (int j = 1; j < argc; j++) {
            if (argv[j] == i.flagString) {
                if (i.withValue) {
                    flags.push_back(flag{
                            i.flagString,   /* flagString */
                            j,              /* index */
                            argv[++j]       /* valueptr */
                    });
                } else {
                    flags.push_back(flag{
                            i.flagString, /* flagString */
                            j             /* index */
                    });
                }
            }
        }
    }
    return flags;
}

}