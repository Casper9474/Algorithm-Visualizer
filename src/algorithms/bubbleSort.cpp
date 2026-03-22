#include "bubbleSort.h"

#include <chrono>

#include "sorter.h"
#include <functional>
#include <thread>

BubbleSort::BubbleSort(std::string_view name) : Sorter(name) {
}

auto BubbleSort::sort(std::shared_ptr<std::vector<int> > data, std::function<void()> updateData,
                      std::atomic<bool> &stopRequested, int delay) -> void {
    if (data == nullptr || data->empty()) return;

    auto n{data->size()};
    bool swapped{true};

    while (swapped && !stopRequested) {
        swapped = false;
        for (auto i{1}; i < n; i++) {
            if ((*data)[i - 1] > (*data)[i]) {
                std::swap((*data)[i - 1], (*data)[i]);
                swapped = true;
            }
        }
        n--;

        updateData();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}
