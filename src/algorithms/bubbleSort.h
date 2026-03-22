#pragma once
#include "sorter.h"

class BubbleSort : public Sorter {
    public:
    auto sort(std::shared_ptr<std::vector<int>> data, std::function<void()>) -> void override;
};