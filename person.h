#pragma once
#include <string>
#include "name.h" 
#include "home.h" 
#include "json.hpp" 
#include <memory> 

namespace ns {
class person {
private:
    Name name; 
    std::string address = "123 Fake St";
    int age = -1;
    home h; 

public:
    person() = default;
    person(Name name_, std::string address_, int age_, home h_)
        : name(std::move(name_)), address(std::move(address_)), age(age_), h(h_) {}
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(person, name, address, age, h)
};
}
