#include "bubbleSort.h"
#include "sorter.h"
#include <functional>

auto BubbleSort::sort(std::shared_ptr<std::vector<int>> data, std::function<void()> updateData) -> void {
    auto n {data->size()};
    bool swapped {true};
    while (swapped) {
        swapped = false;
        for (auto i {1}; i < n; i++) {
            if ((*data)[i-1] > (*data)[i]) {
                std::swap((*data)[i-1], (*data)[i]);
                updateData();
                swapped = true;
            }
        }
    }
}