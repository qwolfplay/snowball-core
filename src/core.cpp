#include "Snowball.h"

#include <vector>
#include <sstream>
#ifdef __GNUC__
#include <cstring>
#endif

bool Snowball::checkArgs(int argc, char** argv) {
        for (int i = 0; i < argc; i++) {
            if (!argv[i]) {
                return false;
            }
        }
        return true;
    }

std::vector<Snowball::flag>
Snowball::checkForFlags(int argc, char *argv[], const std::vector<flagToCheck>& flagsToCheck) {
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

void Snowball::toBinFile(char *path, char *data) {
    std::ofstream outFile(path, std::ios::binary);
    if (!outFile) {
        throw std::exception(); // TODO: REPLACE
    }

    outFile.write(reinterpret_cast<const char *> (data), sizeof(data));
    if (!outFile) {
        throw std::exception(); // TODO: REPLACE
    }

    outFile.close();
}

char *Snowball::toBytes(const void* data, size_t dataSize) {
    char *byteData = new char[dataSize]; // ! DON'T FORGET TO FREE THE MEMORY

    memcpy(byteData, data, dataSize);

    return byteData;
}

void Snowball::clearConsole() {
#if defined(_WIN32) || defined(WIN32)
    system("cls");
#elif defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif
}

void Snowball::fillArrayWithZeros(void *arrayPtr, size_t sizeOfType, size_t size) {
    memset(arrayPtr, 0, size * sizeOfType);
}

std::vector<std::string> Snowball::splitString(const std::string& string, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(string);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}
