#include <vector>

namespace core {
    struct flag {
        const char *flagString = "";
        unsigned short index = nullptr;
        unsigned long long int *valueptr = nullptr;
    };

    struct flagToCheck {
        const char *flagString = "";
        const bool withValue = true;
    };


    flag checkForFlags(int argc, char **agrv[], flagToCheck flagsToCheck[]) {
        std::vector <flag> flagvec = {};

        for (int i = 0; i <; i++) {
            for (int j = 1; j < argc; j++) {
                if (argv[j] == flagsToCheck[i].flagString) {
                    if (flagsToCheck[i].withValue) {
                        flagvec.push_back(flag{
                                flagsToCheck[i].flagString, /* flagString */
                                j,                          /* index */
                                &argv[++j]                  /* valueptr */
                        });
                    } else {
                        flagvec.push_back(flag{
                                flagsToCheck[i].flagString, /* flagString */
                                j                           /* index */
                        });
                    }
                }
            }
        }

        flag flags[flagvec.size()] = {};

        for (int i = 0; i < flagvec.size(); i++) {
            flags[i] = flagvec[i];
        }
        return flags;
    }
}