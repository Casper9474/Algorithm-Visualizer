#pragma once
#include <memory>
#include <vector>
#include <functional>

class Sorter {
    public:
    virtual ~Sorter() = default;

    virtual auto sort(std::shared_ptr<std::vector<int>>, std::function<void()> updateUI) -> void = 0;

    Sorter() = default;
};