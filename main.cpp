#include "person.h"
#include <iostream>
#include <fstream>
#include <memory>
#include "json.hpp"

using json = nlohmann::json;
using namespace ns;

int main() {
    // 创建person对象
    Name name;
    name.first = "zzz";
    name.last = "xxx";
    std::vector<std::shared_ptr<int>> vec = {std::make_shared<int>(10), std::make_shared<int>(20)};
    vec.clear();
    home h(1, vec);

    person p{name, "744 Evergreen Terrace", 60, h};

    // 序列化：person -> json
    // 注意：为了正确序列化person对象，需要为person、Name和home类型提供自定义的to_json方法
    std::cout << "adfa" << std::endl;
    json j = p;
    std::cout << "Serialization: " << j.dump(4) << std::endl;

    // 将JSON写入文件
    std::ofstream file("person.json");
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
        std::cout << "Data serialized to person.json" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
        return 1;
    }

    return 0;
}
