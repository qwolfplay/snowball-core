#ifndef CPP_CORE_CORE_H
#define CPP_CORE_CORE_H

#include <vector>
#include <fstream>
#include <ostream>
#include <filesystem>

namespace Snowball
{

struct flag {
    const char *flagString = "";
    int index = 0;
    char *valueptr = nullptr;
};

struct flagToCheck {
    const char *flagString = "";
    const bool withValue = true;
};

std::vector<flag> checkForFlags(int argc, char *argv[], const std::vector<flagToCheck> &flagsToCheck);
bool checkArgs(int argc, char** argv);
void toBinFile(char *path, char *data);
char* toBytes(const void* data, size_t dataSize);
void clearConsole();
void fillArrayWithZeros(void *arrayPtr, size_t sizeOfType, size_t size);
std::vector<std::string> splitString(const std::string& string, char delimiter);
// TODO: void deletePath(const std::filesystem::path path);

};


#endif //CPP_CORE_CORE_H