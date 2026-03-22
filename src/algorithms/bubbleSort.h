#pragma once
#include "sorter.h"
#include <string_view>
#include <memory>
#include <vector>
#include <functional>

class BubbleSort : public Sorter {
public:
    BubbleSort(std::string_view);

    auto sort(std::shared_ptr<std::vector<int> > data, std::function<void()>, std::atomic<bool> &,
              int) -> void override;
};
