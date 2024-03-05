#include <string>
#include "json.hpp"

class base_name {
public:
    std::string last;

    base_name() = default;
    explicit base_name(std::string last) : last(std::move(last)) {}

    virtual ~base_name() = default;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(base_name, last)
};