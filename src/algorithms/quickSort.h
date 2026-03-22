#pragma once
#include "sorter.h"
#include <string_view>
#include <memory>
#include <vector>
#include <functional>

class QuickSort : public Sorter {
public:
    QuickSort(std::string_view);

    auto sort(std::shared_ptr<std::vector<int> > data, std::function<void()>, std::atomic<bool> &,
              int) -> void override;

private:
    auto quickSort(std::shared_ptr<std::vector<int> > data, int low, int high,
                   std::function<void()> updateData, std::atomic<bool> &stopRequested, int delay) -> void;

    auto partition(std::shared_ptr<std::vector<int> > data, int low, int high,
                   std::function<void()> updateData, std::atomic<bool> &stopRequested, int delay) -> int;
};
