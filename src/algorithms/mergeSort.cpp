#include "mergeSort.h"

#include <chrono>
#include <functional>
#include <thread>
#include <vector>

MergeSort::MergeSort(std::string_view name) : Sorter(name) {
}

auto MergeSort::sort(std::shared_ptr<std::vector<int>> data, std::function<void()> updateData,
                     std::atomic<bool> &stopRequested, int delay) -> void {
    if (data == nullptr || data->empty()) return;

    mergeSort(data, 0, static_cast<int>(data->size()) - 1, updateData, stopRequested, delay);
}

auto MergeSort::mergeSort(std::shared_ptr<std::vector<int>> data, int low, int high,
                          std::function<void()> updateData, std::atomic<bool> &stopRequested,
                          int delay) -> void {
    if (low < high && !stopRequested) {
        auto mid{low + (high - low) / 2};
        mergeSort(data, low, mid, updateData, stopRequested, delay);
        mergeSort(data, mid + 1, high, updateData, stopRequested, delay);
        merge(data, low, mid, high, updateData, stopRequested, delay);
    }
}

auto MergeSort::merge(std::shared_ptr<std::vector<int>> data, int low, int mid, int high,
                      std::function<void()> updateData, std::atomic<bool> &stopRequested,
                      int delay) -> void {
    if (stopRequested) return;

    auto n1{mid - low + 1};
    auto n2{high - mid};

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (auto i{0}; i < n1; i++) {
        left[i] = (*data)[low + i];
    }
    for (auto j{0}; j < n2; j++) {
        right[j] = (*data)[mid + 1 + j];
    }

    auto i{0}, j{0}, k{low};
    while (i < n1 && j < n2) {
        if (stopRequested) return;

        if (left[i] <= right[j]) {
            (*data)[k] = left[i];
            i++;
        } else {
            (*data)[k] = right[j];
            j++;
        }
        
        updateData();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        k++;
    }

    while (i < n1) {
        if (stopRequested) return;
        (*data)[k] = left[i];
        
        updateData();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        i++;
        k++;
    }

    while (j < n2) {
        if (stopRequested) return;
        (*data)[k] = right[j];
        
        updateData();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        j++;
        k++;
    }
}
