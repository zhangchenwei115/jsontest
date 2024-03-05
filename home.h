#pragma once
#include <memory> // 为 shared_ptr
#include <vector>  // 为 vector
#include "json.hpp"  // 确保包含了正确的头文件路径

class home {
public:
    home() = default;
    home(int a_, std::vector<std::shared_ptr<int>> b_) : a(a_), b(b_) {}
    friend void to_json(nlohmann::json& nlohmann_json_j, const home& nlohmann_json_t) {
        // 将b中的每个元素解引用并存储到JSON数组中
        std::vector<int> b_values;
        for (const auto& ptr : nlohmann_json_t.b) {
            b_values.push_back(ptr ? *ptr : 0);  // 解引用或使用0作为null值的替代
        }
        nlohmann_json_j = nlohmann::json{{"a", nlohmann_json_t.a}, {"b", b_values}};
    }
    friend void from_json(const nlohmann::json& nlohmann_json_j, home& nlohmann_json_t) {
        nlohmann_json_t.a = nlohmann_json_j.at("a").get<int>();
        // 从JSON数组构造vector<shared_ptr<int>>
        std::vector<std::shared_ptr<int>> b_vector;
        for (auto& item : nlohmann_json_j.at("b")) {
            b_vector.push_back(std::make_shared<int>(item.get<int>()));
        }
        nlohmann_json_t.b = std::move(b_vector);
    }

private:
    int a;
    std::vector<std::shared_ptr<int>> b;
};