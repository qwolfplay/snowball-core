#include "Snowball/String.h"

#include <sstream>

namespace Snowball::string
{
std::vector<std::string> splitString(const std::string& string, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(string);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}
}