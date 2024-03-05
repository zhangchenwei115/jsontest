// name.h
#include <string>
#include "json.hpp"

struct Name {
    std::string first;
    std::string last;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Name, first, last)
};