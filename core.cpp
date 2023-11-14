#include "core.h"

#include <vector>


std::vector<core::flag>
core::checkForFlags(unsigned short argc, char *argv[], const std::vector<flagToCheck> &flagsToCheck) {
    std::vector<flag> flags = {};

    for (auto &i: flagsToCheck) {
        for (unsigned short j = 1; j < argc; j++) {
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