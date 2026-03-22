#pragma once
#include <memory>
#include <vector>
#include <functional>
#include <string>
#include <string_view>

class Sorter {
public:
    Sorter(std::string_view name) : m_name(name) {
    };

    virtual ~Sorter() = default;

    virtual auto sort(std::shared_ptr<std::vector<int> >, std::function<void()>, std::atomic<bool> &, int) -> void = 0;

    auto getName() const -> std::string_view { return m_name; }

private:
    std::string m_name{};
};
