#include "quickSort.h"

#include <chrono>
#include "sorter.h"
#include <functional>
#include <thread>

QuickSort::QuickSort(std::string_view name) : Sorter(name) {
}

auto QuickSort::sort(std::shared_ptr<std::vector<int> > data, std::function<void()> updateData,
                     std::atomic<bool> &stopRequested, int delay) -> void {
    if (data == nullptr || data->empty()) return;

    quickSort(data, 0, static_cast<int>(data->size()) - 1, updateData, stopRequested, delay);
}

auto QuickSort::quickSort(std::shared_ptr<std::vector<int> > data, int low, int high,
                          std::function<void()> updateData, std::atomic<bool> &stopRequested,
                          int delay) -> void {
    if (low < high && !stopRequested) {
        auto p{partition(data, low, high, updateData, stopRequested, delay)};
        quickSort(data, low, p, updateData, stopRequested, delay);
        quickSort(data, p + 1, high, updateData, stopRequested, delay);
    }
}

auto QuickSort::partition(std::shared_ptr<std::vector<int> > data, int low, int high,
                          std::function<void()> updateData, std::atomic<bool> &stopRequested,
                          int delay) -> int {
    auto mid{low + (high - low) / 2};

    if ((*data)[mid] < (*data)[low]) {
        std::swap((*data)[mid], (*data)[low]);
        updateData();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    if (stopRequested) return mid;

    if ((*data)[high] < (*data)[low]) {
        std::swap((*data)[high], (*data)[low]);
        updateData();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    if (stopRequested) return mid;

    if ((*data)[high] < (*data)[mid]) {
        std::swap((*data)[high], (*data)[mid]);
        updateData();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    if (stopRequested) return mid;

    auto pivot{(*data)[mid]};
    auto i{low - 1};
    auto j{high + 1};

    while (true) {
        if (stopRequested) return j;

        do { i++; } while ((*data)[i] < pivot);
        do { j--; } while ((*data)[j] > pivot);

        if (i >= j) return j;

        std::swap((*data)[i], (*data)[j]);

        updateData();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}
