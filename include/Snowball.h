#ifndef CPP_CORE_CORE_H
#define CPP_CORE_CORE_H

#include <vector>
#include <fstream>
#include <ostream>
#include <filesystem>

class Snowball
{
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
    static bool checkArgs(int argc, char** argv);
    static void toBinFile(char *path, char *data);
    static char* toBytes(const void* data, size_t dataSize);
    static void clearConsole();
    static void fillArrayWithZeros(void *arrayPtr, size_t sizeOfType, size_t size);
    static std::vector<std::string> splitString(const std::string& string, char delimiter);
    // TODO: static void deletePath(const std::filesystem::path path);

};


#endif //CPP_CORE_CORE_H