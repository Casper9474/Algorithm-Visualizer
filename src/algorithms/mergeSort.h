#pragma once
#include "sorter.h"
#include <string_view>
#include <memory>
#include <vector>
#include <functional>

class MergeSort : public Sorter {
public:
    MergeSort(std::string_view);

    auto sort(std::shared_ptr<std::vector<int> > data, std::function<void()>, std::atomic<bool> &,
              int) -> void override;

private:
    auto mergeSort(std::shared_ptr<std::vector<int> > data, int low, int high,
                    std::function<void()> updateData, std::atomic<bool> &stopRequested,
                    int delay) -> void;

    auto merge(std::shared_ptr<std::vector<int> > data, int low, int mid, int high,
               std::function<void()> updateData, std::atomic<bool> &stopRequested,
               int delay) -> void;
};
