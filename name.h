#include "base_name.h"
// name.h
class Name : public base_name {
public:
    std::string first;

    Name() = default;
    Name(std::string first, std::string last) : base_name(std::move(last)), first(std::move(first)) {}

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Name, first, last)
};